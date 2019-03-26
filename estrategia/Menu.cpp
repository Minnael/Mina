#include "robo_hardware2.h"
#include "Menu.h"
#include "Servo.h"



  void Menu::menuLon(){
  
    Serial.println("Pressione botao1 para calibrar.");
    while(!pare){
      if(robo.botao1Pressionado()){   

      pare = true;
      calibrador.calibrar();
  
      val.refletanciaMaisEsq=calibrador.getSRME();
      val.refletanciaEsq=calibrador.getSRE();
      val.refletanciaDir=calibrador.getSRD();
      val.refletanciaMaisDir=calibrador.getSRMD();
      
      robo.salvarCalibracao(val);
      } 
      else if(robo.botao2Pressionado()){
        robo.lerCalibracao(val);
        calibrador.setSRME(val.refletanciaMaisEsq);
        calibrador.setSRE(val.refletanciaEsq);
        calibrador.setSRD(val.refletanciaDir);
        calibrador.setSRMD( val.refletanciaMaisDir);
        robo.desligarLed(1);
        pare = true;
      }
    }

  printDados();
  }

  void Menu::printDados(){
    Serial.println("Mais Esquerdo: ");
    Serial.println(calibrador.getSRME());
    Serial.println("Esquerdo: ");
    Serial.println(calibrador.getSRE());
    Serial.println("Direito: ");
    Serial.println(calibrador.getSRD());
    Serial.println("Mais Direito: ");
    Serial.println(calibrador.getSRMD());
  }

