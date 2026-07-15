# Colas y Dipolos

## **E01-diferencia-estructuras**

¿Cuál es la diferencia entre utilizar una cola, una pila o un dipolo? ¿No es lo mismo emplear una lista?

**Respuesta: [E01-diferencia-estructuras.md](../S06-colas-dipolos/E01-diferencia-estructuras.md)**

## **E02-uso-colas**

¿Indique al menos un uso de las colas en una aplicación?

**Respuesta: [E02-uso-colas.md](../S06-colas-dipolos/E02-uso-colas.md)**

## **E03-evaluacion-prefija**

Elabore un procedimiento que acepte como entrada una expresión aritmética simple (secuencia de números y operadores aritméticos: `+`, `-`, `*` y `/`) en notación prefija y realice su evaluación.

**Ejemplos:**
| Entrada | Salida |
| :--- | :--- |
| `* + 10 2 5` | `60.0` (Equivale a: (10 + 2) * 5) |
| `- * 4 5 6` | `14.0` (Equivale a: (4 * 5) - 6) |


**Respuesta: [E03-evaluacion-prefija.cpp](../S06-colas-dipolos/E03-evaluacion-prefija.cpp)**

## **E04-cola-arreglo**

Proponga una representación para una cola, empleando un arreglo, de manera tal que el orden de la operación encolar sea $O(1)$, e implemente el algoritmo correspondiente con el uso de su estructura.

**Ejemplos:**
| Operación | Estado de la Cola |
| :--- | :--- |
| `push(10)` | `[ 10 ]` |
| `push(20)` | `[ 10 20 ]` |
| `pop()` | `[ 20 ]` |


**Respuesta: [E04-cola-arreglo.cpp](../S06-colas-dipolos/E04-cola-arreglo.cpp)**

## **E05-promedio-invertido**

Dada una cola, se desea conocer el promedio de los elementos que ella almacena. El programa debe imprimir el promedio y la cola de forma invertida.

**Ejemplos:**
| Entrada | Salida |
| :--- | :--- |
| `[ 10 20 30 40 50 ]` | Promedio: `30.0`, Cola Invertida: `[ 50 40 30 20 10 ]` |
| `[ 5 15 ]` | Promedio: `10.0`, Cola Invertida: `[ 15 5 ]` |


**Respuesta: [E05-promedio-invertido.cpp](../S06-colas-dipolos/E05-promedio-invertido.cpp)**

## **E06-mayor-menor-cola**

Dada una cola de enteros, realice un algoritmo que muestre el elemento mayor y el menor.

**Ejemplos:**
| Entrada | Salida |
| :--- | :--- |
| `[ 15 4 42 8 23 ]` | Mayor: `42`, Menor: `4` |
| `[ -10 5 0 ]` | Mayor: `5`, Menor: `-10` |


**Respuesta: [E06-mayor-menor-cola.cpp](../S06-colas-dipolos/E06-mayor-menor-cola.cpp)**

## **E07-simulacion-pilas-colas**

Realice un algoritmo que simule una pila mediante una cola y realice la suma de los elementos de dicha “pila”. Impleméntelo también simulando una cola a través de una pila.

**Ejemplos:**
| Estructura y Entradas | Operación de Salida / Suma |
| :--- | :--- |
| Pila Simulada con cola: `push(10)`, `push(20)` | `top()` -> `20`, Suma -> `30` |
| Cola Simulada con pilas: `push(100)`, `push(200)` | `front()` -> `100`, `pop()` |


**Respuesta: [E07-simulacion-pilas-colas.cpp](../S06-colas-dipolos/E07-simulacion-pilas-colas.cpp)**

## **E08-invertir-dipolo**

Realice un algoritmo que, dada una palabra almacenada en un dipolo, producir otra nueva en otro dipolo que sea el resultado de invertirla.

**Ejemplos:**
| Entrada | Salida |
| :--- | :--- |
| `[ E s t r u c t u r a s ]` | `[ s a r u t c u r t s E ]` |
| `[ U C V ]` | `[ V C U ]` |


**Respuesta: [E08-invertir-dipolo.cpp](../S06-colas-dipolos/E08-invertir-dipolo.cpp)**

## **E09-deshacer-rehacer**

Proponga una estructura de datos que permita implementar fácilmente un mecanismo de rehacer y deshacer eventos en un sistema.

**Ejemplos:**
| Acción / Entrada | Pila Deshacer (Undo) | Pila Rehacer (Redo) |
| :--- | :--- | :--- |
| `registrar("Accion 1")` | `[ "Accion 1" ]` | `[ ]` (Vacía) |
| `deshacer()` | `[ ]` (Vacía) | `[ "Accion 1" ]` |
| `rehacer()` | `[ "Accion 1" ]` | `[ ]` (Vacía) |


**Respuesta: [E09-deshacer-rehacer.cpp](../S06-colas-dipolos/E09-deshacer-rehacer.cpp)**

## **E10-decimal-a-binario**

Dado un número decimal almacenado en una pila llevarlo a binario y dar el resultado en una cola.

**Ejemplos:**
| Entrada (Pila) | Salida (Cola) |
| :--- | :--- |
| `[ 36 ]` | `[ 1 0 0 1 0 0 ]` |
| `[ 5 ]` | `[ 1 0 1 ]` |


**Respuesta: [E10-decimal-a-binario.cpp](../S06-colas-dipolos/E10-decimal-a-binario.cpp)**

## **E11-cola-medieval**

Una cola medieval se comporta como una cola ordinaria, con la única diferencia de que los elementos almacenados en ella se dividen en dos grupos: nobles y plebeyos. Dentro de cada grupo, los elementos deben ser atendidos en orden de llegada; pero siempre que haya nobles en la cola, estos deben ser atendidos antes que los plebeyos. Implemente una cola medieval heredando de una cola normal, pero sobrescribiendo el método encolar.

**Ejemplos:**
| Acciones de Encolado (Entrada) | Estado de la Cola (Salida) |
| :--- | :--- |
| `Juan (P)`, `Pedro (P)`, `Arturo (N)` | `Arturo (N)` -> `Juan (P)` -> `Pedro (P)` |
| `noble1 (N)`, `plebeyo1 (P)`, `noble2 (N)` | `noble1 (N)` -> `noble2 (N)` -> `plebeyo1 (P)` |


**Respuesta: [E11-cola-medieval.cpp](../S06-colas-dipolos/E11-cola-medieval.cpp)**


## **E12-suma-central-dipolo**
Dado un dipolo de enteros, realice un algoritmo el cual sume los primeros N elementos desde el valor central hacia sus extremos, sin utilizar ninguna estructura de datos auxiliar.

**Ejemplos:**
| Entrada (Dipolo y N) | Salida (Suma) |
| :--- | :--- |
| `[ 1, 5, 6, 7, 3 ]` y $N = 3$ | `18` (6 en el centro, sumado con 5 e izquierdo 7) |
| `[ 2, 4, 6, 8 ]` y $N = 2$ | `10` (Centrales iniciales sumados) |


**Respuesta: [E12-suma-central-dipolo.cpp](../S06-colas-dipolos/E12-suma-central-dipolo.cpp)**

## **E13-extraer-central-dipolo**

Dado un dipolo, realice un algoritmo que extraiga el elemento central de la misma si el dipolo posee un número impar de elementos, o los dos elementos centrales si el dipolo posee un número par de elementos. No asuma que existe una función que retorna la cantidad de elementos del dipolo ni que posee la cantidad de elementos al comenzar el algoritmo.

**Ejemplos:**
| Entrada | Salida (Dipolo resultante) |
| :--- | :--- |
| `[ 5, 3, 8, 1, 6 ]` (Impar) | `[ 5, 3, 1, 6 ]` (Se extrae 8) |
| `[ 5, 3, 8, 9, 1, 6 ]` (Par) | `[ 5, 3, 1, 6 ]` (Se extraen 8 y 9) |


**Respuesta: [E13-extraer-central-dipolo.cpp](../S06-colas-dipolos/E13-extraer-central-dipolo.cpp)**

## **E14-palindromo-dipolo**

Suponga que tiene almacenada una secuencia de caracteres en un dipolo, y se desea saber si dicha secuencia es palíndrome.

**Ejemplos:**
| Entrada | Salida |
| :--- | :--- |
| `[ r e c o n o c e r ]` | `true` |
| `[ u c v ]` | `false` |


**Respuesta: [E14-palindromo-dipolo.cpp](../S06-colas-dipolos/E14-palindromo-dipolo.cpp)**

## **E15-ocurrencias-cola-pila**

Dada una cola de enteros positivos se desea obtener una pila que indique qué elementos están en la cola seguido de las ocurrencias de este.

**Ejemplos:**
| Entrada (Cola) | Salida (Pila de [elemento, frecuencia]) |
| :--- | :--- |
| `[ 2, 3, 2, 5, 3, 2 ]` | `[ 2, 3, 3, 2, 5, 1 ]` (2 aparece 3 veces, 3 aparece 2 veces, 5 aparece 1 vez) |
| `[ 4, 4, 1 ]` | `[ 4, 2, 1, 1 ]` (4 aparece 2 veces, 1 aparece 1 vez) |


**Respuesta: [E15-ocurrencias-cola-pila.cpp](../S06-colas-dipolos/E15-ocurrencias-cola-pila.cpp)**

## **E16-eliminar-negativos-cola**

Dada una cola de enteros, realice un algoritmo que elimine los números negativos sin cambiar los otros elementos de la cola.

**Ejemplos:**
| Entrada (Cola) | Salida (Cola) |
| :--- | :--- |
| `[ 10, -5, 20, -3, -1, 30 ]` | `[ 10, 20, 30 ]` |
| `[ -1, -2, -3 ]` | `[ ]` (Vacía) |


**Respuesta: [E16-eliminar-negativos-cola.cpp](../S06-colas-dipolos/E16-eliminar-negativos-cola.cpp)**
