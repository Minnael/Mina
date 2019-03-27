#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {

  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();

  if (sensorLateralEsq < 10 && sensorLateralDir < 10) {
    rampa();
  }

  else if (sensorFrontal < 5) {
    desviarObstaculo();
  }
  //else if (valorSensorMaisEsq > 90) {
  //redutor();
  //}
  else {
    seguirLinha();
  }

}
void Estrategia::redutor() {

    movimento.superfrent();
    delay(300);

    movimento.parar();
    delay(500);

    robo.acionarMotores(-30, -30);
    delay(100);

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
    delay(200);
  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.exesq();
    delay(200);
  }
  else if (sensores.pretoPretoPretoBranco())  {
    movimento.dir();
    delay(200);
  }
  else if (sensores.brancoPretoBrancoBranco())  {
    movimento.esq();
    delay(200);
  }
  else if (sensores.pretoPretoBrancoBranco())  {
    movimento.esq();
    delay(200);
  }
  else if (sensores.brancoBrancoPretoPreto())  {
    movimento.dir();
    delay(200);
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
      delay(700);

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
    
    //robo.acionarServoGarra1(60);

    movimento.girando();
    delay(600);
    movimento.re();
    delay(700);
    robo.acionarMotores(30, 26);
    delay(400);
    robo.acionarMotores(-35, -35);
    delay(300);

    robo.acionarServoGarra1(60);
    robo.acionarServoGarra2(60);
    
    movimento.parar();
    delay(2000);
    
    sensorFrontal = robo.lerSensorSonarFrontal();
    while (sensorFrontal > 2){ 
      sensorFrontal = robo.lerSensorSonarFrontal();
      robo.acionarMotores(30, 26);
      
    }
    sensorFrontal = robo.lerSensorSonarFrontal();
    while (sensorFrontal < 80){
      sensorFrontal = robo.lerSensorSonarFrontal();
      robo.acionarMotores(-30, -30);
    }
    
    movimento.parar();
    while(1);
}
void Estrategia::desviarObstaculo() {

  while (sensores.brancoEsq()){
    robo.acionarMotores(-30, 0);
  }

  movimento.fren();
  delay(1300);

  robo.acionarMotores(30, -40);
  delay(550);

  movimento.fren();
  delay(1500);

  robo.acionarMotores(30, -40);
  delay(550);

  movimento.fren();
  delay(1000);
  
  movimento.fren();
  delay(100);

  robo.acionarMotores(-40, 40);
  delay(700);

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

