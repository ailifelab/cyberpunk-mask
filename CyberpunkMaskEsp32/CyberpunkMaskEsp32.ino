// Include the correct display library
// For a connection via I2C using Wire include
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
#include "images.h"
#include "OLEDDisplayUi.h"
#include "esp32_digital_led_lib.h" //流水灯控制
#include <TimeLib.h>
//for led band
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

#define LED_BAND_PIN 27
#define DISP_SDA_1 0
#define DISP_SCL_1 14
#define DISP_SDA_2 5
#define DISP_SCL_2 4

#define BTN_UP 6
#define BTN_DOWN 7
#define BTN_ENTER 8
#define BTN_BACK 9

int screenW = 128;
int screenH = 64;
int clockCenterX = screenW / 2;
int clockCenterY = ((screenH - 16) / 2) + 16; // top yellow part is 16 px height
int clockRadius = 23;

void espPinMode(int pinNum, int pinDir) {
  // Enable GPIO32 or 33 as output. Doesn't seem to work though.
  // https://esp32.com/viewtopic.php?t=9151#p38282
  if (pinNum == 32 || pinNum == 33) {
    uint64_t gpioBitMask = (pinNum == 32) ? 1ULL << GPIO_NUM_32 : 1ULL << GPIO_NUM_33;
    gpio_mode_t gpioMode = (pinDir == OUTPUT) ? GPIO_MODE_OUTPUT : GPIO_MODE_INPUT;
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = gpioMode;
    io_conf.pin_bit_mask = gpioBitMask;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);
  } else pinMode(pinNum, pinDir);
}

void gpioSetup(int gpioNum, int gpioMode, int gpioVal) {
#if defined(ARDUINO) && ARDUINO >= 100
  espPinMode(gpioNum, gpioMode);
  digitalWrite (gpioNum, gpioVal);
#elif defined(ESP_PLATFORM)
  gpio_num_t gpioNumNative = static_cast<gpio_num_t>(gpioNum);
  gpio_mode_t gpioModeNative = static_cast<gpio_mode_t>(gpioMode);
  gpio_pad_select_gpio(gpioNumNative);
  gpio_set_direction(gpioNumNative, gpioModeNative);
  gpio_set_level(gpioNumNative, gpioVal);
#endif
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"  // It's noisy here with `-Wall`

//strand_t strand = {.rmtChannel = 0, .gpioNum = 26, .ledType = LED_WS2812B_V3, .brightLimit = 32, .numPixels = 64};
strand_t strand = {.rmtChannel = 0, .gpioNum = LED_BAND_PIN, .ledType = LED_SK6812W_V1, .brightLimit = 64, .numPixels = 144};
strand_t * STRANDS [] = { &strand };
int STRANDCNT = COUNT_OF(STRANDS);
#pragma GCC diagnostic pop

int stepper = 0;
int colord = 0;

//**************************************************************************//
void randomStrands(strand_t * strands[], int numStrands, unsigned long delay_ms, unsigned long timeout_ms)
{
  Serial.print("DEMO: random colors, delay = ");
  Serial.println(delay_ms);
  uint32_t dimmer = 0x0F3F3F3F;
  unsigned long start_ms = millis();
  while (timeout_ms == 0 || (millis() - start_ms < timeout_ms)) {
    for (int n = 0; n < numStrands; n++) {
      strand_t * pStrand = strands[n];
      for (uint16_t i = 0; i < pStrand->numPixels; i++) {
        pStrand->pixels[i].num = (esp_random() & dimmer);
      }
    }
    digitalLeds_drawPixels(strands, numStrands);
    delay(delay_ms);
  }
}

// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, DISP_SDA_1 , DISP_SCL_1 );
SSD1306Wire  display2(0x3c, DISP_SDA_2, DISP_SCL_2);
//display 用于菜单选择控制
OLEDDisplayUi ui     ( &display );

/****绘制菜单****/

void msOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(128, 0, String(millis()));
}

void drawFrame1(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // draw an xbm image.
  // Please note that everything that should be transitioned
  // needs to be drawn relative to x and y

  display->drawXbm(x + 34, y + 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
}

void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Demonstrates the 3 included default sizes. The fonts come from SSD1306Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Arial 10");

  display->setFont(ArialMT_Plain_16);
  display->drawString(0 + x, 20 + y, "Arial 16");

  display->setFont(ArialMT_Plain_24);
  display->drawString(0 + x, 34 + y, "Test 24");
}

void drawFrame3(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Text alignment demo
  display->setFont(ArialMT_Plain_10);

  // The coordinates define the left starting point of the text
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(0 + x, 11 + y, "Left aligned (0,10)");

  // The coordinates define the center of the text
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->drawString(64 + x, 22 + y, "Center aligned (64,22)");

  // The coordinates define the right end of the text
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->drawString(128 + x, 33 + y, "Right aligned (128,33)");
}

void drawFrame4(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Demo for drawStringMaxWidth:
  // with the third parameter you can define the width after which words will be wrapped.
  // Currently only spaces and "-" are allowed for wrapping
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawStringMaxWidth(0 + x, 10 + y, 128, "Lorem ipsum\n dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore.");
}

/**
   时钟
*/
void analogClockFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  //  ui.disableIndicator();

  // Draw the clock face
  //  display->drawCircle(clockCenterX + x, clockCenterY + y, clockRadius);
  display->drawCircle(clockCenterX + x, clockCenterY + y, 2);
  //
  //hour ticks
  for ( int z = 0; z < 360; z = z + 30 ) {
    //Begin at 0° and stop at 360°
    float angle = z ;
    angle = ( angle / 57.29577951 ) ; //Convert degrees to radians
    int x2 = ( clockCenterX + ( sin(angle) * clockRadius ) );
    int y2 = ( clockCenterY - ( cos(angle) * clockRadius ) );
    int x3 = ( clockCenterX + ( sin(angle) * ( clockRadius - ( clockRadius / 8 ) ) ) );
    int y3 = ( clockCenterY - ( cos(angle) * ( clockRadius - ( clockRadius / 8 ) ) ) );
    display->drawLine( x2 + x , y2 + y , x3 + x , y3 + y);
  }

  // display second hand
  float angle = second() * 6 ;
  angle = ( angle / 57.29577951 ) ; //Convert degrees to radians
  int x3 = ( clockCenterX + ( sin(angle) * ( clockRadius - ( clockRadius / 5 ) ) ) );
  int y3 = ( clockCenterY - ( cos(angle) * ( clockRadius - ( clockRadius / 5 ) ) ) );
  display->drawLine( clockCenterX + x , clockCenterY + y , x3 + x , y3 + y);
  //
  // display minute hand
  angle = minute() * 6 ;
  angle = ( angle / 57.29577951 ) ; //Convert degrees to radians
  x3 = ( clockCenterX + ( sin(angle) * ( clockRadius - ( clockRadius / 4 ) ) ) );
  y3 = ( clockCenterY - ( cos(angle) * ( clockRadius - ( clockRadius / 4 ) ) ) );
  display->drawLine( clockCenterX + x , clockCenterY + y , x3 + x , y3 + y);
  //
  // display hour hand
  angle = hour() * 30 + int( ( minute() / 12 ) * 6 )   ;
  angle = ( angle / 57.29577951 ) ; //Convert degrees to radians
  x3 = ( clockCenterX + ( sin(angle) * ( clockRadius - ( clockRadius / 2 ) ) ) );
  y3 = ( clockCenterY - ( cos(angle) * ( clockRadius - ( clockRadius / 2 ) ) ) );
  display->drawLine( clockCenterX + x , clockCenterY + y , x3 + x , y3 + y);
}

void digitalClockFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  String timenow = String(hour()) + ":" + twoDigits(minute()) + ":" + twoDigits(second());
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_24);
  display->drawString(clockCenterX + x , clockCenterY + y, timenow );
}
/**
   菜单首页
*/
void drawMainPage(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  digitalClockFrame(display, state, x, y);
}
/**
   流水灯模式选择
*/
void drawFlowLed(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

}
/**
   副屏显示选择
*/
void drawOled(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

}
/**
   蓝牙菜单
*/
void drawBle(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 20 + y, "Bluetooth");
  display->drawXbm(x + 80, y + 10, BLE_Logo_width, BLE_Logo_height, BLE_Logo_bits);
}
/**
   wifi配置
*/
void drawWifi(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->drawXbm(x + 34, y + 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
}

/*******菜单 完成*******/

// This array keeps function pointers to all frames
// frames are the single views that slide in
FrameCallback frames[] = { drawMainPage, drawFlowLed, drawOled, drawBle, drawWifi };

// how many frames are there?
int frameCount = 5;

// Overlays are statically drawn on top of a frame eg. a clock
OverlayCallback overlays[] = { msOverlay };
int overlaysCount = 1;
/***绘制菜单 end****/

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing...");
  digitalLeds_initDriver();

  // Init unused outputs low to reduce noise
  //  gpioSetup(14, OUTPUT, LOW);
  gpioSetup(15, OUTPUT, LOW);
  gpioSetup(26, OUTPUT, LOW);
  gpioSetup(27, OUTPUT, LOW);
  gpioSetup(strand.gpioNum, OUTPUT, LOW);
  int rc = digitalLeds_addStrands(STRANDS, STRANDCNT);
  if (rc) {
    Serial.print("Init rc = ");
    Serial.println(rc);
  }
  if (digitalLeds_initDriver()) {
    Serial.println("Init FAILURE: halting");
    while (true) {};
  }
  digitalLeds_resetPixels(STRANDS, STRANDCNT);

  // Initialising the UI will init the display too.
  // The ESP is capable of rendering 60fps in 80Mhz mode
  // but that won't give you much time for anything else
  // run it in 160Mhz mode or just set it to 30 fps
  ui.setTargetFPS(60);

  // Customize the active and inactive symbol
  ui.setActiveSymbol(activeSymbol);
  ui.setInactiveSymbol(inactiveSymbol);

  // You can change this to
  // TOP, LEFT, BOTTOM, RIGHT
  ui.setIndicatorPosition(BOTTOM);

  // Defines where the first frame is located in the bar.
  ui.setIndicatorDirection(LEFT_RIGHT);

  // You can change the transition that is used
  // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
  ui.setFrameAnimation(SLIDE_LEFT);

  // Add frames
  ui.setFrames(frames, frameCount);

  // Add overlays
  ui.setOverlays(overlays, overlaysCount);

  // Initialising the UI will init the display too.
  ui.init();
  display.flipScreenVertically();

  display2.init();
  // This will make sure that multiple instances of a display driver
  // running on different ports will work together transparently
  display2.setI2cAutoInit(true);
  display2.flipScreenVertically();
  display2.setFont(ArialMT_Plain_10);
  display2.setTextAlignment(TEXT_ALIGN_LEFT);

}

//**************************************************************************//
class Rainbower {
  private:
    strand_t * pStrand;
    const uint8_t color_div = 4;
    const uint8_t anim_step = 1;
    uint8_t anim_max;
    uint8_t stepVal1;
    uint8_t stepVal2;
    pixelColor_t color1;
    pixelColor_t color2;
  public:
    Rainbower(strand_t *);
    void prepareNext();
};


Rainbower::Rainbower(strand_t * pStrandIn)
{
  pStrand = pStrandIn;
  anim_max = pStrand->brightLimit - anim_step;
  stepVal1 = 0;
  stepVal2 = 0;
  color1 = pixelFromRGBW(anim_max, 0, 0, 0);
  color2 = pixelFromRGBW(anim_max, 0, 0, 0);
}


void Rainbower::prepareNext()
{
  color1 = color2;
  stepVal1 = stepVal2;
  for (uint16_t i = 0; i < pStrand->numPixels; i++) {
    pStrand->pixels[i] = pixelFromRGBW(color1.r / color_div, color1.g / color_div, color1.b / color_div, 0);
    if (i == 1) {
      color2 = color1;
      stepVal2 = stepVal1;
    }
    switch (stepVal1) {
      case 0:
        color1.g += anim_step;
        if (color1.g >= anim_max)
          stepVal1++;
        break;
      case 1:
        color1.r -= anim_step;
        if (color1.r == 0)
          stepVal1++;
        break;
      case 2:
        color1.b += anim_step;
        if (color1.b >= anim_max)
          stepVal1++;
        break;
      case 3:
        color1.g -= anim_step;
        if (color1.g == 0)
          stepVal1++;
        break;
      case 4:
        color1.r += anim_step;
        if (color1.r >= anim_max)
          stepVal1++;
        break;
      case 5:
        color1.b -= anim_step;
        if (color1.b == 0)
          stepVal1 = 0;
        break;
    }
  }
}


void rainbows(strand_t * strands[], int numStrands, unsigned long delay_ms, unsigned long timeout_ms)
{
  //Rainbower rbow(pStrand); Rainbower * pRbow = &rbow;
  Rainbower * pRbow[numStrands];
  int i;
  Serial.print("DEMO: rainbows(");
  for (i = 0; i < numStrands; i++) {
    pRbow[i] = new Rainbower(strands[i]);
    if (i > 0) {
      Serial.print(", ");
    }
    Serial.print("ch");
    Serial.print(strands[i]->rmtChannel);
    Serial.print(" (0x");
    Serial.print((uint32_t)pRbow[i], HEX);
    Serial.print(")");
  }
  Serial.print(")");
  Serial.println();
  unsigned long start_ms = millis();
  while (timeout_ms == 0 || (millis() - start_ms < timeout_ms)) {
    for (i = 0; i < numStrands; i++) {
      pRbow[i]->prepareNext();
    }
    digitalLeds_drawPixels(strands, numStrands);
    delay(delay_ms);
  }
  for (i = 0; i < numStrands; i++) {
    delete pRbow[i];
  }
  digitalLeds_resetPixels(strands, numStrands);
}


//***************************************************//
void simpleStepper(strand_t * strands [], int numStrands, unsigned long delay_ms, unsigned long timeout_ms)
{
  int highLimit = 32;
  unsigned long start_ms = millis();
  while (timeout_ms == 0 || (millis() - start_ms < timeout_ms)) {
    strand_t * strand = strands[0];
    strand->pixels[stepper] = pixelFromRGBW(colord, colord, colord, 0);

    stepper++;
    if (stepper > strand->numPixels) {
      stepper = 0;
      colord += 2;
    }

    if (colord > highLimit)
      colord = 0;

    digitalLeds_drawPixels(strands, numStrands);
    delay(delay_ms);
  }
  digitalLeds_resetPixels(strands, numStrands);
}

void loop() {
  int remainingTimeBudget = ui.update();

  if (remainingTimeBudget > 0) {
    // You can do some work here
    // Don't do stuff if you are below your
    // time budget.
    delay(remainingTimeBudget);
  }

  display2.clear();
  display2.drawString(0, 0, "Hello world: " + String(millis()));
  display2.display();

  //  randomStrands(STRANDS, STRANDCNT, 200, 10000);
  rainbows(STRANDS, STRANDCNT, 1, 0);
  //simpleStepper(STRANDS, STRANDCNT, 0, 0);
  delay(10);
}
