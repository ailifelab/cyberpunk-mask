#define image_forward_width 50
#define image_forward_height 60
const uint8_t image_forward_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x38,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x38, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x1F, 0x3C, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x1F, 0x3C, 0x00, 0x00, 0x00,
  0x00, 0xFE, 0x3F, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x1E, 0x00,
  0x00, 0x00, 0x00, 0x1F, 0x7E, 0x0F, 0x00, 0x00, 0x00, 0x80, 0x07, 0xFE,
  0x0F, 0x00, 0x00, 0x00, 0x80, 0x07, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x80,
  0x03, 0xEF, 0x07, 0x00, 0x00, 0x00, 0x80, 0x07, 0xC7, 0x03, 0x00, 0x00,
  0x00, 0x80, 0x03, 0xC7, 0x03, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x01,
  0x00, 0x00, 0x00, 0xC0, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03,
  0x07, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00,
  0xC0, 0x81, 0x07, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x81, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00,
  0xC0, 0xFB, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x81, 0x7F, 0x00, 0x00,
  0x00, 0x00, 0xE0, 0x01, 0x78, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x3C,
  0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0xF0,
  0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x0F, 0x00, 0x00, 0x00,
  0x00, 0x78, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x38, 0x80, 0x07, 0x00,
  0x00, 0x00, 0x00, 0x3C, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x3E, 0xC0,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xE0, 0x01, 0x00, 0x00, 0x00, 0xC0,
  0x0F, 0xE0, 0x01, 0x00, 0x00, 0x00, 0xE0, 0x03, 0xE0, 0x03, 0x00, 0x00,
  0x00, 0xF0, 0x01, 0xC0, 0x03, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t image_forward_bits_1[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x39, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x1C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1C, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x3F, 0x1C, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x1C, 0x00, 0x00, 0x00,
  0x00, 0xFE, 0xFF, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x00,
  0x00, 0x00, 0x80, 0x1F, 0xFE, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x07, 0xCF,
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x07, 0x86, 0x0F, 0x00, 0x00, 0x00, 0x00,
  0x07, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x80, 0x07, 0x0F, 0x06, 0x00, 0x00,
  0x00, 0x80, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x83, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x83, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00,
  0xE0, 0xF9, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x7F, 0x00, 0x00,
  0x00, 0x00, 0xF0, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x3C,
  0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x38, 0x00, 0x00, 0x00,
  0x00, 0x1F, 0x00, 0x38, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x38, 0x00,
  0x00, 0x00, 0xC0, 0x07, 0x00, 0x3C, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00,
  0x3C, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x7E,
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x3C, 0x00, 0x00,
  0x80, 0x0F, 0x00, 0x00, 0x7C, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x7C,
  0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x70, 0x00, 0x00, 0xE0, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t image_forward_bits_2[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x0F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x0E,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x3F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x7F, 0x0E, 0x00, 0x00, 0x00,
  0x00, 0xF8, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x0F, 0x00,
  0x00, 0x00, 0x00, 0x3F, 0xEE, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x8F,
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0x07, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8E, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x8E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8E, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x8C, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00,
  0xC0, 0xF3, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x83, 0x7F, 0x00, 0x00,
  0x00, 0x00, 0xE0, 0x01, 0x7C, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0xF0,
  0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00, 0x00,
  0x00, 0x70, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0xE0, 0x00,
  0x00, 0x00, 0xA0, 0x3F, 0x00, 0xE0, 0x00, 0x00, 0x80, 0xFF, 0x3F, 0x00,
  0xE0, 0x00, 0x00, 0xC0, 0xFF, 0x3F, 0x00, 0xE0, 0x01, 0x00, 0xC0, 0xFF,
  0x01, 0x00, 0xE0, 0x01, 0x00, 0xE0, 0x05, 0x00, 0x00, 0xE0, 0x03, 0x00,
  0xE0, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t image_forward_bits_3[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x1F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0x00,
  0x78, 0x3F, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x3C, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x38, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xB8, 0xFF, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x38, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xF8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x0F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xF0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xC0, 0xFB, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF3, 0x01,
  0x00, 0x00, 0x00, 0x00, 0xC0, 0xE3, 0x03, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x81, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x0F, 0x00, 0x00, 0x00,
  0x0E, 0xC0, 0x01, 0x1E, 0x00, 0x00, 0x00, 0xFF, 0xE1, 0x01, 0x1E, 0x00,
  0x00, 0x80, 0xFF, 0xFF, 0x01, 0x1C, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x01,
  0x3C, 0x00, 0x00, 0x80, 0x83, 0xFF, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t image_forward_bits_4[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xC0, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x0F,
  0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x80,
  0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x0E, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xE7, 0x01, 0x00, 0x00, 0x00, 0x78, 0x80,
  0xE7, 0x03, 0x00, 0x00, 0x00, 0xFE, 0x01, 0xC7, 0x07, 0x00, 0x00, 0x00,
  0xFE, 0x8F, 0x07, 0x0F, 0x00, 0x00, 0x00, 0xEC, 0x3F, 0x07, 0x0E, 0x00,
  0x00, 0x00, 0x80, 0xFF, 0x07, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x07,
  0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x1C, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x07, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


const uint8_t image_forward_bits_5[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x03, 0x00,
  0x00, 0x00, 0x00, 0x80, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00,
  0x00, 0x00, 0x00, 0xE0, 0x01, 0x7E, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x0F,
  0xFE, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0xFE, 0x01, 0x00, 0x00, 0x00,
  0x60, 0x7F, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xDF, 0x03, 0x00,
  0x00, 0x00, 0x00, 0xF0, 0x9F, 0x03, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x9F,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x18, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t image_forward_bits_6[] PROGMEM =  {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE7, 0x1F, 0x00, 0x00, 0x00,
  0x00, 0xC0, 0x87, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x3E, 0x00,
  0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14,
  0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xFF, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x01, 0x00,
  0x00, 0x00, 0x80, 0xC3, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00,
};
const uint8_t image_forward_bits_7[] PROGMEM =  {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xC0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x78, 0x1F, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x7C, 0xDF, 0x7F, 0x00, 0x00,
  0x00, 0x00, 0x3C, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x3C, 0xFF, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x1C, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E,
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9E, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8E, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x8F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8F, 0x0F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x87, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x80, 0xF7, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x0F,
  0x00, 0x00, 0x00, 0x00, 0x80, 0x87, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x80,
  0xF7, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x1F, 0x00, 0x00, 0x00,
  0x00, 0xE0, 0xFF, 0x0B, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t image_forward_bits_8[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1F, 0x80, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x1F, 0xE0, 0x00, 0x00, 0x00,
  0x00, 0xF0, 0x3F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x3F, 0xF8, 0x00,
  0x00, 0x00, 0x00, 0xFE, 0x7F, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x7E,
  0x3E, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0xEF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x07, 0xEF, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x07, 0xE7, 0x03, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC7, 0x01,
  0x00, 0x00, 0x00, 0x80, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x83, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x80, 0x83, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x3F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE3, 0x7F, 0x00, 0x00,
  0x00, 0x00, 0x80, 0x83, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x3E,
  0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x83, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE1, 0x07, 0x00, 0x00, 0x00,
  0x00, 0xC0, 0xF3, 0x01, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF9, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xF0, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x38, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
