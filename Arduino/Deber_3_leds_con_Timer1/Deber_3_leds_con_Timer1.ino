//INCLUIMOS LAS LIBRERIAS

#include <LiquidCrystal.h> 
#include <TimerOne.h>

//VARIBLES DEL PROGRAMA
LiquidCrystal lcd(13,12,11,10,9,8); //RS E d4 d5 d6 d7 se inicia los pines que vamos a usar
 int led1=7;                        //declaramos varible led1 en el pin 7
 int led2=6;                        //declaramos varible led2 en el pin 6
 int led3=5;                        //declaramos varible led3 en el pin 5
 int on=0;
 int t1=10000;
 int t2=15000;
 int t3=5000;
 unsigned int cont = 0;

//INICIO DEL PROGRAMA
void setup() {
  pinMode(led1, OUTPUT);                  //Declaramos led 1como salida
  pinMode(led2, OUTPUT);                  //Decalramos led 2como salida
  pinMode(led3, OUTPUT);                  //Declaramos led 3como salida
 lcd.begin(16,2);                         //Tama;o de la LCD
 attachInterrupt(0,encendido, LOW);       //Configuracion de la Interrupcion del sistema
 Timer1.initialize(1000000);              //Timer1 a 1s
 Timer1.attachInterrupt(contador);        //metodo de timer
}

void loop() {
  //Codigo del Programa para los 20 segundos
  if(cont == 20){                           //condicion para que el led1 se prenda y luego de los 20 segundos se vuelva apagar
    digitalWrite(led1, HIGH);               //encendido del led2
    lcd.setCursor(0,1);                     //posicision de la impresion del mensaje
    lcd.print("led 1");                     //mensaje que se imprime
    delay(t1);                              //tiempo de espera
    digitalWrite(led1, LOW);                //apagado del led2
    lcd.clear();                            //limpieza de la pantalla LCD
    }
  //Codigo de programa para los 25 segungos
  if(cont == 25){                           //condicion para que el led1 se prenda y luego de los 25 segundos se vuelva apagar
    digitalWrite(led2, HIGH);               //encendido del led2
    lcd.setCursor(0,1);                     //posicision de la impresion del mensaje
    lcd.print("led 2");                     //mensaje que se imprime
    delay(t2);                              //tiempo de espera
    digitalWrite(led2, LOW);                //apagado del led2
    lcd.clear();                            //limpieza de la pantalla LCD
    }
  //codigo del programa para los 30 segundos
  if(cont == 30){                           //condicion para que el led1 se prenda y luego de los 303 segundos se vuelva apagar
    digitalWrite(led3, HIGH);               //encendido del led3
    lcd.setCursor(0,1);                     //posicision de la impresion del mensaje
    lcd.print("led 3");                     //mensaje que se imprime
    delay(t3);                              //tiempo de espera
    digitalWrite(led3, LOW);                //apagado del led3
    lcd.clear();                            //limpieza de la pantalla LCD

  }
}

//METODO DE ENCENDIDO
void encendido (){
  on = 1-on;
  if (on==1){
    Serial.println("SISTEMA ON");                 //Imoresion que el sistema est encendido
    Timer1.start();}                              //Inicio del Timer1 
    else{
    Serial.println("SISTEMA OFF");                //Imprecion de que el sistema esta apagago
    cont=0;                                       //igualamos el contador a 0
    delay(200);                                   //tiempo de espera
    Timer1.stop();                                //Paramos el Timer1
    lcd.clear();                                  //Limpieza de la pantalla lcd
  }
}

//METODO DE CONTADOR
void contador(){
  if(on==1){
  cont++;
  lcd.setCursor(0,0);
  lcd.print(cont);
  }
}
