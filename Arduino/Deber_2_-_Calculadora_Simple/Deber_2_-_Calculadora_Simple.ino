#include <LiquidCrystal.h> // Librería para el control del LCD
#include <Keypad.h> // Librería para el control del keypad

LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // varible LCD y pines
const byte filas = 4; // número de filas '4'
const byte columnas = 4; // número de columans '4'

char teclado [filas][columnas] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', 'x'},
  {'*', '0', '=', '/'}
}; //variable teclado

byte filaPines[filas] = {0, 1, 2, 3};                                                     //configuración de filas
byte columnaPines[columnas] = {4, 5, 6, 70};                                              // configuración de columnas

Keypad calcu = Keypad (makeKeymap(teclado), filaPines, columnaPines, filas, columnas);

boolean inicio = false;
boolean final = false;                                                                   // variables de control

String num1, num2;
int ans;
char op;

void setup()
{
  lcd.begin(16, 2);                                                                     //Tama;o de la pantalla LCD
  lcd.setCursor(0, 0);                                                                  //Posicion de inico de los mensajes
  lcd.print("CIERCOM");                                                                 //Mensaje de la panatalla LCD
  delay (2500);                                                                         //Tiempo de espera
  lcd.clear();                                                                          //Limpieza de pantalla LCD
}

void loop()
{
  char key = calcu.getKey();                                                            //Damos los valores para las teclas del teclado matricial

  if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0'))
  {
    if (inicio == false)
    { num1 = num1 + key;
      int numLength = num1.length();                                                    //longitud de num1
      lcd.setCursor(15 - numLength, 0);                                                 //Impresion en el LCD
      lcd.print(num1);                                                                  //Imprecion del num1 en LCD
    }
    else
    { num2 = num2 + key;
      int numLength = num2.length();                                                    //longitud de num1
      lcd.setCursor(15 - numLength, 1);                                                 //Impresion en el LCD
      lcd.print(num2);                                                                  //Imprecion del num1 en LCD
      final = true;
    }
  }
  if (inicio == false && key != NO_KEY && (key == '+' || key == '-' || key == 'x' || key == '/'))

  { inicio = true;
    op = key;
    lcd.setCursor(15, 0);
    lcd.print (op);

  }
  if (final == true && key != NO_KEY && key == '=')
  {
    if (op == '+')                                                                      //Operacion de sumar
    {
      ans = num1.toInt() + num2.toInt();
    }
    if (op == '-')                                                                      //Operacion de restar                                                                     
    {
      ans = num1.toInt() - num2.toInt();
    }
    if (op == 'x')                                                                      //Operacion de multiplicar
    {
      ans = num1.toInt() * num2.toInt();
    }
    if (op == '/')                                                                      //Operacion de dividir
    {
      ans = num1.toInt() / num2.toInt();
    }

    lcd.clear();                                                                        //Limpieza de la LCD
    lcd.setCursor(15, 0);                                                               //posicion de la respuesta
    lcd.autoscroll();                                                                   //Auto recoorido de espacios
    lcd.print(ans);                                                                     //Imprecion de la respuesta
    lcd.noAutoscroll();
  }
  if (key != NO_KEY && key == '*')
  {
    lcd.clear();
    inicio = false;
    final = false;
    num1 = "";
    num2 = "";
    ans = 0;
    op = ' ';
  }
}

