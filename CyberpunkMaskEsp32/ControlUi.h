#ifndef CONTROL_UI_H
#define CONTROL_UI_H

#ifdef ARDUINO
#include <Arduino.h>
#elif __MBED__
#include <mbed.h>
#else
#error "Unkown operating system"
#endif
#include "OLEDDisplayUi.h"

class ControlUi {
  private:
    OLEDDisplayUi *ui;
    OLEDDisplay *display;
  public:
    ControlUi(OLEDDisplayUi *ui, OLEDDisplay *display);
    /**
      切换到主菜单 0
    */
    void goHome();
    /**
       切换到副屏选择菜单 1
    */
    void goDisplayChoose();
    /**
       切换到跑马灯选择菜单 2
    */
    void goFlowLedChoose();
    /**
       切换到蓝牙选择菜单 3
    */
    void goBleChoose();
    /**
       切换到Wifi选择菜单 4
    */
    void goWifiChoose();
    /**
       渲染副屏
    */
    void renderSecondScreen();
    /**
       设置副屏内容
    */
    void setSecondImage(int num);

};
#endif
