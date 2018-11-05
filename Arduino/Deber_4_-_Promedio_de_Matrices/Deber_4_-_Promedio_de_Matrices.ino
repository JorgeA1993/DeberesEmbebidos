//Declaramos las Variables
int matriz [10][4] = { {3,  5, -6,  7},         //variable matriz
                       {3,  8,  6, 17},
                       {2, -4,  4, 27},
                       {2,  4,  8, 10},
                       {2,  4, -2,  5},
                       {4,  5,  6,  7},
                       {5, -8,  6, -7},
                       {1,  5, 16,  8},
                       {0,  5, 12,  7},
                       {4,  5, 16,  7}};

int i = 0;                //variable i inicializada en 0
int j = 0;                //variable j inicializada en 0
float promf, promc;       //variables para los pormediso filas columnas
float acf, acc;           //cariables para los acumuladores de filas y columnas 
int datos;                //variable datos
int t = 500;              //variable para todos los delay
int nmayor = 0;           //variable numero mayor
int nmenor = 0;           //variable numero menor
int almatriz = 0;         //variable numero mayor de la matriz
int bajmatriz = 0;        //variable numero menor de la matriz

//EMPEZAMOS A DESARROLLAR EL CODIGO
void setup() {
  Serial.begin(9600);
}
//LLAMAMOS SOLO A LOS METODOS
void loop() {
  promfil();              //llamamos al metodo promedio fila
  promcol();              //llamamos al metodo promedio columnas
  nummayor();             //llamamos al metodo numero mayor de las filas
  nummenor();             //llamamos al metodo numero menor de las columnas
  altomatriz();           //llamamos al metodo numero mayor de toda la matriz
  bajomatriz();           //llamamos al metodo numero menor de toda la matriz
  delay(900000);          //delay para tiempo de espera
}
//METODO PARA SACAR EL PROMEDIO DE LAS FILAS
void promfil () {
  Serial.println("1.- Encuentre Promedio de Filas");
  for (; i < 10; i++) {
    for (; j < 4; j++) {
      datos = matriz[i][j];
      acf = acf + datos;
    }
    Serial.print("Promedio de Filas es: ");
    Serial.println(acf / 4);
    delay(t);
    j = 0;
    acf = 0;
  }
  i = 0;
  Serial.println(" ");
}
//METODO PARA SACAR EL PROMEDIO DE LAS COLUMNAS
void promcol() {
  Serial.println("2.- Encuentre Promedio de Columnas");
  for (; j < 4; j++) {
    for (; i < 10; i++) {
      datos = matriz[j][i];
      acc = acc + datos;
    }
    Serial.print("Promedio de Columna es: ");
    Serial.println(acc / 10);
    delay(t);
    i = 0;
    acc = 0;
  }
  j = 0;
  Serial.println(" ");
}
//METODO PARA SACAR EL NUMERO MAYOR DE LAS FILAS
void nummayor() {
  Serial.println("3.- Encuentre el # Mayor de cada Fila");
  for (; i < 10; i++) {
    for (; j < 4; j++) {
      if (matriz[i][j] > nmayor) {
        nmayor = matriz[i][j];
      }
    }
    Serial.print("El numero mayor de las fila es: ");
    Serial.println(nmayor);
    delay(t);
    j = 0;
    nmayor = 0;
  }
  i = 0;
  Serial.println(" ");
}
//METODO PARA SACAR EL NUMERO MENOR DE LAS COLUMNAS
void nummenor() {
  Serial.println("4.- Encuentre el # Menor de cada Columnas");
  for (; j < 4; j++) {
    for (; i < 10; i++) {
      if (matriz[i][j] < nmenor) {
        nmenor = matriz[i][j];
      }
    }
    Serial.print("El numero menor de las colunmas es: ");
    Serial.println(nmenor);
    delay(t);
    i = 0;
    nmenor = 0;
  }
  j = 0;
  Serial.println(" ");
}
//METODO PARA SACAR EL NUMERO MAYOR DE TODA LA MATRIZ
void altomatriz() {
  Serial.println("5.- Encuentre el # Mayor de toda la matriz");
  for (; j < 4; j++) {
    for (; i < 10; i++) {
      datos = matriz [i][j];
      if (matriz[i][j] > almatriz) {
        almatriz = matriz[i][j];
      }
    }
    i = 0;
  }
  Serial.print("EL  # Mayor de la Matriz es:   ");
  Serial.println(almatriz);
  delay(t);
  Serial.println(" ");
}
//METODO PARA SACAR EL NUMERO MENOR DE TODA LA MATRIZ
void bajomatriz() {
  Serial.println("6.- Encuentre el # Menor de toda la matriz");
  for (; j < 4; j++) {
    for (; i < 10; i++) {
      datos = matriz [i][j];
      if (matriz[i][j] < bajmatriz) {
        bajmatriz = matriz[i][j];
      }
    }
    i = 0;
  }
  Serial.print("EL  # Menor de la Matriz es:   ");
  Serial.println(bajmatriz);
  delay(t);
  Serial.println(" ");
}
