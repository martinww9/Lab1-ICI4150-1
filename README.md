# Lab1-ICI4150-1

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
  
