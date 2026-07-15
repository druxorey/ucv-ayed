<h1 align="center">E06 - Hallar Cota $g(n)$ y Demostración</h1>

> [!TLDR]
> Para encontrar la cota $g(n)$ de $f(n)$, se identifica el **término de mayor crecimiento** y se demuestran constantes $c$ y $n_0$ que satisfacen $f(n) \le c \cdot g(n)$ para todo $n \ge n_0$.

## Enunciado

Para las siguientes $f(n)$, halle una cota $g(n)$, y demuestre mediante el concepto de dominancia de funciones que $f(n) = O(g(n))$:

- a) $f(n) = 8n^3 - 576n^2 + 832n - 248$
- b) $f(n) = \ln(a^n) + b$
- c) $f(n) = n^2 - \log_2 n + 7$
- d) $f(n) = an^2 + bn + c$
- e) $f(n) = n + n^2 + n^3$
- f) $f(n) = a2^{bn} + c$
- g) $f(n) = 3^x + \log_2(n + 1)$

## Resolución

### a) $f(n) = 8n^3 - 576n^2 + 832n - 248$

- **Cota asintótica:** $g(n) = n^3$

Para $n \ge 1$:

$$8n^3 - 576n^2 + 832n - 248 \le 8n^3 + 832n \le 8n^3 + 832n^3 = 840n^3$$

Elegimos $c = 840$ y $n_0 = 1$. Así, $f(n) \le c \cdot n^3$, por lo que $f(n) = O(n^3)$.

### b) $f(n) = \ln(a^n) + b$

- **Simplificación:** Usando propiedades de los logaritmos, $f(n) = n \ln(a) + b$.
- **Cota asintótica:** $g(n) = n$ (ya que $\ln(a)$ es una constante).

Para $n \ge 1$:

$$n \ln(a) + b \le n \ln(a) + b \cdot n = (\ln(a) + b) \cdot n$$

Elegimos $c = \ln(a) + b$ y $n_0 = 1$. Así, $f(n) \le c \cdot n$, por lo que $f(n) = O(n)$.

### c) $f(n) = n^2 - \log_2 n + 7$

- **Cota asintótica:** $g(n) = n^2$

Para $n \ge 1$:

$$n^2 - \log_2 n + 7 \le n^2 + 7 \le n^2 + 7n^2 = 8n^2$$

Elegimos $c = 8$ y $n_0 = 1$. Así, $f(n) \le c \cdot n^2$, por lo que $f(n) = O(n^2)$.

### d) $f(n) = an^2 + bn + c$

- **Cota asintótica:** $g(n) = n^2$

Para $n \ge 1$:

$$an^2 + bn + c \le |a|n^2 + |b|n + |c| \le |a|n^2 + |b|n^2 + |c|n^2 = (|a| + |b| + |c|)n^2$$

Elegimos $c' = |a| + |b| + |c|$ y $n_0 = 1$. Así, $f(n) \le c' \cdot n^2$, por lo que $f(n) = O(n^2)$.

### e) $f(n) = n + n^2 + n^3$

- **Cota asintótica:** $g(n) = n^3$

Para $n \ge 1$:

$$n + n^2 + n^3 \le n^3 + n^3 + n^3 = 3n^3$$

Elegimos $c = 3$ y $n_0 = 1$. Así, $f(n) \le c \cdot n^3$, por lo que $f(n) = O(n^3)$.

### f) $f(n) = a2^{bn} + c$

- **Cota asintótica:** $g(n) = 2^{bn}$ o $g(n) = d^n$ donde $d = 2^b$.

Para $n \ge 1$:

$$a2^{bn} + c \le |a|2^{bn} + |c|2^{bn} = (|a| + |c|)2^{bn}$$

Elegimos $c' = |a| + |c|$ y $n_0 = 1$. Así, $f(n) \le c' \cdot 2^{bn}$, por lo que $f(n) = O(2^{bn})$.

### g) $f(n) = 3^x + \log_2(n + 1)$

*(Nota: Asumiendo que $3^x$ es una constante $C$ con respecto a $n$, o que la variable es $n$ en lugar de $x$)*

- **Cota asintótica:** $g(n) = \log_2(n)$

Para $n \ge 2$:

$$C + \log_2(n + 1) \le C + \log_2(2n) = C + 1 + \log_2 n \le (C + 1)\log_2 n + \log_2 n = (C + 2)\log_2 n$$

Elegimos $c' = C + 2$ y $n_0 = 2$. Así, $f(n) \le c' \cdot \log_2 n$, por lo que $f(n) = O(\log_2 n)$.
