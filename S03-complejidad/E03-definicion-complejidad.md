<h1 align="center">E03 - Concepto de Complejidad en Tiempo</h1>

> [!TLDR]
> La complejidad en tiempo mide cuántas operaciones ejecuta un algoritmo en función del tamaño de la entrada $n$, analizando su comportamiento asintótico en tres casos: peor ($O$), promedio ($\Theta$) y mejor ($\Omega$).

## Enunciado

¿Qué entiende usted por el término complejidad en tiempo?

## Definición

La **complejidad en tiempo** de un algoritmo es una medida métrica que describe la cantidad de tiempo (o, de forma más precisa, el número de instrucciones elementales de CPU) que requiere un algoritmo para ejecutarse en función del tamaño de sus datos de entrada, denotado comúnmente como $n$. Esto conyeva las siguientes diferencias clave:

1. **Frecuencia de Operaciones**: En lugar de medir el tiempo real en segundos (el cual varía según el hardware, sistema operativo o lenguaje), la complejidad en tiempo contabiliza las operaciones dominantes o críticas (como comparaciones, asignaciones o accesos a memoria).

2. **Comportamiento Asintótico**: Estudia cómo escala la demanda de recursos del algoritmo cuando el tamaño de la entrada $n$ crece sin límites ($n \to \infty$).

3. **Casos de Análisis**:

    - **Peor caso ($O$)**: La máxima cantidad de operaciones para cualquier entrada de tamaño $n$. Es la cota de seguridad garantizada.
    - **Caso promedio ($\Theta$)**: El comportamiento esperado bajo una distribución uniforme de entradas.
    - **Mejor caso ($\Omega$)**: El escenario más favorable con el menor número de operaciones.
