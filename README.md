<h1 align="center">Algoritmos y Estructuras de Datos</h1>

<p align="center">
<a href="#estructura-del-repositorio"><img src="https://img.shields.io/badge/estructura-BD93F9?style=for-the-badge"></a>
<a href="#explicaciones-generales-del-codigo"><img src="https://img.shields.io/badge/explicaciones%20generales-BD93F9?style=for-the-badge"></a>
</p>

<p align="center">Respuestas a las guías de la materia de algoritmos y estructuras de datos en c++</p>

## Estructura del repositorio

- **_enunciados**: Este directorio contiene las guías resueltas en formato markdown.

    - [S01-recursividad](./_enunciados/S01-recursividad.md)
    - [S02-backtraking](./_enunciados/S02-backtraking.md)
    - [S03-complejidad](./_enunciados/S03-complejidad.md)
    - [S04-punteros](./_enunciados/S04-punteros.md)
    - [S05-listas-pilas](./_enunciados/S05-listas-pilas.md)
    - [S06-colas-dipolos](./_enunciados/s06-colas-dipolos.md)
    - [S07-estructuras-multienlazadas](./_enunciados/s07-estructuras-multienlazadas.md)
    - [S08-arboles-generales-y-binarios](./_enunciados/s08-arboles-generales-y-binarios.md)
    - [S09-monticulos](./_enunciados/s09-monticulos.md)

- **S99-libraries**: Este directorio contiene headers con funciones y clases generales que pueden ser utilizadas en varios ejercicios.

- **Ejercicios**: Dentro de cada directorio con el nombre correspondiente a la guía con los enunciados estarán los ejercicios enumerados y organizados según las guías.

## Cómo ejecutar los códigos

Para compilar y ejecutar un programa en c++ **desde la terminal**, sigue estos pasos:

> **Nota:**
> Si prefieres compilar y ejecutar los programas utilizando code runner, consulta la guía en el siguiente enlace: [cómo usar code runner](https://example.com/code-runner-guide).

1. Navega al directorio donde se encuentra el archivo `.cpp`.
2. Compila el archivo con el siguiente comando:

    ```bash
    g++ nombre-del-archivo.cpp -o programa-compilado
    ```

3. Ejecuta el programa con el siguiente comando:

    ```bash
    ./programa-compilado
    ```

## Cómo Ejecutar los Códigos

Para compilar y ejecutar un programa en C++ **desde la terminal**, sigue estos pasos:

> **NOTA:**
> Si prefieres compilar y ejecutar los programas utilizando Code Runner, consulta la guía en el siguiente enlace: [Cómo usar Code Runner](https://example.com/code-runner-guide).

1. Navega al directorio donde se encuentra el archivo `.cpp`.
2. Compila el archivo con el siguiente comando:

    ```bash
    g++ nombre-del-archivo.cpp -o programa-compilado
    ```

3. Ejecuta el programa con el siguiente comando:

    ```bash
    ./programa-compilado
    ```

## Explicaciones Generales del Codigo

En los códigos proporcionados, es común encontrar secuencias de escape que cumplen funciones específicas. A continuación, se explican algunas de ellas:

- `\n`: Es la secuencia de escape utilizada para insertar un salto de línea en la salida del programa.
- `\e[1;34m`: Es una secuencia de escape ANSI que se utiliza para cambiar el color del texto en la terminal. En este caso, `1` indica negrita y `34m` representa el color azul.
- `\e[0m`: Restaura el color y el formato del texto al valor predeterminado de la terminal.
- Variantes como `\e[0;34m`: También cambian el color del texto, pero sin aplicar negrita (el `0` indica formato normal).

Estas secuencias son útiles para mejorar la legibilidad de la salida en la terminal. Para más información sobre las secuencias de escape ANSI y cómo usarlas, consulta el siguiente enlace: [Guía de Secuencias de Escape ANSI](https://es.wikipedia.org/wiki/C%C3%B3digo_escape_ANSI).

## Licencia

Este proyecto está licenciado bajo la Licencia GPL-3.0. Consulta el archivo [LICENSE](LICENSE) para más detalles.
