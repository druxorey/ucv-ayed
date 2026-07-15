# Complejidad en Tiempo y Espacio

## **E01-dominancia-funciones**

Explique el concepto de dominancia de funciones (gráfica y formalmente). Explique cuál es su fin, es decir, ¿para qué es utilizada?

**Respuesta: [E01-dominancia-funciones](../S03-complejidad/E01-dominancia-funciones.md)**

## **E02-demostraciones-dominancia**

Demuestre formalmente las siguientes propiedades del concepto de dominancia de funciones:
- Si $f(n) = O(g(n))$ y $g(n) = O(h(n))$ entonces $f(n) = O(h(n))$
- $f(n) = O(f(n))$
- Si $f(n) = O(g(n))$ y $g(n) = O(f(n))$ entonces $f(n) = g(n)$ (en orden de magnitud)

**Respuesta: [E02-demostraciones-dominancia](../S03-complejidad/E02-demostraciones-dominancia.md)**

## **E03-definicion-complejidad**

¿Qué entiende usted por el término complejidad en tiempo?

**Respuesta: [E03-definicion-complejidad](../S03-complejidad/E03-definicion-complejidad.md)**

## **E04-orden-teorico-practica**

Si dos algoritmos tienen el mismo orden teórico en tiempo de ejecución, entonces ¿ambos tardarán el mismo tiempo en ejecutarse en la práctica? Suponga que ambos se ejecutan en plataformas totalmente iguales. Explique su respuesta.

**Respuesta: [E04-orden-teorico-practica](../S03-complejidad/E04-orden-teorico-practica.md)**

## **E05-veracidad-afirmacion**

Discuta la veracidad de la siguiente afirmación: $n^2 = O(n \log_2 n)$. En caso de ser cierto, demuéstrelo formalmente. En caso de ser falso, indique dos formas distintas que permitan concluir que dicho razonamiento es erróneo.

**Respuesta: [E05-veracidad-afirmacion](../S03-complejidad/E05-veracidad-afirmacion.md)**

## **E06-hallar-cota-g**

Para las siguientes $f(n)$, halle una cota $g(n)$, y demuestre mediante el concepto de dominancia de funciones que $f(n) = O(g(n))$:

- a) $f(n) = 8n^3 - 576n^2 + 832n - 248$
- b) $f(n) = \ln(a^n) + b$
- c) $f(n) = n^2 - \log_2 n + 7$
- d) $f(n) = an^2 + bn + c$
- e) $f(n) = n + n^2 + n^3$
- f) $f(n) = a2^{bn} + c$
- g) $f(n) = 3^x + \log_2(n + 1)$

**Respuesta: [E06-hallar-cota-g](../S03-complejidad/E06-hallar-cota-g.md)**

## **E07-condicional-o1**

¿Es cierto que el siguiente código:

```cpp
if (Cond) {
    X = X + 1;
} else {
    X = X - 1;
}
```

es de $O(1)$? (justifique en detalle su respuesta)

**Respuesta: [E07-condicional-o1](../S03-complejidad/E07-condicional-o1.md)**

## **E08-condiciones-o1**

¿Bajo qué condiciones es un algoritmo de $O(1)$?

**Respuesta: [E08-condiciones-o1](../S03-complejidad/E08-condiciones-o1.md)**

## **E09-calculo-complejidad-bucles**

Supongamos que el tiempo de ejecución de un procedimiento A es una constante M. Calcular el orden de magnitud de la función complejidad T(n) que mide el tiempo de ejecución de los siguientes algoritmos, donde n es el tamaño de la entrada, y demuestre formalmente mediante el concepto de dominancia de funciones cuál es su complejidad.

### Algoritmo 1:

```cpp
int I = 1;
do {
    int J = 1;
    do {
        int K = 1;
        do {
            A();
            K = K + 1;
        } while (K != J);
        J = J + 1;
    } while (J != I);
    I = I + 1;
} while (I != N);
```

### Algoritmo 2:

```cpp
int J = N;
while (J > 1) {
    A();
    J = J/2;
}
```

**Respuesta: [E09-calculo-complejidad-bucles](../S03-complejidad/E09-calculo-complejidad-bucles.md)**

## **E10-analisis-fragmentos**

Analice el tiempo de ejecución T(n) de los siguientes fragmentos de programa y calcule su orden de complejidad:

1.
```cpp
int sum = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n*n; j++) {
        sum = sum + 1;
    }
}
```

2.
```cpp
int i = 1;
int x = 0;
while (i <= n) {
    x = x + 3;
    i = i * 2;
}
```

3.
```cpp
int x = 0;
for (int i = 0; i < n; n++) {
    for (int j = 0; j < i*i; i++) {
        for (int k = 0; k < j; j++) {
            x = x + 2;
        }
    }
}
```

4.
```cpp
int sum = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; i++) {
        sum = sum + 1;
    }
}
```

5.
```cpp
int i = 1;
int x = 0;
do {
    int j = 1;
    while (j <= n) {
        x = x + 1;
        j = j * 2;
    }
    i = i + 1;
} while (i == n);
```

**Respuesta: [E10-analisis-fragmentos](../S03-complejidad/E10-analisis-fragmentos.md)**

## **E11-operacion-selectora**

Suponga que cuenta con un arreglo desordenado de enteros. Se desea implementar una operación selectora, que dado un parámetro k, retorna el entero correspondiente a la posición k del arreglo si este estuviera ordenado (obviamente, sin ordenarlo). Defina un algoritmo que sea eficiente y determinístico, es decir, dado cierto k y cualquier arreglo, el tiempo de búsqueda sea el mismo. Calcule formalmente la complejidad en tiempo del programa.

**Respuesta: [E11-operacion-selectora](../S03-complejidad/E11-operacion-selectora.md)**

## **E12-analisis-algoritmo-comp**

Calcule la complejidad en tiempo del siguiente algoritmo:

```cpp
void comp(int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = 0;
        while (i < n) {
            j = j + 1;
            i = i + 1;
        }
        if (j < n) {
            for (int k = 1; k < n; k++) {
                for (int k2 = 1; k2 < n; k2++) {
                    i = k * k2;
                }
            }
        }
    }
}
```

**Respuesta: [E12-analisis-algoritmo-comp](../S03-complejidad/E12-analisis-algoritmo-comp.md)**

## **E13-algoritmo-alfa**

Dado el siguiente algoritmo:

```cpp
void alfa() {
    int N, X, Y, Z, M;
    X = 0; Y = 0; Z = 0;
    cin >> N;
    M = pow(2, N);
    for (int I = 1; I < M; I++) {
        Z = (4 * I) + 8 + Z;
        Y = Y + (2 * I);
        X = X + 1;
    }
}
```

- a) Calcule la función T(n) del algoritmo e indique su orden de complejidad en tiempo.
- b) Reescriba este algoritmo para que su orden de complejidad sea de $O(1)$. Recuerde que el nuevo algoritmo debe tener los mismos resultados que el original.

**Respuesta: [E13-algoritmo-alfa](../S03-complejidad/E13-algoritmo-alfa.md)**

## **E14-bucle-condicional-salto**

Para el siguiente algoritmo indique su complejidad en tiempo. Explique detalladamente qué ocurre:

```cpp
for (int i = 1; i < n; i++) {
    int j, k1, k2;
    for (j = 1; j < n - 1; j++) {
        i = i + 1;
        j = j + 1;
    }
    for (k1 = i; k1 < n; k1++) {
        for (k2 = k1; k2 < n; k2++) {
            k1 = k1 + 1;
            k2 = k2 + 1;
        }
    }
}
```

**Respuesta: [E14-bucle-condicional-salto](../S03-complejidad/E14-bucle-condicional-salto.md)**

## **E15-analisis-bucle-multiplicativo**
Calcule la complejidad del siguiente algoritmo:
```cpp
int j = 1;
while (j < N) {
    j = j * b;
}
```
Donde b es una constante, dado que:
- a) N también es un valor constante
- b) N es la entrada de datos del programa

**Respuesta: [E15-analisis-bucle-multiplicativo](../S03-complejidad/E15-analisis-bucle-multiplicativo.md)**

## **E16-complejidad-fragmentos-varios**

Calcule la complejidad en tiempo para los siguientes fragmentos de código:

1.
```cpp
int I = 1;
int X = 0;
while (I <= n) {
    x++;
    I += 3;
}
```

2.
```cpp
int I = 1;
int X = 0;
while (I <= n) {
    X += 3;
    I *= 3;
}
```

3.
```cpp
for (int i = 1; i <= n; i++) {
    int j = 1;
    while (j <= i) {
        j *= 2;
        x += 2;
    }
}
```

4.
```cpp
int X = 0;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            X += 2;
        }
    }
}
```

5.
```cpp
int X = 0;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        for (int k = 1; k <= j; k++) {
            X += 2;
        }
    }
}
```

**Respuesta: [E16-complejidad-fragmentos-varios](../S03-complejidad/E16-complejidad-fragmentos-varios.md)**

## **E17-memoria-festival-oti**

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

**Respuesta: [E17-memoria-festival-oti](../S03-complejidad/E17-memoria-festival-oti.md)**

## **E18-memoria-vivienda**

Para el siguiente bloque de programa:

```cpp
struct Vivienda {
    float Costo;
    char Direccion[1024];
    int Pisos;
    bool TieneVigilancia;
    int Metros;
    int Altura;
};
Vivienda Urb[15];
```

Calcule la cantidad de memoria requerida para la estructura del objeto `Urb`.

**Respuesta: [E18-memoria-vivienda](../S03-complejidad/E18-memoria-vivienda.md)**

## **E19-memoria-directorio**

Para el siguiente bloque de programa:

```cpp
struct Fecha {
    int Dia;
    char Mes[4];
    int Año;
};
struct EntradaDeDirectorio {
    char Nombre[256];
    Fecha Creacion;
    int NumeroDeArchivos;
    bool EstaCompartido;
};
```

Calcule la cantidad de memoria requerida para la estructura del objeto `EntradaDeDirectorio`.

**Respuesta: [E19-memoria-directorio](../S03-complejidad/E19-memoria-directorio.md)**

## **E20-complejidad-espacio-k**

Dada la siguiente estructura de datos:

```cpp
struct XG {
    int Elemento[10][10]; // Representado como [10] [1..10] en el PDF
};
struct YG {
    int x, y;
    XG Milista;
};
struct K {
    YG x;
    XG y;
};
K E[20];
```
Calcule la complejidad en espacio de la variable `E`.

**Respuesta: [E20-complejidad-espacio-k](../S03-complejidad/E20-complejidad-espacio-k.md)**

## **E21-memoria-edificio**

Considere las siguientes definiciones de tipo:

```cpp
struct Persona {
    char Nombre[50];
    bool EdoCivil;
    bool Sexo;
    int Edad;
    char DirTrab[512];
    int CI_Rif;
    bool PersonaJuridica;
};
Persona JuntaCondominio[10];

struct Edificio {
    char Nombre[50];
    int CantApartamentos;
    JuntaCondominio Junta; // Asumido como un arreglo del tipo Persona
    char Direccion[100];
};
Edificio Avenida[25];
```

Indique el costo en memoria de la variable `Avenida`.

**Respuesta: [E21-memoria-edificio](../S03-complejidad/E21-memoria-edificio.md)**
