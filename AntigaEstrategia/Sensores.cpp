#include "robo_hardware2.h"
#include "Sensores.h"
#define CINZA 62

void Sensores:: atualizar(){
	valorMaisEsq = robo.lerSensorLinhaMaisEsq();
	valorEsq = robo.lerSensorLinhaEsq();
	valorDir = robo.lerSensorLinhaDir();
	valorMaisDir = robo.lerSensorLinhaMaisDir();

}

bool Sensores:: brancoBrancoBrancoBranco(){

	atualizar();

	return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir > CINZA);

}

bool Sensores:: brancoBrancoBrancoPreto(){

	atualizar();

	return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir <= CINZA);

}

bool Sensores:: brancoBrancoPretoBranco(){

	atualizar();

	return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir <= CINZA && valorMaisDir > CINZA);

}

bool Sensores:: brancoBrancoPretoPreto(){

	atualizar();

	return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);

}

bool Sensores:: brancoPretoBrancoBranco(){

	atualizar();

	return (valorMaisEsq > CINZA && valorEsq <= CINZA && valorDir > CINZA && valorMaisDir > CINZA);

}

bool Sensores:: brancoPretoPretoBranco(){

	atualizar();

	return (valorMaisEsq > CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir > CINZA);

}

bool Sensores:: pretoBrancoBrancoBranco(){

	atualizar();

	return (valorMaisEsq <= CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir > CINZA);

}

bool Sensores:: pretoPretoPretoPreto(){

  atualizar();

  return(valorMaisEsq <= CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);
  
  }

  bool Sensores:: pretoPretoPretoBranco(){

  atualizar();

  return(valorMaisEsq <= CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir > CINZA);
  
  }
   bool Sensores:: brancoPretoPretoPreto(){

  atualizar();

  return(valorMaisEsq > CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);
  
  }
 
  
  

