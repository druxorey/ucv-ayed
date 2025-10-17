# E02 - Ventajas y Desventajas de la Recursividad

> **TLDR**: La recursividad permite escribir código muy **elegante y conciso** para problemas complejos, pero introduce desventajas importantes: consume **más memoria** (con riesgo de *stack overflow*), puede ser **más lenta** que una solución con bucles (iterativa) y a menudo es **más difícil de depurar** debido a sus múltiples niveles de llamadas.

---

## Ventajas y Desventajas de la Recursividad

Aunque es una herramienta poderosa, la recursividad tiene sus pros y sus contras que determinan cuándo es apropiado usarla.

### Ventajas

* **Código Elegante y Conciso:** Para problemas con una naturaleza inherentemente recursiva (como el manejo de árboles o algoritmos de "divide y vencerás"), el código resultante suele ser mucho más corto, limpio y fácil de leer en comparación con una solución iterativa (usando bucles).
* **Simplificación de Problemas Complejos:** Permite descomponer un problema complejo en subproblemas más pequeños y manejables que son idénticos en naturaleza al problema original.
* **Sin Gestión de Estado:** A menudo, se puede evitar la necesidad de gestionar estados complejos con variables temporales, ya que el estado se guarda implícitamente en la pila de llamadas de cada función.

### Desventajas

* **Consumo de Memoria:** Cada llamada a la función crea un nuevo registro en la pila de llamadas (call stack). Una recursividad muy profunda puede agotar la memoria de la pila y provocar un error de **desbordamiento de pila** (stack overflow).
* **Menor Rendimiento:** La sobrecarga asociada con las llamadas a funciones (guardar el estado, pasar parámetros, etc.) puede hacer que las soluciones recursivas sean más lentas que sus equivalentes iterativos.
* **Mayor Dificultad para Depurar:** Seguir el flujo de ejecución a través de múltiples niveles de recursividad puede ser confuso y complicar el proceso de depuración y seguimiento de errores.
