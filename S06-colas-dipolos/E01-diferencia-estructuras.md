<h1 align="center">E01 - Diferencias entre Lista, Pila, Cola y Dipolo</h1>

> [!TLDR]
> Pila (LIFO): solo por el tope. Cola (FIFO): entrada por el final, salida por el frente. Dipolo: ambos extremos. Lista: cualquier posición. Sus restricciones de acceso **garantizan la integridad** del flujo de datos y no son equivalentes entre sí.

## Enunciado

¿Cuál es la diferencia entre utilizar una cola, una pila o un dipolo? ¿No es lo mismo emplear una lista?

## Definiciones de las Estructuras

- **Pila (Stack):** Es una estructura de acceso restringido LIFO (Last In, First Out). Las inserciones (`push`) y eliminaciones (`pop`) se realizan obligatoriamente por un único extremo denominado **tope**.

- **Cola (Queue):** Es una estructura de acceso restringido FIFO (First In, First Out). Las inserciones (`push/enqueue`) se realizan por el extremo final (**rear**) y las eliminaciones (`pop/dequeue`) por el extremo inicial (**front**).

- **Dipolo o Bicola (Deque - Double-ended Queue):** Es una cola de doble extremo. Permite insertar y eliminar elementos por ambos extremos (tanto por el principio como por el final), ofreciendo mayor flexibilidad sin llegar a ser una lista de acceso aleatorio.

- **Lista Enlazada (List):** Es una secuencia de nodos enlazados donde es posible insertar, acceder o eliminar elementos en **cualquier posición lógica** (al principio, al final o en posiciones intermedias) mediante navegación con iteradores o punteros.

## 2. Tabla Comparativa de Características


| Estructura | Inserción | Eliminación | Acceso | ¿No es lo mismo que usar una Lista? |
| :--- | :--- | :--- | :--- | :--- |
| **Pila** | Solo por el Tope ($O(1)$) | Solo por el Tope ($O(1)$) | Solo al Tope ($O(1)$) | **No.** La lista permite accesos aleatorios que violan la restricción LIFO. |
| **Cola** | Solo al Final ($O(1)$) | Solo al Inicio ($O(1)$) | Solo al Inicio ($O(1)$) | **No.** La lista permite romper la regla de llegada (FIFO) insertando en medio. |
| **Dipolo** | Por Inicio y Final ($O(1)$) | Por Inicio y Final ($O(1)$) | Por Inicio y Final ($O(1)$) | **No.** El dipolo restringe operaciones a los extremos, la lista opera en cualquier parte. |
| **Lista** | Cualquier posición ($O(1)$ conocido) | Cualquier posición ($O(1)$ conocido) | Secuencial ($O(N)$) | **Base conceptual.** La lista es la estructura generalizada de la que derivan el resto. |


## 3. Conclusión

¿No es lo mismo emplear una lista? Conceptualmente, una lista doblemente enlazada puede simular a las demás estructuras porque posee todas sus operaciones. Sin embargo, en el diseño de software **las restricciones son virtudes**:

- Usar una **Pila** o **Cola** garantiza la seguridad del flujo de datos, impidiendo que elementos intermedios sean alterados o eliminados accidentalmente.

- Simplifica la interfaz de programación (API) y optimiza el uso de recursos para el patrón de diseño específico.
