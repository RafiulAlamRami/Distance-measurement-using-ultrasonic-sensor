#include <LiquidCrystal.h> 

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

const int trigPin = 2;
const int echoPin = 3;

long duration;
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  
  lcd.begin(20, 4); 
  lcd.setCursor(0,0);
  lcd.setCursor(0,1);
  lcd.print("DISTENCE MEASUREMENT             ");
}
void loop() 
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;
  
  int D = map(distance, 10, 1095, 2, 400);
  
  lcd.setCursor(0,2); 
  lcd.print(" Distance: "); 
  lcd.print(D);
  lcd.print("cm     ");
  lcd.setCursor(0,3); 
  lcd.print(" Distance: "); 
  lcd.print(D/30.48);
  lcd.print("ft     ");
}
