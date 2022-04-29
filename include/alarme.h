#ifndef __ALARME__H__
#define __ALARME__H__




#include <Arduino.h>
#include "global.h"

#include "freertos/task.h"
#include "freertos/queue.h"

void vTaskAlarme(void * parametros);

#define LedVermelho 5
#define LedVerde 18
#define LedAzul 19

#endif  //!__ALARME__H__