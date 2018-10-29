/*
   Interrupciones
   Arduino uno tiene dos interrupciones
    INTO 0-> Pin 2
    INTO 1-> Pin 3
   Configurqcion
   atachInterrupt(interrupcion, metodo, tipo)
          digitalToPinInterrupt(Interrupcion),,LOW,RISING,FALLING)
   TIMER ONE CONFIGURACION
    ->Tier1.initialize(periodo);          ->Periodo 1s = 1000000
    ->Timer1.attachInterrupt(metodo);
    ->Timer1.start();
    ->Tiner1.stop();
    ->Timer1.restart();
    ->Timer1.resumen();
    MODOO SLLEP CONFIGURACION
    ->libreriass ->avr/sleep.h
                   avr/power.h
    ->dentro del void setup ->set_sleep_mode() ->indicar el modo de funcionamietno
                                        modos ->SLEEP_MODE_EDLE, SLEEP_MODE_ADC
                                                SLEEP_MODE_PWR_SAVE, SLEEP_MODE_PWR_DOW
                              sleep_mode(); entrar el modo configurado
                              sleep_disable(); salir del modo sleep configurado
*/

// INCLUIR LIBRERIAS
#include <TimerOne.h>
#include <avr/sleep.h>
#include <avr/power.h>

// INCLUIR VARIABLES
int on;                   //variable ecendido del sistema
unsigned int cont = 0;    //variable del ontador Timer
int config_t1 = 0;        //variab,e para configurar timer1


//CODIGO DEL PROGRAMACION
void setup() {
  attachInterrupt(digitalPinToInterrupt(2), encendido, LOW);     //Configuracion de interrupcion 0
  attachInterrupt(digitalPinToInterrupt(3), config_timer, LOW);  //Configuracion de Timer 1
  Timer1.initialize(1000000);                                    //Timer1 = a 1segundo
  Timer1.attachInterrupt(contador);                              //Metodo de Timer1
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);                           //Configurar sistema de ahorro de bateria
  sleep_enable();                                                //Habilita la configuracion
  Serial.begin(9600);                                            //Habilitar cx serial

}

void loop() {

}


//METODO Encendido
void encendido() {
  on = 1 - on;
  if (on == 1)                                                //si on es exactamente igual a 1 haga esto
    Serial.println("Sistema on");
  else {
    Serial.println("Sistema off");
    cont = 0;                                                 //Variable cont se reinicia
    delay(200);
    sleep_mode();                                             //Duerme el sistema
  }                                             
}


//METODO contador
void contador() {
  if (on == 1) {
    cont++;
    Serial.println(cont);
  }
}

//ME TODO DE CONFIGURACION TIER1
void config_timer() {
  switch (config_t1) {
    case 0:
      Serial.println("T1 STOP");
      Timer1.stop();
      config_t1++;
      break;
    case 1:
      Serial.println("T1 START");
      Timer1.start();
      config_t1++;
      break;
  }
}

