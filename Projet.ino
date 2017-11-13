int inputPin = 0;
int outputPin[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
    Serial.begin(9600);
    for(int i = 0; i < 10; i++)
    {
      pinMode(outputPin[i], OUTPUT);
    }
}

void loop() {
  //Serial.println(analogRead(inputPin)); 
            
  for(int i = 0; i < 10; i++)
  {
    digitalWrite(outputPin[i], HIGH);
    
    while(is_heart_beat)
    {
      delay(10);
    }

    digitalWrite(outputPin[i], LOW);
  }
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

