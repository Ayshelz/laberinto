--------------------
Resumen del proyecto
--------------------

Crear un algoritmo que resuelva un laberinto bajo las siguientes premisas:

Laberinto: matriz rectangular de caracteres donde '.' indicará una casilla vacía y '#' indicará un obstáculo.
           Se asegura que 3 <= longitud <= 1000 tanto en filas como en columnas.

Pieza: el objeto a mover a través del laberinto será un bloque de tres caracteres de anchura y uno de altura.

Movimientos permitidos: 
  - Mover el bloque una posición a la derecha.
  - Mover el bloque una posición a la izquierda.
  - Mover el bloque una posición hacia abajo.
  - Mover el bloque una posición hacia arriba.
  - Rotar el bloque en torno a su centro, quedando siempre de manera vertical u horizontal. 
    Para realizar este último movimiento se requiere que el área de 3x3 alrededor del centro no tenga obstáculos o paredes.

Objetivo: resolver el laberinto en la menor cantidad de movimientos posible y mostrar dicha cantidad.
          En caso de que el laberinto sea imposible de resolver se deberá mostrar el valor -1.

Ejemplos: se conocen 4 ejemplos de laberinto y su resultado para testear el código

------------------------------------------------------------
Planificación del proyecto (48 horas naturales como máximo)
------------------------------------------------------------

- Recogida de los valores de entrada
- Creación de la estructura del laberinto
- Creación del algoritmo solución
- Pruebas
