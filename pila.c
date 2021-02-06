#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "pila.h"
#include "tree.h"

Pila Crear_pila(int elems)
{
    Pila p;
    p.v=(int*)malloc(sizeof(Tree)*elems);
    p.elems_max=elems;
    p.cima=0;
    if(p.v==NULL) printf("La pila no se ha podido crear. No hay espacio. \n");
    return p;
}

bool EsBuida_pila(Pila p)
{
    return(p.cima==0);
}

bool EsPlena_pila(Pila p)
{
    return(p.elems_max==p.cima);
}

Tree Cim_pila(Pila p)
{
    if(EsBuida_pila(p))
    {
        printf("La pila esta vacia.\n");
        return -1;
    } // --> ERR pila vacía
    else
    {
        return p.v[p.cima];
    }
}

Pila Apilar_pila(Pila p, Tree elem)
{
    if(EsPlena_pila(p))
    {
        printf("Error no se ha podido apilar. Pila llena \n");
        return p;
    }
    p.cima+=1;
    p.v[p.cima]=elem;
    return p;
}

Pila Desapilar_pila(Pila p)
{
    if(EsBuida_pila(p))  // --> ERR  pila vacia
    {
        printf("Error desapilamiento. Pila vacia\n");
        return p;
    }
    else
    {
        p.cima-=1;
    }
    return p;
}

void Destruir_pila(Pila p)
{
    free(p.v);
}

