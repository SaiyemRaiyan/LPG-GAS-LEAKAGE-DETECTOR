#include <LiquidCrystal.h>


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define MQPin A0
#define red 9
#define green 10
#define buzzer 11

void setup() 
{
   lcd.begin(16, 2); //lcd turn on
   pinMode(MQPin, INPUT_PULLUP); //arduino input from mqpin
      //output by pin
   pinMode(red, OUTPUT);
   pinMode(green, OUTPUT);
   pinMode(buzzer, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("   GAS LEAKAGE  "); //print
  lcd.setCursor(0, 1);
  lcd.print(" DETECTOR - EIF ");
  delay(1000); //stop time (ms)
  lcd.clear(); //lcd blink
}

void loop() {

int gas_value = digitalRead(MQPin); //MQPin to input gas_value

if(gas_value==HIGH) //high means 1
 {
   digitalWrite(green, LOW); 
   digitalWrite(buzzer, HIGH);
   ledon(); //
   lcdon();
 }
  else
{
   lcdoff();
   ledoff();
}
 
}

void ledon() //red high (on) 
{
   digitalWrite(red, HIGH);   //red on
   delay(200);  // blink                  
   digitalWrite(red, LOW);    
   delay(200);    //blink
}

void ledoff()  
{
  digitalWrite(red, LOW);  //red off
  digitalWrite(green, HIGH);
  digitalWrite(buzzer, LOW);  // buzzer off
}


void lcdon()
{
  lcd.setCursor(0, 0);
  lcd.print("  GAS DETECTED  "); //msg
  lcd.setCursor(0, 1);
  lcd.print(" ALERT ALERT !! "); //msg
  delay(200); //blink
  lcd.clear();
}

void lcdoff()
{
  lcd.clear();  //clear the lcd
  lcd.setCursor(0, 0);
  lcd.print("    NO GAS     ");
  lcd.setCursor(0, 1);
  lcd.print("  DETECTED     ");
  delay(200); //blink in 200ms
}