#include "Calibrador.h"
#include "robo_hardware2.h"

  float Calibrador:: getSRME() {
    return sRME;
  }
  float Calibrador:: getSRE() {
    return sRE;
  }
  float Calibrador:: getSRD() {
    return sRD;
  }
  float Calibrador:: getSRMD() {
    return sRME;
  }
  void Calibrador::setSRME(float sRME2){
    sRME = sRME2;
  }
  void Calibrador::setSRE(float sRE2){
    sRE = sRE2;
  }

  void Calibrador::setSRD(float sRD2){
    sRD = sRD2;
  }

  void Calibrador::setSRMD(float sRMD2){
    sRMD = sRMD2;
  }


  void Calibrador:: calibrar() {    
    delay(1000);
    robo.ligarLed(1);

    Serial.println("CALIBRADOR INICIADO!");


    while (!endC) {
      endStop = false;
    

      while (!robo.botao1Pressionado() );
      delay(1000);
      Serial.println("BRANCO INICIADO!");

      v1 = robo.lerSensorLinhaMaisEsq();
      v2 = robo.lerSensorLinhaEsq();
      v3 = robo.lerSensorLinhaDir();
      v4 = robo.lerSensorLinhaMaisDir();

      s1 = (v1 + s1);
      s2 = (v2 + s2);
      s3 = (v3 + s3);
      s4 = (v4 + s4);

      Serial.println("BRANCO PRONTO!");
      robo.ligarLed(2);

      while ( !robo.botao1Pressionado() );
      delay(1000);
      Serial.println("PRETO INICIADO!");

      v1 = robo.lerSensorLinhaMaisEsq();
      v2 = robo.lerSensorLinhaEsq();
      v3 = robo.lerSensorLinhaDir();
      v4 = robo.lerSensorLinhaMaisDir();


      s1 = (v1 + s1);
      s2 = (v2 + s2);
      s3 = (v3 + s3);
      s4 = (v4 + s4);

    Serial.println("PRETO PRONTO!!");
    robo.ligarLed(3);

    Serial.println("ESCOLHA CONTINUAR (BOTAO 1) OU PARAR (BOTAO 2)!");

    while (!endStop) { //Stop


      if (robo.botao2Pressionado()) {
        endC = true;
        endStop = true;
        robo.desligarLed(1);
        robo.desligarLed(2);
        robo.desligarLed(3);
        Serial.println("CALIBRADOR DESLIGADO!");
      }
      else if (robo.botao1Pressionado()) {
        robo.desligarLed(2);
        robo.desligarLed(3);
        endC = false;
        endStop = true;
        Serial.println("MAIS UMA CALIBRACAO!");
      }

    }

    contador++;

   }
  

    sRME = s1 / (contador*2);
    sRE = s2 / (contador*2);
    sRD = s3 / (contador*2);
    sRMD = s4/ (contador*2);

  }
