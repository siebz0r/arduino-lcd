/**
 * LCD test project
 *
 * The goal is to have an arduino print a incrementing counter to an LCD.
 * The LCD will show "Counter:" followed by the counter. The counter is
 * incremented by pushing a button.
 *
 * Required hardware:
 *   - Arduino
 *   - LCD screen
 *   - Push button (S1)
 *   - 220 ohm resistor (R1)
 *   - 10k ohm resistor (R2)
 *
 * The circuit should be as follows:
 *   - Arduino 5v to:
 *     - S1 pin 1
 *     - R1 pin 1
 *     - LCD VDD
 *   - Arduino GND to:
 *     - R2 pin 2
 *     - LCD VSS
 *     - LCD V0
 *     - LCD RW
 *     - LCD K
 *   - Arduino pin 2 to S1 pin 2
 *   - Arduino pin 7 to LCD DB7
 *   - Arduino pin 8 to LCD DB6
 *   - Arduino pin 9 to LCD DB5
 *   - Arduino pin 10 to LCD DB4
 *   - Arduino pin 11 to LCD E
 *   - Arduino pin 12 to LCD RS
 *   - S1 pin 2 to R2 pin 1
 *   - R1 pin 2 to LCD K
 */

#include "main.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

// Define arduino pins
# define BUTTON_PIN 2
# define DB7_PIN 7
# define DB6_PIN 8
# define DB5_PIN 9
# define DB4_PIN 10
# define E_PIN 11
# define RS_PIN 12

// Keep track of times the butten has been pushed.
volatile int buttonPushCounter = 0;

// Initialise LCD
LiquidCrystal lcd(RS_PIN, E_PIN, DB4_PIN, DB5_PIN, DB6_PIN, DB7_PIN);

void setup() {
  // set up the LCD's number of columns and rows.
  lcd.begin(16, 2);
  // Print default text to the LCD.
  lcd.print("Counter:");
  printCounter();

  // Configure button and attach handler.
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(0, buttonISR, CHANGE);
}

/**
 * Reads the button state. If the state is high, increment the
 * buttonPushCounter and print the counter.
 */
void buttonISR() {
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH) {
  	buttonPushCounter++;
    printCounter();
  }
}

/**
 * An ugly way of getting the amounts of characters in a given int.
 * Only ints from 0 to 1000 are supported.
 */
int intLength(int i) {
  if (i >= 1000) return 4;
  if (i >= 100) return 3;
  if (i >= 10) return 2;
  return 1;
}

/**
 * Print the counter on the first line of the LCD, right aligned.
 */
void printCounter() {
  int cursor = 16 - intLength(buttonPushCounter);
  lcd.setCursor(cursor, 0);
  lcd.print(buttonPushCounter);
}

void loop () {
}
