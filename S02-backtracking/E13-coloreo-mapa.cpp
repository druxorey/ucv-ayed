#include <iostream>

// Función auxiliar para verificar si un color es válido para un país (nodo).
// Concepto Teórico (Restricción de Adyacencia en Coloración de Grafos):
// Un coloreado es propio si no existen dos vértices adyacentes (países limítrofes) que compartan el mismo color.
// Recorremos todos los países; si hay una frontera con 'country' (graph[country][i] es true) 
// y ese vecino ya tiene asignado el color 'c', entonces el color no es seguro (retorna false).
bool isSafe(int country, bool** graph, const int colors[], int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[country][i] && c == colors[i]) {
            return false; // Conflicto de color detectado
        }
    }
    return true; // Es seguro asignar este color
}


// Función recursiva de backtracking para colorear el mapa.
// Concepto Teórico (Búsqueda con Satisfacción de Restricciones - CSP):
// El problema del coloreado de mapas se puede modelar como un CSP (Constraint Satisfaction Problem).
// Se asignan colores del 1 al 'numColors' secuencialmente país por país.
// Si llegamos a una callejón sin salida (ningún color del 1 al numColors es seguro para el país actual),
// retrocedemos y cambiamos la elección del país anterior.
bool colorMapUtil(int country, int numColors, bool** graph, int colors[], int n) {
    // Caso base: Si hemos asignado con éxito un color a todos los países (country == n),
    // la coloración completa es válida y retornamos true para terminar la búsqueda.
    if (country == n) return true;

    // Bucle de decisiones: Intentar colorear el país actual con cada uno de los colores disponibles
    for (int c = 1; c <= numColors; c++) {
        // Verificar si la restricción de coloración se cumple para el color 'c'
        if (isSafe(country, graph, colors, c, n)) {
            // 1. Tomar decisión: Asignar color 'c' al país actual.
            colors[country] = c;

            // 2. Exploración recursiva: Intentar colorear el siguiente país (country + 1)
            if (colorMapUtil(country + 1, numColors, graph, colors, n)) {
                return true; // Propagar éxito si se colorearon correctamente todos los países restantes
            }

            // 3. Deshacer decisión (Backtracking): Si la exploración con el color 'c' falló, 
            //    deshacemos la asignación de color (volvemos a 0) antes de probar el color 'c + 1'.
            colors[country] = 0; 
        }
    }

    return false; // Retorna false si no fue posible encontrar una coloración válida para este subárbol
}


// Función principal para resolver el problema de coloreado.
bool colorMap(bool** graph, int colors[], int n) {
    for (int numColors = 1; numColors <= n; numColors++) {
        for (int i = 0; i < n; i++) {
            colors[i] = 0;
        }

        if (colorMapUtil(0, numColors, graph, colors, n)) {
            printf("\e[1;32m[ÉXITO]\e[0m Se pudo colorear el mapa con un mínimo de %d colores.\n", numColors);
            return true;
        }
    }
    return false;
}


int main() {
    std::cout << "\n\e[0;35m[========= E13-COLOREO-MAPA =========]\e[0m\n\n";

    int n;
    std::cout << "Introduce el número de países (N): ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "\e[1;31m[ERROR]\e[0m El número de países debe ser mayor que cero.\n\n";
        return 1;
    }

    bool** graph = new bool*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            graph[i][j] = false;
        }
    }
    int* colors = new int[n];
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }

    std::cout << "\nIntroduce la matriz de limítrofes de tamaño " << n << "x" << n << " (1 si son limítrofes, 0 si no):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            std::cout << "¿País " << (i + 1) << " limítrofe con País " << (j + 1) << "? (0/1): ";
            if (!(std::cin >> val)) {
                for (int k = 0; k < n; k++) delete[] graph[k];
                delete[] graph;
                delete[] colors;
                return 1;
            }
            graph[i][j] = (val != 0);
        }
    }

    if (colorMap(graph, colors, n)) {
        std::cout << "\n\e[1;32m[RESULTADO]\e[0m Asignación de colores por país:\n";
        for (int i = 0; i < n; i++) {
            std::cout << "  País " << (i + 1) << " -> Color " << colors[i] << "\n";
        }
        std::cout << "\n";
    } else {
        std::cout << "\n\e[1;31m[RESULTADO]\e[0m No se encontró ninguna solución para colorear el mapa.\n\n";
    }

    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] colors;

    return 0;
}
