<h1 align="center">E17 - Análisis de Memoria y Algoritmos del Festival OTI</h1>

> [!TLDR]
> Un `Cantante` ocupa 530 bytes; el arreglo de 20 elementos ocupa 10,600 bytes (~10.35 KB). El algoritmo para contar invitados es $O(N)$ en tiempo y $O(1)$ en espacio; el de obtener el ganador también es $O(N)$ tiempo y $O(1)$ espacio.

## Enunciado

Para el festival OTI de este año se diseñó la siguiente estructura:

```cpp
struct Cantante {
    char nombre[512];
    char paisOrig[10];
    char nomCanc;
    char autor;
    int puntosObt;
    bool sexo;
    bool esInvitado;
};
Cantante festival[20];
```

- a) Calcule la cantidad de memoria requerida para la estructura del objeto `festival`.
- b) Realice un algoritmo que indique el número de invitados que se encontraban en el festival (asuma que el arreglo es de tamaño N). Calcule la complejidad en tiempo del mismo.
- c) Realice un algoritmo que permita saber los datos del participante que haya obtenido el mayor puntaje. Calcule la complejidad en tiempo del mismo.

## Respuesta

### Parte a) Cálculo de Memoria Requerida

Calculamos el tamaño neto en memoria de un objeto del tipo `Cantante` sumando sus campos primitivos:

- `nombre`: $512 \times \text{size}(char) = 512 \times 1 \text{ byte} = 512 \text{ bytes}$
- `paisOrig`: $10 \times \text{size}(char) = 10 \times 1 \text{ byte} = 10 \text{ bytes}$
- `nomCanc`: $1 \times \text{size}(char) = 1 \text{ byte}$
- `autor`: $1 \times \text{size}(char) = 1 \text{ byte}$
- `puntosObt`: $1 \times \text{size}(int) = 4 \text{ bytes}$
- `sexo`: $1 \times \text{size}(bool) = 1 \text{ byte}$
- `esInvitado`: $1 \times \text{size}(bool) = 1 \text{ byte}$

$$\text{Tamaño de Cantante} = 512 + 10 + 1 + 1 + 4 + 1 + 1 = 530 \text{ bytes}$$

Dado que el arreglo `festival` almacena exactamente 20 elementos de tipo `Cantante`:

$$\text{Memoria total del arreglo} = 20 \times 530 \text{ bytes} = 10,600 \text{ bytes} \approx 10.35 \text{ KB}$$

*(Nota: Si el compilador aplica alineación de palabra a 4 bytes, el tamaño del struct podría redondearse al múltiplo de 4 superior inmediato, pero el cálculo neto directo es el estándar en los exámenes del curso).*

### Parte b) Algoritmo para Contar Invitados

```cpp
int contarInvitados(Cantante array[], int N) {
    int totalInvitados = 0;
    for (int i = 0; i < N; i++) {
        if (array[i].esInvitado) {
            totalInvitados++;
        }
    }
    return totalInvitados;
}
```

- **Complejidad en Tiempo:** El algoritmo realiza un único ciclo que itera $N$ veces comparando un campo booleano, por lo que su complejidad temporal es **lineal**: $O(N)$.

- **Complejidad en Espacio:** Utiliza una cantidad constante de variables auxiliares, por lo que su complejidad espacial es **constante**: $O(1)$.

### Parte c) Algoritmo para Obtener el Participante con Mayor Puntaje

```cpp
Cantante obtenerGanador(Cantante array[], int N) {
    if (N <= 0) {
        throw std::invalid_argument("El festival no tiene cantantes");
    }
    
    int indiceGanador = 0;
    int maxPuntaje = array[0].puntosObt;
    
    for (int i = 1; i < N; i++) {
        if (array[i].puntosObt > maxPuntaje) {
            maxPuntaje = array[i].puntosObt;
            indiceGanador = i;
        }
    }
    return array[indiceGanador];
}
```

- **Complejidad en Tiempo:** Recorre el arreglo de tamaño $N$ realizando una comparación numérica por elemento. Su complejidad temporal es **lineal**: $O(N)$.

- **Complejidad en Espacio:** Usa memoria constante: $O(1)$.
