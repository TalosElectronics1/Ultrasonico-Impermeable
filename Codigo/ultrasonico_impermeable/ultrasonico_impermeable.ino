#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define ECHOPIN 2// Pin to receive echo pulse
#define TRIGPIN 3// Pin to send trigger pulse

void setup() {
  Serial.begin(115200);
  pinMode(ECHOPIN, INPUT_PULLUP);
  pinMode(TRIGPIN, OUTPUT);
  digitalWrite(ECHOPIN, HIGH);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

}
void loop()
{

  digitalWrite(TRIGPIN, LOW); // Inicia el pulso en bajo por 2uS
  delayMicroseconds(2);//Espera 2us
  digitalWrite(TRIGPIN, HIGH); //Se genera el pulso por 10us 
  delayMicroseconds(10);//Espera 10us
  digitalWrite(TRIGPIN, LOW); // Termina el pulso 
  int distancia = pulseIn(ECHOPIN, HIGH, 26000); // se mide el tiempo que tardo en regresar el pulso en us
  distancia = distancia / 58;//Ecuacion para medir la distancia
  delay(150);// Esperar 150 ms antes de volver a medir
  
  lcd.setCursor(0, 0);
  lcd.print(distancia);
  lcd.print("  ");
  Serial.print(distancia);
  Serial.println("   cm");
}
