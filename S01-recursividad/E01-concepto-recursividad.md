# E01 - El Concepto de la Recursividad

> **TLDR**: La **recursividad** es un método donde la solución a un problema depende de soluciones a versiones más pequeñas del mismo problema, en programación, esto se logra cuando una función se llama a sí misma. Para evitar un bucle infinito, toda función recursiva necesita un **caso base**, que es la condición que detiene las llamadas, y un **paso recursivo**, donde se vuelve a llamar con un problema modificado que se acerca a ese caso base. Cada una de estas llamadas anidadas representa un **nivel de recursividad**, similar a preguntar a la persona de adelante en una fila cuántas personas hay al frente, donde cada pregunta es un nivel más profundo hasta llegar al primero (el caso base), y la respuesta «rebota» hacia atrás.

---

## ¿Qué es la Recursividad?

La recursividad es un concepto fundamental en matemáticas y ciencias de la computación que describe un proceso en el cual la solución a un problema depende de soluciones a instancias más pequeñas del mismo problema. En términos más simples, es una técnica donde una función se llama a sí misma para realizar una tarea.

Imagina que tienes una muñeca rusa (matrioska). Para abrir la muñeca grande, primero debes abrir la muñeca un poco más pequeña que está dentro. Y para abrir esa, necesitas abrir la que le sigue en tamaño, y así sucesivamente, hasta que llegas a la muñeca más pequeña que ya no se puede abrir. Este proceso es análogo a la recursividad.

En programación, una función recursiva funciona de manera similar. Debe tener dos componentes clave:

* **Caso Base:** Es la condición que detiene la recursividad. Es el equivalente a la muñeca más pequeña que no contiene otra dentro. Sin un caso base, la función se llamaría a sí misma infinitamente, causando un error.
* **Paso Recursivo:** Es la parte de la función donde se llama a sí misma, pero con una entrada que la acerca un paso más al caso base. Es el acto de abrir una muñeca para encontrar una versión ligeramente más pequeña de sí misma.

Un ejemplo clásico es el cálculo del factorial de un número. El factorial de un número entero no negativo `n`, denotado como `n!`, es el producto de todos los enteros positivos menores o iguales a `n`.

* El **caso base** es `0! = 1`.
* El **paso recursivo** es `n! = n * (n-1)!`.

Como puedes ver, para calcular `5!`, necesitas calcular `4!`, y para eso necesitas `3!`, y así hasta llegar al caso base de `0!`.

## ¿Qué Significan los Niveles de Recursividad?

Los **niveles de recursividad** se refieren a la **profundidad** de las llamadas a funciones anidadas antes de alcanzar el caso base. Cada vez que una función recursiva se llama a sí misma, desciende un nivel más profundo en la recursión. Cuando se alcanza el caso base, el proceso se invierte, y cada función retorna su resultado al nivel superior del que fue llamada.

Usando la analogía de las muñecas rusas:

* **Nivel 0:** La muñeca más grande y externa.
* **Nivel 1:** La primera muñeca que encuentras dentro.
* **Nivel 2:** La muñeca dentro de la del Nivel 1.
* Y así sucesivamente hasta el último nivel, que corresponde al caso base (la muñeca más pequeña).

Cada llamada recursiva crea una nueva instancia de la función con su propio conjunto de variables locales en la pila de llamadas (call stack) de la computadora. El número de estas instancias apiladas en un momento dado representa el nivel actual de recursividad. Si los niveles se vuelven demasiado profundos (demasiadas llamadas recursivas sin llegar a un caso base), puede ocurrir un error conocido como «desbordamiento de pila» (stack overflow), ya que la memoria asignada para estas llamadas se agota.
