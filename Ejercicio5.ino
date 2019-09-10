#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Objeto pantalla
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

#define PIN_SERVO 9
#define PIN_POT A0
//https://www.luisllamas.es/salidas-analogicas-pwm-en-arduino/
Servo miservo;

void setup() {
  Serial.begin(9600);
  miservo.attach(PIN_SERVO);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  int val = analogRead(PIN_POT);
  int Ang = map(val, 0, 1023, 10, 170);
  Serial.println(Ang);
  miservo.write(Ang);
  muestraTexto(Ang);
  delay(150);
}

void muestraTexto(int Ang) {
   lcd.clear();
  Serial.println(F("Muestra Texto en Pantalla LCD 20x4."));
  lcd.setCursor(0, 0);
  lcd.print("Posicion: ");
  lcd.print(Ang);
  lcd.print(" grados");
  

}
