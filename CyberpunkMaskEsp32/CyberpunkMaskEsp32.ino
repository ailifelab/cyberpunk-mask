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
#include "led_brand_effects.h"
//定义输出
#define LED_BAND_PIN 27
#define DISP_SDA_1 0
#define DISP_SCL_1 14
#define DISP_SDA_2 5
#define DISP_SCL_2 4
//定义按钮
#define BTN_UP 18
#define BTN_DOWN 19
#define BTN_ENTER 25
#define BTN_BACK 26
int preBtnStatUp = HIGH;
int preBtnStatDown = HIGH;
int preBtnStatEnter = HIGH;
int preBtnStatBack = HIGH;
#define LIGHT_NUM_METER 22

// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, DISP_SDA_1 , DISP_SCL_1, GEOMETRY_128_64, I2C_ONE);
SSD1306Wire  display2(0x3c, DISP_SDA_2, DISP_SCL_2, GEOMETRY_128_64, I2C_TWO);
//display 用于菜单选择控制
OLEDDisplayUi ui ( &display );
ControlUi controlUi ( &ui, &display2 );

//for LED band
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"  // It's noisy here with `-Wall`
strand_t strand = {.rmtChannel = 0, .gpioNum = LED_BAND_PIN, .ledType = LED_WS2812B_V3, .brightLimit = 30, .numPixels = LIGHT_NUM_METER};
strand_t * STRANDS [] = { &strand };
int STRANDCNT = COUNT_OF(STRANDS);
#pragma GCC diagnostic pop

LedBrandEffects * ledbrand;

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
    Serial.println("button enter!");
    OLEDDisplayUiState* uiStat = ui.getUiState();
    uint8_t currentFrame = uiStat->currentFrame;
    if (menuNum == 0) {
      if (currentFrame == 0) {
        //main page do nothing
        menuNum = 0;
      } else if (currentFrame == 1) {
        //drawFlowLed
        controlUi.goFlowLedChoose();
        menuNum = 1;
      } else if (currentFrame == 2) {
        //drawOled
        controlUi.goDisplayChoose();
        menuNum = 2;
      } else if (currentFrame == 3) {
        //drawBle
        //        menuNum = 3;
      } else if (currentFrame == 4) {
        //drawWifi
        //        menuNum = 4;
      }
    } else if (menuNum == 1) {
      //choose led
      ledbrand->setEffNum(currentFrame);
    } else if (menuNum == 2) {
      //choose image show
      controlUi.setSecondImage(currentFrame);
    }
  }
  if ((btnStatBack != preBtnStatBack) && (btnStatBack == LOW)) {
    Serial.println("button back!");
    controlUi.goHome();
    if (menuNum == 1) {
      ui.switchToFrame(1);
    } else if (menuNum == 2) {
      ui.switchToFrame(2);
    } else if (menuNum == 3) {
      ui.switchToFrame(3);
    } else if (menuNum == 4) {
      ui.switchToFrame(4);
    }
    menuNum = 0;
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
  Serial.begin(115200);
  Serial.println("Initializing...");
  // Initialising the UI will init the display too.
  // The ESP is capable of rendering 60fps in 80Mhz mode
  // but that won't give you much time for anything else
  // run it in 160Mhz mode or just set it to 30 fps
  ui.setTargetFPS(60);
  ui.init();
  //  display.setTextAlignment(TEXT_ALIGN_CENTER);
  //  display.setFont(ArialMT_Plain_10);
  //  display.drawString(64, 18, "Initializing");
  //  display.drawProgressBar(4, 32, 120, 8, 10);
  digitalLeds_initDriver();
  gpioSetup(BTN_UP, INPUT_PULLUP, HIGH);
  gpioSetup(BTN_DOWN, INPUT_PULLUP, HIGH);
  gpioSetup(BTN_ENTER, INPUT_PULLUP, HIGH);
  gpioSetup(BTN_BACK, INPUT_PULLUP, HIGH);
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
  ledbrand = new LedBrandEffects(&strand);
  //  display.drawProgressBar(4, 32, 120, 8, 30);

  display2.init();
  // This will make sure that multiple instances of a display driver
  // running on different ports will work together transparently
  display2.setI2cAutoInit(true);
  //  display2.flipScreenVertically();
  //  display.drawProgressBar(4, 32, 120, 8, 60);

  unsigned long secsSinceStart = millis();
  // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
  const unsigned long seventyYears = 2208988800UL;
  // subtract seventy years:
  unsigned long epoch = secsSinceStart - seventyYears * SECS_PER_HOUR;
  setTime(epoch);

  //  display.drawProgressBar(4, 32, 120, 8, 100);
  controlUi.goHome();
  // Add overlays
  //  ui.setOverlays(overlays, overlaysCount);
  Serial.println("Initialized.");
}

void loop() {
  int remainingTimeBudget = ui.update();
  long startTime = millis();

  controlUi.renderSecondScreen();

  // randomStrands(STRANDS, STRANDCNT, 200, 10000);
  //  rainbows(STRANDS, STRANDCNT, 1, 10);
  // simpleStepper(STRANDS, STRANDCNT, 0, 0);
  ledbrand->renderLed();
  btnControl();

  long endTime = millis() - startTime;
  //等待ui处理完成
  if (remainingTimeBudget > endTime) {
    delay(remainingTimeBudget - endTime);
  }
}
