# E04 - Cómo Saber si Existe una Solución

> **TLDR**: Para saber si un problema tiene solución con backtracking el algoritmo explora caminos recursivamente. Si encuentra **una solución completa** retorna `true`. Este `true` se propaga hacia atrás deteniendo la búsqueda. Si después de explorar **todos los caminos posibles** no encuentra nada la función original retorna `false` lo que significa que no hay ninguna solución.

---

## Determinando si una Solución Existe

Para saber si un problema determinado tiene solución o no se utiliza el esquema de **problema de decisión** de backtracking. El enfoque no busca encontrar la mejor solución ni todas las soluciones solo necesita confirmar la existencia de al menos una. El proceso funciona de la siguiente manera:

### 1. La Función Retorna un Booleano
La función recursiva principal se diseña para que devuelva un valor booleano «`true` o `false`».
* `true` significará «He encontrado una solución desde este punto».
* `false` significará «No hay ninguna solución posible por este camino».

### 2. Búsqueda de la Primera Solución
El algoritmo comienza a construir una solución paso a paso. En cada nivel explora una de las opciones disponibles.

* **Condición de Éxito**: Se define una condición base que si se cumple significa que se ha encontrado una solución completa y válida. Al llegar a este punto la función inmediatamente retorna `true`.

* **Propagación del Éxito**: Cuando una llamada recursiva retorna `true` la función que la llamó sabe que se ha encontrado una solución en esa rama. Ya no necesita probar otras alternativas. Inmediatamente detiene su propia ejecución y también retorna `true` a la función que la llamó a ella. Este `true` se propaga como una reacción en cadena hacia arriba por la pila de llamadas hasta llegar a la llamada original.

### 3. Agotamiento de las Opciones
Si la función prueba todas las opciones disponibles en su nivel y cada una de las llamadas recursivas que hizo le devolvieron `false` significa que ninguna de esas ramas llevó a una solución.

* **Condición de Fracaso**: Una vez que ha agotado todas sus opciones sin éxito la función concluye que no hay solución posible desde su estado actual y retorna `false`.

### El Veredicto Final
La llamada inicial al algoritmo recibirá uno de dos resultados posibles:
* Si recibe `true` significa que en algún punto de la exploración profunda se encontró una solución y la confirmación se propagó hasta el inicio. **El problema tiene solución**.
* Si la llamada inicial termina su ejecución y devuelve `false` significa que exploró absolutamente todo el árbol de posibilidades sin encontrar nunca una solución válida. **El problema no tiene solución**.
