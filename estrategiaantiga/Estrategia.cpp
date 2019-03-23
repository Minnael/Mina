#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {
  seguirLinha();
}
void Estrategia::seguirLinha() {

  if (sensores.brancoBrancoBrancoBranco()) {
    robo.acionarMotores(50, 50);
  } else if (sensores.brancoPretoBrancoBranco()) {
    robo.acionarMotores(-60, 55);
  } else if (sensores.brancoBrancoPretoBranco()) {
    robo.acionarMotores(45,-50);
  } else if (sensores.brancoBrancoBrancoPreto()) {
    robo.acionarMotores(55, -60);
  } else if (sensores.pretoBrancoBrancoBranco()) {
    robo.acionarMotores(-60, 55);
  } else if (sensores.pretoPretoPretoPreto()) {
    robo.acionarMotores(60, 60);
  }
    else if(sensores.pretoPretoPretoBranco()){
    robo.acionarMotores(55, -60);
  }
}
void Estrategia::verde() {}
void Estrategia::sala3() {}
void Estrategia::desviarObstaculo() {}
