
#include "alarme.h"

void vTaskAlarme(void * parametros){
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(LedAzul, OUTPUT);
  variaveis_ambiente_t variaveis_ambiente;
  float Recebe_H;
  float Recebe_T;
  int contador = 0;

  BaseType_t pdStatus;
  while(1)
  {
    pdStatus = xQueueReceive(xQueueAmbiente, &variaveis_ambiente, 0);

   Recebe_T = variaveis_ambiente.temp;
   Recebe_H = variaveis_ambiente.umid;
   contador++;

  if(pdStatus == true){

    Serial.println("entrou");
   if(Recebe_H < 50)
    {
      Serial.println("O ambiente está seco.");
    }else if(Recebe_H <= 62.99)
    {
      Serial.println("O ambiente está um pouco seco.");
    }else if(Recebe_H >= 63)
    {
      Serial.println("O ambiente  está Úmido.");
    }

    if(Recebe_T < 25)
    {
      Serial.println("Ambiente Frio.");
      digitalWrite(LedAzul, HIGH);
      vTaskDelay(650 / portTICK_PERIOD_MS);
      digitalWrite(LedAzul, LOW);
    }else if(Recebe_T < 27.99)
    {
      Serial.println("Ambiente um pouco Frio.");
      digitalWrite(LedAzul, HIGH);
      digitalWrite(LedVerde, HIGH);
      vTaskDelay(650 / portTICK_PERIOD_MS);
      digitalWrite(LedAzul, LOW);
      digitalWrite(LedVerde, LOW);
    }else if(Recebe_T >= 30)
    {
      Serial.println("O ambiente está quente");
      digitalWrite(LedVermelho, HIGH);
      digitalWrite(LedAzul, LOW);
      digitalWrite(LedVerde,HIGH );
      vTaskDelay(650 / portTICK_PERIOD_MS);
      digitalWrite(LedVermelho, LOW);
      digitalWrite(LedAzul, LOW);
      digitalWrite(LedVerde, LOW);
    }
    
   }
   



   Serial.println("Contador=" + String(contador));
   vTaskDelay(10000 / portTICK_PERIOD_MS);
  }
}
