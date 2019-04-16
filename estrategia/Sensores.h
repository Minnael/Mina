#ifndef SENSORES_H
#define SENSORES_H

#include "Logica.h"
#include "Calibrador.h"

class Sensores{

  private:

    Logica logica;

  public:

    bool MB();
    bool PB();
    
    bool BBBB();
    bool BBBBB();
    bool BBBP();
    bool BBPB();
    bool BBPP();
    bool BPBB();
    bool BPPB();
    bool PBBB();
    bool PPPP();
    bool PPPB();
    bool BPPP();
    bool PPBB();
    bool BPBP();
    bool brancoMesq();
    bool PPP();
    bool brancoMdir();
    bool brancoDir();
    bool pretoMdir();
    bool BBB();
    bool brancoEsq();
		bool entSala3();
    bool superBrancoME();

    inline void setValoresCalibracao(Calibrador c){logica.setValoresCalibracao(c);}
};

#endif
