# Tipo de Dato Apuntador

## **E01-concepto-apuntador**

¿Qué es el tipo de dato referencia o apuntador?

**Respuesta: [E01-concepto-apuntador](../S04-punteros/E01-concepto-apuntador.md)**

## **E02-operadores-apuntador**

Describa el uso que se le da en este contexto a los operadores `&` y `*`.

**Respuesta: [E02-operadores-apuntador](../S04-punteros/E02-operadores-apuntador.md)**

## **E03-anidacion-apuntadores**

¿Es posible tener apuntadores de apuntadores y anidarlos cuantas veces sea necesario?

**Respuesta: [E03-anidacion-apuntadores](../S04-punteros/E03-anidacion-apuntadores.md)**

## **E04-mapa-memoria-salida**

Para las siguientes instrucciones, haga un mapa de memoria que muestre qué ocurre en ella, y cuál es la salida del programa.

```cpp
struct node {
    int info;
    node *next;
};

int main() {
    node *p, *r, *s;
    p = new node();
    s = new node();
    r = new node();
    (*p).next = r;
    (*r).next = s;
    s->next = p;
    s->info = 3;
    p->next->next->next->info = 2;
    *(s->next).next->info = 1;
    p = s->next;
    std::cout << *(p).info << " " << s->info << " " << *(r).info << std::endl;
    return 0;
}
```

**Respuesta: [E04-mapa-memoria-salida](../S04-punteros/E04-mapa-memoria-salida.md)**

## **E05-trazas-independientes-secuenciales**

Dada las siguientes definiciones:

```cpp
class Nodo {
public:
    int N;
    Nodo *prox;
};
Nodo *q, *r, *s;
Nodo t;
```

Asuma como estado inicial la figura del PDF (una cadena de nodos enlazados: `q -> [1|.] -> [2|.] -> [3|.] -> [4|.] -> [5|/]` (null) con `r` apuntando al nodo de valor 3, `s` apuntando al de valor 4, y `t` como objeto local), e indique el estado final después de ejecutar cada una de las siguientes instrucciones independientemente y luego una tras otra secuencialmente.


| Instrucciones izquierda | Instrucciones derecha |
|-------------------------|------------------------|
| `q = q->prox`           | `s->prox = s`          |
| `*q = *(q->prox)`       | `t = *q`               |
| `q->prox`               | `*q = *s`              |
| `q->prox->prox`         | `*s = t`               |
| `q = r->prox`           | `q = t`                |
| `*q = *(*r.prox)`       | `(*r).prox = q`        |
| `s->prox = q->prox`     | `q = q->prox->prox->prox` |

**Respuesta: [E05-trazas-independientes-secuenciales](../S04-punteros/E05-trazas-independientes-secuenciales.md)**

## **E06-traza-liberacion-memoria**

Dada la siguiente secuencia de instrucciones indique qué es lo que ocurre en cada línea. Indique si queda algún espacio de memoria por liberar.

```cpp
class Nodo {
public:
    int Info;
    Nodo *prox;
};

Nodo *P, *Q;
int *E;
int I;
int **F;

int main() {
    P = new Nodo();
    E = new int();
    *E = 0;
    F = &E;
    P->prox = new Nodo();
    Q = &(*P);
    P = P->prox; 
    Q->Info = 30;
    (*P).Info = Q->Info + 10;
    P->prox = new Nodo();
    P->prox->Info = Q->Info + P->Info + 10;
    P = (*P).prox;
    P->prox = NULL;
    while (Q != NULL) {
        *E = *F + Q->Info;
        Q = Q->prox;
    }
    F = new int*();
    *F = new int();
    **F = 1;
    delete *F;
    *F = &I;
    I = 5;
    std::cout << **F << std::endl;
    return 0;
}
```

**Respuesta: [E06-traza-liberacion-memoria](../S04-punteros/E06-traza-liberacion-memoria.md)**

## **E07-efecto-operaciones-basicas**

Considere las siguientes declaraciones:

```cpp
int *X, *Y, *Z;
char *W;
int A;
char B;
bool C;
```

Indique el efecto de las siguientes operaciones:

- `X = new int();`
- `Y = new int();`
- `W = new char();`
- `X = Y;`
- `B = *W;`
- `Z = new int();`
- `Z = W;`
- `C = W == Z;`
- `X = new int();`
- `*X = 1;`
- `*W = 'G';`
- `A = *X + *Y;`
- `C = (*W == A);`
- `*Z = A;`
- `Z = X;`
- `delete Y;`

**Respuesta: [E07-efecto-operaciones-basicas](../S04-punteros/E07-efecto-operaciones-basicas.md)**

## **E08-traza-funcion-lol**

Dada la siguiente secuencia de instrucciones indique qué ocurre en cada línea. Indique además si queda algún elemento por liberar de memoria al terminar `LOL()`.

```cpp
class Nodo {
public:
    int Info;
    Nodo *prox;
};
Nodo *P, *Q;

void LOL() {
    P = new Nodo();
    P->Info = 10;
    P->prox = P;
    Q = new Nodo();
    P->prox = Q;
    Q->Info = P->Info + 3;
    Q->prox = P;
    Q->prox = NULL;
    Q = new Nodo();
    Q->Info = P->Info + P->prox->Info;
    P->prox->prox = Q;
    Q->prox = NULL;
    Q = P;
    while (Q != NULL) {
        std::cout << Q->Info << std::endl;
        Q = Q->prox;
    }
}
```

**Respuesta: [E08-traza-funcion-lol](../S04-punteros/E08-traza-funcion-lol.md)**

## **E09-traza-matriz-dinamica**

Haga la traza del siguiente algoritmo y explique qué sucede en cada instrucción.

```cpp
int main() {
    int i, j, n;
    int *arr;
    int **mat;
    std::cin >> n;
    arr = new int[n];
    mat = new int*[n];
    for (i = 0; i < n - 1; i++) {
        arr[i] = i;
        mat[i] = new int[n];
        for (j = 0; j < n - 1; j++) {
            mat[i][j] = i + j;
        }
    }
    i = n - 1;
    while (i >= 0) {
        std::cout << arr[i] << std::endl;
        delete[] mat[i];
        i = i - 1;
    }
    delete[] arr;
    delete[] mat;
    // en este momento, ¿a quién apunta arr?. ¿Podría acceder arr[1]?
    return 0;
}
```

**Respuesta: [E09-traza-matriz-dinamica](../S04-punteros/E09-traza-matriz-dinamica.md)**

## **E10-traza-apuntadores-dobles**

Realice la traza del siguiente algoritmo. En cada línea, muestre el estado de las estructuras de datos gráficamente, y en caso de que la instrucción sea incorrecta, indicar el tipo de error.

```cpp
struct Nodo {
    int Info;
    Nodo *prox;
};

Nodo **p, **s, *q, *r;
p = &q;
q->info = 30;
q->prox = NULL;
r = new Nodo();
r->info = 2;
s = &r;
delete q;
q = new Nodo();
q->info = 31;
s->prox = q; // ¿Es válida esta instrucción?
(*p)->info = q->info + (*s)->prox->info;
```

**Respuesta: [E10-traza-apuntadores-dobles](../S04-punteros/E10-traza-apuntadores-dobles.md)**

## **E11-traza-clases-destructores**

Haga la traza del siguiente algoritmo y explique qué sucede en cada instrucción.

```cpp
class Point {
public:
    float x, y;
    Point() {
        x = 0; 
        y = 0;
    }
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }
};

class Rect {
public:
    Point *p1, *p2;
    Rect() { p1 = p2 = NULL; }
    Rect(Point *p1, Point *p2) {
        this->p1 = p1;
        this->p2 = p2;
    }
    ~Rect() {
        if (p1 != NULL) delete p1;
        if (p2 != NULL) delete p2;
    }
};

int main() {
    Point *a, *b;
    a = new Point();
    b = new Point(1, 1);
    Rect *r = new Rect(a, b);
    delete a;
    delete r; // ¿Qué error ocurre aquí?
    Rect otro(a, b);
    return 0;
} // ¿Qué sucede al llamar al destructor de otro?
```

**Respuesta: [E11-traza-clases-destructores](../S04-punteros/E11-traza-clases-destructores.md)**

## **E12-paso-parametros-apuntadores**

Indique el estado final, y responda las preguntas comentadas en `Any()`.

```cpp
struct node {
    int info;
    node *prox;
};

void X(node *&q, int value) {
    q = new node();
    q->info = value;
    q->prox = NULL;
}

void Y(node **q, int value) {
    *q = new node();
    (*q)->info = value;
    (*q)->prox = NULL;
}

void W(node *q, int value) {
    q->info = value;
}

void Z(node *q, int value) {
    q = new node();
    q->info = value;
    q->prox = NULL;
}

void Any() {
    node *p;
    X(p, 1);
    Y(&(p->prox), 2);
    Z(p->prox->prox, 3);
    W(p, 4);
}
```

- a) ¿Cuál es el estado de la memoria en este momento?
- b) ¿Es posible liberar todos los elementos creados con New? ¿De qué forma?

**Respuesta: [E12-paso-parametros-apuntadores](../S04-punteros/E12-paso-parametros-apuntadores.md)**
