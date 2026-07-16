<h1 align="center">E12 - Análisis de Memoria de Matrices Esparcidas</h1>

> [!TLDR]
> La matriz 100×100 al 10%: 22,400 bytes (ahorro del 44% vs 40,000 bytes estática). Matriz 1000×1000 al 1%: 224,000 bytes (ahorro del 94.4% vs ~3.81 MB estática). La ventaja crece exponencialmente con la densidad decreciente.

## Enunciado

Dada una matriz de 100x100 donde solo el 10% de sus elementos son distintos de cero. Calcule y compare la memoria necesaria frente a la matriz estática para dimensiones de 100x100 y 1000x1000.

## Modelo de Tamaños (Arquitectura de 32 bits estándar)

Para calcular el tamaño físico en bytes, asumimos:

- Puntero (`pointer`): $4 \text{ bytes}$
- Entero (`int`): $4 \text{ bytes}$
- Número real (`float`): $4 \text{ bytes}$

### Estructuras de Nodos:

1. **Cabecera de Fila (`RowHeader`):** Contiene el índice de fila ($4 \text{ bytes}$), puntero al siguiente encabezado ($4 \text{ bytes}$) y puntero al primer nodo celda ($4 \text{ bytes}$). Total = $12 \text{ bytes}$.

2. **Cabecera de Columna (`ColHeader`):** Contiene el índice de columna ($4 \text{ bytes}$), puntero al siguiente encabezado ($4 \text{ bytes}$) y puntero al primer nodo celda ($4 \text{ bytes}$). Total = $12 \text{ bytes}$.

3. **Nodo Celda (`CellNode`):** Contiene sus índices de fila y columna ($8 \text{ bytes}$), el valor float ($4 \text{ bytes}$), puntero al siguiente nodo en la misma fila ($4 \text{ bytes}$) y puntero al siguiente nodo en la misma columna ($4 \text{ bytes}$). Total = $20 \text{ bytes}$.

## Parte a) Matriz de 100x100 con 10% de elementos no nulos

- **Elementos no nulos (activos):** $100 \times 100 \times 0.10 = 1,000 \text{ celdas}$.
- **Encabezados de Fila:** $100 \times 12 \text{ bytes} = 1,200 \text{ bytes}$.
- **Encabezados de Columna:** $100 \times 12 \text{ bytes} = 1,200 \text{ bytes}$.
- **Nodos Celda:** $1,000 \times 20 \text{ bytes} = 20,000 \text{ bytes}$.

$$\text{Memoria Esparcida Total} = 1,200 + 1,200 + 20,000 = 22,400 \text{ bytes} \approx 21.88 \text{ KB}$$

Una matriz estática de $99 \times 100$ tipo `float` requiere:

$$\text{Memoria Estática} = 100 \times 100 \times 4 \text{ bytes} = 40,000 \text{ bytes} \approx 39.06 \text{ KB}$$

*Ahorro:* Se reduce el uso de memoria en aproximadamente un **$44\%$**.

## Parte b) Matriz de 1000x1000 con 1% de elementos no nulos

- **Elementos no nulos (activos):** $1,000,000 \times 0.01 = 10,000 \text{ celdas}$.
- **Encabezados de Fila:** $1,000 \times 12 \text{ bytes} = 12,000 \text{ bytes}$.
- **Encabezados de Columna:** $1,000 \times 12 \text{ bytes} = 12,000 \text{ bytes}$.
- **Nodos Celda:** $10,000 \times 20 \text{ bytes} = 200,000 \text{ bytes}$.

$$\text{Memoria Esparcida Total} = 12,000 + 12,000 + 200,000 = 224,000 \text{ bytes} \approx 218.75 \text{ KB}$$

Una matriz estática de $1000 \times 1000$ tipo `float` requiere:

$$\text{Memoria Estática} = 1,000,000 \times 4 \text{ bytes} = 4,000,000 \text{ bytes} \approx 3.81 \text{ MB}$$

*Ahorro:* El uso de memoria es de tan solo $218.75 \text{ KB}$ frente a los $3.81 \text{ MB}$ de la representación estática, logrando un ahorro de **$94.4\%$** de memoria.

### Conclusión

A medida que la dimensionalidad de la matriz crece y la densidad de elementos no nulos disminuye, la ventaja en espacio de la representación esparcida frente a la estática se vuelve exponencialmente superior.
