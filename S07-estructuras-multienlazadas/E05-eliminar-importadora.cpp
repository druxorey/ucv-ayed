#include <iostream>

// Estructura de Compañía Importadora (Company).
struct Company {
    const char* name;
    double balance;
    Company* next;
    Company* prev;

    Company(const char* nom, double bal) : name(nom), balance(bal), next(nullptr), prev(nullptr) {}
};


// Compara si dos cadenas de caracteres son iguales.
bool stringsEqual(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    return s1[i] == s2[i];
}


// Elimina una compañía de la lista circular si su balance está por debajo del umbral.
// Concepto Teórico (Búsqueda y Eliminación Condicional en Listas Circulares Dobles):
// 1. Búsqueda con Retorno de Vuelta: Recorremos el anillo usando una estructura do-while.
//    La condición de salida 'current != head' evita bucles infinitos al garantizar que nos detendremos
//    cuando el puntero de exploración regrese al punto de partida 'head'.
// 2. Eliminación física:
//    - Caso Especial (Un solo nodo): Si el nodo es el único de la lista ('current->next == current'), 
//      liberamos la memoria del nodo y ponemos 'head' en nullptr.
//    - Caso General (Varios nodos): Realizamos el desvío de punteros contiguos. Si el nodo a eliminar
//      coincide con 'head', re-apuntamos 'head' al nodo sucesor ('current->next') para no perder la 
//      referencia a la lista circular antes de liberar 'current' de la memoria Heap.
void verifyAndRemoveCompany(Company*& head, const char* nameToSearch, double minThreshold) {
    if (head == nullptr) return; // Caso base: Lista vacía

    Company* current = head;
    bool found = false;

    // Búsqueda secuencial en el anillo circular
    do {
        if (stringsEqual(current->name, nameToSearch)) {
            found = true;
            break; // Detener búsqueda, elemento encontrado
        }
        current = current->next; // Avanzar en el anillo
    } while (current != head);

    if (!found) {
        std::cout << "Compañía \"" << nameToSearch << "\" no encontrada.\n";
        return;
    }

    std::cout << "Compañía \"" << current->name << "\" encontrada (Balance: " << current->balance << ")\n";

    // Evaluar si el balance incumple el umbral mínimo establecido
    if (current->balance < minThreshold) {
        std::cout << "  [ELIMINANDO] Balance menor al umbral de " << minThreshold << ".\n";
        
        // Caso Especial: La lista tiene un solo nodo
        if (current->next == current) {
            delete current;
            head = nullptr; // La lista queda vacía
            return;
        }

        // Caso General: Desvío de punteros de los nodos adyacentes
        current->prev->next = current->next;
        current->next->prev = current->prev;

        // Si el nodo que se elimina es la cabeza actual, re-apuntar la cabeza a su sucesor
        if (current == head) {
            head = current->next;
        }

        delete current; // Liberar memoria física del nodo
    } else {
        std::cout << "  [CONSERVADA] Balance suficiente.\n";
    }
}


void displayCompaniesCircular(Company* head) {
    if (head == nullptr) {
        std::cout << "[ Lista vacía ]\n";
        return;
    }
    Company* current = head;
    std::cout << "Lista de Compañías:\n";
    do {
        std::cout << "  - " << current->name << " (Balance: " << current->balance << ")\n";
        current = current->next;
    } while (current != head);
}


int main() {
    std::cout << "\n\e[0;35m[========= E05-ELIMINAR-IMPORTADORA =========]\e[0m\n\n";

    // Crear lista circular de 3 compañías
    Company* c1 = new Company("Importadora Alimentos", 15000.0);
    Company* c2 = new Company("Importadora Metales", 4500.0);
    Company* c3 = new Company("Importadora Textil", 8900.0);

    c1->next = c2; c1->prev = c3;
    c2->next = c3; c2->prev = c1;
    c3->next = c1; c3->prev = c2;

    Company* list = c1;
    displayCompaniesCircular(list);

    double threshold = 5000.0;
    std::cout << "\nVerificando compañía 'Importadora Metales' con umbral " << threshold << "...\n";
    verifyAndRemoveCompany(list, "Importadora Metales", threshold);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Estado final de la lista:\n";
    displayCompaniesCircular(list);
    std::cout << "\n";

    // Liberar memoria restante
    if (list != nullptr) {
        list->prev->next = nullptr;
        while (list != nullptr) {
            Company* temp = list->next;
            delete list;
            list = temp;
        }
    }

    return 0;
}
