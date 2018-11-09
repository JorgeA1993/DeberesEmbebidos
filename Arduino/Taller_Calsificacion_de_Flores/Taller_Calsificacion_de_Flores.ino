#include"datos_entrenamiento.h"
#include"datos_test.h"
int row, col = 0;
int cont = 1;
int c = 0;
int n = 0;
float distan ;
float dismenor = 10000;
int fp = 22;
int res[100] ;
int pos[100] ;


void setup() {
  Serial.begin(9600);
}

void loop() {
  distancia(5);
  leer();
}
//metodo de compracion
void comparacion() {
  for (; row < 120; row++) {//CONTADOR DE FILAS
    for (; col < 5; col++) {//CONTADOR DE COLUMNAS
      Serial.print(matriz[row][col]);
      Serial.print(',');
      delay(25);
    }
    col = 0;
    Serial.println(' ');
  }
}

//metodo calculo de distancias
void distancia(int k) {
  for (; cont < 2; cont++) {
    for (; row < 120; row++) {


      distan = sqrt(pow((matriz[row][0] - prueba[fp][0]), 2) +
                    pow((matriz[row][1] - prueba[fp][1]), 2 ) +
                    pow((matriz[row][2] - prueba[fp][2]), 2 ) +
                    pow((matriz[row][3] - prueba[fp][3]), 2));
        if (distan < 1) {
        c++;
        dismenor = distan;
        n = matriz[fila][4];
        Serial.println(distan);
        if (c == 5) {
          Serial.print(n);
          c = 0;
        }
      }
    }
    
    if (n == 1) {
      Serial.print("El grupo es:iris_setosa");
    }
    if (n == 2) {
      Serial.print("El grupo es:iris_versicolor");
    }
    if (n == 3) {
      Serial.print("El grupo es:iris_virginica");
    }
  }
}
