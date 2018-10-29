/*
 * SECCIONES DEL PROGRAMA
 * 1.Incluir librerias -> local y global
 *    local-> include "libreria"
 *    global-> include <libreria>
 * 2.Variables
 *    tipo de variable+el nombre de la variable+valor de la variable
 * 3. Configuración-> seleccionar el tipo de recursos a utilizar   
 *      ->Puertos e/s
 *      ->Cx sserial
 *      ->CAD
 *      ->Timer
 * 4.Ciclo infinito
 *    el sistema funcione en reiteradas ocasiones mientras sea energizado
 *    
 */
 
 /*int i=0;
 int j=0;
 int k=0;
 int leds[6]={13,12,11,10,9,8}; // inicializar puertos
 int sw[4]={7,6,5,4};//pines como entrada
void setup() {
  //encender leds
  for(;i<6;i++){
   pinMode(leds[i],OUTPUT);// configuracion del puerto
   delay(50);
  }
  i=0;
  
  for(;i<4;i++){
   pinMode(sw[i],INPUT);// configuracion del puerto
   delay(50);
  }
  i=0;
 Serial.begin(9600); 
}

void loop() {
 if(digitalRead(sw[0])==HIGH && digitalRead(sw[1])==LOW && digitalRead(sw[2])==LOW)
 juego1();
 if(digitalRead(sw[0])==LOW &&  digitalRead(sw[1])==HIGH && digitalRead(sw[2])==LOW)
 juego2();
 if(digitalRead(sw[0])==LOW &&  digitalRead(sw[1])==LOW && digitalRead(sw[2])==HIGH)
 juego3();
 
 
}
//void no me retora nada
void juego1(){
   //juego1
   Serial.println("juego #1");
  for (;i<6;i++){
    digitalWrite(leds[i],HIGH);
    delay(200);
    digitalWrite(leds[i],LOW);
    delay(200);
    }
    i=0;
}
void juego2(){
//juego2
Serial.println("juego #2");
  for (;j<6;j++){
    digitalWrite(leds[j],HIGH);
    delay(200);
    }
   for (;j>0;j--){
    digitalWrite(leds[j],LOW);
    delay(200);
    } 
}  
void juego3(){
  //juego3
  Serial.println("juego #3");
  for (;i<6;i++){
    k=random(0,5);
    digitalWrite(leds[k],HIGH);
    delay(200);
    digitalWrite(leds[k],LOW);
    delay(200);
    }
    i=0;    
    }  */

    /*
 * SECCIONES DEL PROGRAMA
 * 1.Incluir librerias -> local y global
 *    local-> include "libreria"
 *    global-> include <libreria>
 * 2.Variables
 *    tipo de variable+el nombre de la variable+valor de la variable
 * 3. Configuración-> seleccionar el tipo de recursos a utilizar   
 *      ->Puertos e/s
 *      ->Cx sserial
 *      ->CAD
 *      ->Timer
 * 4.Ciclo infinito
 *    el sistema funcione en reiteradas ocasiones mientras sea energizado
 *    
 */


 // forma larga de controlar Cx
 //analogo potenciometro
 int i=0;
 int j=0;
 int k=0;
 int a=0; //juego1
 int b=0; //juego2
 int c=0; //juego3
 int dato=0;
 int comparacion;
 int leds[6]={13,12,11,10,9,8}; // inicializar puertos
 int sw[4]={7,6,5,4};//pines como entrada
void setup() {
  //encender leds
  for(;i<6;i++){
   pinMode(leds[i],OUTPUT);// configuracion del puerto
   delay(50);
  }
  i=0;
  
  for(;i<4;i++){
   pinMode(sw[i],INPUT);// configuracion del puerto
   delay(50);
  }
  i=0;
 Serial.begin(9600); 
}

void loop() {
 if(digitalRead(sw[0])==HIGH && digitalRead(sw[1])==LOW && digitalRead(sw[2])==LOW)
 juego1();
 if(digitalRead(sw[0])==LOW &&  digitalRead(sw[1])==HIGH && digitalRead(sw[2])==LOW)
 juego2();
 if(digitalRead(sw[0])==LOW &&  digitalRead(sw[1])==LOW && digitalRead(sw[2])==HIGH)
 juego3();
 if(digitalRead(sw[3])==HIGH){
 // Serial.println(analogRead(0));
     comparacion=analogRead(0);
     if(comparacion != dato){
       Serial.println(comparacion);
      // delay(50);
      dato=comparacion;
     }
     
     
  }
  
 
}
//void no me retora nada
void juego1(){
   //juego1
   
   if (a==0)
   {
    Serial.println("juego #1");
     a=1; b=0; c=0;
    }
  for (;i<6;i++){
    digitalWrite(leds[i],HIGH);
    delay(200);
    digitalWrite(leds[i],LOW);
    delay(200);
    }
    i=0;
}
void juego2(){
//juego2
   if (b==0)
   {
    Serial.println("juego #2");
     a=0; b=1; c=0;
    }
  for (;j<6;j++){
    digitalWrite(leds[j],HIGH);
    delay(200);
    }
   for (;j>0;j--){
    digitalWrite(leds[j],LOW);
    delay(200);
    } 
}  
void juego3(){
  //juego3
     if (c==0)
   {
    Serial.println("juego #3");
     a=0; b=0; c=1;
    }
  for (;i<6;i++){
    k=random(0,5);
    digitalWrite(leds[k],HIGH);
    delay(200);
    digitalWrite(leds[k],LOW);
    delay(200);
    }
    i=0;    
    }  
