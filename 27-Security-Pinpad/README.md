# Zadání
Vycházíme z předchozího zadání 26, máme maticovou klávesnici a I2C displej 16x2.

Pomocí tlačítek 0-9 zpracovat jako čísla 0-9 uvnitř arduina, tedy identifikovat stisk.  
Tlačítko "#" je pro potvrzení, tedy Enter.  
Tlačítko "*" je pro smazání, tedy Delete.  

Načtený kód zobrazit nejdříve na sériové lince v počítači, poté i na displeji pro bezpečnostní login.
Potom budeme na displeji místo stisknutých čísel zobrazovat znak "*". Počet hvězdiček bude odpovídat počtu stisknutých kláves.

Dodělat logiku pro hesla. Po potvrzení ověřit jestli je heslo správné, či nikoliv.
Rozšířit logiku na více hesel? :) 

# Potřeby
- Pochopit zapojení matice, kde jsou sloupce a řádky?
  - https://dronebotworkshop.com/keypads-arduino/ 
Knihovna MAtrix Keypad by Victor Salvi
  - https://github.com/victorsvi/MatrixKeypad
- Připojit I2C Displej
  - Knihovna pro displej od Matthiase Hertel
  - https://docs.arduino.cc/libraries/liquidcrystal_pcf8574/
- Logika pro kódy


# Schema zapojení

![zapojeni](wiring.png)

# Poznamky
- Neblokující výpis displeje
- Neblokující čtení z klávesnice!

