
//Librerías pantalla LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIN_LDR A1
//Objeto pantalla
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

int maximo = 0;
int minimo = 1023;

void setup() {
  Serial.begin(9600);

  //Inicializo pantalla
  Serial.println(F("Inicializando pantalla..."));
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(2000);
  lcd.clear();

}

void loop() {
  int sensorValue = analogRead(PIN_LDR);
  maximo = max(maximo,sensorValue);
  minimo = min(minimo,sensorValue);
  Serial.print("Valor actual: ");
  Serial.println(sensorValue);
  Serial.print("Maximo: ");
  Serial.println(maximo);
  Serial.print("Mínimo: ");
  Serial.println(minimo);
  muestraTexto(sensorValue,maximo,minimo);
  delay(1000);
}
void muestraTexto(int act, int maxi, int mini) {
   lcd.clear();
  Serial.println(F("Muestra Texto en Pantalla LCD 16x2."));
  lcd.setCursor(0, 0);
  lcd.print("Valor actual: ");
  lcd.print(act);
  lcd.setCursor(0, 1);
  lcd.print("Max: ");
  lcd.print(maxi);
 lcd.print(" Min: ");
  lcd.print(mini);


}
