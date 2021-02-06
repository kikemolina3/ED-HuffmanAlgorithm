#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

/* Definicio de tipus */
typedef struct
{
    Tree *v;
    int cima, elems_max;
}Pila;

/* Capçaleres de funcions */
Pila Crear_pila();
bool EsBuida_pila (Pila p);
Tree Cim_pila (Pila p);
Pila Apilar_pila(Pila p, Tree elem);
Pila Desapilar_pila(Pila p);
bool EsPlena_pila (Pila p);
void Destruir_pila(Pila p);
