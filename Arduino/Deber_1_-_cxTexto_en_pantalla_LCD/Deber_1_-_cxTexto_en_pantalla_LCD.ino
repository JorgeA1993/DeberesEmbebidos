// Agregamos libreria de LCD
#include <LiquidCrystal.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);       //RS,E,D4,D3,D2,D1
int t = 1500;
String palabra = "CIERCOM";
int texto = palabra.length();
int puesto = 0;
int on = 0;

void setup() {
  Serial.begin(9600);           //inicializo counicacion serial
  lcd.begin(16, 2);             //Damos el tama;o de la LCD
  attachInterrupt(digitalPinToInterrupt(2), encendido, FALLING); //on/of sistema
  
}

void loop() {
  if (on == 1) {
    lcd.setCursor(0, 0);                                //Posiciona el cursor en la posicion (0,0)
    lcd.print(palabra);                                 //Muestra el mensaje
    delay(t);                                           //tiempo de retardo
    for (; puesto < (16 + texto); puesto++)             //for para mover el texto de iquierda a derecha
    {
      lcd.scrollDisplayRight();                         //desplaza el cotenido de la pantalla
      delay(300);
    }
    puesto = 0;
  }
}

void encendido() {                                      // metodo de encendido
  on = 1 - on;
  if (on == 1) {
    Serial.println("Sistema On");
  }
}
