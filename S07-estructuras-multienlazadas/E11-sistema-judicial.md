# E11 - Diseño del Sistema Judicial (Estructuras Multienlazadas)

> [!TLDR]
> Se usa una **lista cruzada**: cada `PresoNode` tiene dos punteros (`nextInTribunal` y `nextInCarcel`). Los tribunales y cárceles son cabeceras de listas. Esto evita duplicar datos y permite acceso $O(1)$ a los presos de cada entidad.

## Enunciado

El Poder Judicial ha decidido implementar un sistema que permita llevar un control eficiente de los tribunales y cárceles con que cuenta la nación. Dicho sistema debe satisfacer los requerimientos de listado y consultas.

## Problema
Diseñar una representación mediante estructuras de datos enlazadas para modelar el sistema judicial del país, donde existen:
1.  **Tribunales:** Cada tribunal tiene un conjunto de presos bajo su jurisdicción.
2.  **Cárceles:** Cada cárcel alberga un grupo de presos físicamente.
3.  **Presos:** Cada preso está físicamente en una cárcel y legalmente asignado a un tribunal.

## Propuesta de Representación Multienlazada

Para resolver este problema de forma eficiente (evitando duplicar los datos de los presos o realizar búsquedas costosas de $O(N)$), se propone una estructura de **Lista Cruzada (Crossed List)**:

```text
    [Tribunal 1] ---> [Preso A] ------------> [Preso D]
                           |                      |
                           v                      v
    [Cárcel 1]   ---> [Preso A] ---> [Preso B]
                           |
                           v
    [Cárcel 2]   ------------------> [Preso D]
```

### 1. Estructura de Nodo Preso (`PresoNode`)
El preso es el nodo de intersección. Contiene la información del preso y dos punteros de enlace (siguiente en el tribunal y siguiente en la cárcel):
```cpp
struct PresoNode {
    std::string cedula;
    std::string nombre;
    std::string delito;
    
    PresoNode* nextInTribunal; // Enlace al siguiente preso del mismo tribunal
    PresoNode* nextInCarcel;   // Enlace al siguiente preso en la misma cárcel
};
```

### 2. Estructura de Nodo Tribunal (`TribunalNode`)
Cada tribunal encabeza una lista de presos bajo su tutela legal:
```cpp
struct TribunalNode {
    std::string codigoTribunal;
    std::string juez;
    PresoNode* listaPresos; // Puntero al primer preso de este tribunal (nextInTribunal)
};
```

### 3. Estructura de Nodo Cárcel (`CarcelNode`)
Cada cárcel encabeza una lista de presos físicamente recluidos en ella:
```cpp
struct CarcelNode {
    std::string nombreCarcel;
    std::string ubicacion;
    PresoNode* listaPresos; // Puntero al primer preso de esta cárcel (nextInCarcel)
};
```

## Ventajas del Diseño
1.  **Cero Duplicación:** Los datos de cada preso se almacenan en un único objeto físico `PresoNode` en el Heap.
2.  **Acceso en $O(1)$:** Es posible saber instantáneamente qué presos están en una cárcel o tribunal recorriendo el enlace respectivo sin necesidad de buscar en todo el sistema.
