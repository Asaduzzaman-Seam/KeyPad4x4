#include <Keypad.h>
const byte ROWS = 4; /* four rows */
const byte COLS = 4; /* four columns */
/* define the symbols on the buttons of the keypads */
char Keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}
};
byte rowPins[ROWS] = {2,3,4,5}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {6,7,8,9}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 

void setup(){
Serial.begin(9600);
}

void loop(){
  Serial.print("1st Number = ");
  char customKey1;
  customKey1 = customKeypad.waitForKey();
  if (customKey1){
    Serial.println(customKey1);
  }
  int a = (int)customKey1 - 48;

  Serial.print("2nd Number = ");
  char customKey2;
  customKey2 = customKeypad.waitForKey();
  if (customKey2){
    Serial.println(customKey2);
  }
  int b = (int)customKey2 - 48;

  Serial.print("Operation : ");
  char customKeyo;
  customKeyo = customKeypad.waitForKey();
  if (customKeyo){
    Serial.println(customKeyo);
  }

  if( '+' == customKeyo)
  {
    int s = a+b;
    Serial.print("Sum = ");
    Serial.println(s);
  }

  
}
