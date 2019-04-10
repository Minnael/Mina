#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {

  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  valorSensorEsq = robo.lerSensorLinhaEsq();
  valorSensorDir = robo.lerSensorLinhaDir();
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();

  if (sensorLateralEsq < 10) {
    rampa();
}
  else if (sensorFrontal < 5) {
    desviarObstaculo();
}
  //else if (valorSensorMaisEsq > 97) {
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

   movimento.re();
   delay(100);
   movimento.parar();
   delay(1000);
   movimento.fren();
   delay(100);
   
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
    movimento.parar();
    delay(200); 

   if (valorSensorMaisDir > 60 && valorSensorMaisDir < 70){
    verde1();
}
   else if (valorSensorMaisDir > 80){
    robo.ligarLed(1);
    movimento.fren();
    delay(500);
}

   seguirLinha();
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
      delay(150);
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
      delay(150);
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
      delay(150);
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
      delay(150);
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
      delay(150);
    }
  }

}  
void Estrategia::verde2() {
  movimento.fren();
  delay(300);
  robo.acionarMotores(30, -35);
  delay(500);
  movimento.fren();
  delay(200);

  movimento.parar();
  delay(100);
  seguirLinha();
}
void Estrategia::verde1() {
  movimento.fren();
  delay(300);
  robo.acionarMotores(-35, 30);
  delay(500);
  movimento.fren();
  delay(200);

  movimento.parar();
  delay(100);
  seguirLinha();
}
void Estrategia::rampa() {
  
   robo.ligarLed(3);  
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

    for (int a= 0; a  < 5; a++){
        robo.ligarLed(1);
        delay(100);
        robo.ligarLed(2);
        delay(100);
        robo.ligarLed(3);
        delay(100);
        robo.desligarLed(1);
        delay(100);
        robo.desligarLed(2);
        delay(100);
        robo.desligarLed(3);
        delay(100);
}

    movimento.parar();
    delay(2000);

    movimento.re();
    delay(400);
    movimento.fren();
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

for(int i=0; i<8; i++){
    sala3.procurar();
    sala3.alinhar(); 
 }  
}
void Estrategia::desviarObstaculo() {

  movimento.parar();
  delay(200);

  for (int obs = 0; obs < 10; obs++){
    robo.ligarLed(3);
    delay(100);
    robo.desligarLed(3);
    delay(100);
  }

  movimento.fren();
  delay(100);
  robo.ligarLed(3);
  
  while (sensores.brancoEsq()){
    robo.acionarMotores(-30, 0);
}
  while (sensores.brancoMdir()){
    robo.acionarMotores(-30, 0);
}
  movimento.frenmed();
  delay(500);
  movimento.rodaEsqMais();
  delay(1050);
  robo.ligarLed(1);

  movimento.frenmed();
  delay(550);
  movimento.rodaEsqMais();
  delay(1100);
  robo.ligarLed(2);

  while (sensores.brancoBrancoBrancoBranco()){
    movimento.frenmed();
}
  movimento.parar();
  delay(300);
  
  movimento.frenmed();
  delay(70);
  movimento.rodaEsqMenos();
  delay(500);

  while (sensores.brancoBrancoBrancoBranco()){
    movimento.re();
}

  movimento.re();
  delay(70);

  for (int obs2 = 0; obs2 < 5; obs2++){
   movimento.parar();
   delay(300);
   robo.desligarTodosLeds();
   delay(200);
   robo.ligarTodosLeds();
   robo.desligarLed(1);
   delay(100);
   robo.desligarLed(2);
   delay(100);
   robo.desligarLed(3); 
}

  seguirLinha();
}
void Estrategia:: led(){

  for (int o = 0; o < 3; o++){
    movimento.parar();
    delay(200);
    robo.ligarLed(1);
    delay(100);
    robo.ligarLed(3);
    delay(100);
    robo.ligarLed(2);
    delay(100);
    robo.desligarTodosLeds();
    delay(100);
    robo.ligarTodosLeds();
    delay(100);
    robo.desligarTodosLeds();
    
  }
}

