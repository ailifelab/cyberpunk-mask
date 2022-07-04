#include "ControlUi.h"
#include <TimeLib.h>
#include "images.h"
#include "image_action_cube_long.h"
//定义屏幕尺寸
int screenW = 128;
int screenH = 64;
//时钟控制
int clockCenterX = screenW / 2;
int clockCenterY = ((screenH - 16) / 2) + 16; // top yellow part is 16 px height
int clockRadius = 23;
//副屏选择 0 cubelong,1
int secondImage = 0;
long lastFlipTime = 0L;

ControlUi::ControlUi(OLEDDisplayUi *ui, OLEDDisplay *display) {
  this->ui = ui;
  this->display = display;
}

/**
   时钟
*/
// utility function for digital clock display: prints leading 0
String twoDigits(int digits) {
  if (digits < 10) {
    String i = '0' + String(digits);
    return i;
  }
  else {
    return String(digits);
  }
}

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
  display->drawString(clockCenterX + x , clockCenterY - 10 + y, timenow );
}
/*******主菜单*******/
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
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(5 + x, 20 + y, "Choose LED band mode");
}
/**
   副屏显示选择
*/
void drawOled(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setFont(ArialMT_Plain_16);
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(10 + x, 20 + y, "Choose Picture");
}
/**
   蓝牙菜单
*/
void drawBle(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(10 + x, 20 + y, "Bluetooth");
  display->drawXbm(x + 65, y + 5, cube_01_width, cube_01_height, cube_01_bits);
}
/**
   wifi配置
*/
void drawWifi(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->drawXbm(x + 34, y + 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
}
FrameCallback homeFrames[] = { drawMainPage, drawFlowLed, drawOled, drawBle, drawWifi };
int homeFrameCount = 5;
/***********图片菜单************/
void drawPic01(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->drawXbm(x + 20, y + 5, cube_long_width, cube_long_height, cube_long_bits);
}
void drawPic02(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->drawXbm(x + 30, y + 5, cube_01_width, cube_01_height, cube_01_bits);
}
FrameCallback picFrames[] = { drawPic01, drawPic02 };
int picFrameCount = 2;

/***跑马灯设置*****/
void flowLed01(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(10 + x, 20 + y, "Radom Fireworks");
  display->drawString(10 + x, 40 + y, "<------****------>");
}
void flowLed02(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(10 + x, 20 + y, "Flow motion down");
  display->drawString(10 + x, 40 + y, "****------>");
}
void flowLed03(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(10 + x, 20 + y, "Flow motion up");
  display->drawString(10 + x, 40 + y, "<------****");
}
FrameCallback ledFrames[] = { flowLed01, flowLed02, flowLed03 };
int ledFrameCount = 3;

/**
   切换到主菜单 0
*/
void ControlUi::goHome() {
  // TOP, LEFT, BOTTOM, RIGHT
  ui->setIndicatorPosition(BOTTOM);
  // Defines where the first frame is located in the bar.
  ui->setIndicatorDirection(LEFT_RIGHT);
  // Customize the active and inactive symbol
  ui->setActiveSymbol(activeSymbol);
  ui->setInactiveSymbol(inactiveSymbol);
  // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
  ui->setFrameAnimation(SLIDE_LEFT);
  // Add frames
  ui->setFrames(homeFrames, homeFrameCount);
}
/**
   切换到副屏选择菜单 1
*/
void ControlUi::goDisplayChoose() {
  ui->setIndicatorPosition(LEFT);
  ui->setIndicatorDirection(LEFT_RIGHT);
  ui->setFrameAnimation(SLIDE_UP);
  ui->setFrames(picFrames, picFrameCount);
}
/**
   切换到跑马灯选择菜单 2
*/
void ControlUi::goFlowLedChoose() {
  ui->setIndicatorPosition(LEFT);
  ui->setIndicatorDirection(LEFT_RIGHT);
  ui->setFrameAnimation(SLIDE_UP);
  ui->setFrames(ledFrames, ledFrameCount);
}

/**
   切换到蓝牙选择菜单 3
*/
void ControlUi::goBleChoose() {

}
/**
   切换到Wifi选择菜单 4
*/
void ControlUi::goWifiChoose() {

}
int fpsNum = 0;
/**
   渲染副屏
*/
void ControlUi::renderSecondScreen() {
  long nowTime = millis();
  if (nowTime - lastFlipTime >= 1000) {
    lastFlipTime = nowTime;
    this->display->clear();
    if (0 == secondImage) {
      int x = 65;
      int y = 5;
      switch (fpsNum) {
        case 0:
          display->drawXbm( x,  y, cube_long_width, cube_long_height, cube_long_bits);
          break;
        case 1:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_1);
          break;
        case 2:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_2);
          break;
        case 3:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_3);
          break;
        case 4:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_4);
          break;
        case 5:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_5);
          break;
        case 6:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_6);
          break;
        case 7:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_7);
          break;
        case 8:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_8);
          break;
        case 9:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_9);
          break;
        case 10:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_10);
          break;
        case 11:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_11);
          break;
        case 12:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_12);
          break;
        case 13:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_13);
          break;
        case 14:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_14);
          break;
        case 15:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_15);
          break;
        case 16:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_16);
          break;
        case 17:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_17);
          break;
        case 18:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_18);
          break;
        case 19:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_19);
          break;
        case 20:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_20);
          break;
        case 21:
          display->drawXbm(x, y, cube_long_width, cube_long_height, cube_long_bits_21);
          break;
        default:
          fpsNum = -1;
      }
      fpsNum++;
    } else if (1 == secondImage) {
      this->display->clear();
    } else if (2 == secondImage) {
      this->display->clear();
    } else if (3 == secondImage) {
      this->display->clear();
    } else {
      this->display->setFont(ArialMT_Plain_16);
      this->display->setTextAlignment(TEXT_ALIGN_LEFT);
      this->display->drawString(10, 10, " " + String(nowTime));
    }

    this->display->display();
  }
}

/**
   设置副屏内容
*/
void ControlUi::setSecondImage(int num) {
  secondImage = num;
}
