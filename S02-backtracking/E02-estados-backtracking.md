# E02 - Estados en Backtracking

> **TLDR**: En backtracking cada llamada recursiva crea un **estado** o ambiente temporal. Este estado es como una foto instantánea que guarda las **variables locales** de la decisión actual «ejemplo: probar el camino a la derecha». También tiene acceso a los **parámetros** que representan la solución construida hasta ahora «el camino recorrido». Al retroceder o hacer backtrack este estado se destruye por completo permitiendo explorar una nueva opción sin dejar rastros.

---

## Estados y Alcance en Backtracking

Cada llamada recursiva en un algoritmo de backtracking crea su propio «universo» de ejecución aislado. Este universo se conoce como **estado** o *stack frame* y es fundamental para que el algoritmo pueda explorar un camino y luego retroceder para probar otro de forma limpia.

Este estado temporal contiene principalmente dos tipos de variables:

### **1. Variables Locales: La Decisión Actual**

Estas son variables que nacen y mueren dentro de la llamada recursiva actual. Representan las opciones específicas que se están evaluando en este punto exacto del problema. Por ejemplo en el problema de las 8 reinas una variable local podría ser `columna_actual` que itera de 0 a 7 para probar dónde colocar la siguiente reina en la fila actual. Cada llamada recursiva tendrá su propia `columna_actual` independiente de las demás.

### **2. Parámetros y Variables de Alcance Superior: El Historial**

Estas variables guardan el progreso general de la solución. Son pasadas de una llamada a la siguiente. Representan las decisiones que ya se han tomado y que nos han traído hasta el estado actual. Siguiendo el ejemplo de las reinas un parámetro sería el tablero de ajedrez ♟️ o una lista con las posiciones de las reinas ya colocadas. La función actual lee este «historial» para tomar decisiones válidas y si avanza pasará una versión actualizada del mismo a la siguiente llamada recursiva.

La magia del backtracking reside en esta separación. Cuando una rama de exploración falla y la función retorna su estado entero «sus variables locales» se elimina de la memoria. El control regresa a la llamada anterior que conserva su propio estado intacto y puede entonces probar una nueva opción local. Este mecanismo de crear y destruir estados en la pila de llamadas es lo que permite al algoritmo retroceder y explorar sistemáticamente todas las posibilidades.
