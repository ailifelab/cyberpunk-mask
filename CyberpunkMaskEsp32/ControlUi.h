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
  public:
    ControlUi(OLEDDisplayUi *ui);
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
};
#endif
