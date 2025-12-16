#include <stdio.h>
#include <stdlib.h>
#include "pilhamult.h"
void inicializa_pilhas(Pilhamult *pm)
{
    pm->num_elemp = TAM_PILHA/NUM_PILHA;
    for(int i=0;i<NUM_PILHA;i++)
    {
       pm->base[i]=pm->num_elemp*i;
       pm->topo[i]=pm->base[i];
    }
}
int se_cheia(Pilhamult *pm,int num_pilha)
{
    if((pm->topo[num_pilha]-pm->base[num_pilha])==pm->num_elemp-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int se_vazia(Pilhamult *pm,int num_pilha)
{
    if(pm->base[num_pilha]==pm->topo[num_pilha])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(Pilhamult *pm,int num_pilha,char caract)
{
    if(se_cheia(pm,num_pilha))
    {
        printf("Essa pilha está cheia!\n");
        return;
    }
    else
    {
        pm->pilha[pm->topo[num_pilha]]=caract;
        pm->topo[num_pilha]++;
    }
}
void pop(Pilhamult *pm,int num_pilha,char *caract)
{
    if(se_vazia(pm,num_pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }
    else
    {
        *caract=pm->pilha[pm->topo[num_pilha]-1];
        pm->topo[num_pilha]--;
    }
}
void obtertopo(Pilhamult *pm,int num_pilha,char *carct)
{
    if(se_vazia(pm,num_pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }
    else
    {
        *carct=pm->pilha[pm->topo[num_pilha]-1];
    }
}
