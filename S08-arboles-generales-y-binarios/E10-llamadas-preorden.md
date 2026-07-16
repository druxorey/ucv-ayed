<h1 align="center">E10 - Análisis del Número de Llamadas Recursivas en Preorden</h1>

> [!TLDR]
> Solución A (llamadas ciegas): $2N + 1$ llamadas totales ($N$ exitosas + $N+1$ sobre punteros nulos). Solución B (llamadas validadas): solo $N$ llamadas. La Solución B es más eficiente y evita el riesgo de stack overflow.

## Enunciado

Considere el problema de recorrer un árbol binario en preorden bajo dos soluciones (ciega vs. validada). ¿Cuántas llamadas se realizan en cada caso? Exprese su respuesta en base al número de nodos del árbol.

## 1. Análisis de la Solución A (Llamadas ciegas)

```cpp
void PreOrden (Arbin A) {
    if (! EsVacio(A)) {
        cout << Raiz(A) << endl;
        PreOrden(Izq(A));
        PreOrden(Der(A));
    }
}
```

- **Funcionamiento:** La función realiza la llamada recursiva a los hijos izquierdo y derecho de forma ciega, sin verificar de antemano si los punteros están vacíos. La validación se delega al inicio de la función en la siguiente llamada.

- **Cálculo del número de llamadas:**
    1.  **Llamadas Exitosas:** Para cada uno de los $N$ nodos no vacíos, se hace una llamada exitosa donde se imprime su raíz. Esto da **$N$ llamadas**.
    2.  **Llamadas Nulas:** Un árbol binario de $N$ nodos posee exactamente **$N + 1$ enlaces vacíos** (punteros a `nullptr`). Para cada uno de estos enlaces, el padre realiza una llamada recursiva que inmediatamente retorna al validar `EsVacio(A)`. Esto da **$N + 1$ llamadas**.

- **Total de llamadas (Solución A):**

$$\text{Llamadas Totales}_a = N + (N + 1) = 2N + 1$$

## 2. Análisis de la Solución B (Llamadas validadas)

```cpp
void PreOrden (Arbin A) {
    if (! EsVacio(A)) {
        cout << Raiz(A) << endl;
        if (! EsVacio(Izq(A))) {
            PreOrden(Izq(A));
        }
        if (! EsVacio(Der(A))) {
            PreOrden(Der(A));
        }
    }
}
```

- **Funcionamiento:** Antes de realizar la llamada recursiva, el algoritmo comprueba si el subárbol correspondiente existe (`! EsVacio`). Esto previene la invocación de llamadas sobre punteros nulos.

- **Cálculo del número de llamadas:**
    1.  La llamada inicial sobre la raíz se realiza directamente: **$1$ llamada**.
    2.  Cada uno de los restantes $N - 1$ nodos del árbol solo es invocado cuando su padre comprueba que su puntero es no nulo. Cada nodo se invoca exactamente una vez: **$N - 1$ llamadas**.
    3.  No se realiza ninguna llamada sobre punteros vacíos (`nullptr`).

- **Total de llamadas (Solución B):**

$$\text{Llamadas Totales}_b = 1 + (N - 1) = N$$

## 3. Conclusión Comparativa

- **Solución A:** Realiza $2N + 1$ llamadas.
- **Solución B:** Realiza $N$ llamadas (aproximadamente la mitad).

La **Solución B** es mucho más eficiente en la práctica porque evita la sobrecarga de apilar y desapilar llamadas recursivas nulas en la pila de ejecución del procesador (*call stack*), previniendo problemas de desbordamiento de pila (*stack overflow*) en árboles de gran profundidad.
