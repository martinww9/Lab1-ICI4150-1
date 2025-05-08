# Lab1-ICI4150-1

---

Parte 1: 

• ¿ Que funcion cumple los sensores, actuadores y controladores en el
robot?
  Los sensores capturan informacion del entorno o del propio robot. Los actuadores ejecturan la accion fisica en el robot, transforman senales electricas o de otro tipo, en movimiento mecanico o cambios de estado. Mientras que los controladores procesan la informacion de los sensores y envian señales a los actuadores para alcanzar el comportamiento desesado.

• ¿ Como se puede estimar la velocidad sin encoders?
  Se puede recurrir a metodos de estimacion basados en sensores inerciales, ultrasonido, SLAM basado en LIDAR o modelar matematicamente el motor.

• ¿ Como afecta la falta de encoders a la precision del movimiento?
  Sin retroalimentacion directa de los ejes, no se corrigen errores debido a cargas variables, deslizamientos o irregularidades del terreno. Ademas las desviaciones de rumbo y posicion limitan la capacidad de mantener rutas exactas, especialmente en largos recorridos.

• ¿ Que es PWM y como ayuda a controlar la velocidad de los motores?
  Es una tecnica de modulacion de la anchura del pulso para controlar la potencia media entregada a un motor. Variando el porcentaje de tiempo en alto podemos aumentar o disminuir la velocidad de manera proporcional.
  
• ¿ Como afecta el control de velocidad a la precision de la navegacion
sin encoders?
  Podriamos obtener una respuesta lenta o inexacta ya que sin retroalimentacion el control por PWM asume una relacion lineal entre la velocidad y el porcentaje de tiempo en alto. Al igual que un mayor error en la velocidad deseada.
  
---
Explicacion y conexion correcta de componentes

| **Componente**                 | **Pin del Componente**          | **Pin del Arduino UNO**     | **Descripción de la Conexión**                           |
| ------------------------------ | ------------------------------- | --------------------------- | -------------------------------------------------------- |
| **Driver L298N**               | IN1                             | D8                          | Control dirección Motor A                                |
|                                | IN2                             | D9                          | Control dirección Motor A                                |
|                                | IN3                             | D10                         | Control dirección Motor B                                |
|                                | IN4                             | D11                         | Control dirección Motor B                                |
|                                | ENA                             | D5 (PWM)                    | Habilita y controla velocidad Motor A                    |
|                                | ENB                             | D6 (PWM)                    | Habilita y controla velocidad Motor B                    |
| **Motores DC (x2)**            | Terminales de Motor A y Motor B | Salidas del L298N           | Conectados directamente al puente H                      |                                                                                                                       
| **Sensor ultrasónico HC‑SR04** | Trig                            | D12                         | Pin de disparo (distancia)                               |
|                                | Echo                            | D13                         | Pin de recepción (distancia)                             |    
|| **Sensor IMU MPU‑6050**       | SDA                             | A4                          | Comunicación I²C                                         |
|                                | SCL                             | A5                          | Comunicación I²C                                         |
| **Módulo de alimentación**     | VIN o entrada batería           | Batería externa             | 9 V para todo el sistema                                 |
|                                | 5V                              | 5V rail protoboard          | Alimentación de sensores                                 |



