#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
void inicializar(Fila *fila)
{
    fila->inicio=0;
    fila->fim=0;
    fila->contador_elem=0;
}
int se_vazia(Fila *fila)
{
    if(!fila->contador_elem)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int se_cheia(Fila *fila)
{
    if((fila->fim+1)%MAX==fila->inicio)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void inserir(Fila *fila,int elem)
{
    if(se_cheia(fila))
    {
        printf("Fila cheia!\n");
        return;
    }
    else
    {
        fila->vFila[fila->fim] = elem;
        fila->contador_elem++;
        fila->fim = (fila->fim+1)%MAX;

    }
}
void remover(Fila *fila,int *elem)
{
    if(se_vazia(fila))
    {
        printf("Fila vazia!\n");
        return;
    }
    *elem = fila->vFila[fila->inicio];
    fila->contador_elem--;
    fila->inicio=(fila->inicio+1)%MAX;

}
void obter_ini(Fila *fila,int *elem)
{
    if(se_vazia(fila))
    {
        printf("Fila vazia!\n");
        return;
    }
    else
    {
        *elem = fila->vFila[fila->inicio];
    }
}
int qnt_elem(Fila *fila)
{
    return fila->contador_elem;
}
