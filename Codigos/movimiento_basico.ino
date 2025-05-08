const int pwmL = 5;    // PWM rueda izquierda (ENA)
const int dirL1 = 8;   // IN1
const int dirL2 = 9;   // IN2

const int pwmR = 6;    // PWM rueda derecha (ENB)
const int dirR1 = 10;  // IN3
const int dirR2 = 11;  // IN4

void setup() {
  // Inicializa pines
  pinMode(pwmL, OUTPUT);
  pinMode(dirL1, OUTPUT);
  pinMode(dirL2, OUTPUT);
  pinMode(pwmR, OUTPUT);
  pinMode(dirR1, OUTPUT);
  pinMode(dirR2, OUTPUT);
}

void loop() {
  adelante();
  delay(1000);
  atras();
  delay(1000);
  giroDerecha();
  delay(500);
  giroIzquierda();
  delay(500);
}

// Funciones de movimiento
void adelante() {
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirR2, LOW);
}

void atras() {
  digitalWrite(dirL1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirR2, HIGH);
}

void giroDerecha() {
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirR2, HIGH);
}

void giroIzquierda() {
  digitalWrite(dirL1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirR2, LOW);
}
