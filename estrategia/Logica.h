#ifndef LOGICA_H
#define LOGICA_H

#include "Calibrador.h"
  
class Logica{
  private:

    Calibrador calibrador;
    float sRME;
    float sRE;
    float sRD;
    float sRMD;
    float valorMaisEsq;
    float valorEsq;
    float valorDir;
    float valorMaisDir;

  public:

    bool superBrancoME();
    
    bool bValorMaisEsq();
    bool pValorMaisEsq();
    
    bool bValorEsq();
    bool pValorEsq();
    
    bool bValorDir();
    bool pValorDir();
    
    bool bValorMaisDir();
    bool pValorMaisDir();

    void valores();
    
    void atualizarVME();
    void atualizarVE();
    void atualizarVD();
    void atualizarVMD();

    void setValoresCalibracao(Calibrador c);

};

#endif
