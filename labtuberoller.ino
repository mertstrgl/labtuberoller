/* Design and realization of a Laboratory Tube Roller
   This code is tester. You should change **zaman command for hours.

    Required connections:
       ULN          ARDUINO
      ------------------------
          Motor  |       3

       Others       ARDUINO
      ------------------------
          Fan    |       10
          Buzzer |       8

       LCD          ARDUINO
      ------------------------
           RS    |       12
           EN    |       11
           DB4   |       4
           DB5   |       5
           DB6   |       6
           DB7   |       7

       BUTTONs      ARDUINO
      ----------------------
     Time Setting |       9
     Start        |       2
     Reset        |       RST

    Authors:
    Talat Mert Satiroglu tm.satiroglu (at) gmail.com
    Alen Guler
    Gizem Yetim

    May, 2017
*/



#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

int butonDurumu = 0;
int motorPin = 3;
int motorPin2 = 10;
int d = 0;
int zaman;
int sayac = 0;
const int butonPin3 = 9;
const int butonPin4 = 2;

int butonDurumu3 = 0;
int butonDurumu4 = 0;

int sayac3 = 0;
int buzzer = 8;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  pinMode(butonPin3, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(butonPin4, INPUT_PULLUP);


  Serial.begin(9600);

  lcd.begin(16, 2);
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.print(".");
    lcd.setCursor(3, 1);
    lcd.print("BEKLEYINIZ");
    delay(100);

  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Buton kullanimi");
  lcd.setCursor(0, 1);
  lcd.print("S:zaman G:baslat");
  delay(3000);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Lab. Tube Roller");


}

void loop() {
  butonDurumu3 = digitalRead(butonPin3);
  butonDurumu4 = digitalRead(butonPin4);


  if (butonDurumu3 == HIGH) {
    delay(50);
    sayac3 ++;
    zaman = (sayac3) - 1;

    lcd.setCursor(0, 1);  lcd.print(zaman);
    lcd.setCursor(3, 1);  lcd.print("dakika");


    while (butonDurumu3 == HIGH) {
      butonDurumu3 = digitalRead(butonPin3);

      butonDurumu4 = digitalRead(butonPin4);

      if (butonDurumu4 == LOW) {



        analogWrite(motorPin, 75);
        digitalWrite(motorPin2, HIGH);



        for (d = 0; d <= (zaman * 6); d++) {
          lcd.clear();
          lcd.setCursor(3, 0);
          lcd.print("Kalan sure");

          lcd.setCursor(2, 1);  lcd.print((((zaman) * 6) - d) * 10);
          lcd.setCursor(8, 1);  lcd.print("saniye");


          delay(10000);
        }
        tone(8, 260);
        analogWrite(motorPin, 0);
        digitalWrite(motorPin2, LOW);

        lcd.clear();
        lcd.setCursor(2, 1);  lcd.print(" ISLEM BITTI");

        delay(1000);
        noTone(8);

      }

    }
  }
}





