#include "Arduino.h"
#include "seven_segment_font_generator.h"


uint8_t SevenSegmentFonts::reverseBits(uint8_t num) 
{ 
  uint8_t tempByte = 0;
  bitWrite(tempByte, segment_sequence[0], bitRead(num, segment_sequence[3])); // d -> a
  bitWrite(tempByte, segment_sequence[1], bitRead(num, segment_sequence[4])); // e -> b
  bitWrite(tempByte, segment_sequence[2], bitRead(num, segment_sequence[5])); // f -> c
  bitWrite(tempByte, segment_sequence[6], bitRead(num, segment_sequence[6])); // g -> g
  bitWrite(tempByte, segment_sequence[7], bitRead(num, segment_sequence[7])); // dp -> dp
  bitWrite(tempByte, segment_sequence[3], bitRead(num, segment_sequence[0])); // a -> d
  bitWrite(tempByte, segment_sequence[4], bitRead(num, segment_sequence[1])); // b -> e
  bitWrite(tempByte, segment_sequence[5], bitRead(num, segment_sequence[2])); // c -> f
  return tempByte;
} 
uint8_t SevenSegmentFonts::changeFont(uint8_t num) 
{ 
  uint8_t tempByte = 0;
  bitWrite(tempByte, segment_sequence[0], bitRead(num, 0)); // a
  bitWrite(tempByte, segment_sequence[1], bitRead(num, 1)); // b
  bitWrite(tempByte, segment_sequence[2], bitRead(num, 2)); // c
  bitWrite(tempByte, segment_sequence[3], bitRead(num, 3)); // d
  bitWrite(tempByte, segment_sequence[4], bitRead(num, 4)); // e
  bitWrite(tempByte, segment_sequence[5], bitRead(num, 5)); // f
  bitWrite(tempByte, segment_sequence[6], bitRead(num, 6)); // g
  bitWrite(tempByte, segment_sequence[7], bitRead(num, 7)); // dp
  return tempByte;
} 
void SevenSegmentFonts::begin(bool type, uint8_t global_Flip, bool dp_Invert){
  displayTypeSelector = type;
  globalFlip = global_Flip;
  dpInvert = dp_Invert;
}
void SevenSegmentFonts::sequence(uint8_t sequence[8]){
//  sequenceModified = 1;
  for(uint8_t i = 0; i<8; i++){
//        Serial.print(segment_sequence[i]);
    segment_sequence[i] = sequence[i];
//        Serial.println(segment_sequence[i]);
  }
  f0 = changeFont(f0);
  f1 = changeFont(f1);
  f2 = changeFont(f2);
  f3 = changeFont(f3);
  f4 = changeFont(f4);
  f5 = changeFont(f5);
  f6 = changeFont(f6);
  f7 = changeFont(f7);
  f8 = changeFont(f8);
  f9 = changeFont(f9);
  	
  fA = changeFont(fA);
  fB = changeFont(fB);
  fC = changeFont(fC);
  fD = changeFont(fD);
  fE = changeFont(fE);
  fF = changeFont(fF);
  fG = changeFont(fG);
  fH = changeFont(fH);
  fI = changeFont(fI);
  fJ = changeFont(fJ);
  fL = changeFont(fL);
  fN = changeFont(fN);
  fO = changeFont(fO);
  fP = changeFont(fP);
  fQ = changeFont(fQ);
  fR = changeFont(fR);
  fS = changeFont(fS);
  fT = changeFont(fT);
  fU = changeFont(fU);
  fY = changeFont(fY);
  
  fequal = changeFont(fequal);
  fdash = changeFont(fdash);
}
uint8_t SevenSegmentFonts::show(char value, bool dpON, bool flip){
  uint8_t returnValue = 0;
  switch(value){
    case '1': returnValue = (displayTypeSelector ? ~f1 : f1); break;
    case '2': returnValue = (displayTypeSelector ? ~f2 : f2); break;
    case '3': returnValue = (displayTypeSelector ? ~f3 : f3); break;
    case '4': returnValue = (displayTypeSelector ? ~f4 : f4); break;
    case '5': returnValue = (displayTypeSelector ? ~f5 : f5); break;
    case '6': returnValue = (displayTypeSelector ? ~f6 : f6); break;
    case '7': returnValue = (displayTypeSelector ? ~f7 : f7); break;
    case '8': returnValue = (displayTypeSelector ? ~f8 : f8); break;
    case '9': returnValue = (displayTypeSelector ? ~f9 : f9); break;
    case '0': returnValue = (displayTypeSelector ? ~f0 : f0); break;
    case '-': returnValue = (displayTypeSelector ? ~fdash : fdash); break;
    case ' ': returnValue = (displayTypeSelector ? ~fblank : fblank); break;
    case 'A': case 'a': returnValue = (displayTypeSelector ? ~fA : fA); break;
    case 'B': case 'b': returnValue = (displayTypeSelector ? ~fB : fB); break;
    case 'C': case 'c': returnValue = (displayTypeSelector ? ~fC : fC); break;
    case 'D': case 'd': returnValue = (displayTypeSelector ? ~fD : fD); break;
    case 'E': case 'e': returnValue = (displayTypeSelector ? ~fE : fE); break;
    case 'F': case 'f': returnValue = (displayTypeSelector ? ~fF : fF); break;
    case 'G': case 'g': returnValue = (displayTypeSelector ? ~fG : fG); break; //conflicts with q
    case 'H': case 'h': returnValue = (displayTypeSelector ? ~fH : fH); break;
    case 'I': case 'i': returnValue = (displayTypeSelector ? ~fI : fI); break;
    case 'J': case 'j': returnValue = (displayTypeSelector ? ~fJ : fJ); break;
    case 'L': case 'l': returnValue = (displayTypeSelector ? ~fL : fL); break;
    case 'N': case 'n': returnValue = (displayTypeSelector ? ~fN : fN); break;
    case 'O': case 'o': returnValue = (displayTypeSelector ? ~fO : fO); break;
    case 'P': case 'p': returnValue = (displayTypeSelector ? ~fP : fP); break;
    case 'Q': case 'q': returnValue = (displayTypeSelector ? ~fQ : fQ); break; //conflicts with g use dp with q when possible
    case 'R': case 'r': returnValue = (displayTypeSelector ? ~fR : fR); break;
    case 'S': case 's': returnValue = (displayTypeSelector ? ~fS : fS); break;
    case 'T': case 't': returnValue = (displayTypeSelector ? ~fT : fT); break;
    case 'U': case 'u': returnValue = (displayTypeSelector ? ~fU : fU); break;
    case 'Y': case 'y': returnValue = (displayTypeSelector ? ~fY : fY); break;
    case '=': returnValue = (displayTypeSelector ? ~fequal : fequal); break;
	default : returnValue = (displayTypeSelector ? ~fblank : fblank); break;
  }
  if(dpON){
	if(displayTypeSelector){
		bitClear(returnValue, segment_sequence[7]);
      //if(dpInvert == false) bitClear(returnValue, segment_sequence[7]);
      //if(dpInvert)          bitSet(returnValue, segment_sequence[7]);
    }
    else{
		bitSet(returnValue, segment_sequence[7]);
      //if(dpInvert == false) bitSet(returnValue, segment_sequence[7]);
      //if(dpInvert)          bitClear(returnValue, segment_sequence[7]);
    }
  }
  /*else {
	if(displayTypeSelector){
      if(dpInvert)          bitClear(returnValue, segment_sequence[7]);
      if(dpInvert == false) bitSet(returnValue, segment_sequence[7]);
    }
    else{
      if(dpInvert)          bitSet(returnValue, segment_sequence[7]);
      if(dpInvert == false) bitClear(returnValue, segment_sequence[7]);
    }
  }*/
  if(globalFlip) returnValue = reverseBits(returnValue);
  if(flip) return reverseBits(returnValue);
  else return returnValue;
}
bool SevenSegmentFonts::displayType(){
  return displayTypeSelector;
}

//uint8_t SevenSegmentFonts::show_sequence(){
//	return segment_sequence;
//}
uint8_t SevenSegmentFonts::show_sequence_pin(uint8_t pin){
	return segment_sequence[pin];
}