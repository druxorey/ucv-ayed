# E05 - Cómo Encontrar Todas las Soluciones y la Mejor

> **TLDR**: Para encontrar **todas las soluciones** el algoritmo no se detiene al hallar la primera. La guarda en una lista y sigue buscando hasta explorar cada rincón del laberinto. Para encontrar **la mejor solución** el algoritmo guarda la primera que encuentra como «la mejor hasta ahora» y sigue buscando. Cada vez que halla una nueva solución la compara con la guardada y si es superior la reemplaza. Este proceso continúa hasta haber revisado todas las opciones para garantizar que el resultado final es el óptimo.

---

## Determinando el Conjunto Completo de Soluciones

Para encontrar **todo el conjunto de soluciones** de un problema se utiliza el esquema de **enumeración**. El enfoque es muy similar al de encontrar una única solución pero con una diferencia clave: la búsqueda no se detiene al primer éxito.

### 1. No Hay Detención Temprana

A diferencia del esquema de decisión la función recursiva no retorna un valor booleano para detener la ejecución. Generalmente su tipo de retorno es `void` porque su objetivo no es propagar una señal de éxito sino completar su búsqueda.

### 2. Contenedor Global de Soluciones

Se utiliza una estructura de datos externa a la función recursiva «como una lista o un vector» para almacenar todas las soluciones encontradas. Esta estructura se pasa por referencia a través de las llamadas o se declara en un alcance superior.

### 3. Guardar y Continuar

Cuando el algoritmo llega a una **condición de éxito** «es decir ha construido una solución completa y válida» hace lo siguiente:
* **Guarda la solución**: Añade la solución actual al contenedor global.
* **Continúa la búsqueda**: En lugar de detenerse y retornar el algoritmo simplemente continúa. Finge que este camino no fue una solución final para forzar un «retroceso» o *backtrack*. Esto le permite explorar otras ramas del árbol de búsqueda que podrían contener soluciones diferentes.

El proceso solo termina cuando el algoritmo ha explorado exhaustivamente todos los caminos posibles desde la llamada inicial. Al final el contenedor global tendrá todas y cada una de las soluciones válidas del problema.

---

## Determinando la Mejor Solución

Para encontrar **la mejor solución** se usa el esquema de **optimización**. Este método requiere que el algoritmo explore todas las posibilidades pero con un objetivo adicional: llevar un registro de la solución más óptima encontrada hasta el momento.

### 1. Una Variable para la «Mejor Solución»

Se declara una variable en un alcance superior que almacenará la «mejor solución encontrada hasta ahora». También se necesita una variable para registrar el valor o mérito de esa solución «ejemplo: el peso máximo el coste mínimo».

### 2. Encontrar una Solución y Comparar

El algoritmo busca soluciones de la misma manera que en el esquema de enumeración. Sin embargo cada vez que encuentra una solución válida realiza un paso adicional:
* **Evalúa la solución actual**: Calcula su valor o puntuación según el criterio de optimización.
* **Compara con la mejor**: Compara el valor de la solución actual con el de la «mejor solución guardada».
* **Actualiza si es necesario**: Si la solución actual es mejor que la guardada «o si es la primera solución encontrada» se actualiza la variable de la «mejor solución» con la actual.

### 3. Búsqueda Exhaustiva para Garantizar Optimalidad
El algoritmo **no puede detenerse** después de encontrar una o varias soluciones. Debe continuar explorando todo el espacio de búsqueda. Solo después de haber recorrido todas las ramas posibles se puede tener la certeza de que la solución almacenada en la variable «mejor solución» es verdaderamente la óptima.
