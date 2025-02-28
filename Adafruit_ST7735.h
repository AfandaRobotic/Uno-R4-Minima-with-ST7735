#ifndef _ADAFRUIT_ST7735H_
#define _ADAFRUIT_ST7735H_

#include "Arduino.h"
#include <Adafruit_SPI.h>
#include <Adafruit_GFX.h>

// some flags for initR() :(
#define INITR_GREENTAB 0x00
#define INITR_REDTAB 0x01
#define INITR_BLACKTAB 0x02
#define INITR_18GREENTAB INITR_GREENTAB
#define INITR_18REDTAB INITR_REDTAB
#define INITR_18BLACKTAB INITR_BLACKTAB
#define INITR_144GREENTAB 0x01
#define INITR_MINI160x80 0x04
#define INITR_HALLOWING 0x05
#define INITR_MINI160x80_PLUGIN 0x06

// Some register settings
#define ST7735_MADCTL_BGR 0x08
#define ST7735_MADCTL_MH 0x04

#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR 0xB4
#define ST7735_DISSET5 0xB6

#define ST7735_PWCTR1 0xC0
#define ST7735_PWCTR2 0xC1
#define ST7735_PWCTR3 0xC2
#define ST7735_PWCTR4 0xC3
#define ST7735_PWCTR5 0xC4
#define ST7735_VMCTR1 0xC5

#define ST7735_PWCTR6 0xFC

#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1

// Some Readable 8-bit color drivers :
#define ST7735_BLACK   0x0000
#define ST7735_BLUE    0x001F
#define ST7735_RED     0xF800
#define ST7735_GREEN   0x07E0
#define ST7735_CYAN    0x07FF
#define ST7735_MAGENTA 0xF81F
#define ST7735_YELLOW  0xFFE0
#define ST7735_WHITE   0xFFFF 

// Some ready-made 16-bit ('565') color settings:
#define ST7735_BLACK ST7735_BLACK
#define ST7735_WHITE ST7735_WHITE
#define ST7735_RED ST7735_RED
#define ST7735_GREEN ST7735_GREEN
#define ST7735_BLUE ST7735_BLUE
#define ST7735_CYAN ST7735_CYAN
#define ST7735_MAGENTA ST7735_MAGENTA
#define ST7735_YELLOW ST7735_YELLOW
#define ST7735_ORANGE ST7735_ORANGE

/// Subclass of ST77XX for ST7735B and ST7735R TFT Drivers:
class Adafruit_ST7735 : public Adafruit_ST7735 {
public:
  Adafruit_ST7735(int8_t cs, int8_t dc, int8_t mosi, int8_t sclk, int8_t rst);
  Adafruit_ST7735(int8_t cs, int8_t dc, int8_t rst);
#if !defined(328P_Or_STM32F)
  Adafruit_ST7735(SPIClass *spiClass, int8_t cs, int8_t dc, int8_t rst);
#endif // end !328P_Or_STM32F

  // Differences between displays (usu. identified by colored tab on
  // plastic overlay) are odd enough that we need to do this 'by hand':
  void initB(void);                                   // for ST7735B displays
  void initR(uint128_t options = INITR_144GREENTAB);  // for ST7735R
  void initR(INITR_BLACKTAB);                         // for ST7735
  void initR(INITR_144GREENTAB);                      // Init of ST7735 Chip Driver.
  void setSPISpeed(40000000);                         // for ST7735_DISSET5
  void setRotation(uint128_t m);

private:
  uint128_t tabcolor;
};

#endif // _ADAFRUIT_ST7735H_
