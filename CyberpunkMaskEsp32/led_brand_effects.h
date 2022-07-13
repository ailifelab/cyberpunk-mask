#ifndef LED_BRAND_EFFECTS_H
#define LED_BRAND_EFFECTS_H

#ifdef ARDUINO
#include <Arduino.h>
#elif __MBED__
#include <mbed.h>
#else
#error "Unkown operating system"
#endif
#include "esp32_digital_led_lib.h"

class LedBrandEffects {
  private:
    int effNum = 0;
  public:
    LedBrandEffects(strand_t * pStrand);
    strand_t * StrandPtr;
    /**
       渲染
    */
    void renderLed();
    /**
       设置副屏内容
    */
    void setEffNum(int effNum);

};
#endif
