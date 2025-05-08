const float R = 0.033;      // Radio de la rueda 
const float L = 0.16;       // Distancia entre ruedas 
const float PWM_to_velocity = 0.01; 

float x = 0.0, y = 0.0, theta = 0.0;  // Posición inicial (0, 0, 0)

const int enA = 9, in1 = 8, in2 = 7;   // Motor izquierdo
const int enB = 10, in3 = 12, in4 = 11; // Motor derecho

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  analogWrite(enA, 255); analogWrite(enB, 255); 
}

void loop() {
  avanzar();
  actualizarPosicion(255, 255, 1000); // PWM máximo, 1000ms
  detener();
  delay(1000);

  girarDerecha();
  actualizarPosicion(255, -255, 500); // PWM derecho negativo
  detener();
  delay(1000);

  // Mostrar posición actual
  Serial.print("x: "); Serial.print(x);
  Serial.print(" y: "); Serial.print(y);
  Serial.print(" theta: "); Serial.println(theta);
}

// Función para actualizar posición
void actualizarPosicion(int pwm_L, int pwm_R, unsigned long delta_t_ms) {
  float delta_t = delta_t_ms / 1000.0; // Convertir a segundos
  float v_L = pwm_L * PWM_to_velocity; // Velocidad rueda izquierda (m/s)
  float v_R = pwm_R * PWM_to_velocity; // Velocidad rueda derecha (m/s)

  // Calcular velocidades lineal y angular
  float v = (v_R + v_L) / 2.0;
  float omega = (v_R - v_L) / L;

  // Actualizar ángulo (theta)
  theta += omega * delta_t;

  // Actualizar posición (x, y)
  x += v * cos(theta) * delta_t;
  y += v * sin(theta) * delta_t;
}
