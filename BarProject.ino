#include <HX711_ADC.h>


#include <LiquidCrystal.h>

HX711_ADC scale(A2, A3);
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  lcd.begin(16, 2);  
  lcd.print("Profuse Studio");
}

void loop() {
  lcd.setCursor(0, 1);  
  lcd.print(scale.getGram(), 1);
  lcd.println(" g          ");
  delay(200);
  Serial.println(scale.averageValue());
  if(digitalRead(2) == HIGH)
  {
      lcd.setCursor(0, 1);
      lcd.print("Reseting        ");
      delay(1000);
      scale.setOffset(scale.averageValue());
  }
}
























