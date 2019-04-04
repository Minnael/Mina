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
  else if (valorSensorMaisEsq > 97) {
  redutor();
  }
  else {
    seguirLinha();
  }

}
void Estrategia::redutor() {

    movimento.superfrent();
    delay(500);

    movimento.parar();
    delay(500);

    movimento.parar();
    delay(1000);

    movimento.re();
    delay(200);
    
  if (!sensores.brancoBrancoBrancoBranco()){
    seguirLinha();
  }
  if (sensores.brancoBrancoBrancoBranco()){
    
    robo.acionarMotores(-30, 30);
     delay(700);   
  
  }
  if (!sensores.brancoBrancoBrancoBranco()){
    seguirLinha();
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
    movimento.re();
    delay(300);
}
  
  else if (sensores.brancoPretoPretoBranco()){
    movimento.re();
    delay(300);
}
  
  else if (sensores.brancoBrancoBrancoPreto()){ ///OBS

    movimento.parar();
    delay(200);
    while (sensores.brancoBrancoBrancoBranco()){
      movimento.exdir();
    }
    if (!sensores.brancoBrancoBrancoBranco()){
      movimento.exdir();
      delay(200);
    }
    
}
  else if (sensores.brancoPretoPretoPreto())  {
    
    movimento.parar();
    delay(200);
    while (sensores.brancoBrancoBrancoBranco()){
      movimento.exesq();
    }
    if (!sensores.brancoBrancoBrancoBranco()){
      movimento.exesq();
      delay(200);
    }

}


  else if (sensores.pretoPretoPretoBranco())  {
    
    movimento.parar();
    delay(200);
    while (sensores.brancoBrancoBrancoBranco()){
      movimento.exdir();
    }
    if (!sensores.brancoBrancoBrancoBranco()){
      movimento.exdir();
      delay(200);
    }
}


  else if (sensores.pretoPretoBrancoBranco())  {
    
     movimento.parar();
     delay(200);
     while (sensores.brancoBrancoBrancoBranco()){
      movimento.exesq();
    }
    if (!sensores.brancoBrancoBrancoBranco()){
      movimento.exesq();
      delay(200);
    }
}


  else if (sensores.brancoBrancoPretoPreto())  {
    
    movimento.parar();
     delay(200);
    while (sensores.brancoBrancoBrancoBranco()){
      movimento.exdir();
    }
    if (!sensores.brancoBrancoBrancoBranco()){
      movimento.exdir();
      delay(200);
    }
  }

  
  /*else {
    for(int i=0; i<5000; i++){
       robo.ligarTodosLeds();
       delay(400);
       robo.desligarTodosLeds();
      delay(400);
    }
  }
 */
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
    else if (sensores.pretoPretoPretoBranco()) {
      movimento.superfrent();
      delay(500);
      movimento.parar();
      delay(500);
       Sala3();       
    }
    else if (sensores.brancoPretoPretoPreto()) {
      movimento.superfrent();
      delay(500);
      movimento.parar();
      delay(500);
       Sala3(); 
    }
    else if (sensores.pretoPretoPretoPreto()) {
      movimento.superfrent();
      delay(500);
      movimento.parar();
      delay(500); 
      Sala3(); 
    }  
  }
}
void Estrategia::Sala3() {

    movimento.parar();
    delay(2000);

    movimento.fren();
    delay(800);
    movimento.re();
    delay(400);
    movimento.girando();
    delay(700);
    movimento.re();
    delay(700);
    robo.acionarMotores(28, 24);
    delay(400);
    robo.acionarMotores(-45, -45);
    delay(500);
    robo.acionarMotores(28, 24);
    delay(500);
    robo.acionarMotores(-28, -24);
    delay(700);

for(int i=0; i<5; i++){
    sala3.procurar();
    sala3.alinhar(); 
 }  
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
