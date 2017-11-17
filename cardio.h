#ifndef CARDIO_H_INCLUDED
#define CARDIO_H_INCLUDED

#include <Arduino.h>
#include <param.h>

#define NO_VALUE -1

#ifdef __cplusplus
extern "C" {
#endif

bool is_heart_beat(int* pin, int *nbBeat, int *beat_value);
int pulse_processing(unsigned int *last_time, int *nbBeat);
unsigned int time_elapsed(unsigned int last_time);
unsigned int get_time();
int get_beat(int *nbBeat);
void set_time(unsigned int *timeVar);

#ifdef __cplusplus
}
#endif


#endif
