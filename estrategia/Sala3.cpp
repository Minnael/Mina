#include "robo_hardware2.h"
#include "Sala3.h"

void Sala3::rampa (){
  
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
      movimento.exdir();
    }
    else if (sensores.pretoBrancoBrancoBranco()) {
      movimento.exesq();
    }
    else if (sensores.pretoPretoPretoBranco()) {
      movimento.superfrent();
      delay(600);
      movimento.parar();
      delay(500);
      alinhar();      
    }
    else if (sensores.brancoPretoPretoPreto()) {
      movimento.superfrent();
      delay(600);
      movimento.parar();
      delay(700);
      alinhar(); 
    }
    else if (sensores.pretoPretoPretoPreto()) {
      movimento.superfrent();
      delay(600);
      movimento.parar();
      delay(500); 
      alinhar();    
    }  
  }
}
void Sala3::procurar(){


  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();
  
    robo.acionarServoGarra2(60);
    robo.acionarServoGarra1(180);
    
    movimento.parar();
    delay(2000);

    movimento.re();
    delay(500);

    movimento.fren();
    delay(200);

    robo.acionarMotores(-45, -45);
    delay(400);

    robo.acionarMotores(54, 49);
    delay(1400);

    robo.acionarServoGarra2(0);
    
    movimento.parar();
    delay(1000);
    
    robo.acionarMotores(-54, -47);
    delay(1400);
    
    movimento.parar();
    delay(200);
    
    robo.acionarMotores(54, 50);
    delay(100);

    movimento.parar();
    delay(500);
    robo.acionarServoGarra2(10);
    delay(500);
    movimento.parar();
    delay(500);
    robo.acionarServoGarra2(20);
    movimento.parar();
    delay(500);
    robo.acionarServoGarra2(40);
    movimento.parar();
    delay(500);
    robo.acionarServoGarra2(50);
    movimento.parar();
    delay(500);
    robo.acionarServoGarra2(60);
    movimento.parar();
    delay(500);
    
    movimento.re();
    delay(300);

    robo.acionarMotores(-45, -45);
    delay(300);

    robo.acionarServoGarra1(40);

    movimento.parar();
    delay(2000);

    sensorFrontal = robo.lerSensorSonarFrontal();
    if (sensorFrontal < 30){
      
    robo.acionarServoGarra1(180);
    movimento.parar();
    delay(1000);
    movimento.fren();
    delay(300);
    movimento.parar();
    delay(200);
    robo.acionarServoGarra2(0);
    delay(500);
    
    sensorFrontal = robo.lerSensorSonarFrontal();
    resgate();
    }
}
void Sala3::alinhar(){

    robo.acionarMotores(38, 34);
    delay(400);

    movimento.parar();
    delay(1000);
    
    movimento.fren();
    delay(600);
    robo.acionarMotores(30, -30);
    delay(800);
    movimento.fren();
    delay(600);
    movimento.parar();
    delay(500);
    movimento.girando();
    delay(800);
    robo.acionarMotores(-40, -40);
    delay(600);
    movimento.parar();
    delay(2000);
    
}
void Sala3::resgate(){
   
  robo.acionarServoGarra1(60);

  robo.acionarMotores(38, 34);
  delay(1400);

  robo.acionarMotores(-30, 0);
  delay(1250);

  sensorLateralEsq = robo.lerSensorSonarEsq();
  if (sensorLateralEsq < 10){

      robo.ligarTodosLeds();
      robo.acionarMotores(-30, 0);
      delay(1000);
      robo.acionarMotores(0, -30);
      delay(1000);
      movimento.re();
      delay(800); 
      movimento.fren();
      delay(200);
      robo.acionarMotores(-40, -40);
      delay(300); 
      robo.desligarTodosLeds();    
           
      sensorLateralEsq = robo.lerSensorSonarEsq();  
  }
  
  sensorFrontal = robo.lerSensorSonarFrontal();
  while(sensorFrontal > 18){
    sensorFrontal = robo.lerSensorSonarFrontal();
    robo.acionarMotores(38, 34);
  }

  sensorFrontal = robo.lerSensorSonarFrontal();
  if (sensorFrontal < 18){
    sensorFrontal = robo.lerSensorSonarFrontal();
    movimento.re();
    delay(300);
  }
  sensorFrontal = robo.lerSensorSonarFrontal();
  if (sensorFrontal >= 18 && sensorFrontal < 20){
    sensorFrontal = robo.lerSensorSonarFrontal();
    movimento.fren();
    delay(300);
  }
  
  robo.acionarMotores(-40, 40);
  delay(950);

  movimento.re();
  delay(1000);

  robo.acionarMotores(-40, -40);
  delay(300);

  movimento.fren();
  delay(300);

  robo.acionarMotores(-40, -40);
  delay(400);

  robo.acionarMotores(-45, -45);
  delay(400);
  

  movimento.parar();
  delay(1000);

  robo.acionarMotores(50, 49);
  delay(1300);
  
  robo.acionarMotores(-40, 0);
  delay(300);
  
  sensorFrontal = robo.lerSensorSonarFrontal();
  
  movimento.fren();
  delay(1600);
    
  movimento.parar();
  delay(2000);
  robo.acionarServoGarra1(140);
  delay(1000);
  movimento.parar();
  delay(1000);
  robo.acionarServoGarra2(10);
  delay(100);
  robo.acionarServoGarra2(40);
  delay(1000);

  movimento.parar();
  while(1);
}
