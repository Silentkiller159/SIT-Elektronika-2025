/**
 * Matrix Keypad
 * 
 * This example shows how to use the library to perform a blocking read of a generic keypad.
 *  
 * @version 1.1.0
 * @author Victor Henrique Salvi
 */
#include <stdint.h>

const uint8_t rown = 4; //4 rows
const uint8_t coln = 3; //3 columns
uint8_t rowPins[rown] = {2, 3, 4, 5}; //frist row is connect to pin 10, second to 9...
uint8_t colPins[coln] = {8, 9, 10}; //frist column is connect to pin 6, second to 5...
char keymap[rown][coln] = 
  {{'1','2','3'}, //key of the frist row frist column is '1', frist row second column column is '2'
   {'4','5','6'}, //key of the second row frist column is '4', second row second column column is '5'
   {'7','8','9'},
   {'*','0','#'}};

char key;

void setup() {

	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);

	uint8_t i;

	for(i = 0; i < rown; i++){
		pinMode(rowPins[i], OUTPUT);
		digitalWrite(rowPins[i], HIGH);		// Radky jako vystup
	}
	for(i = 0; i < coln; i++){
		pinMode(colPins[i], INPUT_PULLUP); // Sloupce jako vstup
	}
}

void loop() {
	key = '\0';
	for(int row = 0; row < rown; row++){
			digitalWrite(rowPins[row], LOW);		// Stáhnout pin na LOW k detekci stisku, ostatní HIGH
			for(int col = 0; col < coln; col++){
				if(digitalRead(colPins[col]) == LOW) {
					key = keymap[row][col]; // Pokud je stisknuto, spadne to k LOW -> Tedy, najít v mapě příslušný rádek a sloupec znaku
				}
			}			
			digitalWrite(rowPins[row], HIGH);	// Vratit zpet na HIGH
	}

	if(key != '\0'){
		Serial.print(key); //prints the pressed key to the serial output
	}

	blink (); //blinks a led everytime that's called to show that the keypad scanning is blocking the program
	
	delay(20); //do something
}

/* inverts the led state */
void blink () {
	static int led_state = LOW;
	if(led_state == HIGH){
		led_state = LOW;
	}
	else {
		led_state = HIGH;
	}
	digitalWrite(LED_BUILTIN, led_state);
}