#ifndef __GLOBAL__H__
#define __GLOBAL__H__


// #include <TridentTD_EasyFreeRTOS32.h>
#include "freertos/task.h"
#include "freertos/queue.h"

typedef struct 
{
    float temp;   
    float umid;    

} variaveis_ambiente_t;

QueueHandle_t xQueueAmbiente;


#endif  //!__GLOBAL__H__