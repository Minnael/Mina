#include "Estrategia.h"
#include "robo_hardware2.h"
#include "Servo.h"
#include "Menu.h"

  Estrategia estrategia;
  Menu menu;

  void setup() {
    robo.configurar(false);
    Serial.begin(9600);
  
    menu.menuLon();
  
    estrategia.setValoresCalibracao(menu.getValoresCalibracao());
  }
  void loop() {
    estrategia.executa();
  }
