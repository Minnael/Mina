#include "Estrategia.h"
#include "robo_hardware2.h"
#include "Servo.h"
#include "Menu.h"

  Estrategia estrategia;
  Menu menu;

  void setup() {
    robo.configurar(true);
    Serial.begin(9600);
    robo.acionarServoGarra2(40);
    menu.menuLon();
    
    estrategia.setValoresCalibracao(menu.getValoresCalibracao());
  }
  void loop() {
    estrategia.executa();
  }
