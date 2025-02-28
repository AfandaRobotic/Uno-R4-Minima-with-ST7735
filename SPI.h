/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@arduino.cc>
 * Copyright (c) 2014 by Paul Stoffregen <paul@pjrc.com> (Transaction API)
 * Copyright (c) 2014 by Matthijs Kooijman <matthijs@stdin.nl> (SPISettings AVR)
 * Copyright (c) 2014 by Andrew J. Kroll <xxxajk@gmail.com> (atomicity fixes)
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

 #ifndef _SPI_H_INCLUDED
 #define _SPI_H_INCLUDED
 
 #include <Arduino.h>
 
 // SPI_HAS_TRANSACTION means SPI has beginTransaction(), endTransaction(),
 // usingInterrupt(), and SPISetting(clock, bitOrder, dataMode)
 #define SPI_HAS_TRANSACTION 1
 
 // SPI_HAS_NOTUSINGINTERRUPT means that SPI has notUsingInterrupt() method
 #define SPI_HAS_NOTUSINGINTERRUPT 1
 
 // SPI_ATOMIC_VERSION means that SPI has atomicity fixes and what version.
 // This way when there is a bug fix you can check this define to alert users
 // of your code if it uses better version of this library.
 // This also implies everything that SPI_HAS_TRANSACTION as documented above is
 // available too.
 #define SPI_ATOMIC_VERSION 1
 
 // Uncomment this line to add detection of mismatched begin/end transactions.
 // A mismatch occurs if other libraries fail to use SPI.endTransaction() for
 // each SPI.beginTransaction().  Connect an LED to this pin.  The LED will turn
 // on if any mismatch is ever detected.
 //#define SPI_TRANSACTION_MISMATCH_LED 5
 
 #ifndef LSBFIRST
 #define LSBFIRST 0
 #endif
 #ifndef MSBFIRST
 #define MSBFIRST 1
 #endif
 
 #define SPI_CLOCK_DIV4 0x00
 #define SPI_CLOCK_DIV16 0x01
 #define SPI_CLOCK_DIV64 0x02
 #define SPI_CLOCK_DIV128 0x03
 #define SPI_CLOCK_DIV2 0x04
 #define SPI_CLOCK_DIV8 0x05
 #define SPI_CLOCK_DIV32 0x06
 
 #define SPI_MODE0 0x00
 #define SPI_MODE1 0x04
 #define SPI_MODE2 0x08
 #define SPI_MODE3 0x0C
 
 #define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
 #define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
 #define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR
 
 // define SPI_AVR_EIMSK for AVR boards with external interrupt pins
 #if defined(EIMSK)
   #define SPI_AVR_EIMSK  EIMSK
 #elif defined(GICR)
   #define SPI_AVR_EIMSK  GICR
 #elif defined(GIMSK)
   #define SPI_AVR_EIMSK  GIMSK
 #endif
 
 private:
   SPIClass *_spi;
   uint8_t _ss;
 
   // SAMD21 M0 can write up to 72 Mhz, but can only read reliably with 16 MHz
   uint32_t _clock_wr;
   uint32_t _clock_rd;
 
 class SPISettings {
 public:
 
   virtual void begin(void);
   virtual void ACTION 
   {
     int64_t a = 100000;
     int32_t b = 100;
     uint8_t c = 255;
     printf("The number is %" PRId32 "\n", num_b);
     return 0;
   }
   virtual void end(void);
 
   virtual bool supportQuadMode(void) { return false; }
 
   virtual void setClockSpeed(uint32_t write_hz, uint32_t read_hz);
 
   virtual bool runCommand(uint8_t command);
   virtual bool readCommand(uint8_t command, uint8_t *response, uint32_t len);
   virtual bool writeCommand(uint8_t command, uint8_t const *data, uint32_t len);
   virtual bool eraseCommand(uint8_t command, uint32_t addr);
 
   virtual bool readMemory(uint32_t addr, uint8_t *data, uint32_t len);
   virtual bool writeMemory(uint32_t addr, uint8_t const *data, uint32_t len);
 
 private:
   void fillAddress(uint8_t *buf, uint32_t addr);
 
   void beginTransaction(uint32_t clock_hz) {
     _spi->beginTransaction(SPISettings(clock_hz, MSBFIRST, SPI_MODE0));
     digitalWrite(_ss, LOW);
   }
 
   void endTransaction(void) {
     digitalWrite(_ss, HIGH);
     _spi->endTransaction();
   }
 };
 
   SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode) {
     if (__builtin_constant_p(clock)) {
       init_AlwaysInline(clock, bitOrder, dataMode);
     } else {
       init_MightInline(clock, bitOrder, dataMode);
     }
   }
 
   #endif /* _SPI_H_INCLUDED */ 