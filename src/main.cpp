#include <Arduino.h>
#include "global.h"


#include "sensor.h"
#include "alarme.h"

#include "freertos/task.h"
#include "freertos/queue.h"






void setup() 
{
  
  Serial.begin(9600);
  xQueueAmbiente = xQueueCreate(5, sizeof(variaveis_ambiente_t));
  if(xQueueAmbiente == NULL)
  {
   Serial.println("Fila não foi criada");
  }else
  {
   Serial.println("Fila foi criada");
  }

   xTaskCreatePinnedToCore(vTaskSensorDHT, "SensorDHT", 4000, NULL, 10, NULL,0);
   xTaskCreatePinnedToCore(vTaskAlarme, "Alarme", 4000, NULL, 2, NULL,1);
}

void loop() {
  // put your main code here, to run repeatedly:
}



