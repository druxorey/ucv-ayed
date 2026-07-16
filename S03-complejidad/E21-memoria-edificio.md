<h1 align="center">E21 - Análisis de Memoria de la Variable Avenida</h1>

> [!TLDR]
> `Persona` = 573 bytes, `JuntaCondominio[10]` = 5,730 bytes, `Edificio` = 5,884 bytes. El arreglo `Avenida[25]` ocupa $25 \times 5884 = 147,100$ bytes (~143.65 KB).

## Enunciado

Considere las siguientes definiciones de tipo:

```cpp
struct Persona {
    char Nombre[50];
    bool EdoCivil;
    bool Sexo;
    int Edad;
    char DirTrab[512];
    int CI_Rif;
    bool PersonaJuridica;
};
Persona JuntaCondominio[10];

struct Edificio {
    char Nombre[50];
    int CantApartamentos;
    JuntaCondominio Junta; // Asumido como un arreglo del tipo Persona
    char Direccion[100];
};
Edificio Avenida[25];
```

Indique el costo en memoria de la variable `Avenida`.

## Respuesta

### 1. Estructura `Persona`

Sumamos los campos individuales en bytes:

- `Nombre`: $50 \times \text{size}(char) = 50 \text{ bytes}$
- `EdoCivil`: $\text{size}(bool) = 1 \text{ byte}$
- `Sexo`: $\text{size}(bool) = 1 \text{ byte}$
- `Edad`: $\text{size}(int) = 4 \text{ bytes}$
- `DirTrab`: $512 \times \text{size}(char) = 512 \text{ bytes}$
- `CI_Rif`: $\text{size}(int) = 4 \text{ bytes}$
- `PersonaJuridica`: $\text{size}(bool) = 1 \text{ byte}$

$$\text{Tamaño de Persona} = 50 + 1 + 1 + 4 + 512 + 4 + 1 = 573 \text{ bytes}$$

### 2. Variable `JuntaCondominio`

Es un arreglo estático que contiene exactamente 10 elementos de tipo `Persona`:

$$\text{Tamaño de JuntaCondominio} = 10 \times \text{size}(Persona) = 10 \times 573 \text{ bytes} = 5,730 \text{ bytes}$$

### 3. Estructura `Edificio`

Sumamos los campos de un edificio:

- `Nombre`: $50 \times 1 \text{ byte} = 50 \text{ bytes}$
- `CantApartamentos`: $\text{size}(int) = 4 \text{ bytes}$
- `Junta`: $\text{size}(JuntaCondominio) = 5,730 \text{ bytes}$ (arreglo anidado de 10 personas)
- `Direccion`: $100 \times 1 \text{ byte} = 100 \text{ bytes}$

$$\text{Tamaño de Edificio} = 50 + 4 + 5,730 + 100 = 5,884 \text{ bytes}$$

La variable `Avenida` es un arreglo estático de 25 elementos de tipo `Edificio`:
$$\text{Memoria total de Avenida} = 25 \times 5,884 \text{ bytes} = 147,100 \text{ bytes}$$

En kilobytes:

$$\text{Memoria total} \approx 143.65 \text{ KB}$$
