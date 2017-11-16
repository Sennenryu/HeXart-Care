#include "cardio.h"

int inputPin = 0;
int outputPin[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int x = 0;
unsigned int timeVar = 0;
int nbBeat = 0;
int pulse = -1;
int beat_value = 0;


void setup() {
    Serial.begin(9600);

    pinMode(inputPin, INPUT);
    for(int i = 0; i < 10; i++)
    {
      pinMode(outputPin[i], OUTPUT);
    }

    x = 0;
}

void loop() 
{  
  Serial.println(analogRead(inputPin));

  ledControl(TYPE, INIT, PAS);

  Serial.print(beat_value);
  Serial.print(';');
  Serial.print(millis());
  
  pulse = pulse_processing(&timeVar, &nbBeat);
}

void ledControl(int ofType, int initLed, int nbLed)
{
  if(ofType == 0)
  {
    if(is_heart_beat(&inputPin, &nbBeat, &beat_value))
    {
      for(int i = initLed; i < 10; i += nbLed)
      {
        digitalWrite(outputPin[i], HIGH);
      }
    }
    
    delay(100);
    
    for(int i = initLed; i < 10; i += nbLed)
    {
      digitalWrite(outputPin[i], LOW);
    }
  }
  else if(ofType == 1)
  {
    if(is_heart_beat(&inputPin, &nbBeat, &beat_value))
    {
        digitalWrite(outputPin[x], HIGH);
        
        if(x == 0)
        {
            for(int i = 1; i < 10; i++)
            {
               digitalWrite(outputPin[i], LOW);
            }
        }
        else
        {
          digitalWrite(outputPin[x-1], LOW);
        }
         
        x++;
    }

    if(x >= 10)
    {
      x = 0;
    }
    delay(150);
  }
}
