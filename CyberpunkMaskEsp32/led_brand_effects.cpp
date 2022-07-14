#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#elif defined(ARDUINO) // pre-1.0
// No extras
#elif defined(ESP_PLATFORM)
#include "../../main/arduinoish.hpp"
#endif
#include "led_brand_effects.h"
#include "fireworks_effects.h"
int centerNum = 0;
pixelColor_t lastColor;
long lastFlashTime = 0L;
FireworksEffects * fweffects;

LedBrandEffects::LedBrandEffects(strand_t * pStrand) {
  StrandPtr = pStrand;
  lastColor = pixelFromRGBW(0x00, 0x00, 0x00, 0x00);
  fweffects = new FireworksEffects(pStrand);
}

void LedBrandEffects::renderLed() {
  long nowTime = millis();
  if (effNum == 0) {
    fweffects->Render();
  } else if (effNum == 1) {
    if (nowTime - lastFlashTime >= 50) {
      if (centerNum >= StrandPtr->numPixels) {
        centerNum = 0;
        for (uint16_t i = 0; i < StrandPtr->numPixels; i++) {
          StrandPtr->pixels[i] = lastColor;
        }
      } else {
        if (centerNum - 4 > 0) {
          StrandPtr->pixels[centerNum - 4] = lastColor;
        }
        byte lightByte = 0x3F;
        for (uint16_t i = centerNum - 3; i < centerNum + 3; i++) {
          if (i < 0) {
            continue;
          } else if (i > StrandPtr->numPixels) {
            break;
          }
          StrandPtr->pixels[i] = pixelFromRGBW(lightByte + 16 * (i - centerNum), lightByte + 16 * (i - centerNum), lightByte + 16 * (i - centerNum), lightByte + 16 * (i - centerNum));
          // Serial.println(StrandPtr->pixels[i].raw32, HEX);
        }
        centerNum++;
      }
      strand_t * strands [] = { StrandPtr };
      lastFlashTime = nowTime;
      digitalLeds_drawPixels(strands, 1);
    }
  } else if (effNum == 2) {
    if (nowTime - lastFlashTime >= 50) {
      if (centerNum <= 2) {
        centerNum = StrandPtr->numPixels;
        for (uint16_t i = 0; i < StrandPtr->numPixels; i++) {
          StrandPtr->pixels[i] = lastColor;
        }
      } else {
        if (centerNum + 4 < StrandPtr->numPixels) {
          StrandPtr->pixels[centerNum + 4] = lastColor;
        }
        byte lightByte = 0x3F;
        for (uint16_t i = centerNum + 3 ; i > centerNum - 3; i--) {
          if (i < 0) {
            break;
          } else if (i > StrandPtr->numPixels) {
            continue;
          }
          StrandPtr->pixels[i] = pixelFromRGBW(lightByte + 16 * (i - centerNum), lightByte + 16 * (i - centerNum), lightByte + 16 * (i - centerNum), lightByte + 16 * (i - centerNum));
        }
        centerNum--;
      }
      strand_t * strands [] = { StrandPtr };
      lastFlashTime = nowTime;
      digitalLeds_drawPixels(strands, 1);
    }
  }
}
/**
   设置效果序号
*/
void LedBrandEffects::setEffNum(int effNum) {
  this->effNum = effNum;
  centerNum = 0;
}
