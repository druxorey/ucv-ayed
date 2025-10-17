# E03 - Pilas de Recursividad

> **TLDR**: La **pila de recursividad** (o pila de llamadas) es como una pila de platos donde cada llamada a una función apila un nuevo "plato" en la cima. Cada plato es un **ambiente recursivo** aislado, que contiene sus propias variables y la dirección a la que debe regresar. Cuando una función llega al caso base y termina, su plato se retira, devolviendo el control y el resultado al plato que está debajo, hasta que la pila se vacía por completo.

---

## La Pila de Llamadas y los Ambientes Recursivos

Para que la recursividad funcione sin que las llamadas se mezclen entre sí, los lenguajes de programación utilizan una estructura de datos fundamental llamada **pila de llamadas** (*call stack*).

### Pila de Recursividad (Call Stack)

Imagina una pila de platos: solo puedes añadir o quitar un plato de la parte superior. La pila de llamadas funciona bajo el mismo principio **LIFO** (Last-In, First-Out, "el último en entrar es el primero en salir").

* **Apilar (Push):** Cada vez que se llama a una función (sea recursiva o no), se crea un bloque de información y se coloca en la cima de la pila.
* **Desapilar (Pop):** Cuando una función finaliza su ejecución (con una instrucción `return` o al llegar al final de su código), su bloque de información se retira de la cima de la pila y el control vuelve a la función que se encuentra justo debajo.

### Ambientes Recursivos (Stack Frames)

Ese "bloque de información" que se apila es el **ambiente** de la función, también conocido como *stack frame* o registro de activación. Es como una caja que contiene todo lo que esa instancia particular de la función necesita para operar de forma independiente:

1.  **Parámetros:** Los valores con los que fue llamada (ej. el `5` en `factorial(5)`).
2.  **Variables Locales:** Cualquier variable declarada dentro de esa función.
3.  **Dirección de Retorno:** El punto exacto en el código al que el programa debe volver cuando esta función termine.

La clave de la recursividad es que **cada llamada recursiva crea un ambiente completamente nuevo y separado en la pila**. Por eso, las variables locales de `factorial(5)` no interfieren con las de `factorial(4)`. Cuando `factorial(4)` termina, devuelve su resultado al ambiente de `factorial(5)`, que lo utiliza para completar su propio cálculo antes de ser, a su vez, retirado de la pila. Si la recursividad es demasiado profunda, se apilan tantos ambientes que la memoria asignada se agota, provocando el famoso error **stack overflow**.
