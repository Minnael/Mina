#ifndef SALA3_H
#define SALA3_H

#include "Sensores.h"
#include "Movimento.h"
#include "Calibrador.h"

class Sala3 {
	
	private:
	
	 Movimento movimento;
	 Sensores sensores;

	  float sensorLateralDir;
    float sensorLateralEsq;
    float sensorFrontal;

    bool parar;
	
	public:
    
	  void rampa();
	  void alinhar();
	  void capturar();
	  void resgate();
	  void procurar();
    void procurar2();
    
	  void led();
	  void sonares();
	
};

#endif
