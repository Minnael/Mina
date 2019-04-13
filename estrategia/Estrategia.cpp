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
  meio = robo.lerSensorLinhaMeio();

  if (sensorLateralEsq < 10) {
    rampa();
}
  else if (sensorFrontal < 5) {
    desviarObstaculo();
}
  //else if (meio < 25) {
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
    
  if (!sensores.BBBB()){
    seguirLinha();
  }
  if (sensores.BBBB()){
    
    robo.acionarMotores(-30, 30);
     delay(700);   
  
  }

  if (!sensores.BBBB()){
    seguirLinha();
  }
  while(sensores.BBBB()){
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

  if (sensores.BBBB()) { //BRANCO-BRANCO-BRANCO-BRANCO
    movimento.fren();
}
  else if (sensores.BPBB()) { ;//BRANCO-PRETO-BRANCO-BRANCO
    movimento.esq();
}
  else if (sensores.BBPB()) { //BRANCO-BRANCO-PRETO-BRANCO
    movimento.dir();
}
  else if (sensores.BBBP()) { //BRANCO-BRANCO-BRANCO-PRETO
    movimento.exdir();
}
  else if (sensores.PBBB()) { //PRETO-BRANCO-BRANCO-BRANCO
    movimento.exesq();
}
  else if (sensores.PPPP()) { //PRETO-PRETO-PRETO-PRETO
    
    movimento.re();
    delay(300); 
    movimento.parar();
    delay(200); 
   if (valorSensorMaisDir > 60 && valorSensorMaisDir < 70){
    verde1();
    
}  else if (valorSensorMaisDir > 80){
    movimento.fren();
    delay(500);
}
   seguirLinha();
}

  else if (sensores.BPPB()){ //BRANCO-PRETO-PRETO-BRANCO
    movimento.re();
    delay(300);
}
  
  else if (sensores.BBBP()){  //BRANCO-BRANCO-BRANCO-PRETO
    
    movimento.parar();
    delay(200);
     while (sensores.MB()){
      movimento.exdir();
} 
     if (sensores.BBBP()){
      while (!sensores.MB()){
      movimento.exdir();
}
}
}

  else if (sensores.BPPP())  { //BRANCO-PRETO-PRETO-PRETO
    
    movimento.parar();
    delay(200);
    while (sensores.MB()){
      movimento.exesq();
}
    if (sensores.BPPP()){
      while (!sensores.MB()){
         movimento.exesq();
}
}
}


  else if (sensores.PPPB())  { //PRETO-PRETO-PRETO-BRANCO
    
    movimento.parar();
    delay(200);
    
    while (sensores.MB()){
      movimento.exdir();
} 
    if (sensores.PPPB()){
      while (!sensores.MB()){
      movimento.exdir();
}
}
}

  else if (sensores.PPBB())  { //PRETO-PRETO-BRANCO-BRANCO
    
     movimento.parar();
     delay(200);
     
     while (sensores.MB()){
      movimento.exesq();  
}    
     if (sensores.PPBB()){
      while (!sensores.MB()){
      movimento.exesq();
}
}
}


  else if (sensores.BBPP())  { //BRANCO-BRANCO-PRETO-PRETO
    
    movimento.parar();
     delay(200);
     
    while (sensores.MB()){
      movimento.exdir();
}   
    if (sensores.BBPP()){
     while (!sensores.MB()){
     movimento.exdir();
}
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

    if (sensores.BBBB()) {
      movimento.superfrent();
    }
    else if (sensores.BPBB()) {
      movimento.esqq();
    }
    else if (sensores.BBPB()) {
      movimento.dirr();
    }
    else if (sensores.PPPB()) {
      movimento.superfrent();
      delay(500);
      movimento.parar();
      delay(500);
       Sala3();       
    }
    else if (sensores.BPPP()) {
      movimento.superfrent();
      delay(500);
      movimento.parar();
      delay(500);
       Sala3(); 
    }
    else if (sensores.PPPP()) {
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
  delay(200);
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

  while (sensores.BBBB()){
    movimento.frenmed();
}
 
  movimento.parar();
  delay(300);
  
  //movimento.frenmed();
  //delay(70);
  movimento.rodaEsqMenos();
  delay(600);

  while (sensores.MB()){
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

