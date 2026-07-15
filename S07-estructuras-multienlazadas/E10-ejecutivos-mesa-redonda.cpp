#include <iostream>

struct Executive {
    const char* name;
    int memoryCapacity;
    Executive* next;
    Executive* prev;

    Executive(const char* nom, int ret) : name(nom), memoryCapacity(ret), next(nullptr), prev(nullptr) {}
};


// Ejecuta el juego de mesa redonda eliminando ejecutivos hasta dejar al ganador.
// Concepto Teórico (Problema de Josephus Dinámico con Saltos Variables):
// Este problema simula una rueda de eliminación (tipo Josephus) utilizando una lista circular doblemente enlazada.
// A diferencia del Josephus tradicional (donde el número de pasos 'k' es constante), aquí el tamaño del salto
// cambia dinámicamente según la retentiva ('memoryCapacity') del ejecutivo de turno.
// - En cada ronda, partiendo de 'current', contamos 'jumps' pasos hacia adelante para encontrar al ejecutivo a eliminar ('toRemove').
// - El siguiente turno comenzará con el ejecutivo a la derecha del eliminado ('toRemove->next').
// - El nodo 'toRemove' se desvincula del anillo circular re-enlazando sus vecinos (bypass) y liberando su memoria.
// - El juego termina cuando un nodo se apunta a sí mismo ('current->next == current'), indicando que queda un solo superviviente.
void playRoundTable(Executive*& head) {
    if (head == nullptr) return; // Caso base: Lista vacía

    Executive* current = head;

    std::cout << "Inicio del juego con el ejecutivo: " << current->name << " (Retentiva: " << current->memoryCapacity << ")\n\n";

    // El juego continúa hasta que solo quede un ejecutivo en el anillo
    while (current->next != current) {
        int jumps = current->memoryCapacity; // Obtener la longitud del salto del ejecutivo actual
        Executive* toRemove = current;

        // Avanzar 'jumps' posiciones en sentido de las agujas del reloj
        for (int i = 0; i < jumps; i++) {
            toRemove = toRemove->next;
        }

        std::cout << "  Eliminado: " << toRemove->name << " (al contar " << jumps << " pasos)\n";

        // El siguiente turno comienza en el sucesor directo de la persona eliminada
        current = toRemove->next;

        // Desvincular físicamente 'toRemove' de la lista doblemente enlazada circular
        toRemove->prev->next = toRemove->next;
        toRemove->next->prev = toRemove->prev;

        // Si el ejecutivo eliminado era la cabeza, actualizar 'head' para mantener el acceso a la lista
        if (toRemove == head) {
            head = current; 
        }

        delete toRemove; // Liberar memoria física del ejecutivo eliminado
    }

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m El ejecutivo ganador es: \e[1;33m" << current->name << "\e[0m\n\n";
    head = current; // El ganador es la nueva y única cabeza de la lista
}


int main() {
    std::cout << "\n\e[0;35m[========= E10-EJECUTIVOS-MESA-REDONDA =========]\e[0m\n\n";

    Executive* e1 = new Executive("Alejandro", 2);
    Executive* e2 = new Executive("Beatriz", 3);
    Executive* e3 = new Executive("Carlos", 1);
    Executive* e4 = new Executive("Daniela", 4);
    Executive* e5 = new Executive("Eduardo", 2);

    e1->next = e2; e1->prev = e5;
    e2->next = e3; e2->prev = e1;
    e3->next = e4; e3->prev = e2;
    e4->next = e5; e4->prev = e3;
    e5->next = e1; e5->prev = e4;

    Executive* table = e1;

    playRoundTable(table);

    if (table != nullptr) {
        delete table;
    }

    return 0;
}
