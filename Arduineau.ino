#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int valeurEau=0;
String stringlvl = "Humidite: " ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valeurEau=analogRead(A0);
  String lvl = stringlvl + valeurEau ;
  Serial.println(valeurEau);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  if (valeurEau >= 350 && valeurEau <= 430) {
    lcd.setCursor(0,0);
    lcd.print("Je suis mouillee!");
    lcd.setCursor(2,1);
    lcd.print(lvl);
  } else if (valeurEau >= 431 && valeurEau <= 520) {
    lcd.setCursor(0,0);
    lcd.print("Je suis sec!");
    lcd.setCursor(2,1);
    lcd.print(lvl);
  } else if (valeurEau <= 349) {
    lcd.setCursor(0,0);
    lcd.print("Cable deconnecte");
    lcd.setCursor(2,1);
    lcd.print(lvl);
  } else if (valeurEau >= 521) {
    lcd.setCursor(0,0);
    lcd.print("Chargement...");
    lcd.setCursor(2,1);
    lcd.print(lvl);
  }
}
