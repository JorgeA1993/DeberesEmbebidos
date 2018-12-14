#include <knn.h>
#include"bddnor.h"
float vector[30][5] = {
  {5.1, 3.5, 1.4, 0.2, 1},
  {4.9, 3, 1.4, 0.2, 1},
  {4.7, 3.2, 1.3, 0.2, 1},
  {4.6, 3.1, 1.5, 0.2, 1},
  {5, 3.6, 1.4, 0.2, 1},
  {5.4, 3.9, 1.7, 0.4, 1},
  {4.6, 3.4, 1.4, 0.3, 1},
  {5, 3.4, 1.5, 0.2, 1},
  {4.4, 2.9, 1.4, 0.2, 1},
  {4.9, 3.1, 1.5, 0.1, 1},
  {7, 3.2, 4.7, 1.4, 2},
  {6.4, 3.2, 4.5, 1.5, 2},
  {6.9, 3.1, 4.9, 1.5, 2},
  {5.5, 2.3, 4, 1.3, 2},
  {6.5, 2.8, 4.6, 1.5, 2},
  {5.7, 2.8, 4.5, 1.3, 2},
  {6.3, 3.3, 4.7, 1.6, 2},
  {4.9, 2.4, 3.3, 1, 2},
  {6.6, 2.9, 4.6, 1.3, 2},
  {5.2, 2.7, 3.9, 1.4, 2},
  {6.3, 3.3, 6, 2.5, 3},
  {5.8, 2.7, 5.1, 1.9, 3},
  {7.1, 3, 5.9, 2.1, 3},
  {6.3, 2.9, 5.6, 1.8, 3},
  {6.5, 3, 5.8, 2.2, 3},
  {7.6, 3, 6.6, 2.1, 3},
  {4.9, 2.5, 4.5, 1.7, 3},
  {7.3, 2.9, 6.3, 1.8, 3},
  {6.7, 2.5, 5.8, 1.8, 3},
  {7.2, 3.6, 6.1, 2.5, 3}
};
int on = 0;
float result, promc1, dista, maxnor, promc2, promc3, promc4, promf1, distan, disprom, dispromedio;
int u = 0;
float v1[40];
float nor[40];
float y[40];
float x[40];
int c = 0;
float rang1 = 0.85;
float rang2 = 0.93;
int porcentaje;
int fila, col,  coll, fil, fi = 0;
int cont = 1;
float p1 , p2, p3, p4;
void setup() {
  Serial.begin(9600);
}

void loop() {
  leer();
  //  distancia();

  if (on == 0) {
    for (int i = 0; i < 30; i++) {
      result = knn(3, 5, 1, 3, vector[i]);
      if (result == vector[i][4]) {
        u++;
        Serial.println(u);
      }
      porcentaje = u * 100 / 30;
    }
    Serial.print("El procentaje es el del: ");
    Serial.println(porcentaje);
  }
  on = 1;

}
void leer() {
  for (; fila < 40; fila++) {
    for (; col < 1; col++) {
      promc1 = (promc1 + bdd[fila][0]);
      promc2 = (promc2 + bdd[fila][1]);
      promc3 = (promc3 + bdd[fila][2]);
      promc4 = (promc4 + bdd[fila][3]);
      //      delay(25);

    }
    p1 = promc1 / 40;
    p2 = promc2 / 40;
    p3 = promc3 / 40;
    p4 = promc4 / 40;
    col = 0;

  }
  for (; fil < 40; fil++) {
    distan = sqrt(pow((bdd[fil][0] - p1), 2) +
                  pow((bdd[fil][1] - p2), 2 ) +
                  pow((bdd[fil][2] - p3), 2 ) +
                  pow((bdd[fil][3] - p4), 2));
    v1[fil] = distan;
    maxnor = max(maxnor, distan);
    //    Serial.println(v1[fil]);
  }
  fil = 0;
  for (; fil < 40; fil++) {
    nor[fil] = v1[fil] / maxnor;
    //    Serial.println(nor[fil]);
  }
  for (; fi < 40; fi++) {
    if (nor[fi] >= rang1 && nor[fi] <= rang2) {
      y[fi] = 1;
      x[fi] = fi;
      //      Serial.println(y[fi]);
    }
    else {
      y[fi] = 0;
      //      Serial.println(y[fi]);
    }
    if (y[fi] == 1) {
      Serial.print(bdd[fi][0]);
      Serial.print(",");
      Serial.print(bdd[fi][1]);
      Serial.print(",");
      Serial.print(bdd[fi][2]);
      Serial.print(",");
      Serial.print(bdd[fi][3]);
      Serial.print(" ");
    }
  }

}



