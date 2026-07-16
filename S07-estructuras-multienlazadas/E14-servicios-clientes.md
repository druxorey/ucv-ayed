<h1 align="center">E14 - Modelo de Relación Muchos a Muchos para DigitelUCV</h1>

> [!TLDR]
> Se usa una **lista cruzada** con `ContratoNode` como nodo de intersección que enlaza cada cliente con cada servicio. Permite consultar los servicios de un cliente en $O(S)$ y los clientes de un servicio en $O(C)$ sin duplicar datos.

## Enunciado

Proponga una representación utilizando estructuras enlazadas para modelar el caso de DigitelUCV (Clientes contratando múltiples servicios).

## Propuesta de Diseño: Estructura de Lista Cruzada (Crossed List)

Para evitar duplicar información tanto de clientes como de servicios, se propone utilizar una **Lista Cruzada** similar a una matriz esparcida:

```text
    [Cliente 1] ---> [Contrato A] ----------> [Contrato C]
                           |                       |
                           v                       v
    [Servicio 1] ---> [Contrato A]
                           |
                           v
    [Servicio 2] ---------------------------> [Contrato C]
```

### 1. Nodo Cliente (`ClienteNode`)

Contiene los datos del cliente y un puntero de cabecera a su lista de contratos:

```cpp
struct ContratoNode; // Declaración hacia adelante

struct ClienteNode {
    std::string cedula;
    std::string nombre;
    std::string direccion;
    std::string telefono;
    
    ContratoNode* primerContrato; // Cabecera de la lista de servicios del cliente
};
```

### 2. Nodo Servicio (`ServicioNode`)

Contiene los datos del servicio y un puntero de cabecera a la lista de clientes contratados:

```cpp
struct ServicioNode {
    std::string codigo;
    std::string descripcion;
    double costoMensual;
    
    ContratoNode* primerCliente; // Cabecera de la lista de clientes del servicio
};
```

### 3. Nodo de Intersección Contrato (`ContratoNode`)

Este es el nodo cruzado que une a un cliente con un servicio específico. Almacena punteros directos hacia los objetos principales y los enlaces de navegación secuencial:

```cpp
struct ContratoNode {
    ClienteNode* cliente;   // Enlace al cliente propietario
    ServicioNode* servicio; // Enlace al servicio contratado
    std::string fechaContratacion; // Datos del contrato en sí
    
    ContratoNode* sigServicioCliente; // Siguiente servicio contratado por el mismo cliente
    ContratoNode* sigClienteServicio; // Siguiente cliente que contrató el mismo servicio
};
```

## Análisis de Operaciones Beneficiadas

1. **Consultar todos los servicios de un cliente:** Se accede a `cliente->primerContrato` y se recorre usando `sigServicioCliente` en tiempo $O(S)$ donde $S$ es el número de servicios de ese cliente.

2. **Consultar todos los clientes de un servicio:** Se accede a `servicio->primerCliente` y se recorre usando `sigClienteServicio` en tiempo $O(C)$ donde $C$ es el número de clientes que contrataron el servicio.

3. **Bajo Consumo de Memoria:** No hay datos redundantes; la información de cada cliente y de cada servicio reside en un solo lugar del Heap. Los contratos son solo celdas con punteros de enlace.
