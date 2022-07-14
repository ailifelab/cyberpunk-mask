#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#elif defined(ARDUINO) // pre-1.0
// No extras
#elif defined(ESP_PLATFORM)
#include "../../main/arduinoish.hpp"
#endif
#include "led_brand_effects.h"

int centerNum = 0;
pixelColor_t lastColor;
long lastFlashTime = 0L;

LedBrandEffects::LedBrandEffects(strand_t * pStrand) {
  StrandPtr = pStrand;
  lastColor = pixelFromRGBW(0x3F, 0x3F, 0x3F, 0x3F);
}

void LedBrandEffects::renderLed() {
  long nowTime = millis();
  if (nowTime - lastFlashTime >= 100) {
    if (centerNum == StrandPtr->numPixels) {
      centerNum = 0;
      for (uint16_t i = centerNum; i < StrandPtr->numPixels; i++) {
        StrandPtr->pixels[i] = lastColor;
      }
    } else {
      for (uint16_t i = centerNum; i < StrandPtr->numPixels; i++) {
        StrandPtr->pixels[i] = pixelFromRGBW(0x3F, 0x3F, 0x3F, 0xFF - 4 * (i - centerNum));
      }
      centerNum++;
    }
    strand_t * strands [] = { StrandPtr };
    digitalLeds_drawPixels(strands, 1);
  }
}
/**
   设置效果序号
*/
void LedBrandEffects::setEffNum(int effNum) {
  this->effNum = effNum;
  centerNum = 0;
}
