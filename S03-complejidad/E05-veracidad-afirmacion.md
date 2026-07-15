<h1 align="center">E05 - Veracidad de la Afirmación $n^2 = O(n \log_2 n)$</h1>

> [!TLDR]
> La afirmación es **FALSA**. $n^2$ crece más rápido que $n \log n$, por lo que no puede estar acotada superiormente por ella. Se demuestra por límites: $\lim_{{n\to\infty}} n^2/(n\log n) = \infty$.

## Enunciado

Discuta la veracidad de la siguiente afirmación: $n^2 = O(n \log_2 n)$. En caso de ser cierto, demuéstrelo formalmente. En caso de ser falso, indique dos formas distintas que permitan concluir que dicho razonamiento es erróneo.

## Afirmación:

$$n^2 = O(n \log_2 n)$$

Esta afirmación es **FALSA**. La función $n^2$ crece estrictamente más rápido que la función $n \log_2 n$. Por lo tanto, $n^2$ no puede estar acotada superiormente por $n \log_2 n$.

## Justificación 1: Demostración mediante Límites (Criterio del Límite)

Para determinar la relación de orden asintótico entre dos funciones $f(n) = n^2$ y $g(n) = n \log_2 n$, calculamos el límite de su cociente cuando $n \to \infty$:

$$L = \lim_{n \to \infty} \frac{f(n)}{g(n)} = \lim_{n \to \infty} \frac{n^2}{n \log_2 n} = \lim_{n \to \infty} \frac{n}{\log_2 n}$$

Aplicando la regla de L'Hôpital (derivando numerador y denominador con respecto a $n$):

*   Derivada del numerador ($n$): $1$
*   Derivada del denominador ($\log_2 n = \frac{\ln n}{\ln 2}$): $\frac{1}{n \ln 2}$

$$L = \lim_{n \to \infty} \frac{1}{\frac{1}{n \ln 2}} = \lim_{n \to \infty} (n \ln 2) = \infty$$

Como el límite tiende a infinito ($L = \infty$), concluimos que $f(n)$ es de un orden estrictamente superior a $g(n)$, es decir:

$$f(n) = \Omega(g(n)) \quad \text{y} \quad f(n) \neq O(g(n))$$

## Justificación 2: Contradicción Formal por Definición

Supongamos que la afirmación es verdadera. Por definición de Big-O, deberían existir constantes $c > 0$ y $n_0 \ge 1$ tales que:

$$n^2 \le c \cdot n \log_2 n \quad \forall n \ge n_0$$

Dividiendo ambos miembros entre $n$ (dado que $n \ge n_0 \ge 1$):

$$n \le c \cdot \log_2 n \implies \frac{n}{\log_2 n} \le c \quad \forall n \ge n_0$$

Sin embargo, sabemos que el cociente $\frac{n}{\log_2 n}$ crece indefinidamente a medida que $n$ aumenta (por ejemplo, para $n = 1024$, el cociente es $\frac{1024}{10} = 102.4$; para $n = 1,048,576$, es $\frac{1,048,576}{20} \approx 52428.8$).

Por lo tanto, no existe ninguna constante finita $c$ que pueda acotar superiormente a $\frac{n}{\log_2 n}$ para todo $n$ suficientemente grande. Llegamos a una contradicción, lo que demuestra que la afirmación original es falsa.
