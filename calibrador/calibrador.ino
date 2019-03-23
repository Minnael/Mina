#include <robo_hardware2.h>
#include <Servo.h>

float v1, v2, v3, v4; //Armazena valores para 12 testes BRANCO E PRETO(faremos vários testes, pois assim o resultado é mais preciso)
float s1, s2, s3, s4; //Armazena as somas dos 12 testes REFLETE-BRANCO ou REFLETE-PRETO
float md1b, md2b, md3b, md4b; //Armazena as médias tiradas DO BRANCO no primeiro instante(Não as definitivas)
float md1p, md2p, md3p, md4p; //Armazena as médias tiradas DO PRETO no primeiro instante(Não as definitivas)
float sRME, sRE, sRD, sRMD; //VALOR CALIBRADO DE CADA SENSOR(MÉDIA FINAL)

void setup() {
  Serial.begin(9600);
  robo.configurar(false);

  while( !robo.botao1Pressionado() );
  Serial.print("BRANCO COMEÇOU!");


  for (int i = 1; i <= 12; i++) {             //Armazenamento de leitura no Branco (12x)
    v1 = robo.lerSensorLinhaMaisEsq();
    v2 = robo.lerSensorLinhaEsq();
    v3 = robo.lerSensorLinhaDir();
    v4 = robo.lerSensorLinhaMaisDir();

    s1 = v1 + s1;
    s2 = v2 + s2;
    s3 = v3 + s3;
    s4 = v4 + s4;
    
    delay(100);
  }

  md1b = s1 / 12;
  md2b = s2 / 12;
  md3b = s3 / 12;
  md4b = s4 / 12;
  
  
  Serial.print("BRANCO PRONTO!");

  while( !robo.botao1Pressionado() );
  Serial.print("PRETO COMEÇOU!");
 
 
 
    s1 = 0; //ZERANDO ÀS VÁRIAVEIS PARA SEREM REUTILIZADAS
    s2 = 0;
    s3 = 0;
    s4 = 0;

    for (int i = 1; i <= 12; i++) {             //Armazenamento de leitura no Branco (12x)
    v1 = robo.lerSensorLinhaMaisEsq();
    v2 = robo.lerSensorLinhaEsq();
    v3 = robo.lerSensorLinhaDir();
    v4 = robo.lerSensorLinhaMaisDir();

 
      s1 = v1 + s1;
      s2 = v2 + s2;
      s3 = v3 + s3;
      s4 = v4 + s4;

   delay(100);

    }


    md1p = s1 / 12;
    md2p = s2 / 12;
    md3p = s3 / 12;
    md4p = s4 / 12;



    sRME = (md1b + md1p) / 2;
    sRE = (md2b + md2p) / 2;
    sRD = (md3b + md3p) / 2;
    sRMD = (md4b + md4p) / 2;


    Serial.println("Mais Esquerdo: ");
    Serial.println(sRME);
    Serial.println("Esquerdo: ");
    Serial.println(sRE);
    Serial.println("Direito: ");
    Serial.println(sRD);
    Serial.println("Mais Direito: ");
    Serial.println(sRMD);

  }

 

void loop() {
  
  }
