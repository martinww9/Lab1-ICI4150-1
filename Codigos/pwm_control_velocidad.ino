
const int enA   = 5;  
const int in1   = 8;
const int in2   = 9;
const int enB   = 6;   
const int in3   = 10;
const int in4   = 11;

// Niveles de velocidad y sus duraciones
const int speeds[]     = {100, 180, 255};
const unsigned long durations[] = {2000, 3000, 4000};
const int stages  = 3;

void setup() {
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < stages; i++) {
    int v = speeds[i];
    unsigned long t = durations[i];
    
    // Arranca motores a velocidad v
    analogWrite(enA, v);
    analogWrite(enB, v);
    Serial.print("Velocidad PWM: "); Serial.print(v);
    Serial.print(" durante "); Serial.print(t); Serial.println(" ms");
    
    // Mantiene la velocidad t milisegundos
    delay(t);
  }
  
  // Después de todas las etapas, detiene los motores 2 s y repite
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  Serial.println("Detenido 2000 ms");
  delay(2000);
}
