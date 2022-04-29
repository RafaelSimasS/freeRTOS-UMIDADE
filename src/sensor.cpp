#include "sensor.h"


void vTaskSensorDHT(void * parametros){

 dht.begin();
  variaveis_ambiente_t variaveis_ambiente;
  
  while(1)
  {
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    float hic = dht.computeHeatIndex(t, h, false);
    Serial.print(F("Humidade: "));
    Serial.print(h);
    Serial.print(F("%  Temperatura: "));
    Serial.print(t);
    Serial.print(F("°C  Índice de calor: "));
    Serial.print(hic);
    Serial.println(F("°C "));
    variaveis_ambiente.temp = t;
    variaveis_ambiente.umid  = h;
    xQueueSend(xQueueAmbiente, &variaveis_ambiente, portMAX_DELAY);

  }
}