# Árboles Generales y Binarios

## **E01-suma-entre-niveles**

Usando las primitivas de árboles generales, desarrolle una función que retorne la suma de todos los enteros comprendidos entre dos niveles $A$ y $B$ (inclusive).

**Ejemplos:**
| Estructura del Árbol (Entrada) | Rango de Niveles | Salida (Suma) |
| :--- | :--- | :--- |
| Nivel 0: `[10]`, Nivel 1: `[20, 30]`, Nivel 2: `[40, 50]` | De $1$ a $2$ | `140` (20 + 30 + 40 + 50) |
| Nivel 0: `[10]`, Nivel 1: `[20, 30]`, Nivel 2: `[40, 50]` | De $0$ a $1$ | `60` (10 + 20 + 30) |


**Respuesta: [E01-suma-entre-niveles.cpp](../S08-arboles-generales-y-binarios/E01-suma-entre-niveles.cpp)**

## **E02-arbol-semi-completo**

Digamos que un árbol general es semi-completo cuando sus nodos no hojas (internos) tienen exactamente el mismo grado. Empleando las primitivas de árbol general, elabore un algoritmo que permita saber si un árbol es semi-completo (el grado del árbol no se conoce de antemano).

**Ejemplos:**
| Estructura del Árbol (Entrada) | Salida (¿Es Semi-Completo?) |
| :--- | :--- |
| Nivel 0: `[1]`, Nivel 1: `[2, 3]`, Nivel 2 de 2: `[4, 5]`, Nivel 2 de 3: `[6, 7]` | `true` (Todos los internos tienen grado 2) |
| Nivel 0: `[1]`, Nivel 1: `[2, 3]`, Nivel 2 de 2: `[4]`, Nivel 2 de 3: `[6, 7]` | `false` (Un interno tiene grado 1, otro grado 2) |


**Respuesta: [E02-arbol-semi-completo.cpp](../S08-arboles-generales-y-binarios/E02-arbol-semi-completo.cpp)**

## **E03-inorden-preorden-desde-postorden**

Elabore los recorridos en inorden (también llamado simétrico) y preorden de árboles generales usando solamente el recorrido en postorden (es decir, debe reconstruir la estructura a partir de la secuencia postorden y sus grados, y luego imprimir las otras dos).

**Ejemplos:**
| Entrada (Postorden y Grados) | Salida (Recorridos) |
| :--- | :--- |
| Postorden: `[ D, E, B, C, A ]`, Grados: `[ 0, 0, 2, 0, 2 ]` | Preorden: `[ A B D E C ]`, Inorden: `[ D B E A C ]` |


**Respuesta: [E03-inorden-preorden-desde-postorden.cpp](../S08-arboles-generales-y-binarios/E03-inorden-preorden-desde-postorden.cpp)**

## **E04-primos-arbol-genealogico**

Se tiene un árbol genealógico representado gráficamente como un nodo raíz que representa al abuelo/cabeza de familia, cuyos descendientes forman la estructura del árbol. Implemente la operación primos que, dado el nombre de una persona, imprima a todos sus primos (hijos de los hermanos de su padre).

**Ejemplos:**
| Familia / Árbol (Entrada) | Persona Buscada | Salida (Primos) |
| :--- | :--- | :--- |
| Pedro tiene a Jose y Luis. Jose tiene a Juan y Ana. Luis tiene a Santiago. | `"Santiago"` | `"Juan"`, `"Ana"` (hijos de Jose, hermano de Luis) |


**Respuesta: [E04-primos-arbol-genealogico.cpp](../S08-arboles-generales-y-binarios/E04-primos-arbol-genealogico.cpp)**

## **E05-podar-hojas**

Usando las primitivas de árboles generales, implemente la operación `PodarHojas`, la cual consiste en eliminar todos aquellos nodos que son hojas en el árbol.

**Ejemplos:**
| Árbol Inicial (Preorden) | Árbol Resultante (Preorden) |
| :--- | :--- |
| `[ 10 20 40 50 30 ]` (Hojas: 40, 50, 30) | `[ 10 20 ]` |


**Respuesta: [E05-podar-hojas.cpp](../S08-arboles-generales-y-binarios/E05-podar-hojas.cpp)**

## **E06-valor-productoria**

Elabore un algoritmo empleando las primitivas de árbol binario, que retorne el siguiente valor recorriendo cada nodo una sola vez:
$$\text{Valor}(A) = \text{Productoria}(\text{izquierdo}(A)) - \text{Productoria}(\text{derecho}(A))$$

**Ejemplos:**
| Árbol (Raíz 5) | Subárbol Izq (2 y 3) | Subárbol Der (4 y 1) | Salida (Diferencia) |
| :--- | :--- | :--- | :--- |
| `raiz` | Prod = 6 | Prod = 4 | `2` (6 - 4) |


**Respuesta: [E06-valor-productoria.cpp](../S08-arboles-generales-y-binarios/E06-valor-productoria.cpp)**

## **E07-representacion-estatica**

Considere la representación estática de árboles consistente en almacenar el recorrido en postorden definido en un arreglo (además de tener el grado de cada nodo). ¿Qué desventajas podría tener este enfoque de almacenamiento estático? Basado en esta representación defina las primitivas de `Primer_Hijo`, `Hermano_Der` y `Padre`.

**Respuesta: [E07-representacion-estatica.md](../S08-arboles-generales-y-binarios/E07-representacion-estatica.md)**

## **E08-afirmaciones-verdaderas-falsas**

Indique cuáles de las afirmaciones dadas en el enunciado son verdaderas o falsas y justifique su respuesta con argumentos y contraejemplos.

**Respuesta: [E08-afirmaciones-verdaderas-falsas.md](../S08-arboles-generales-y-binarios/E08-afirmaciones-verdaderas-falsas.md)**

## **E09-orden-recorridos**

Generalice la forma de los árboles binarios cuyos nodos aparecen exactamente en el mismo orden en los recorridos de:

*   a. Preorden y Simétrico.
*   b. Postorden y Simétrico.
*   c. Preorden y Postorden.

**Respuesta: [E09-orden-recorridos.md](../S08-arboles-generales-y-binarios/E09-orden-recorridos.md)**

## **E10-llamadas-preorden**

Considere el problema de recorrer un árbol binario en preorden bajo dos soluciones (ciega vs. validada). ¿Cuántas llamadas se realizan en cada caso? Exprese su respuesta en base al número de nodos del árbol.

**Respuesta: [E10-llamadas-preorden.md](../S08-arboles-generales-y-binarios/E10-llamadas-preorden.md)**

## **E11-general-a-binario**

Dada la representación de árboles generales, elabore un algoritmo que, dado un árbol general, produzca su equivalente en un árbol binario usando el estándar Left-Child Right-Sibling (LCRS).

**Ejemplos:**
| Árbol General | Equivalencia LCRS (Preorden) |
| :--- | :--- |
| `10` con hijos `[20, 30]` | `10` (izq -> `20`, der de 20 -> `30`) |


**Respuesta: [E11-general-a-binario.cpp](../S08-arboles-generales-y-binarios/E11-general-a-binario.cpp)**

## **E12-inorden-no-recursivo**

Realice un algoritmo iterativo (sin recursión) empleando una pila que permita recorrer un árbol binario en orden Simétrico (Inorden).

**Ejemplos:**
| Árbol Binario | Salida Recorrido Inorden |
| :--- | :--- |
| Raíz: 10, izq: 5 (con hijo 2 y 7), der: 15 | `[ 2 5 7 10 15 ]` |


**Respuesta: [E12-inorden-no-recursivo.cpp](../S08-arboles-generales-y-binarios/E12-inorden-no-recursivo.cpp)**

## **E13-operaciones-arbin**

Desarrolle las operaciones `EsHoja` y `EsPadre` utilizando las primitivas de árbol binario. Indique las modificaciones necesarias para que `EsPadre` sea de tiempo constante $O(1)$.

**Ejemplos:**
| Operación | Salida |
| :--- | :--- |
| `EsHoja(15)` | `true` |
| `EsPadre(10, 5)` | `true` |


**Respuesta: [E13-operaciones-arbin.cpp](../S08-arboles-generales-y-binarios/E13-operaciones-arbin.cpp)**

## **E14-arbol-binario-completo**

Utilizando las primitivas de la clase Arbin elabore un algoritmo que verifique si un árbol binario es estrictamente completo.

**Ejemplos:**
| Estructura del Árbol (Entrada) | Salida (¿Es completo?) |
| :--- | :--- |
| `10` con hijos `[5, 15]` | `true` (Todos tienen 2 hijos) |
| `10` con hijo izquierdo `[5]` | `false` (10 tiene un solo hijo) |


**Respuesta: [E14-arbol-binario-completo.cpp](../S08-arboles-generales-y-binarios/E14-arbol-binario-completo.cpp)**

## **E15-verificar-subarbol**

Escriba una función que indique si un árbol binario $S$ está incluido en un árbol binario $T$, en cuyo caso debe retornar la dirección física del subárbol de $T$ que es idéntico a $S$.

**Ejemplos:**
| Árbol T | Subárbol S | Salida (Dirección) |
| :--- | :--- | :--- |
| `T: 10->(5->(2,7), 15)` | `S: 5->(2,7)` | Dirección de la raíz del nodo `5` en `T` |


**Respuesta: [E15-verificar-subarbol.cpp](../S08-arboles-generales-y-binarios/E15-verificar-subarbol.cpp)**

## **E16-verificar-simetria**

Escriba un algoritmo que verifique si un árbol binario es simétrico (su subárbol izquierdo y derecho son imágenes especulares).

**Ejemplos:**
| Estructura (Entrada) | Salida (¿Es Simétrico?) |
| :--- | :--- |
| `1` con izq `(2->(3,null))` y der `(2->(null,3))` | `true` |
| `1` con izq `(2->(null,3))` y der `(2->(null,3))` | `false` |


**Respuesta: [E16-verificar-simetria.cpp](../S08-arboles-generales-y-binarios/E16-verificar-simetria.cpp)**

## **E17-verificar-ascendiente**

Escriba una función recursiva eficiente que verifique si el nodo $X$ es ascendiente del nodo $Y$ en un árbol binario.

**Ejemplos:**
| Árbol / Nodos | Salida |
| :--- | :--- |
| Raíz `10`, `nodo5`, `nodo2`. Busca: `10` es ancestro de `2` | `true` |
| Busca: `15` es ancestro de `2` | `false` |


**Respuesta: [E17-verificar-ascendiente.cpp](../S08-arboles-generales-y-binarios/E17-verificar-ascendiente.cpp)**

## **E18-prefijo-a-infijo**

Dada una expresión aritmética en notación prefija almacenada en un árbol de expresión, implemente un algoritmo que la recorra para imprimir su equivalente en notación infija parentizada.

**Ejemplos:**
| Entrada (Árbol Prefijo) | Salida (Infijo) |
| :--- | :--- |
| `* (+ A B) C` | `((A + B) * C)` |
| `+ 3 4` | `(3 + 4)` |


**Respuesta: [E18-prefijo-a-infijo.cpp](../S08-arboles-generales-y-binarios/E18-prefijo-a-infijo.cpp)**
