# Backtracking

## **E01-definicion-de-backtraking**

Defina con sus propias palabras el término “búsqueda exhaustiva” en un algoritmo de backtracking.

**Respuesta: [E01-definicion-de-backtraking](../S02-backtracking/E01-definicion-de-backtraking.cpp)**

## **E02-estados-backtracking**

Explique brevemente los estados (variables y términos de alcance) creados en cada llamada recursiva en un algoritmo de backtracking.

**Respuesta: [E02-estados-backtracking](../S02-backtracking/E02-estados-backtracking.cpp)**

## **E03-esquemas-backtracking**

¿Cuáles son los principales esquemas de solución utilizados en backtracking?

**Respuesta: [E03-esquemas-backtracking](../S02-backtracking/E03-esquemas-backtracking.cpp)**

## **E04-solucion-backtracking**

Indique (mediante la técnica de backtracking) cómo se puede saber si un problema determinado tiene solución o no.

**Respuesta: [E04-solucion-backtracking](../S02-backtracking/E04-solucion-backtracking.cpp)**

## **E05-conjunto-soluciones**

Indique (mediante la técnica de backtracking) cómo se puede determinar todo el conjunto de soluciones de un determinado problema. ¿Y la mejor solución?

**Respuesta: [E05-conjunto-soluciones](../S02-backtracking/E05-conjunto-soluciones.cpp)**

## **E06-arreglo-de-permutaciones**

Genere todas las permutaciones posibles de un arreglo de caracteres de tamaño N.

**Ejemplo:**

| Entrada | Salida                                                                 |
|---------|------------------------------------------------------------------------|
| `N=1`   | `a`                                                                   |
| `N=3`   | `abc, acb, bac, bca, cab, cba`                                        |
| `N=2`   | `ab, ba`                                                              |
| `N=4`   | `abcd, abdc, acbd, acdb, adbc, adcb, bacd, badc, bcad, bcda, bdac,`   |
|         | `bdca, cabd, cadb, cbad, cbda, cdab, cdba, dabc, dacb, dbac, dbca,`   |
|         | `dcab, dcba`                                                          |


**Respuesta: [E06-arreglo-de-permutaciones](../S02-backtracking/E06-arreglo-de-permutaciones.cpp)**
## **E07-numeros-m-cifras**

Obtener todos los números de m cifras (m <= 9), todas ellas distintas de cero y distintas entre sí, de tal manera que el número formado por las primeras n cifras, cualquiera que sea n (n <= m), sea múltiplo de n.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `m=4`         | `1236, 9872`                       |
| `m=3`         | `123, 456, 789`                    |
| `m=2`         | `12, 34, 56, 78, 90`               |
| `m=1`         | `1, 2, 3, 4, 5, 6, 7, 8, 9`        |


**Respuesta: [E07-numeros-m-cifras](../S02-backtracking/E07-numeros-m-cifras.cpp)**

## **E08-expresiones-aritmeticas**

Dado un entero N, imprimir todas las expresiones aritméticas compuestas por los operadores +, -, *, y /, y los primeros N números naturales en orden en la cual el resultado sea igual a un R dado. El orden de prioridad es de izquierda a derecha.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `N=4, R=0`    | `-1-2+3*4=0, +1+2-3*4=0`           |
| `N=3, R=6`    | `1+2+3=6, 2*3=6`                   |
| `N=2, R=1`    | `1*1=1`                            |
| `N=5, R=10`   | `1+2+3+4=10`                       |


**Respuesta: [E08-expresiones-aritmeticas](../S02-backtracking/E08-expresiones-aritmeticas.cpp)**

## **E09-domino-trancado**

Un juego de dominó se considera “trancado” si las dos piezas que permiten a los jugadores participar en el juego son iguales, y ninguno de ellos (en el caso de cuatro jugadores) posee ninguna piedra que tenga ese valor. Se desea conocer todas las formas en la cual un juego de dominó está trancado.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `Piezas=6`    | `[(6,6)]`                          |
| `Piezas=4`    | `[(4,4)]`                          |
| `Piezas=2`    | `[(2,2)]`                          |


**Respuesta: [E09-domino-trancado](../S02-backtracking/E09-domino-trancado.cpp)**

## **E10-recorrido-del-caballo**

Se desea que usted indique todas las formas en las cuales la pieza de caballo colocada en la esquina superior derecha de un tablero de ajedrez puede recorrerlo completo, sin pasar dos veces por el mismo lugar. Tenga en cuenta que el tablero de ajedrez es de tamaño 8x8, y el caballo se mueve en forma de “L”. Ahora, indique si el caballo puede recorrer el tablero sin pasar dos veces por el mismo lugar.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `Tablero 8x8` | `Todas las rutas posibles`          |


**Respuesta: [E10-recorrido-del-caballo](../S02-backtracking/E10-recorrido-del-caballo.cpp)**

## **E11-dilema-del-pastor**

Un pastor se encuentra en una orilla de un río con una oveja, un lobo y una col. Para pasar a la otra orilla dispone de una barca muy pequeña en la que no puede cruzar más que acompañado como máximo por uno de los tres. Realice un algoritmo (basado en la técnica de Backtracking) que encuentre el modo para que el pastor pueda trasladar a la oveja, al lobo y la col, sabiendo que si en un momento dado deja solos al lobo y la oveja, éste se la comerá; y del mismo modo, si las dejara solas, la oveja se comería a la col.

**Ejemplo:**

| Entrada | Salida                              |
|---------|-------------------------------------|
| `null`  | `Pastor -> Oveja -> Pastor -> Col -> Oveja -> Lobo -> Pastor -> Oveja` |


**Respuesta: [E11-dilema-del-pastor](../S02-backtracking/E11-dilema-del-pastor.cpp)**

## **E12-camino-del-laberinto**

Una matriz bidimensional N x N puede representar un laberinto cuadrado. Cada posición contiene un entero no negativo que indica si la casilla es transitable (0) o si no lo es (1). Las casillas (1, 1) y (n, n) corresponden a la entrada y salida del laberinto y siempre son transitables. Diseñe un algoritmo que encuentre un camino, si existe, para ir de la entrada a la salida. Del mismo modo, consiga el camino de costo mínimo (menos casillas que recorrer).

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `Laberinto`   | `Camino encontrado`                |


**Respuesta: [E12-camino-del-laberinto](../S02-backtracking/E12-camino-del-laberinto.cpp)**

## **E13-coloreo-mapa**

Realice un algoritmo que permita colorear un mapamundi (en caso de ser posible). La manera de colorear el mapa es la siguiente: Para que un color sea válido para un determinado país debe ocurrir que sea distinto del que tienen asignado todos sus países limítrofes. Debe utilizar la menor cantidad de colores posibles. Asuma que existen N países distintos, y que cuenta con una matriz de \[1..N, 1..N\] de lógico, que indica si un país es limítrofe de otros. Los colores se representan mediante enteros.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `Mapa`        | `Colores asignados`                |
| `Mapa 4 países` | `Colores: [1, 2, 3, 1]`          |
| `Mapa 3 países` | `Colores: [1, 2, 1]`             |
| `Mapa 2 países` | `Colores: [1, 2]`                |


**Respuesta: [E13-coloreo-mapa](../S02-backtracking/E13-coloreo-mapa.cpp)**

## **E14-saltar-peones**

En un tablero de ajedrez de dimensiones N x N consideramos el siguiente juego. En el tablero hay colocados peones blancos y negros. Partiendo de una posición inicial y realizando movimientos válidos deseamos saltar todos los peones blancos de acuerdo con las siguientes reglas:

1. Solo se permiten movimientos en cruz.
2. Tipos de movimientos posibles:
	1. Movimiento a una casilla vacía. Coste de longitud 1.
	2. Salto de un peón blanco. Coste de longitud 2.
	3. No se pueden saltar peones negros.

Escriba un algoritmo que determine si dada una posición inicial y un número máximo de movimientos, es posible saltar a todos los peones blancos.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `Tablero`     | `Saltos posibles`                  |
| `Tablero 5x5` | `Saltos: 3`                        |
| `Tablero 3x3` | `Saltos: 2`                        |
| `Tablero 2x2` | `No hay saltos posibles`           |


**Respuesta: [E14-saltar-peones](../S02-backtracking/E14-saltar-peones.cpp)**

## **E15-torres-de-hanoi**

Cuenta la leyenda que en el gran templo de Benarés existe una base de bronce de la que sobresalen tres varillas de diamante. En el momento de la creación, Dios colocó 64 discos de oro ensartados en la primera varilla, colocados de abajo arriba en orden de tamaño decreciente; esta es la torre de Brahma. Los sacerdotes están tratando de pasar la pila de la primera varilla a la segunda, sometidos a las leyes de Brahma que indican que sólo se puede mover un disco a la vez, y que en ningún momento se puede colocar un disco más grande sobre uno más pequeño. Se cuenta con la tercera varilla para colocar los discos temporalmente. Desarrolle un programa con un método recursivo que solucione el problema de las torres de Hanoi para un número arbitrario de discos. El programa debe imprimir la secuencia precisa de transferencia de los n discos de una varilla a otra.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `Discos=3`    | `Secuencia de movimientos`         |
| `Discos=4`    | `Secuencia de movimientos`         |
| `Discos=5`    | `Secuencia de movimientos`         |
| `Discos=6`    | `Secuencia de movimientos`         |


**Respuesta: [E15-torres-de-hanoi](../S02-backtracking/E15-torres-de-hanoi.cpp)**

## **E16-ocho-reinas**

El problema consiste en colocar en un tablero de ajedrez normal 8 reinas sin que alguna ataque a las demás. En el ajedrez, una reina puede atacar a otra pieza desplazándose cualquier distancia en casillas: sobre la fila que ocupa, la columna que ocupa o bien sobre la diagonal o las diagonales que ocupa. Un tablero de ajedrez normal tiene 8 filas y 8 columnas.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `Tablero 8x8` | `Posiciones válidas`               |
| `Tablero 4x4` | `Posiciones válidas`               |
| `Tablero 3x3` | `No hay posiciones válidas`        |


**Respuesta: [E16-ocho-reinas](../S02-backtracking/E16-ocho-reinas.cpp)**

## **E17-segmentos-de-cables**

Utilice la técnica de backtracking para resolver el siguiente problema: En una ferretería se venden segmentos de cable. Los clientes suelen pedir varios metros de cable, por lo que siempre quedan pedazos cortos de cable sin vender. Todos esos pedazos cortos van quedando sin ser vendidos en la ferretería, por lo que se ha decidido soldar todos los pedazos para vender cables repotenciados de 100 metros, a un precio razonablemente menor. El ferretero entiende que este problema es complejo, pues tiene que tomar un conjunto de pedazos de cable que sumen exactamente 100 metros. El ferretero recurre a los estudiantes de AYED para que le resuelvan su problema, que en resumen consiste en: dada las longitudes de cada uno de los N pedazos de cable existentes, indicar si se puede generar un cable de 100 metros, y en dado caso, saber qué segmentos de cable se soldaron para generar uno de 100 metros con la menor cantidad de soldaduras posibles.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `Cables`      | `Combinación óptima`               |
| `Cables=[50, 50, 25, 25]` | `Combinación: [50, 50]` |
| `Cables=[40, 60, 20, 80]` | `Combinación: [40, 60]` |
| `Cables=[30, 70, 10, 90]` | `Combinación: [30, 70]` |


**Respuesta: [E17-segmentos-de-cables](../S02-backtracking/E17-segmentos-de-cables.cpp)**
