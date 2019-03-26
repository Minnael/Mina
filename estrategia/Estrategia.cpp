#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {

  sensorBaixo = robo.lerSensorSonarDir();
  sensorLateral = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();

  // if (sensorLateral < 10 && sensores.entSala3()) {
  // oSala3.rampa();
  //} 
  
  if (sensorLateral < 10 && sensorBaixo < 10) {
    rampa();
  }

  else if (sensorFrontal < 5) {
    desviarObstaculo();
  }
  //else if (valorSensorMaisEsq > 85) {
  //redutor();
  //}
  else {
    seguirLinha();
  }

}
void Estrategia::redutor() {

    movimento.superfrent();
    delay(500);

    movimento.parar();
    delay(500);

    robo.acionarMotores(-30, -30);
    delay(400);

    movimento.parar();
    delay(1000);

  if (!sensores.brancoBrancoBrancoBranco()){
    seguirLinha();
  }
  if (sensores.brancoBrancoBrancoBranco()){
    
    robo.acionarMotores(-30, 30);
     delay(1000);   

  }
  while(sensores.brancoBrancoBrancoBranco()){
     robo.acionarMotores(30, -30);
  }

  seguirLinha();
  
 }
void Estrategia::seguirLinha() {

  if (sensores.brancoBrancoBrancoBranco()) {
    movimento.fren();
  }
  else if (sensores.brancoPretoBrancoBranco()) {
    movimento.esq();
  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.dir();
  }
  else if (sensores.brancoBrancoBrancoPreto()) {
    movimento.exdir();
  }
  else if (sensores.pretoBrancoBrancoBranco()) {
    movimento.exesq();
  }
  else if (sensores.pretoPretoPretoPreto()) {
    robo.acionarMotores(20, 20);
  }
  else if (sensores.brancoPretoPretoBranco()) {
    movimento.dir();
    delay(100);
  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.exesq();
    delay(100);
  }
  else if (sensores.pretoPretoPretoBranco())  {
    movimento.dir();
    delay(100);
  }
  else if (sensores.brancoPretoBrancoBranco())  {
    movimento.esq();
    delay(100);
  }
  else if (sensores.pretoPretoBrancoBranco())  {
    movimento.esq();
    delay(100);
  }
  else if (sensores.brancoBrancoPretoPreto())  {
    movimento.dir();
    delay(100);
  }
  else{
    movimento.re();
  }
}
void Estrategia::verde() {}

void Estrategia::rampa() {
  
  parar = false;

  while (!parar) {

    if (sensores.brancoBrancoBrancoBranco()) {
      movimento.superfrent();
    }
    else if (sensores.brancoPretoBrancoBranco()) {
      movimento.esqq();
    }
    else if (sensores.brancoBrancoPretoBranco()) {
      movimento.dirr();
    }
    else if (sensores.brancoBrancoBrancoPreto()) {
      movimento.exesq();
    }
    else if (sensores.pretoBrancoBrancoBranco()) {
      movimento.exdir();
    }
    
    else if (sensores.pretoPretoPretoBranco()) {
      movimento.superfrent();
      delay(800);

      movimento.parar();
      delay(500);
      
      sala3();
    }
    else if (sensores.brancoPretoPretoPreto()) {
      movimento.superfrent();
      delay(800);
      
      movimento.parar();
      delay(500);

        sala3();
    }
    else if (sensores.pretoPretoPretoPreto()) {
      movimento.superfrent();
      delay(800);

      movimento.parar();
      delay(500);

      sala3();
    }
    
  }
}
void Estrategia::sala3() {

    movimento.parar();
    delay(2000);

    movimento.girando();
    delay(1100);
    robo.acionarMotores(-50, -50);
    delay(800);
    robo.acionarMotores(38, 41);
    while(1);
    
}
void Estrategia::led() {

  static long redLedInterval = 300;
  static bool redLedState = false;
  static   long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > redLedInterval) {
    previousMillis = currentMillis;

    if (redLedState == LOW) {
      robo.ligarTodosLeds();
      redLedState = HIGH;

    }
    else {

      robo.desligarTodosLeds();
      redLedState = LOW;

    }
  }
}

void Estrategia::desviarObstaculo() {
  
  movimento.parar();
  delay(1000);

  movimento.re();
  delay(200);

  while (sensores.brancoMesq()){
     robo.acionarMotores(0, -30);
  }

  seguirLinha();
}
void Estrategia:: voltarParaALinha() {
  robo.ligarLed(1);
  movimento.obRe();
  delay(300);
  robo.acionarMotores(70, 15);
  delay(660);
  robo.acionarMotores(-15, -50);
  delay(550);
  parar = true;
}

