<h1 align="center">E02 - Demostraciones Formales de Dominancia</h1>

> [!TLDR]
> Se demuestran tres propiedades de la notación Big-O: **Transitividad** ($f=O(g)$ y $g=O(h)$ implica $f=O(h)$), **Reflexividad** ($f=O(f)$) y **Simetría** (si $f=O(g)$ y $g=O(f)$, entonces $f=\Theta(g)$).

## Enunciado

Demuestre formalmente las siguientes propiedades del concepto de dominancia de funciones:

- Si $f(n) = O(g(n))$ y $g(n) = O(h(n))$ entonces $f(n) = O(h(n))$
- $f(n) = O(f(n))$
- Si $f(n) = O(g(n))$ y $g(n) = O(f(n))$ entonces $f(n) = g(n)$ (en orden de magnitud)

## Propiedad 1: Transitividad

**Enunciado:** Si $f(n) = O(g(n))$ y $g(n) = O(h(n))$ entonces $f(n) = O(h(n))$.

**Demostración:**

Por definición de Big-O:
1. Como $f(n) = O(g(n))$, existen constantes $c_1 > 0$ y $n_1 \ge 1$ tales que:

    $$f(n) \le c_1 \cdot g(n) \quad \forall n \ge n_1$$

2. Como $g(n) = O(h(n))$, existen constantes $c_2 > 0$ y $n_2 \ge 1$ tales que:

    $$g(n) \le c_2 \cdot h(n) \quad \forall n \ge n_2$$

Sustituyendo (2) en (1), para todo $n \ge \max(n_1, n_2)$:

$$f(n) \le c_1 \cdot g(n) \le c_1 \cdot (c_2 \cdot h(n)) = (c_1 \cdot c_2) \cdot h(n)$$

Definiendo la nueva constante $c_3 = c_1 \cdot c_2 > 0$ y $n_3 = \max(n_1, n_2) \ge 1$:

$$f(n) \le c_3 \cdot h(n) \quad \forall n \ge n_3$$

Por lo tanto, $f(n) = O(h(n))$. $\blacksquare$

## Propiedad 2: Reflexividad

**Enunciado:** $f(n) = O(f(n))$.

**Demostración:**

Queremos encontrar constantes $c > 0$ y $n_0 \ge 1$ tales que:

$$f(n) \le c \cdot f(n) \quad \forall n \ge n_0$$

Si elegimos la constante $c = 1$ y $n_0 = 1$:

$$f(n) \le 1 \cdot f(n)$$

Lo cual se cumple trivialmente para toda función positiva $f(n)$.
Por lo tanto, $f(n) = O(f(n))$. $\blacksquare$

## Propiedad 3: Equivalencia de Orden de Magnitud (Simetría)

**Enunciado:** Si $f(n) = O(g(n))$ y $g(n) = O(f(n))$ entonces ambas funciones tienen el mismo orden de crecimiento (es decir, $f(n) = \Theta(g(n))$ o $f(n) \equiv g(n)$).

**Demostración:**
1. Dado $f(n) = O(g(n))$, existen $c_1 > 0$ y $n_1 \ge 1$ tales que:

    $$f(n) \le c_1 \cdot g(n) \quad \forall n \ge n_1$$

2. Dado $g(n) = O(f(n))$, existen $c_2 > 0$ y $n_2 \ge 1$ tales que:

    $$g(n) \le c_2 \cdot f(n) \implies \frac{1}{c_2} \cdot g(n) \le f(n) \quad \forall n \ge n_2$$

Definiendo $n_0 = \max(n_1, n_2)$ y combinando las desigualdades para todo $n \ge n_0$:

$$\frac{1}{c_2} \cdot g(n) \le f(n) \le c_1 \cdot g(n)$$

Al existir constantes positivas $k_1 = \frac{1}{c_2}$ y $k_2 = c_1$ tales que:

$$k_1 \cdot g(n) \le f(n) \le k_2 \cdot g(n) \quad \forall n \ge n_0$$

Concluimos que $f(n) = \Theta(g(n))$, lo que demuestra que ambas funciones comparten exactamente el mismo orden de crecimiento asintótico. $\blacksquare$
