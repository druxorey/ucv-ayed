# Estructuras Multienlazadas

## **E01-invertir-lista-doble**

Dada una lista lineal doblemente enlazada, implemente un algoritmo que invierta físicamente sus enlaces para retornar la lista invertida.

**Ejemplos:**
| Entrada (Lista inicial) | Salida (Lista invertida) |
| :--- | :--- |
| `[ 10 20 30 40 ]` | `[ 40 30 20 10 ]` |
| `[ 5 8 ]` | `[ 8 5 ]` |


**Respuesta: [E01-invertir-lista-doble.cpp](../S07-estructuras-multienlazadas/E01-invertir-lista-doble.cpp)**

## **E02-mezclar-listas-dobles**

Dadas las listas lineales doblemente enlazadas L1 y L2 que se encuentran ordenadas ascendentemente, elabore un algoritmo que las mezcle in-place produciendo una única lista ordenada del mismo modo.

**Ejemplos:**
| Entrada L1 y L2 | Salida (Lista fusionada) |
| :--- | :--- |
| `L1: [ 10 30 50 ]`, `L2: [ 20 40 60 ]` | `[ 10 20 30 40 50 60 ]` |
| `L1: [ 1 5 ]`, `L2: [ 2 3 ]` | `[ 1 2 3 5 ]` |


**Respuesta: [E02-mezclar-listas-dobles.cpp](../S07-estructuras-multienlazadas/E02-mezclar-listas-dobles.cpp)**

## **E03-suma-anterior-circular**

Implemente una función que recibe una lista circular doblemente enlazada por parámetro y un entero "n", y sume el valor de los $n$ elementos anteriores consecutivamente a cada nodo de la lista.

**Ejemplos:**
| Entrada (Lista y n) | Salida (Lista resultante) |
| :--- | :--- |
| `[ 5 10 15 20 ]` y $n = 2$ | `n3` (15) pasa a ser `30` (sumando los anteriores: 10 y 5) |


**Respuesta: [E03-suma-anterior-circular.cpp](../S07-estructuras-multienlazadas/E03-suma-anterior-circular.cpp)**

## **E04-eliminar-posicion-circular**

Dada una lista circular, implemente:

*   a) Un método que dada una posición lógica inicial $P \ge 1$ y un desplazamiento $d \ge 0$, elimine el elemento que está en la posición $P$ y el elemento en la posición $P+d$ de la lista circular.
*   b) Calcule el orden en tiempo de ejecución de su algoritmo.

**Ejemplos:**
| Entrada (Lista, P y d) | Salida (Lista resultante) |
| :--- | :--- |
| `[ 10 20 30 40 50 ]`, $P = 2, d = 2$ | `[ 10 30 50 ]` (Se eliminan 20 y 40) |


**Respuesta: [E04-eliminar-posicion-circular.cpp](../S07-estructuras-multienlazadas/E04-eliminar-posicion-circular.cpp)**

## **E05-eliminar-importadora**

Se dispone de la información referente a un conjunto de compañías importadoras estructuradas en una lista circular. Diseñe e implemente una función que permita eliminar una importadora determinada de la mesa redonda basándose en su balance financiero.

**Ejemplos:**
| Compañías en la lista (Entrada) | Compañía a Buscar | Umbral | Salida |
| :--- | :--- | :--- | :--- |
| `Alimentos (15000)`, `Metales (4500)`, `Textil (8900)` | `"Metales"` | `5000` | Eliminada (su balance era 4500 < 5000) |


**Respuesta: [E05-eliminar-importadora.cpp](../S07-estructuras-multienlazadas/E05-eliminar-importadora.cpp)**

## **E06-diagonal-esparcida**

Dada una matriz esparcida M de tamaño $N \times N$, elabore un algoritmo que retorne en una lista enlazada simple los elementos no nulos de la diagonal principal.

**Ejemplos:**
| Entrada (Matriz) | Salida (Lista) |
| :--- | :--- |
| `[ 10 | 55 ]`, `[ 0 | 20 ]` en diag | `[ 10 20 ]` |

**Respuesta: [E06-diagonal-esparcida.cpp](../S07-estructuras-multienlazadas/E06-diagonal-esparcida.cpp)**

## **E07-multiplicacion-esparcidas**

Implemente la multiplicación de 2 matrices esparcidas M1 y M2 compatibles. Deje los resultados en una nueva matriz esparcida M3.

**Ejemplos:**
| Matriz A (2x3) | Matriz B (3x2) | Matriz C resultante (2x2) |
| :--- | :--- | :--- |
| `A[0][0]=1, A[0][2]=2, A[1][1]=3` | `B[0][1]=4, B[1][0]=5, B[2][1]=6` | `C[0][1]=16, C[1][0]=15` |


**Respuesta: [E07-multiplicacion-esparcidas.cpp](../S07-estructuras-multienlazadas/E07-multiplicacion-esparcidas.cpp)**

## **E08-imprimir-esparcida**

Implemente una función que recorra y muestre formateadamente en consola todos los elementos no nulos de una matriz esparcida con sus coordenadas de fila y columna correspondientes.

**Ejemplos:**
| Matriz (Entrada) | Salida (Consola) |
| :--- | :--- |
| `matriz.set(0, 1, 3.14)` | `Posición (0, 1) -> 3.14` |


**Respuesta: [E08-imprimir-esparcida.cpp](../S07-estructuras-multienlazadas/E08-imprimir-esparcida.cpp)**

## **E09-buscar-esparcida**

Dada una matriz esparcida M y un entero N, elabore un algoritmo que realice la búsqueda de N y retorne sus coordenadas de fila y columna en caso de ser encontrado.

**Ejemplos:**
| Entrada (Matriz y Buscado) | Salida |
| :--- | :--- |
| `matriz` con `99` en (1, 1), busca `99` | Encontrado en posición `(1, 1)` |
| busca `500` | No se encuentra en la matriz |


**Respuesta: [E09-buscar-esparcida.cpp](../S07-estructuras-multienlazadas/E09-buscar-esparcida.cpp)**

## **E10-ejecutivos-mesa-redonda**

Se encuentran $N$ ejecutivos sentados en una mesa redonda (lista circular doble). Cada ejecutivo tiene un nombre y una capacidad de retentiva (entero). Implemente el juego de eliminación de ejecutivos que cuenta la retentiva del ejecutivo actual hacia la derecha, elimina al ejecutivo en esa posición y continúa desde su sucesor, hasta dejar a un ganador único.

**Ejemplos:**
| Ejecutivos e Iniciales (Entrada) | Ganador (Salida) |
| :--- | :--- |
| `Alejandro(2)`, `Beatriz(3)`, `Carlos(1)`, `Daniela(4)`, `Eduardo(2)` | `Alejandro` |


**Respuesta: [E10-ejecutivos-mesa-redonda.cpp](../S07-estructuras-multienlazadas/E10-ejecutivos-mesa-redonda.cpp)**

## **E11-sistema-judicial**

El Poder Judicial ha decidido implementar un sistema que permita llevar un control eficiente de los tribunales y cárceles con que cuenta la nación. Dicho sistema debe satisfacer los requerimientos de listado y consultas.

**Respuesta: [E11-sistema-judicial.md](../S07-estructuras-multienlazadas/E11-sistema-judicial.md)**

## **E12-analisis-matriz-esparcida**

Dada una matriz de 100x100 donde solo el 10% de sus elementos son distintos de cero. Calcule y compare la memoria necesaria frente a la matriz estática para dimensiones de 100x100 y 1000x1000.

**Respuesta: [E12-analisis-matriz-esparcida.md](../S07-estructuras-multienlazadas/E12-analisis-matriz-esparcida.md)**

## **E13-analisis-representacion-esparcida**

¿Qué ventajas y desventajas tiene utilizar una estructura doblemente enlazada para los elementos de una matriz esparcida (proxFila, prevFila, proxCol, prevCol) con respecto a punteros simples? ¿Qué operaciones se benefician?

**Respuesta: [E13-analisis-representacion-esparcida.md](../S07-estructuras-multienlazadas/E13-analisis-representacion-esparcida.md)**

## **E14-servicios-clientes**

Proponga una representación utilizando estructuras enlazadas para modelar el caso de DigitelUCV (Clientes contratando múltiples servicios).

**Respuesta: [E14-servicios-clientes.md](../S07-estructuras-multienlazadas/E14-servicios-clientes.md)**
