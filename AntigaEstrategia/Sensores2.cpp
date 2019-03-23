#include "robo_hardware2.h"
#include "Sensores2.h"
#define CINZA 50

void Sensores2:: atualizar(){
	double valorEsq = robo.lerSensorLinhaEsq();
	double valorDir = robo.lerSensorLinhaDir();

}

bool Sensores2:: brancoBranco(){

	atualizar();

	return (valorEsq > CINZA && valorDir > CINZA);

}

bool Sensores2:: brancoPreto(){

	atualizar();

	return (valorEsq > CINZA && valorDir <= CINZA);

}

bool Sensores2:: pretoBranco(){

	atualizar();

	return (valorEsq <= CINZA && valorDir > CINZA );

}

bool Sensores2:: pretoPreto(){

	atualizar();

	return (valorEsq <= CINZA && valorDir <= CINZA);
}
