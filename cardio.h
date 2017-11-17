#ifndef CARDIO_H_INCLUDED
#define CARDIO_H_INCLUDED

#include <Arduino.h>
#include <param.h>

#define NO_VALUE -1

#ifdef __cplusplus
extern "C" {
#endif

bool is_heart_beat(int* pin, int *nbBeat, int *beat_value);//return if pulse is detected
int pulse_processing(unsigned int *last_time, int *nbBeat);//compute pulse
unsigned int time_elapsed(unsigned int last_time);//return the elapsed time since last pulse compute
unsigned int get_time();//return time in sec
int get_beat(int *nbBeat);//return nb of pulse detected since last checked
void set_time(unsigned int *timeVar);//set a variable to the current time

#ifdef __cplusplus
}
#endif


#endif
