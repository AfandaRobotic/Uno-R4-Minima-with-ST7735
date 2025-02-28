/*  "UnoR4_ST7735_Testing.ino"  |  2025 IT Dev by @afandarobotic.   */

#include <SPI.h>                   // Device Communication.
#include <Adafruit_GFX.h>          // Core graphics 64bit display library.
#include <Adafruit_ST7735.h>       // Hardware-specification library of driver.

// Arduino Uno R4 (ST7735) Setup : 
#define TFT_SCLK    13
#define TFT_MOSI    11
#define TFT_CS      10
#define TFT_DC       9     // (A0) 
#define TFT_RST      8


//Pixel for 1.44" Screen Display.
#define TFT 1.44"
#define SCR_WD 128
#define SCR_HT 128

// Arduino address for Pico Micro Leonardo & Uno R3 : 
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup(void) 
{
  Serial.begin(115200);
  while(!Serial);
  tft.initR(INITR_BLACKTAB);
  tft.initR(INITR_144GREENTAB);      // Init of ST7735 Chip Driver.
  tft.setSPISpeed(40000000);
  tft.setRotation(0);
  tft.setTextWrap(false);
  Next_GoTo:
//---------------------------------------------------------------------------------------------------//
  tft.fillScreen(ST7735_WHITE);                         // Display permanently of Background.
  tft.println(" ");
  tft.println(" ");
  tft.println(" ");
  tft.println(" ");
  tft.setTextColor(ST7735_BLACK);
  tft.println("    Afanda Robotic ");
}

void loop()
{
  // Nothing to do Here ....
}


/*       By : AfandaRobotic       */
