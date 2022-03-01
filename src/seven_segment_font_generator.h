/*
 * font_generator.h - library for 7 segment font generation.
 * Created by Wahidul Islam Rahim, March 2020
 */
#ifndef font_generator_h
#define font_generator_h

#include "Arduino.h"
#define CA 1
#define CC 0
class SevenSegmentFonts{
  private:     
//    const bool common_anode = true;
//    const bool common_cathode = false;
    uint8_t f0 = 0x3F;
    uint8_t f1 = 0x06;
    uint8_t f2 = 0x5B;
    uint8_t f3 = 0x4F;
    uint8_t f4 = 0x66;
    uint8_t f5 = 0x6D;
    uint8_t f6 = 0x7D;
    uint8_t f7 = 0x07;
    uint8_t f8 = 0x7F;
    uint8_t f9 = 0x6F;

    uint8_t fA = 0x77;
    uint8_t fB = 0x7C;
    uint8_t fC = 0x39;
    uint8_t fD = 0x5E;
    uint8_t fE = 0x79;
    uint8_t fF = 0x71;
    uint8_t fG = 0x6F;
    uint8_t fH = 0x76;
    uint8_t fI = 0b00110000;
    uint8_t fJ = 0x1E;
    uint8_t fL = 0x38;
    uint8_t fN = 0x54;
    uint8_t fO = 0x5C;
    uint8_t fP = 0x73;
    uint8_t fQ = 0b11100110;
    uint8_t fR = 0x50;
    uint8_t fS = 0x6D;
    uint8_t fT = 0x78;
    uint8_t fU = 0x3E;
    uint8_t fY = 0x6E;
    uint8_t fequal = 0x48;
    
    uint8_t fdash = 0x40;
    uint8_t fblank = 0x00;
    uint8_t segment_sequence[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // a, b, c, d, e, f, g, dp
    
	uint8_t globalFlip = false;
	bool dpInvert = false;
//    bool sequenceModified = 0; // will indicate if segment sequence is changed or not.
    uint8_t reverseBits(uint8_t num) ;
    uint8_t changeFont(uint8_t num) ;
  public:
    bool displayTypeSelector = 0; //0 = CC, 1 = CA
    void begin(bool type, uint8_t global_Flip = false, bool dp_Invert = false) ;
    void sequence(uint8_t sequence[8]) ;
    uint8_t show(char value, bool dpON = false, bool flip = false) ; 
//	uint8_t show_sequence();
	uint8_t show_sequence_pin(uint8_t pin);
    bool displayType() ;
};

#endif
