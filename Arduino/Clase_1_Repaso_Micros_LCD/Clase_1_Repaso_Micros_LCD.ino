/*
   Programa para manejo de LCD 16x2
*/

#include <LiquidCrystal.h>

/*
   iniciamos el programa
*/

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);       //RS,E,D4,D3,D2,D1
char vector [7] = {'C', 'I', 'E', 'R', 'C', 'O', 'M'}; //Vector Juego
int i = 0;
int encender;                                   //Encender el sistema

void setup() {
  lcd.begin(16, 2);                                     //Definimos la fora de trabajo de la matriz
  attachInterrupt(digitalPinToInterrupt(2), on, LOW);   //
}

void loop() {
  if (encender == 1) {
    lcd.setCursor(0, 1);
    lcd.print(analogRead(0));
    for (; i < 7; i++) {
      lcd.setCursor(i, 0);                        //Elijo posicion de LCD
      lcd.print(vector[i]);                       //Imprimo los Datos
      delay(100);                                 //Tiempo de espera
      lcd.setCursor(i, 0);
      lcd.print(' ');
      delay(100);
    }
    i = 0;
  }
  else
  lcd.clear();
}
void on() {
  encender = 1 - encender;
}
