<h1 align="center">E11 - Algoritmo para la Operación Selectora (k-ésimo Menor)</h1>

> [!TLDR]
> El algoritmo **Mediana de Medianas** encuentra el k-ésimo menor en $O(N)$ garantizado. Agrupa el arreglo en bloques de 5, calcula medianas de medianas como pivote y particiona recursivamente, acotando la recurrencia a $T(N) \le T(N/5) + T(7N/10) + O(N)$.

## Enunciado

Suponga que cuenta con un arreglo desordenado de enteros. Se desea implementar una operación selectora, que dado un parámetro k, retorna el entero correspondiente a la posición k del arreglo si este estuviera ordenado (obviamente, sin ordenarlo). Defina un algoritmo que sea eficiente y determinístico, es decir, dado cierto k y cualquier arreglo, el tiempo de búsqueda sea el mismo. Calcule formalmente la complejidad en tiempo del programa.

## Respuesta

El algoritmo clásico para este problema es **Quickselect** (basado en la partición de Quicksort), pero en el peor caso su complejidad es $O(N^2)$. Para asegurar un comportamiento estrictamente lineal y determinístico de $O(N)$ en el peor de los casos para cualquier entrada, se utiliza el algoritmo de **Mediana de Medianas** (Blum-Floyd-Pratt-Rivest-Tarjan).

### Pasos del Algoritmo:

1. **Agrupación:** Dividir el arreglo de $N$ elementos en $\lceil N / 5 \rceil$ subgrupos, donde cada subgrupo contiene exactamente 5 elementos (el último subgrupo puede tener menos).

2. **Medianas Locales:** Ordenar individualmente cada subgrupo de 5 elementos (este ordenamiento toma tiempo constante $O(1)$ porque el tamaño de entrada de cada grupo es fijo en 5) y extraer su mediana.

3. **Mediana de Medianas:** Encontrar recursivamente la mediana de las $\lceil N / 5 \rceil$ medianas obtenidas en el paso anterior. Llamemos a este elemento el pivote $x$.

4. **Partición:** Particionar el arreglo original alrededor del pivote $x$ en tres subarreglos:
    - $L$: Elementos menores que $x$.
    - $E$: Elementos iguales a $x$.
    - $G$: Elementos mayores que $x$.

5.  **Decisión:**
    - Si $k \le |L|$, buscar recursivamente el k-ésimo elemento en $L$.
    - Si $|L| < k \le |L| + |E|$, retornar el pivote $x$.
    - Si $k > |L| + |E|$, buscar recursivamente el $(k - |L| - |E|)$-ésimo elemento en $G$.

## Análisis Formal de Complejidad

Definamos la función de recurrencia $T(N)$ para el tiempo de ejecución:

1. **División y ordenación de subgrupos (Pasos 1 y 2):** Se procesan $\lceil N / 5 \rceil$ grupos, ordenando 5 elementos en cada uno. Esto toma tiempo lineal: $O(N)$.

2. **Encontrar la mediana de las medianas (Paso 3):** Es una llamada recursiva sobre un arreglo de tamaño $N/5$: $T(N/5)$.

3. **Partición (Paso 4):** Se realiza en un único recorrido lineal sobre el arreglo: $O(N)$.

4. **Llamada recursiva de búsqueda (Paso 5):** Por la construcción de la mediana de medianas, se garantiza que al menos la mitad de las medianas del paso 2 son menores o iguales al pivote $x$. Esto equivale a al menos la mitad de los $\lceil N / 5 \rceil$ grupos, es decir, al menos:

$$3 \cdot \left( \frac{1}{2} \cdot \frac{N}{5} \right) = \frac{3}{10} N \text{ elementos}$$

Son menores o iguales a $x$. Por simetría, también al menos $\frac{3}{10} N$ elementos son mayores o iguales a $x$. Por tanto, en el peor caso, el subarreglo en el que buscamos de forma recursiva tendrá a lo sumo:

$$N - \frac{3}{10} N = \frac{7}{10} N \text{ elementos}$$

Lo cual nos da la recurrencia: $T(\frac{7}{10} N)$.

### Ecuación de Recurrencia:

$$T(N) \le T\left(\frac{N}{5}\right) + T\left(\frac{7N}{10}\right) + c \cdot N$$

### Resolución de la Recurrencia:

Dado que la suma de las fracciones de las llamadas recursivas es menor que 1:

$$\frac{1}{5} + \frac{7}{10} = \frac{2}{10} + \frac{7}{10} = \frac{9}{10} < 1$$

Podemos demostrar por inducción matemática que la solución a esta recurrencia es lineal:

$$T(N) = O(N)$$

Esto garantiza un tiempo de ejecución eficiente y acotado linealmente para cualquier entrada.
