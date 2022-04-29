#ifndef __SENSOR__H__
#define __SENSOR__H__

#include "global.h"
#include "DHT.h"



void vTaskSensorDHT(void * parametros);



#define DHTTYPE DHT11
#define DHTPIN 4



DHT dht(DHTPIN, DHTTYPE);

#endif  //!__SENSOR__H__