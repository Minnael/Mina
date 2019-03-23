#ifndef SENSORES_H
#define SENSORES_H

#include "Logica.h"
#include "Calibrador.h"

class Sensores{

  private:

    Logica logica;

  public:

    bool brancoBrancoBrancoBranco();

    bool brancoBrancoBrancoPreto();

    bool brancoBrancoPretoBranco();

    bool brancoBrancoPretoPreto();

    bool brancoPretoBrancoBranco();

    bool brancoPretoPretoBranco();

    bool pretoBrancoBrancoBranco();

    bool pretoPretoPretoPreto();

    bool pretoPretoPretoBranco();

    bool brancoPretoPretoPreto();

    bool pretoPretoBrancoBranco();

    bool brancoPretoBrancoPreto();

    bool brancoMesq();

    bool pretoPretoPreto();

    bool brancoMdir();

    bool brancoDir();

    bool pretoMdir();

    bool brancoBrancoBranco();

    bool brancoEsq();

		bool entSala3();

    bool superBrancoME();

    inline void setValoresCalibracao(Calibrador c){logica.setValoresCalibracao(c);}
};

#endif
