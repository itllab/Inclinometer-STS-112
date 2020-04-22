#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 13, 4, 5, 6, 7); // устанавливаем адрес 0x27 или 0x3F, и дисплей 20 символов в 4 строки (20х4)
int REL = 14;
String Val[21];   // переменная для хранения полученного байта
int Byte[21];
String x;
String y;

void setup() {
    lcd.begin(16, 2);
    Serial.begin(9600); // устанавливаем последовательное соединение 
    pinMode(REL, OUTPUT);
    lcd.setCursor(7,0);
    lcd.print("ITL");
    lcd.setCursor(0, 1);
    lcd.print("Terminal STS-112");
    delay(3000);
    digitalWrite(REL, HIGH);
}

void loop() {
   lcd.clear();
   int i; for (i = 0; i < 21; i++)
    {
    Byte[i] = Serial.read();
    if (Byte[0] == 88)
      {
      if (Byte[i] == 10) 
      {Val[i] = ' ';}
      if (Byte[i] == 13) 
      {Val[i] = ' ';}
      if (Byte[i] == 43) 
      {Val[i] = '+';}
      if (Byte[i] == 45) 
      {Val[i] = '-';}
      if (Byte[i] == 46) 
      {Val[i] = '.';}
      if (Byte[i] == 48) 
      {Val[i] = '0';}
      if (Byte[i] == 49) 
      {Val[i] = '1';}
      if (Byte[i] == 50) 
      {Val[i] = '2';}
      if (Byte[i] == 51) 
      {Val[i] = '3';}
      if (Byte[i] == 52) 
      {Val[i] = '4';}
      if (Byte[i] == 53) 
      {Val[i] = '5';}
      if (Byte[i] == 54) 
      {Val[i] = '6';}
      if (Byte[i] == 55) 
      {Val[i] = '7';}
      if (Byte[i] == 56) 
      {Val[i] = '8';}
      if (Byte[i] == 57) 
      {Val[i] = '9';}
      if (Byte[i] == 61) 
      {Val[i] = '=';}
      if (Byte[i] == 88) 
      {Val[i] = 'X';}
      if (Byte[i] == 89) 
      {Val[i] = 'Y';}
      //Serial.print(Val[i]);
      }
    }
    x = Val[0]+Val[1]+Val[2]+Val[3]+Val[4]+Val[5]+Val[6]+Val[8]+Val[9];
    y = Val[11]+Val[12]+Val[13]+Val[14]+Val[15]+Val[16]+Val[17]+Val[18];
    lcd.setCursor(0, 0); // 1 строка
    lcd.print(x);
    lcd.setCursor(0, 1); // 2 строка
    lcd.print(y);
    delay(200);
}
