// Do not remove the include below
#include <LiquidCrystal_I2C.h>
#include <ButtonDebounce.h>

#include "sharp_tester.h"
#include "BigDigitDisplay.h"
#include "HX711.h"

// Arduino NodeMCU pin mapping
#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)
#define SD3 10 // GPIO10
#define SD2 9  // GPIO09
#define SD1 8 // GPIO08

bool SERIAL_ENABLED = true;

// user set calibration factor (float)
float SCALE_CAL_FACTOR = -344.0;

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 16x2 display
BigDigitDisplay display(&lcd);

// Create our LoadCell object
HX711 scale(D3, D4);
long t;
float peak = 0.0;

ButtonDebounce measure(D7, 250);

//The setup function is called once at startup of the sketch
void setup() {
	//Serial
	if (SERIAL_ENABLED) {
		Serial.begin(115200);
	}
	Serial.println("################### Loading ################");

	// LCD
	lcd.init(); // init display
	lcd.backlight(); // backlight

	// BigDigitDisplay
	display.init();
	display.printScore(8888);

	Serial.println("Stabilizing scale...");
	delay(3000);

	// scale init
	scale.set_scale(SCALE_CAL_FACTOR);
	delay(100);
	scale.tare();
	Serial.println("Startup + tare is complete");
	delay(500);
	display.printScore(0);
	Serial.println("################### OK ################");
}

// The loop function is called in an endless loop
void loop() {
	//get smoothed value from data set + current calibration factor
	if (millis() > (unsigned) t + 50) {
		float actualScore = scale.get_units();
		Serial.print("score: ");
		Serial.println(actualScore, 2);
		if (actualScore > peak) {
			peak = actualScore;
			display.printScore(peak);
		}
//		display.printScore(actualScore);
		t = millis();
	}

	// start new measurement set peak to 0.0
	measure.update();
	if (measure.state() == LOW) {
		display.printScore(8888);
		Serial.println("new measurement");
		delay(1000);
		peak = 0.0;
		display.printScore(peak);
	}

}
