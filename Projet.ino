#include <VSync.h>
#include <avr/wdt.h>
#define Reset_AVR() wdt_enable(WDTO_1S);while(1){}

int inputPin = 0;
int outputPin[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
int analog = 0;
//int time_send = 0;

ValueSender<1> sender;

void setup() {
    Serial.begin(9600);
    sender.observe(analog);
    //sender.observe(time_send);
    pinMode(outputPin[0], OUTPUT);
    /*for(int i = 0; i < 10; i++)
    {
      pinMode(outputPin[i], OUTPUT);
    }*/
}

void loop() 
{
  //time_send = millis();
  analog = analogRead(inputPin);

  sender.sync();
  
  digitalWrite(outputPin[0], HIGH);
  delay(500);

  //time_send = millis();
  analog = analogRead(inputPin);

  sender.sync();
  
  digitalWrite(outputPin[0], LOW);
  delay(500);

  if(millis() > 30000)
  {
    Reset_AVR();
  }
  
  
  /*for(int i = 0; i < 10; i++)
  {
    digitalWrite(outputPin[i], HIGH);
    
    while(is_heart_beat)
    {
      delay(10);
    }

    digitalWrite(outputPin[i], LOW);
  }*/
}

bool is_heart_beat()
{
  if(analogRead(inputPin) > 300)
  {
    return true;
  }
  else
  {
    return false;
  }
}
