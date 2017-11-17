#include <time.h>
#include "cardio.h"

/*******************************variable**************************************/
int inputPin = 0;
int outputPin[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int x = 0;
unsigned int timeVar = 0;
int nbBeat = 0;
int tmpPulse = 0;
int pulse = -1;
int beat_value = 0;
int delay_simulation = 0;

/****************************fonction******************************************/
void simulation();
void ledControl(int ofType, int initLed, int nbLed);


void setup() {
    Serial.begin(9600);

    pinMode(inputPin, INPUT);//set A0 to input mode
    for(int i = 0; i < 10; i++)//set all digital 2-11 to output
    {
      pinMode(outputPin[i], OUTPUT);
    }

    //for simulation
    srand(time(NULL));
    delay_simulation = (rand()%400)+700;
    
    x = 0;//first pin if = 0
}

void loop() 
{  
  //simulation();
  
  beat_value = analogRead(inputPin);
  ledControl(TYPE, INIT, PAS);
  if(tmpPulse != NO_VALUE)
  {
    pulse = tmpPulse;
  }
    
  pulse = tmpPulse;//compute the pulse

  /****serial output info****/
  Serial.print(pulse);
  Serial.print(';');
  Serial.print(millis());
}


void ledControl(int ofType, int initLed, int nbLed)//ofType: type of led control, initLed: the first Led(def: 0), nbLed: nbLed to skip
{ 
  if(ofType == 0)
  {
    if(is_heart_beat(&inputPin, &nbBeat, &beat_value))//check if a pulse was detected
    {
      for(int i = initLed; i < 10; i += nbLed)
      {
        digitalWrite(outputPin[i], HIGH);
      }
    }
    
    delay(100);//let led light up
    
    for(int i = initLed; i < 10; i += nbLed)
    {
      digitalWrite(outputPin[i], LOW);
    }
      
    delay(200);//wait before next pulse
  }
  else if(ofType == 1)
  {
    if(is_heart_beat(&inputPin, &nbBeat, &beat_value))
    {
        digitalWrite(outputPin[x], HIGH);//set current led to on
        
        if(x == 0)//if first led
        {
            for(int i = 1; i < 10; i++)
            {
               digitalWrite(outputPin[i], LOW);//off all the led exept first one
            }
        }
        else
        {
          digitalWrite(outputPin[x-1], LOW);//off the led before
        }
         
        x++;//next led
    }

    if(x >= 10)
    {
      x = 0;
    }
    delay(200);
  }
}


void simulation()//to simulate pulse
{
  beat_value = 700;//make a pulse
  ledControl(TYPE, INIT, PAS);//run pulse detection
  beat_value = 0;//set back pulse to 0
  delay(delay_simulation);//wait before making a new pulse
}

