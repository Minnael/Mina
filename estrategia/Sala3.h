#include "Movimento.h"
#include "Sensores.h"

#ifndef SALA3_H
#define SALA3_H

class Sala3{

  bool parar;

	Movimento movimento;
	Sensores sensores;

	public:
	
		void alinhar();

    void rampa();
};
#endif
