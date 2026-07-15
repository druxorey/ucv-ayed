#include <iostream>

// Función recursiva que resuelve y describe los movimientos de Hanoi
// n: número de discos
// source: varilla desde donde movemos los discos
// destination: varilla a donde movemos los discos
// auxiliary: varilla de soporte temporal
// Función recursiva que resuelve y describe los movimientos de las Torres de Hanoi.
// Concepto Teórico (Estrategia Divide y Vencerás / Recurrencia Exponencial):
// El problema de mover 'n' discos se reduce a tres fases secuenciales:
// 1. Mover los 'n-1' discos superiores a la varilla auxiliar (subproblema).
// 2. Mover el disco más grande 'n' (la base) directamente al destino (paso directo).
// 3. Mover los 'n-1' discos restantes desde la varilla auxiliar al destino (subproblema).
// La relación de recurrencia T(n) = 2T(n-1) + 1 resulta en una complejidad de tiempo de O(2^n) 
// y una complejidad de espacio de O(n) debido a la profundidad de la pila de llamadas.
void solveHanoi(int n, char source, char destination, char auxiliary, int &movement) {
    // Caso base: Si solo hay 1 disco (n == 1), lo movemos directamente del origen al destino
    // sin necesidad de usar la varilla de soporte auxiliar. Detiene la recursión para esta rama.
    if (n == 1) {
        movement++;
        printf("Movimiento %3d: Mover disco %d de la varilla \e[0;33m%c\e[0m a la varilla \e[0;32m%c\e[0m\n", 
               movement, n, source, destination);
        return;
    }

    // Fase 1: Mover los n-1 discos superiores del origen 'source' al auxiliar 'auxiliary',
    // utilizando el destino 'destination' como soporte intermedio temporal.
    solveHanoi(n - 1, source, auxiliary, destination, movement);

    // Fase 2 (Paso Combinar / Intermedio):
    // Movemos el disco restante (el más grande, disco n) directamente desde el origen 'source' al destino 'destination'.
    movement++;
    printf("Movimiento %3d: Mover disco %d de la varilla \e[0;33m%c\e[0m a la varilla \e[0;32m%c\e[0m\n", 
           movement, n, source, destination);

    // Fase 3: Mover los n-1 discos que dejamos temporalmente en 'auxiliary' hacia el destino 'destination',
    // utilizando el origen 'source' como soporte intermedio temporal.
    solveHanoi(n - 1, auxiliary, destination, source, movement);
}


int main() {
    std::cout << "\n\e[0;35m[========= E15-TORRES-DE-HANOI =========]\e[0m\n\n";

    int disks;
    std::cout << "Introduce el número de discos: ";
    if (!(std::cin >> disks)) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Entrada inválida.\n\n";
        return 1;
    }

    if (disks <= 0) {
        std::cerr << "\e[1;31m[ERROR]\e[0m El número de discos debe ser mayor que cero.\n\n";
        return 1;
    }

    int movement = 0;
    // Resolver y mostrar la secuencia de movimientos
    solveHanoi(disks, 'A', 'C', 'B', movement);

    // Total de movimientos esperados es 2^n - 1
    int totalExpected = (1 << disks) - 1;
    printf("\n\e[1;32m[RESULTADO]\e[0m Se realizaron %d movimientos (Esperados: %d).\n\n", 
           movement, totalExpected);

    return 0;
}
