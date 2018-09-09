// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _bigdigitdisplay_H_
#define _bigdigitdisplay_H_
#include "Arduino.h"
//add your includes for the project sharp_tester here
#include <LiquidCrystal_I2C.h>

//end of add your includes here

// the 8 arrays that form each segment of the custom numbers
const byte bar1[8] = {
B11100,
B11110,
B11110,
B11110,
B11110,
B11110,
B11110,
B11100 };
const byte bar2[8] = {
B00111,
B01111,
B01111,
B01111,
B01111,
B01111,
B01111,
B00111 };
const byte bar3[8] = {
B11111,
B11111,
B00000,
B00000,
B00000,
B00000,
B11111,
B11111 };
const byte bar4[8] = {
B11110,
B11100,
B00000,
B00000,
B00000,
B00000,
B11000,
B11100 };
const byte bar5[8] = {
B01111,
B00111,
B00000,
B00000,
B00000,
B00000,
B00011,
B00111 };
const byte bar6[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B11111,
B11111 };
const byte bar7[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00111,
B01111 };
const byte bar8[8] = {
B11111,
B11111,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000 };

//add your function definitions for the project sharp_tester here

class BigDigitDisplay {
public:
	BigDigitDisplay(LiquidCrystal_I2C *lcd);
	void init();
	void printScore(int score);
private:
	LiquidCrystal_I2C* lcd;
	void customEmpty(int col);
	void custom0(int col);
	void custom1(int col);
	void custom2(int col);
	void custom3(int col);
	void custom4(int col);
	void custom5(int col);
	void custom6(int col);
	void custom7(int col);
	void custom8(int col);
	void custom9(int col);
	void printNumber(int value, int col);
};

//Do not add code below this line
#endif /* _bigdigitdisplay_H_ */
