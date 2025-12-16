#ifndef PILHA_H
#define PILHA_H

typedef struct noPilha
{
    int elemento;
    struct noPilha *prox;
}noPilha;
typedef struct
{
    struct noPilha *topo;
}Pilha;
void inicializa_pilha(Pilha *pilha);
int se_vazia(Pilha *pilha);
void push(Pilha *pilha,int elem);
void pop(Pilha *pilha,int *elem);
void obter_topo(Pilha *pilha,int *elem);
void reinicializa(Pilha *pilha);
#endif
