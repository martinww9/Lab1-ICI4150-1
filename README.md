# Lab1-ICI4150-1

---

## Parte 1: 

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
## Explicacion y conexion correcta de componentes

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

---

## Parte 2:   
  1. ¿Cómo se calcula la velocidad del robot sin encoders usando PWM?
     - Para estimar la velocidad de un motor DC sin utilizar encoders, se recurre a la relación entre el ciclo de trabajo del PWM y la velocidad angular del eje del motor. ω = kD * D. Siendo D el ciclo de trabajo del PWM.

  2. ¿Cómo factores afectan la trayectoria y velocidad del robot al cambiar los intervalos de tiempo?
     - Un motor DC no cambia instantáneamente de velocidad, tarda un tiempo de respuesta en estabilizarse. Si los “intervalos” son demasiado cortos, nunca alcanzará la velocidad objetivo, generando errores.
     - Al girar, subir una pendiente o rozar una superficie distinta, la carga sobre el motor cambia. A igual PWM, la velocidad varía según la fricción o la pendiente.
  3. ¿Cuáles son las ventajas y desventajas de usar un IMU para ajustar la dirección en lugar de encoders

      | Aspecto         | IMU (acelerómetro + giroscopio)                                                                                                                                                                                                                     |
      | --------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | 
      | **Ventajas**    | • Mide rotaciones y aceleraciones en 3 ejes (yaw, pitch, roll).<br>• Detecta inclinación y vuelcos, útil en terrenos irregulares.<br>• No requiere acoplamiento mecánico al eje de la rueda.                                                        | 
      | **Desventajas** | • **Deriva**: el giroscopio sufre drift acumulativo si no se corrige con acelerómetro o magnetómetro.<br>• **Ruido**: los sensores  son sensibles a vibraciones.<br>• Requiere filtros (complementario o Kalman) para obtener ángulos estables. | 

  4. ¿Qué efecto tiene la inclinación o el giro en el movimiento del robot, y cómo se corrige con el IMU?
     - Si el robot sube o baja una pendiente, la componente de la gravedad cambia. Esto puede alterar la carga en los motores y provocar que avance más lento o se detenga. Midiendo el pitch, el sistema puede aumentar o disminuir el PWM para mantener la velocidad en el plano horizontal efectivo.
     - Desniveles, superficies irregulares o diferencias de fricción hacen que el robot gire ligeramente al avanzar en línea recta. Midiendo el yaw con el giroscopio puedes calcular un erro y aplicar un corrector en la velocidad diferencial.
