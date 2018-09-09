// Do not remove the include below
#include "BigDigitDisplay.h"

#include <LiquidCrystal_I2C.h>

/**
 * A set of custom made large numbers for a 16x2 LCD using the
 * LiquidCrystal_I2C librabry. Works with displays compatible with the
 * Hitachi HD44780 driver.
 *
 * character created using:
 * http://mikeyancey.com/hamcalc/lcd_characters.php
 */
BigDigitDisplay::BigDigitDisplay(LiquidCrystal_I2C *lcd) {
	this->lcd = lcd;
}

void BigDigitDisplay::init() {
	// assignes each segment a write number
	lcd->createChar(1, (uint8_t*) bar1);
	lcd->createChar(2, (uint8_t*) bar2);
	lcd->createChar(3, (uint8_t*) bar3);
	lcd->createChar(4, (uint8_t*) bar4);
	lcd->createChar(5, (uint8_t*) bar5);
	lcd->createChar(6, (uint8_t*) bar6);
	lcd->createChar(7, (uint8_t*) bar7);
	lcd->createChar(8, (uint8_t*) bar8);
}

void BigDigitDisplay::printScore(int score) {
	int m, c, d, u, number;
	number = score;
	if (number > 999) {
		m = (number - (number % 1000)) / 1000;
		number = number % 1000;
	} else {
		m = -1;
	}

	if (number > 99) {
		c = (number - (number % 100)) / 100;
		number = number % 100;
	} else {
		if (score > 99) {
			c = 0;
		} else {
			c = -1;
		}
	}

	if (number > 9) {
		d = (number - (number % 10)) / 10;
		number = number % 10;
	} else {
		if (score > 9) {
			d = 0;
		} else {
			d = -1;
		}
	}

	u = number;
	lcd->setCursor(0, 0);
	lcd->print("PEAK ");
	printNumber(m, 4);
	printNumber(c, 7);
	printNumber(d, 10);
	printNumber(u, 13);
}

void BigDigitDisplay::customEmpty(int col) { // uses segments to build the number 0
	lcd->setCursor(col, 0);
	lcd->print("   ");
	lcd->setCursor(col, 1);
	lcd->print("   ");
}

void BigDigitDisplay::custom0(int col) {
	lcd->setCursor(col, 0);
	lcd->write(2);
	lcd->write(8);
	lcd->write(1);
	lcd->setCursor(col, 1);
	lcd->write(2);
	lcd->write(6);
	lcd->write(1);
}

void BigDigitDisplay::custom1(int col) {
	lcd->setCursor(col, 0);
	lcd->write(32);
	lcd->write(32);
	lcd->write(1);
	lcd->setCursor(col, 1);
	lcd->write(32);
	lcd->write(32);
	lcd->write(1);
}

void BigDigitDisplay::custom2(int col) {
	lcd->setCursor(col, 0);
	lcd->write(5);
	lcd->write(3);
	lcd->write(1);
	lcd->setCursor(col, 1);
	lcd->write(2);
	lcd->write(6);
	lcd->write(6);
}

void BigDigitDisplay::custom3(int col) {
	lcd->setCursor(col, 0);
	lcd->write(5);
	lcd->write(3);
	lcd->write(1);
	lcd->setCursor(col, 1);
	lcd->write(7);
	lcd->write(6);
	lcd->write(1);
}

void BigDigitDisplay::custom4(int col) {
	lcd->setCursor(col, 0);
	lcd->write(2);
	lcd->write(6);
	lcd->write(1);
	lcd->setCursor(col, 1);
	lcd->write(32);
	lcd->write(32);
	lcd->write(1);
}

void BigDigitDisplay::custom5(int col) {
	lcd->setCursor(col, 0);
	lcd->write(2);
	lcd->write(3);
	lcd->write(4);
	lcd->setCursor(col, 1);
	lcd->write(7);
	lcd->write(6);
	lcd->write(1);
}

void BigDigitDisplay::custom6(int col) {
	lcd->setCursor(col, 0);
	lcd->write(2);
	lcd->write(3);
	lcd->write(4);
	lcd->setCursor(col, 1);
	lcd->write(2);
	lcd->write(6);
	lcd->write(1);
}

void BigDigitDisplay::custom7(int col) {
	lcd->setCursor(col, 0);
	lcd->write(2);
	lcd->write(8);
	lcd->write(1);
	lcd->setCursor(col, 1);
	lcd->write(32);
	lcd->write(32);
	lcd->write(1);
}

void BigDigitDisplay::custom8(int col) {
	lcd->setCursor(col, 0);
	lcd->write(2);
	lcd->write(3);
	lcd->write(1);
	lcd->setCursor(col, 1);
	lcd->write(2);
	lcd->write(6);
	lcd->write(1);
}

void BigDigitDisplay::custom9(int col) {
	lcd->setCursor(col, 0);
	lcd->write(2);
	lcd->write(3);
	lcd->write(1);
	lcd->setCursor(col, 1);
	lcd->write(7);
	lcd->write(6);
	lcd->write(1);
}

void BigDigitDisplay::printNumber(int value, int col) {
	if (value == -1) {
		customEmpty(col);
	}
	if (value == 0) {
		custom0(col);
	}
	if (value == 1) {
		custom1(col);
	}
	if (value == 2) {
		custom2(col);
	}
	if (value == 3) {
		custom3(col);
	}
	if (value == 4) {
		custom4(col);
	}
	if (value == 5) {
		custom5(col);
	}
	if (value == 6) {
		custom6(col);
	}
	if (value == 7) {
		custom7(col);
	}
	if (value == 8) {
		custom8(col);
	}
	if (value == 9) {
		custom9(col);
	}

}
