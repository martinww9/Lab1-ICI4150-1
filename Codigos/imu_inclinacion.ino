#include <Wire.h>
#include <MPU9250_asukiaaa.h>

const int pwmL  = 5;    // ENA
const int dirL1 = 8;    // IN1
const int dirL2 = 9;    // IN2
const int pwmR  = 6;    // ENB
const int dirR1 = 10;   // IN3
const int dirR2 = 11;   // IN4


MPU9250_asukiaaa mpu;
float yawOffset = 0.0;    // Para referenciar inicio en cero
const float GYRO_SCALE = 131.0; 
const int baseSpeed = 200; 

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Inicializar IMU
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("Error: MPU6050 no conectado");
    while (1);
  }

  // Calibrar sesgo de giroscopio Z 
  long sum = 0;
  const int samples = 200;
  for (int i = 0; i < samples; i++) {
    mpu.getRotation();
    sum += mpu.getRotationZ();
    delay(5);
  }
  yawOffset = sum / float(samples);

  // Pines de motor como salida
  pinMode(pwmL, OUTPUT);
  pinMode(dirL1, OUTPUT);
  pinMode(dirL2, OUTPUT);
  pinMode(pwmR, OUTPUT);
  pinMode(dirR1, OUTPUT);
  pinMode(dirR2, OUTPUT);

  // Poner ambos motores hacia adelante
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirR2, LOW);
}

void loop() {
  // 1) Avanzar
  analogWrite(pwmL, baseSpeed);
  analogWrite(pwmR, baseSpeed);

  // 2) Leer giroscopio Z
  mpu.getRotation();
  int16_t gz_raw = mpu.getRotationZ();
  float gz = (gz_raw - yawOffset) / GYRO_SCALE; // °/s

  // 3) Integrar para estimar yaw 
  static float yaw = 0.0;
  static unsigned long lastT = micros();
  unsigned long now = micros();
  float dt = (now - lastT) / 1e6;
  lastT = now;
  yaw += gz * dt; // acumula desviación en grados

  // 4) Imprimir desviación
  Serial.print("Yaw (°): ");
  Serial.println(yaw, 2);

  delay(100);
}
