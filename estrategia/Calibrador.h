#ifndef CALIBRADOR_H
#define CALIBRADOR_H

#include "robo_hardware2.h"


class Calibrador {
  private:
    float v1, v2, v3, v4; //Armazena valores para 12 testes BRANCO E PRETO(faremos vários testes, pois assim o resultado é mais preciso)
    float s1, s2, s3, s4; //Armazena as somas dos 12 testes REFLETE-BRANCO ou REFLETE-PRETO
    float sRME, sRE, sRD, sRMD; //VALOR CALIBRADO DE CADA SENSOR(MÉDIA FINAL)
   
    bool endC;
    bool endStop;
    
    int contador;

  public:

    void calibrar();
    float getSRME();
    float getSRE();
    float getSRD();
    float getSRMD();
    void setSRME(float);
    void setSRE(float);
    void setSRD(float);
    void setSRMD(float);
    

};

#endif
