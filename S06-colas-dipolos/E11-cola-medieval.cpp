#include <iostream>
#include "../S99-implementaciones/drxqueue.hpp"

// Estructura para modelar a los ciudadanos medievales (Citizen).
struct Citizen {
    const char* name;
    bool isNoble;

    friend std::ostream& operator<<(std::ostream& out, const Citizen& c) {
        out << c.name << " (" << (c.isNoble ? "Noble" : "Plebeyo") << ")";
        return out;
    }
};


// Clase Cola Medieval (MedievalQueue) que hereda de la Cola base.
class MedievalQueue : public DrxQueue<Citizen> {
public:
    // Sobrescribimos el método push (encolar) para priorizar nobles sobre plebeyos.
    // Concepto Teórico (Cola de Prioridad Básica con Dos Clases de Servicio):
    // Modelamos un comportamiento donde los Nobles se atienden antes que los Plebeyos.
    // Para insertar un nuevo elemento manteniendo este orden híbrido (FIFO por clase, pero Nobles > Plebeyos):
    // 1. Vaciamos la cola actual y segmentamos sus elementos en dos colas auxiliares: 'nobles' y 'plebeyos'.
    // 2. Reconstruimos la cola principal en el orden correcto:
    //    a) Encolamos los nobles existentes.
    //    b) Si el nuevo es noble, ingresa inmediatamente (al final de la sección de nobles).
    //    c) Encolamos los plebeyos existentes.
    //    d) Si el nuevo es plebeyo, ingresa al final (detrás de toda la cola).
    // Esto ilustra cómo simular prioridades sin estructuras complejas como montículos (heaps), a coste de tiempo O(n).
    void push(const Citizen& val) {
        // Caso base: Si la cola está vacía, no hay conflicto de prioridades.
        // Llamamos directamente a la inserción básica de la clase base.
        if (this->isEmpty()) {
            DrxQueue<Citizen>::push(val);
            return;
        }

        DrxQueue<Citizen> nobles;
        DrxQueue<Citizen> plebeyos;

        // Fase 1: Segmentación (Desensamblado).
        // Extraemos y clasificamos a los ciudadanos actuales en sus colas correspondientes.
        while (!this->isEmpty()) {
            if (this->front().isNoble) {
                nobles.push(this->front());
            } else {
                plebeyos.push(this->front());
            }
            this->pop();
        }

        // Fase 2: Reconstrucción (Ensamblado en Orden de Rango).
        
        // a) Re-encolar Nobles en orden FIFO original.
        while (!nobles.isEmpty()) {
            DrxQueue<Citizen>::push(nobles.front());
            nobles.pop();
        }

        // b) Si el nuevo ciudadano es noble, se une detrás de sus pares nobles, adelantándose a los plebeyos.
        if (val.isNoble) {
            DrxQueue<Citizen>::push(val);
        }

        // c) Re-encolar Plebeyos en orden FIFO original.
        while (!plebeyos.isEmpty()) {
            DrxQueue<Citizen>::push(plebeyos.front());
            plebeyos.pop();
        }

        // d) Si el nuevo ciudadano es plebeyo, se encola al final absoluto, respetando el orden de llegada.
        if (!val.isNoble) {
            DrxQueue<Citizen>::push(val);
        }
    }
};


int main() {
    std::cout << "\n\e[0;35m[========= E11-COLA-MEDIEVAL =========]\e[0m\n\n";

    MedievalQueue queue;
    std::cout << "1. Encolando plebeyo: Juan\n";
    queue.push({"Juan", false});
    std::cout << "2. Encolando plebeyo: Pedro\n";
    queue.push({"Pedro", false});
    std::cout << "3. Encolando noble: Arturo\n";
    queue.push({"Arturo", true});
    std::cout << "4. Encolando plebeyo: Maria\n";
    queue.push({"Maria", false});
    std::cout << "5. Encolando noble: Lanzarote\n";
    queue.push({"Lanzarote", true});

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Orden de atención en la cola medieval:\n";
    while (!queue.isEmpty()) {
        std::cout << "  Atendiendo a: " << queue.front() << "\n";
        queue.pop();
    }
    std::cout << "\n";

    return 0;
}
