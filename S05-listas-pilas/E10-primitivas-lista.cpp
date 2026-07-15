#include <iostream>

// Definición de la estructura Node usando una clase plantilla
template <typename T>
class Node {
public:
    T info;
    Node<T>* next;

    Node(T valor) : info(valor), next(nullptr) {}
};


// Implementación de una lista enlazada simple para el ejercicio
template <typename T>
class SimplyLinkedList {
private:
    Node<T>* head;
    int length;

public:
    SimplyLinkedList() : head(nullptr), length(0) {}


    ~SimplyLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }


    void insert(T valor) {
        Node<T>* newNode = new Node<T>(valor);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        length++;
    }


    // PRIMITIVA: Acceder (Access)
    // Concepto Teórico (Acceso Secuencial vs Acceso Directo):
    // A diferencia de los arreglos (que permiten acceso directo O(1) mediante cálculo de desplazamiento),
    // en una lista enlazada simple debemos recorrer secuencialmente los nodos desde la cabeza ('head') 
    // hasta la posición deseada. Esto resulta en una complejidad temporal de O(i) para acceder al i-ésimo elemento.
    T* access(int position) {
        // Validación de límites lógicos
        if (position < 0 || position >= length) {
            return nullptr;
        }

        Node<T>* current = head;
        int currentIndex = 0;

        // Bucle de salto de punteros hasta la posición buscada
        while (current != nullptr && currentIndex < position) {
            current = current->next;
            currentIndex++;
        }

        // Devolvemos la dirección del dato para permitir modificación o lectura
        return (current != nullptr) ? &(current->info) : nullptr;
    }


    // PRIMITIVA: Eliminar (Remove)
    // Concepto Teórico (Desvío de Punteros en Eliminación):
    // Para eliminar un nodo en la posición P de una lista enlazada simple sin romper la estructura, debemos:
    // 1. Identificar el nodo predecessor 'prev' (en P - 1).
    // 2. Apuntar el enlace 'next' del predecessor directamente al sucesor del nodo a eliminar ('toDelete->next').
    //    Esto desvía la ruta y desconecta el nodo a eliminar de la cadena.
    // 3. Liberar la memoria del nodo desconectado ('delete toDelete') para evitar fugas de memoria.
    // Caso Especial: Si eliminamos la cabeza (P == 0), no hay predecessor, por lo que simplemente
    // actualizamos 'head' para apuntar al segundo nodo ('head->next').
    bool remove(int position) {
        // Validación de límites lógicos
        if (position < 0 || position >= length) {
            return false;
        }

        Node<T>* toDelete = nullptr;

        // Caso Especial: Eliminar el primer elemento (cabeza)
        if (position == 0) {
            toDelete = head;
            head = head->next; // La cabeza se desplaza al segundo nodo
        } 
        // Caso General: Eliminar en medio o al final
        else {
            Node<T>* prev = head;
            // Avanzar hasta el predecesor (posición anterior a la que queremos borrar)
            for (int i = 0; i < position - 1; i++) {
                prev = prev->next;
            }
            toDelete = prev->next;        // El nodo a eliminar es el sucesor del predecesor
            prev->next = toDelete->next;  // Desviar el puntero: saltarse 'toDelete'
        }

        delete toDelete; // Liberar la memoria física del nodo del Heap
        length--;        // Decrementar el contador lógico de la lista
        return true;
    }


    void display() {
        Node<T>* current = head;
        std::cout << "Lista: \e[1;34m[\e[0m";
        while (current != nullptr) {
            std::cout << current->info;
            current = current->next;
            if (current != nullptr) std::cout << " -> ";
        }
        std::cout << "\e[1;34m]\e[0m (Tamaño: " << length << ")\n";
    }
};


int main() {
    std::cout << "\n\e[0;35m[========= E10-PRIMITIVAS-LISTA =========]\e[0m\n\n";

    SimplyLinkedList<int> list;
    list.insert(100);
    list.insert(200);
    list.insert(300);
    list.insert(400);

    std::cout << "Estado inicial:\n  ";
    list.display();

    // 1. Probar la primitiva "Acceder"
    int accessPos;
    std::cout << "\nIngrese posición a acceder (0 a 3): ";
    if (!(std::cin >> accessPos)) return 1;

    int* value = list.access(accessPos);
    if (value != nullptr) {
        printf("  \e[1;32m[ACCESO EXITOSO]\e[0m El valor en la posición %d es: %d\n", accessPos, *value);
    } else {
        printf("  \e[1;31m[ERROR DE ACCESO]\e[0m Posición %d no válida.\n", accessPos);
    }

    // 2. Probar la primitiva "Eliminar"
    int removePos;
    std::cout << "\nIngrese posición a eliminar (0 a 3): ";
    if (!(std::cin >> removePos)) return 1;

    if (list.remove(removePos)) {
        printf("  \e[1;32m[ELIMINACIÓN EXITOSA]\e[0m Elemento eliminado en posición %d.\n", removePos);
        std::cout << "Estado actual:\n  ";
        list.display();
    } else {
        printf("  \e[1;31m[ERROR DE ELIMINACIÓN]\e[0m No se pudo eliminar en la posición %d.\n", removePos);
    }
    std::cout << "\n";

    return 0;
}
