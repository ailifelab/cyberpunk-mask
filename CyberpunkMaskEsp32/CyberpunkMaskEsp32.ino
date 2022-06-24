/**
   Cyberpunk Mask Diplay Controller
   使用ESP-WROOM-32主板
   External libraries:
     1.ESP32 Digital RGB LED Drivers | https://github.com/MartyMacGyver/ESP32-Digital-RGB-LED-Drivers | WS2812跑马灯带
     2.ESP8266 and ESP32 OLED driver for SSD1306 displays| https://github.com/ThingPulse/esp8266-oled-ssd1306 | SSD1306 OLED I2C屏幕
     3.Time | 时间库
*/
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <TimeLib.h>
#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"
#include "esp32_digital_led_lib.h" //流水灯控制
#include "ControlUi.h"
//定义输出
#define LED_BAND_PIN 27
#define DISP_SDA_1 0
#define DISP_SCL_1 14
#define DISP_SDA_2 5
#define DISP_SCL_2 4
//定义按钮
#define BTN_UP 6
#define BTN_DOWN 7
#define BTN_ENTER 8
#define BTN_BACK 9
int preBtnStatUp = HIGH;
int preBtnStatDown = HIGH;
int preBtnStatEnter = HIGH;
int preBtnStatBack = HIGH;

// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, DISP_SDA_1 , DISP_SCL_1, GEOMETRY_128_64, I2C_ONE);
SSD1306Wire  display2(0x3c, DISP_SDA_2, DISP_SCL_2, GEOMETRY_128_64, I2C_TWO);
//display 用于菜单选择控制
OLEDDisplayUi ui ( &display );
ControlUi controlUi ( &ui );

//for LED band
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"  // It's noisy here with `-Wall`
strand_t strand = {.rmtChannel = 0, .gpioNum = LED_BAND_PIN, .ledType = LED_WS2812B_V3, .brightLimit = 32, .numPixels = 64};
strand_t * STRANDS [] = { &strand };
int STRANDCNT = COUNT_OF(STRANDS);
#pragma GCC diagnostic pop
int stepper = 0;
int colord = 0;

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


/****绘制菜单****/
/**
   an over layer
*/
void msOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(128, 0, String(millis()));
}



// Overlays are statically drawn on top of a frame eg. a clock
OverlayCallback overlays[] = { msOverlay };
int overlaysCount = 1;
/***绘制菜单 end****/

//****************LED灯带********************//
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
  Serial.println(")");
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
/***LED灯带 结束**/
uint8_t menuNum = 0;
/**
   按钮控制
*/
void btnControl() {
  int btnStatUp = digitalRead(BTN_UP);
  int btnStatDown = digitalRead(BTN_DOWN);
  int btnStatEnter = digitalRead(BTN_ENTER);
  int btnStatBack = digitalRead(BTN_BACK);
  if ((btnStatUp != preBtnStatUp) && (btnStatUp == LOW)) {
    ui.previousFrame();
  }
  if ((btnStatDown != preBtnStatDown) && (btnStatDown == LOW)) {
    ui.nextFrame();
  }
  if ((btnStatEnter != preBtnStatEnter) && (btnStatEnter == LOW)) {
    OLEDDisplayUiState* uiStat = ui.getUiState();
    uint8_t currentFrame = uiStat->currentFrame;
    if (menuNum == 0) {
      if (currentFrame == 0) {
        //main page do nothing
      } else if (currentFrame == 1) {
        //drawFlowLed
        controlUi.goFlowLedChoose();
      } else if (currentFrame == 2) {
        //drawOled
        controlUi.goDisplayChoose();
      } else if (currentFrame == 3) {
        //drawBle
      } else if (currentFrame == 4) {
        //drawWifi
      }
    }
  }
  if ((btnStatBack != preBtnStatBack) && (btnStatBack == LOW)) {
    controlUi.goHome();
  }
  preBtnStatUp = btnStatUp;
  preBtnStatDown = btnStatDown;
  preBtnStatEnter = btnStatEnter;
  preBtnStatBack = btnStatBack;
}

/**
   初始化
*/
void setup() {
  // Initialising the UI will init the display too.
  // The ESP is capable of rendering 60fps in 80Mhz mode
  // but that won't give you much time for anything else
  // run it in 160Mhz mode or just set it to 30 fps
  ui.setTargetFPS(60);
  // Initialising the UI will init the display too.
  ui.init();
  //  ui.setLoadingDrawFunction(LoadingDrawDefault);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_10);
  display.drawString(64, 18, "Initializing");
  display.drawProgressBar(4, 32, 120, 8, 10);
  Serial.begin(115200);
  Serial.println("Initializing...");

  digitalLeds_initDriver();
  gpioSetup(BTN_UP, INPUT_PULLUP, HIGH);
  gpioSetup(BTN_DOWN, INPUT_PULLUP, HIGH);
  gpioSetup(BTN_ENTER, INPUT_PULLUP, HIGH);
  gpioSetup(BTN_BACK, INPUT_PULLUP, HIGH);
  // Init unused outputs low to reduce noise
  //  gpioSetup(14, OUTPUT, LOW);
  //  gpioSetup(15, OUTPUT, LOW);
  //  gpioSetup(26, OUTPUT, LOW);
  gpioSetup(strand.gpioNum, OUTPUT, LOW);
  int rc = digitalLeds_addStrands(STRANDS, STRANDCNT);
  //  if (rc) {
  //    Serial.print("Init rc = ");
  //    Serial.println(rc);
  //  }
  //  if (digitalLeds_initDriver()) {
  //    Serial.println("Init FAILURE: halting");
  //    while (true) {};
  //  }
  digitalLeds_resetPixels(STRANDS, STRANDCNT);
  display.drawProgressBar(4, 32, 120, 8, 30);

  display2.init();
  // This will make sure that multiple instances of a display driver
  // running on different ports will work together transparently
  display2.setI2cAutoInit(true);
  display2.flipScreenVertically();
  display.drawProgressBar(4, 32, 120, 8, 60);

  unsigned long secsSinceStart = millis();
  // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
  const unsigned long seventyYears = 2208988800UL;
  // subtract seventy years:
  unsigned long epoch = secsSinceStart - seventyYears * SECS_PER_HOUR;
  setTime(epoch);

  display.drawProgressBar(4, 32, 120, 8, 100);
  // TOP, LEFT, BOTTOM, RIGHT
  ui.setIndicatorPosition(BOTTOM);
  // Defines where the first frame is located in the bar.
  ui.setIndicatorDirection(LEFT_RIGHT);
  controlUi.goHome();
  // Add overlays
  ui.setOverlays(overlays, overlaysCount);

}

void loop() {
  int remainingTimeBudget = ui.update();
  long startTime = millis();

  display2.setFont(ArialMT_Plain_10);
  display2.setTextAlignment(TEXT_ALIGN_LEFT);
  display2.clear();
  display2.drawString(0, 0, "Hello world: " + String(millis()));
  display2.display();

  // randomStrands(STRANDS, STRANDCNT, 200, 10000);
  rainbows(STRANDS, STRANDCNT, 1, 0);
  // simpleStepper(STRANDS, STRANDCNT, 0, 0);
  btnControl();

  long endTime = millis() - startTime;
  //等待ui处理完成
  if (remainingTimeBudget > endTime) {
    delay(remainingTimeBudget - endTime);
  }
}
