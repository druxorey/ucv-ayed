<h1 align="center">Ventajas y Desventajas de la Recursividad</h1>

> [!TLDR]
> La recursividad produce código **elegante**, pero consume **más memoria** (riesgo de stack overflow), es **más lenta** que la iteración y **más difícil de depurar**.

## Enunciado

Enumere brevemente las ventajas y desventajas de la recursividad.

## Ventajas

- **Código Elegante y Conciso:** Para problemas con una naturaleza inherentemente recursiva (como el manejo de árboles o algoritmos de «divide y vencerás»), el código resultante suele ser mucho más corto, limpio y fácil de leer en comparación con una solución iterativa (usando bucles).

- **Simplificación de Problemas Complejos:** Permite descomponer un problema complejo en subproblemas más pequeños y manejables que son idénticos en naturaleza al problema original.

- **Sin Gestión de Estado:** A menudo, se puede evitar la necesidad de gestionar estados complejos con variables temporales, ya que el estado se guarda implícitamente en la pila de llamadas de cada función.

## Desventajas

- **Consumo de Memoria:** Cada llamada a la función crea un nuevo registro en la pila de llamadas (call stack). Una recursividad muy profunda puede agotar la memoria de la pila y provocar un error de **desbordamiento de pila** (stack overflow).

- **Menor Rendimiento:** La sobrecarga asociada con las llamadas a funciones (guardar el estado, pasar parámetros, etc.) puede hacer que las soluciones recursivas sean más lentas que sus equivalentes iterativos.

- **Mayor Dificultad para Depurar:** Seguir el flujo de ejecución a través de múltiples niveles de recursividad puede ser confuso y complicar el proceso de depuración y seguimiento de errores.
