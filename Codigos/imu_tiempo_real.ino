#include <Wire.h>
#include <MPU9250_asukiaaa.h>

const int pwmL  = 5;    
const int dirL1 = 8;    
const int dirL2 = 9;   
const int pwmR  = 6;   
const int dirR1 = 10;   
const int dirR2 = 11;   

MPU9250_asukiaaa mpu;


const int baseSpeed = 200;    
const float Kp = 4.0;       

// Variables yaw
float yaw = 0.0;              
unsigned long lastT = 0;
float yawOffset = 0.0;         

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 no detectado"); while (1);
  }

  // Calibración de giroscopio Z
  long sum = 0;
  for (int i = 0; i < 200; i++) {
    mpu.getRotation();
    sum += mpu.getRotationZ();
    delay(5);
  }
  yawOffset = sum / 200.0;

  // Pines motor
  pinMode(pwmL, OUTPUT); pinMode(dirL1, OUTPUT); pinMode(dirL2, OUTPUT);
  pinMode(pwmR, OUTPUT); pinMode(dirR1, OUTPUT); pinMode(dirR2, OUTPUT);

  // Arranque en marcha adelante
  digitalWrite(dirL1, HIGH); digitalWrite(dirL2, LOW);
  digitalWrite(dirR1, HIGH); digitalWrite(dirR2, LOW);

  lastT = micros();
}

void loop() {
  // Leer giroscopio Z
  mpu.getRotation();
  int16_t gz_raw = mpu.getRotationZ();
  float gz = (gz_raw - yawOffset) / 131.0; 

  // Integrar yaw
  unsigned long now = micros();
  float dt = (now - lastT) / 1e6;
  lastT = now;
  yaw += gz * dt;      // desviación acumulada en grados

  // Calcular corrección proporcional
  float error = 0.0 - yaw;             
  int adjust = constrain(int(Kp * error), -100, 100);

  // Aplicar velocidades corregidas
  int speedL = constrain(baseSpeed + adjust, 0, 255);
  int speedR = constrain(baseSpeed - adjust, 0, 255);
  analogWrite(pwmL, speedL);
  analogWrite(pwmR, speedR);

  // Debug
  Serial.print("Yaw: "); Serial.print(yaw, 2);
  Serial.print(" | Adj: "); Serial.print(adjust);
  Serial.print(" | L: "); Serial.print(speedL);
  Serial.print(" R: "); Serial.println(speedR);

  delay(50);
}
