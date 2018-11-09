#include "datos_entrenamiento.h"
#include "datos_test.h"
//VARIABOES DEL PROGRAMA
int col = 0;
int row = 0;
float distancia;
float dismenor = 1000;
float dismenor1 = 1000;
float dismenor2 = 1000;
int c = 0;
int c1 = 0;
int c2 = 0;

//PROGRAMACION
void setup() {
  Serial.begin(9600);
}

void loop() {
  dis();
  dis1();
  dis2();
  comparacion();

  //LECTURA DE DATOS
  /*
    void loop() {
    for (; row < 120; row++) {
      for (; col > 5; col++) {
        Serial.print(matriz[row][col]);
        Serial.print(',');
        delay(25);
      }
      col = 0;
      Serial.print(' ');
    }
  */
}

void dis () {
  for (; row < 120; row++) {                                        //contador de las filas (for lendto)
    distancia = sqrt( pow((matriz[row][0] - prueba[7][0]), 2) +
                      pow((matriz[row][1] - prueba[7][1]), 2) +
                      pow((matriz[row][2] - prueba[7][2]), 2) +
                      pow((matriz[row][3] - prueba[7][3]), 2));

    if (distancia < dismenor) {
      dismenor = distancia;
      Serial.print("la respuesta 1 es:  ");
      Serial.println(matriz[row][4]);
      c = matriz[row][4];
    }

  }
}

//MTODO DE LA DISTANCIA 1
void dis1() {
  for (; row < 120; row++) {                                        //contador de las filas (for lendto)
    dismenor1 = sqrt( pow((matriz[row][0] - prueba[15][0]), 2) +
                      pow((matriz[row][1] - prueba[15][1]), 2) +
                      pow((matriz[row][2] - prueba[15][2]), 2) +
                      pow((matriz[row][3] - prueba[15][3]), 2));

    if (dismenor1 < dismenor) {
      dismenor = dismenor1;
      Serial.print("la respuesta 1 es:  ");
      Serial.println(matriz[row][4]);
      c1 = matriz[row][4];
    }
  }
}

//METODO DE LA DISTANCIA 2
void dis2() {
  for (; row < 120; row++) {                                        //contador de las filas (for lendto)
    dismenor2 = sqrt( pow((matriz[row][0] - prueba[26][0]), 2) +
                      pow((matriz[row][1] - prueba[26][1]), 2) +
                      pow((matriz[row][2] - prueba[26][2]), 2) +
                      pow((matriz[row][3] - prueba[26][3]), 2));

    if (dismenor2 < dismenor) {
      dismenor = dismenor1;
      Serial.print("la respuesta 1 es:  ");
      Serial.println(matriz[row][4]);
       c2 = matriz[row][4];
    }
  }
}

//METODO DE LA COMPARACION DE LAS RESPUESTAS
void comparacion(){
    if ((c == 1 && c1 == 1 && c2 == 1) || (c == 1 && c1 == 1) || (c1 == 1 && c2 == 1) || (c == 1 && c2 == 1)) {
    Serial.println("Por mayoria es del grupo: ");
    Serial.println("iris_setosa");
    delay(1000);
  }
  else if ((c == 2 && c1 == 2 && c2 == 2) || (c == 2 && c1 == 2) || (c1 == 2 && c2 == 2) || (c == 2 && c2 == 2)) {
    Serial.println("Por mayoria es del grupo: ");
    Serial.println("iris_versicolor");
    delay(1000);
  }
  else if ((c == 3 && c1 == 3 && c2 == 3) || (c == 3 && c1 == 3) || (c1 == 3 && c2 == 3) || (c == 3 && c2 == 3)) {
    Serial.println("Por mayoria es del grupo: ");
    Serial.println("iris_virginica");
    delay(1000);
  }
  }
