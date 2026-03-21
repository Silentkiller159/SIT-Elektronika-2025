#include <ezButton.h>

int LED_PIN = 11;     // PIN kde bydlí LEDka
int BUTTON_PIN = 8;   // PIN kde bydli tlacitko

int SHORT_PRESS_TIME = 1000;  // Pocet ms, do ktereho bude kratky stisk
int LONG_PRESS_TIME = 1000;   // Pocet ms, od ktereho bude dlouhy stisk

ezButton tlacitko(BUTTON_PIN);  // Zalozeni promenne na tlacitko
bool tlacitkoZmacknuto = false; // Stav tlacitka
bool dlouhyStisk = false;       // Indikace dlouheho stisku
long casZmacknutiTlacitka = millis();
long casPusteniTlacitka = millis();

bool ledMaSvitit = false;
int  ledJas = 255;
bool rostouciLed = false;

void setup() {
  // put your setup code here, to run once:
  tlacitko.setDebounceTime(50);
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  tlacitko.loop();    // Oblusha tlacitka
  // put your main code here, to run repeatedly:
  if (tlacitko.isPressed()){
    if(tlacitkoZmacknuto == false){
      // PRvni navsteva metody
      Serial.println("ZMACKNUTO");
    }
    tlacitkoZmacknuto = true;
    dlouhyStisk = false;
    casZmacknutiTlacitka = millis(); // Nastavim "stopky"
  }

  if (tlacitko.isReleased()){
    if(tlacitkoZmacknuto == true){
      // Prvni navsteva metody
      Serial.println("UVOLNENO");
    }

    tlacitkoZmacknuto = false;
    casPusteniTlacitka = millis(); // Cvaknu stopky pri pusteni

    if (casPusteniTlacitka - casZmacknutiTlacitka < SHORT_PRESS_TIME){
      // Kratky stisk
      Serial.println("KRATKY STISK");
      ledMaSvitit = !ledMaSvitit;
      if(ledMaSvitit){
        analogWrite(LED_PIN, ledJas);
      }
      else{
        digitalWrite(LED_PIN, LOW);
      }
    }
  
  }

  if (millis() - casZmacknutiTlacitka > LONG_PRESS_TIME && tlacitkoZmacknuto){
    if(dlouhyStisk == false){
      // Pouze při hraně, zacatku dlouheho stisku
      Serial.println("DLOUHY STISK PROBIHA....");
    }

    if(ledMaSvitit){
      if(rostouciLed){
        ledJas += 1;
      }
      else{
        ledJas -= 1;
      }
      if(ledJas >= 255 || ledJas <= 0){
        rostouciLed = !rostouciLed;
      }
      Serial.println(ledJas);
      analogWrite(LED_PIN, ledJas);
    }
    dlouhyStisk = true;   
  }
}
