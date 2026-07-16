<h1 align="center">E02 - Ventajas y Desventajas de Listas vs. Arreglos</h1>

> [!TLDR]
> Las **listas** tienen tamaño dinámico e inserción $O(1)$ pero sin acceso aleatorio. Los **arreglos** tienen acceso directo $O(1)$ y mejor caché pero tamaño fijo e inserción/eliminación $O(N)$.

## Enunciado

Describa, en general, las ventajas y desventajas del uso de listas con apuntadores con respecto al uso de arreglos.

## Listas

### Ventajas:

1. **Tamaño Dinámico:** La memoria se asigna en tiempo de ejecución nodo por nodo. No es necesario conocer el tamaño máximo de la estructura de antemano.

2. **Inserciones y Eliminaciones Eficientes en $O(1)$:** Una vez posicionados en una dirección de memoria, insertar o remover un nodo requiere simplemente actualizar un par de punteros vecinos. No hay necesidad de mover o desplazar elementos físicamente.

3. **Fácil Redimensionamiento:** Crece y decrece de forma flexible según la demanda real de datos en el Heap.

### Desventajas:

1. **Sin Acceso Aleatorio Directo:** Para acceder al elemento en la posición $k$, es obligatorio recorrer secuencialmente los primeros $k-1$ nodos desde el inicio ($O(N)$).

2. **Mayor Consumo de Memoria:** Cada nodo debe almacenar, además de los datos de usuario, uno o dos punteros de control.

3. **Incompatibilidad con Caché (Falta de Localidad):** Los nodos dinámicos se esparcen en ubicaciones arbitrarias del Heap, provocando fallos de caché de la CPU (*cache misses*) durante el recorrido.

## Arreglos

### Ventajas:

1. **Acceso Directo en $O(1)$:** Cualquier elemento se puede leer o escribir inmediatamente calculando su dirección física directamente mediante aritmética de índices: $\text{dir} = \text{base} + \text{indice} \times \text{tamaño}$.

2. **Alineación Óptima y Localidad:** Al almacenarse de forma contigua en memoria, aprovechan al máximo la caché del procesador.

3. **Cero Sobrecarga de Espacio:** No se consume memoria en punteros de enlace; solo se guarda la carga útil.

### Desventajas:

1. **Tamaño Fijo Estático:** Debe predefinirse un tamaño máximo en su declaración. Si la entrada sobrepasa este tamaño, se produce un desbordamiento; si la entrada es pequeña, se desperdicia memoria.

2. **Inserción y Eliminación Costosas en $O(N)$:** Insertar o eliminar en una posición intermedia requiere desplazar físicamente todos los elementos siguientes para mantener la contigüidad.

3. **Costo de Redimensionamiento Dinámico:** Si es un vector dinámico, duplicar su capacidad requiere reservar un nuevo arreglo más grande y copiar todos los elementos uno por uno ($O(N)$).
