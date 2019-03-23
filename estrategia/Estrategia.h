#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include "Sensores.h"
#include "Movimento.h"
#include "Calibrador.h"
#include "Sala3.h"

class Estrategia{

  private:
  
    #define VERMELHO 1
    #define AMARELO 2
    #define VERDE 3
   
    Sensores sensores;
    Movimento movimento;
		Sala3 oSala3;

    float sensorFrontal;
    float sensorLateral;
    float sensorBaixo;

    float valorSensorMaisEsq;
    
    bool parar;

  public:

    void led();
    void executa();
    void seguirLinha();
    void verde();
    void sala3();
    void desviarObstaculo();
    void redutor();
    void voltarParaALinha();
    void rampa();
    
    inline void setValoresCalibracao(Calibrador c){sensores.setValoresCalibracao(c);}

};

#endif
