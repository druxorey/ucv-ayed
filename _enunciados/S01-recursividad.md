# Recursividad

## **E01-concepto-recursividad**:

Describa el concepto de recursividad. ¿Qué significan los niveles de recursividad?

**Respuesta: [E01-concepto-recursividad](../S01-recursividad/E01-concepto-recursividad.md)**

## **E02-ventajas-desventajas**:

Enumere brevemente las ventajas y desventajas de la recursividad.

**Respuesta: [E02-ventajas-desventajas](../S01-recursividad/E02-ventajas-desventajas.md)**

## **E03-pilas-recursividad**:

Explique brevemente el funcionamiento de las pilas de recursividad y los ambientes recursivos.

**Respuesta: [E03-pilas-recursividad](../S01-recursividad/E03-pilas-recursividad.md)**

## **E04-solucion-iterativa**:

¿Existen casos donde una solución iterativa es mejor que una solución recursiva para un mismo problema?

**Respuesta: [E04-solucion-iterativa](../S01-recursividad/E04-solucion-iterativa.md)**

## **E05-combinatoria**:

Construya una función recursiva que calcule el valor de la combinatoria de 2 números enteros.

**Ejemplo:**

| Entrada   | Salida                              |
|-----------|-------------------------------------|
| `n=5, k=2` | `10`                              |
| `n=6, k=3` | `20`                              |
| `n=4, k=2` | `6`                               |
| `n=7, k=0` | `1`                               |


**Respuesta: [E05-combinatoria](../S01-recursividad/E05-combinatoria.cpp)**

## **E06-fibonacci-recursivo**:

Dado un número N, desarrolle una función recursiva que calcule la secuencia de números de Fibonacci para N.

**Ejemplo:**

| Entrada   | Salida                              |
|-----------|-------------------------------------|
| `N=5`     | `0, 1, 1, 2, 3`                    |
| `N=7`     | `0, 1, 1, 2, 3, 5, 8`              |
| `N=3`     | `0, 1, 1`                          |
| `N=1`     | `0`                                |


**Respuesta: [E06-fibonacci-recursivo](../S01-recursividad/E06-fibonacci-recursivo.cpp)**

## **E07-conversion-a-binario**:

Dado un número entero positivo o nulo (en base decimal), construya un algoritmo recursivo que tenga por resultado otro número entero cuyo valor sea la representación en binario (en base 2) del valor dado. Haga el mismo proceso para base 16.

**Ejemplo:**

| Entrada   | Salida                              |
|-----------|-------------------------------------|
| `N=5`     | `101`                              |
| `N=10`    | `1010`                             |
| `N=15`    | `1111`                             |
| `N=16`    | `10000`                            |


**Respuesta: [E07-conversion-a-binario](../S01-recursividad/E07-conversion-a-binario.cpp)**

## **E08-palabra-capicua**:

Elabore una función recursiva la cual dado un arreglo de caracteres que forman una palabra retorne verdadero si ésta es capicúa.

**Ejemplo:**

| Entrada   | Salida                              |
|-----------|-------------------------------------|
| `salas`   | `Verdadero`                        |
| `oro`     | `Verdadero`                        |
| `casa`    | `Falso`                            |
| `arepera` | `Verdadero`                        |


**Respuesta: [E08-palabra-capicua](../S01-recursividad/E08-palabra-capicua.cpp)**

## **E09-suma-de-naturales**:

Escriba un algoritmo recursivo que halle la suma de los primeros N números naturales.

**Ejemplo:**

| Entrada   | Salida                              |
|-----------|-------------------------------------|
| `N=5`     | `15`                               |
| `N=10`    | `55`                               |
| `N=3`     | `6`                                |
| `N=1`     | `1`                                |


**Respuesta: [E09-suma-de-naturales](../S01-recursividad/E09-suma-de-naturales.cpp)**

## **E10-maximo-comun-divisor**:

Escriba una función recursiva para calcular el máximo común divisor (m.c.d.) de dos números enteros dados aplicando las propiedades recurrentes.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `a=48, b=18`  | `6`                                |
| `a=56, b=42`  | `14`                               |
| `a=101, b=103`| `1`                                |
| `a=12, b=8`   | `4`                                |


**Respuesta: [E10-maximo-comun-divisor](../S01-recursividad/E10-maximo-comun-divisor.cpp)**

## **E11-factorial-recursivo**:

Escriba una función recursiva para calcular el factorial de un número entero positivo.

**Ejemplo:**

| Entrada   | Salida                              |
|-----------|-------------------------------------|
| `n=5`     | `120`                              |
| `n=4`     | `24`                               |
| `n=3`     | `6`                                |
| `n=0`     | `1`                                |


**Respuesta: [E11-factorial-recursivo](../S01-recursividad/E11-factorial-recursivo.cpp)**

## **E12-potencia-real**:

Escriba una función recursiva para calcular la potencia de un número real elevado a un entero positivo.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `x=2, n=3`    | `8`                                |
| `x=5, n=0`    | `1`                                |
| `x=3, n=2`    | `9`                                |
| `x=7, n=1`    | `7`                                |


**Respuesta: [E12-potencia-real](../S01-recursividad/E12-potencia-real.cpp)**

## **E13-arreglo-operaciones**:

Dado un arreglo de N números enteros, diseñar algoritmos recursivos que calculen:

- El mayor elemento del arreglo.
- La suma de los elementos del arreglo.
- La media de todos los elementos del arreglo.
- Verificar si el arreglo está ordenado.

**Ejemplo:**

| Entrada               | Salida                              |
|-----------------------|-------------------------------------|
| `[1, 2, 3, 4, 5]`     | `Mayor: 5, Suma: 15, Media: 3, Ordenado: Sí` |
| `[5, 3, 1]`           | `Mayor: 5, Suma: 9, Media: 3, Ordenado: No`  |
| `[10, 20, 30]`        | `Mayor: 30, Suma: 60, Media: 20, Ordenado: Sí` |
| `[7, 7, 7]`           | `Mayor: 7, Suma: 21, Media: 7, Ordenado: Sí`  |


**Respuesta: [E13-arreglo-operaciones](../S01-recursividad/E13-arreglo-operaciones.cpp)**

## **E14-busqueda-binaria**:

Elabore un algoritmo recursivo el cual dado un arreglo de enteros ordenado en forma ascendente y sin elementos repetidos, haga una búsqueda binaria de un elemento E indicando si éste existe en el mismo.

**Ejemplo:**

| Entrada               | Salida                              |
|-----------------------|-------------------------------------|
| `Arreglo: [1, 3, 5, 7], E=5` | `Existe`                     |
| `Arreglo: [2, 4, 6, 8], E=3` | `No Existe`                  |
| `Arreglo: [10, 20, 30], E=20`| `Existe`                     |
| `Arreglo: [1, 2, 3], E=4`    | `No Existe`                  |


**Respuesta: [E14-busqueda-binaria](../S01-recursividad/E14-busqueda-binaria.cpp)**

## **E15-ordenar-en-mezcla**:

Escribir un programa recursivo que ordene un arreglo de enteros por el método de Mezcla.

**Ejemplo:**

| Entrada               | Salida                              |
|-----------------------|-------------------------------------|
| `[5, 3, 8, 6]`        | `[3, 5, 6, 8]`                     |
| `[10, 2, 7, 1]`       | `[1, 2, 7, 10]`                    |
| `[4, 3, 2, 1]`        | `[1, 2, 3, 4]`                     |
| `[9, 5, 3, 7]`        | `[3, 5, 7, 9]`                     |


**Respuesta: [E15-ordenar-en-mezcla](../S01-recursividad/E15-ordenar-en-mezcla.cpp)**

## **E16-invertir-digitos-recursivo**:

Escriba una función que invierta los dígitos de un número entero, empleando operaciones sobre números enteros.

**Ejemplo:**

| Entrada   | Salida                              |
|-----------|-------------------------------------|
| `653`     | `356`                              |
| `1234`    | `4321`                             |
| `789`     | `987`                              |
| `100`     | `1`                                |


**Respuesta: [E16-invertir-digitos-recursivo](../S01-recursividad/E16-invertir-digitos-recursivo.cpp)**

## **E17-multiplicacion-recursiva**:

Diseñe una función recursiva la cual, dados dos reales A y B, retorne como resultado la evaluación de A * B usando solo +, -, /.

**Ejemplo:**

| Entrada       | Salida                              |
|---------------|-------------------------------------|
| `A=3, B=4`    | `12`                               |
| `A=5, B=0`    | `0`                                |
| `A=7, B=2`    | `14`                               |
| `A=10, B=3`   | `30`                               |


**Respuesta: [E17-multiplicacion-recursiva](../S01-recursividad/E17-multiplicacion-recursiva.cpp)**

## **E18-paridad-recursiva**:

Desarrolle las funciones lógicas, mutuamente recursivas, EsPar y EsImpar, que se complementen a la hora de averiguar la paridad de un entero positivo.

**Ejemplo:**

| Entrada   | Salida                              |
|-----------|-------------------------------------|
| `N=0`     | `EsPar: Verdadero, EsImpar: Falso` |
| `N=1`     | `EsPar: Falso, EsImpar: Verdadero` |
| `N=2`     | `EsPar: Verdadero, EsImpar: Falso` |
| `N=3`     | `EsPar: Falso, EsImpar: Verdadero` |


**Respuesta: [E18-paridad-recursiva](../S01-recursividad/E18-paridad-recursiva.cpp)**
