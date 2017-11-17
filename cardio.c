#include "cardio.h"


bool is_heart_beat(int *pin, int *nbBeat, int *beat_value)
{ 
  if(*beat_value > 650)
  {
    (*nbBeat)++;
    return true;
  }
  else
  {
    return false;
  }
}

int pulse_processing(unsigned int *last_time, int *nbBeat)
{
  int pulse = -1;
  
  if(time_elapsed(last_time) >= 15)
  {
    pulse  = get_beat(nbBeat)/15;
    pulse  = pulse * 60;

    set_time(&last_time);

    return pulse;
  }
  else
  {
    return pulse;
  }
}

unsigned int time_elapsed(unsigned int last_time)
{
  unsigned int current_time = 0;
  unsigned int elapsed_time = 0;

  current_time = get_time();
  elapsed_time = current_time - last_time;

  return elapsed_time;
}

unsigned int get_time()
{
  return (millis()/1000);
}

int get_beat(int *nbBeat)
{
  int temp = 0;
  
  temp = *nbBeat;
  *nbBeat = 0;

  return temp;
}

void set_time(unsigned int *timeVar)
{
  *timeVar = get_time();
}

