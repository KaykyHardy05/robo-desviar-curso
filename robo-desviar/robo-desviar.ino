#include <RoboCore_Vespa.h>

///////////////////////////////////////////////////////////////////////////////////////

const int TRIGGER = 26;
const int ECHO = 25;

VespaMotors motor;

int sensor_ultrassonico(int pinotrigger,int pinoecho){

  //realiza o pulso de 10 microsegundos no trigger do sensor
  digitalWrite(pinotrigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrigger,LOW);

  //mede o pulso em microsegundos retornado para o echo do sensor
  //e converte o tempo para distancia ao dividir por 58
  return pulseIn(pinoecho,HIGH)/58;
  
}

///////////////////////////////////////////////////////////////////////////////////////

void setup(){

  int repetirH = 0; //O objetivo disso é quando ele for desviar ele vai ser o numero para ele repetir para o tanto de vezes que ele se distancio de seu percurso X. (espero q tenha dado para entender).

  Serial.begin(115200);

  pinMode(TRIGGER,OUTPUT);
  pinMode(ECHO,INPUT);

  digitalWrite(TRIGGER,LOW);

}

///////////////////////////////////////////////////////////////////////////////////////

void loop(){ //void loop N°1.

  int distancia = sensor_ultrassonico(TRIGGER,ECHO);
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(100);

///////////////////////////////////////////////////////////////////////////////////////

  if(distancia < 20){

    motor.stop(); //carrinho detectou algo em sua frente e parou.
    delay(100);

    repetirH += 1;

    motor.backward(75); //carrinho andara para tras dando um pouco de espaço.
    delay(175);

    motor.turn(100,25); //carrinho virara para a direita.
    delay(100);

    motor.forward(85); //carrinho andara para frente tentado sair da frente do obstaculo q esta a sua esquerda no momento.
    delay(100);

    motor.turn(25,100); // carrinho virara para a esquerda.
    delay(100);

    motor.forward(75); //carrinho andara para tras dando um pouco de espaço.
    delay(175);

    ///////////////////////////////////////////////////////////////////////////////////////

   if(distancia < 20){
      motor.stop(); //carrinho detectou algo em sua frente e parou.
      delay(100);

      motor.backward(75); //carrinho andara para tras dando um pouco de espaço.
      delay(175);

      motor.turn(100,25); //carrinho virara para a direita.
      delay(100);

      motor.forward(85); //carrinho andara para frente tentado sair da frente do obstaculo q esta a sua esquerda no momento.
      delay(100);

      motor.turn(25,100); // carrinho virara para a esquerda.
      delay(100);

      motor.forward(75); //carrinho andara para tras dando um pouco de espaço.
      delay(175);
    } 

     ///////////////////////////////////////////////////////////////////////////////////////

    else{
     loop(repetirH){ //void loop N°2

      repetirH -= 1;

     motor.forward(100);
     delay(500);

     motor.turn(25,100);
     delay(100);

     motor.forward(100);
     delay(250);
      }
      ///////////////////////////////////////////////////////////////////////////////////////
    }
    ///////////////////////////////////////////////////////////////////////////////////////
  }
  ///////////////////////////////////////////////////////////////////////////////////////
}
///////////////////////////////////////////////////////////////////////////////////////