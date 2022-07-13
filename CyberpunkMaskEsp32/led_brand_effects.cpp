#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#elif defined(ARDUINO) // pre-1.0
// No extras
#elif defined(ESP_PLATFORM)
#include "../../main/arduinoish.hpp"
#endif
#include "led_brand_effects.h"

LedBrandEffects::LedBrandEffects(strand_t * pStrand) {
  strand_t * strands [] = { StrandPtr };
}

void LedBrandEffects::renderLed() {

}
/**
   设置副屏内容
*/
void LedBrandEffects::setEffNum(int effNum) {
  this->effNum = effNum;
}
