#include "cardio.h"


bool is_heart_beat(int *pin, int *nbBeat, int *beat_value)//int* pin not usefull
{ 
  if(*beat_value > 650)
  {
    (*nbBeat)++;//add one pulse
    return true;
  }
  else
  {
    return false;
  }
}

int pulse_processing(unsigned int *last_time, int *nbBeat)
{
  int pulse = -1;//-1 = no pulse
  
  if(time_elapsed(last_time) >= 15)//if 15 sec passed
  {
    pulse  = get_beat(nbBeat)/15;
    pulse  = pulse * 60;//convert to minute

    set_time(&last_time);//reset last_time

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
  return (millis()/1000);//return time in sec
}

int get_beat(int *nbBeat)
{
  int temp = 0;
  
  temp = *nbBeat;
  *nbBeat = 0;//reset nbBeat

  return temp;//return nb_Beat
}

void set_time(unsigned int *timeVar)
{
  *timeVar = get_time();
}

