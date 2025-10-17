# E01 - El Concepto de Backtracking

> **TLDR**: La **búsqueda exhaustiva** en backtracking es como intentar resolver un laberinto  maze explorando sistemáticamente **cada camino posible**, uno por uno. Cuando llegas a un callejón sin salida, «retrocedes» (*backtrack*) al último cruce donde tomaste una decisión y pruebas una ruta diferente, asegurándote de no dejar ninguna piedra sin remover hasta encontrar la salida o confirmar que no existe.

---

## La Búsqueda Exhaustiva en Backtracking

En el contexto de un algoritmo de backtracking, la **«búsqueda exhaustiva»** (a menudo llamada búsqueda de fuerza bruta) es la estrategia de explorar de manera metódica y completa **todas las posibles configuraciones o soluciones** a un problema para encontrar la correcta.

No es una búsqueda al azar, sino un proceso ordenado. El algoritmo construye una solución candidata paso a paso y, en cada nivel, evalúa si el camino actual sigue siendo viable.

* **Si el camino es prometedor**, continúa avanzando, añadiendo el siguiente paso a la solución.
* **Si el camino viola alguna de las reglas del problema o llega a un punto muerto**, el algoritmo se detiene, descarta ese último paso y «retrocede» (hace *backtrack*) para probar la siguiente alternativa disponible en el paso anterior.

Este proceso garantiza que el algoritmo eventualmente considerará todas las combinaciones posibles. La «exhaustividad» no significa que siempre construya todas las soluciones hasta el final, su inteligencia radica en **«podar»** el árbol de búsqueda, descartando ramas enteras de soluciones potenciales tan pronto como se da cuenta de que no conducirán a un resultado válido, lo que lo hace mucho más eficiente que una simple fuerza bruta.
