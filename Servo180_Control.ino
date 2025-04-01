#include <Servo.h>

Servo servomotor1;
Servo servomotor2;

const int aumentar1 = 3; // Pin para incrementar el ángulo del servo 1
const int disminuir1 = 5; // Pin para disminuir el ángulo del servo 1
const int aumentar2 = 6; // Pin para incrementar el ángulo del servo 2
const int disminuir2 = 7; // Pin para disminuir el ángulo del servo 2

int angulo1 = 90; // Ángulo inicial del servo 1
int angulo2 = 90; // Ángulo inicial del servo 2

void setup() {
  servomotor1.attach(9); // Conectar el servo 1 al pin PWM 9
  servomotor2.attach(10); // Conectar el servo 2 al pin PWM 10

  pinMode(disminuir1, INPUT_PULLUP); // Pulsadores con resistencia pull-up
  pinMode(aumentar1, INPUT_PULLUP);
  pinMode(disminuir2, INPUT_PULLUP);
  pinMode(aumentar2, INPUT_PULLUP);

  servomotor1.write(angulo1); // Inicializar el servo 1
  servomotor2.write(angulo2); // Inicializar el servo 2
}

void loop() {
  // Control del servo 1
  if (digitalRead(aumentar1) == LOW) {
    if (angulo1 < 180) {
      angulo1 += 10; // Incrementar ángulo en pasos
      servomotor1.write(angulo1);
      delay(50); // Antirrebote
    }
  }
  if (digitalRead(disminuir1) == LOW) {
    if (angulo1 > 0) {
      angulo1 -= 10; // Disminuir ángulo en pasos
      servomotor1.write(angulo1);
      delay(50); // Antirrebote
    }
  }

  // Control del servo 2
  if (digitalRead(aumentar2) == LOW) {
    if (angulo2 < 180) {
      angulo2 += 10; // Incrementar ángulo en pasos
      servomotor2.write(angulo2);
      delay(50); // Antirrebote
    }
  }
  if (digitalRead(disminuir2) == LOW) {
    if (angulo2 > 0) {
      angulo2 -= 10; // Disminuir ángulo en pasos
      servomotor2.write(angulo2);
      delay(50); // Antirrebote
    }
  }
}
