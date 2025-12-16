#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"
void imprimir_pilha(Pilha *pilha) {
    if (se_vazia(pilha)) {
        printf("A pilha está vazia.\n");
        return;
    }
    noPilha *atual = pilha->topo;
    printf("Elementos da pilha: ");
    while (atual) {
        printf("%d ", atual->elemento);
        atual = atual->prox;
    }
    printf("\n");
}
int main()
{
    Pilha pilha;
    inicializa_pilha(&pilha);
    push(&pilha,7);
    push(&pilha,9);
    push(&pilha,4);
    printf("Valores: \n");
    while(!se_vazia(&pilha))
    {
        int topo;
        pop(&pilha,&topo);
        printf("%d ",topo);
    }
    Pilha pi;
    inicializa_pilha(&pi);
    push(&pi,7);
    push(&pi,5);
    push(&pi,4);
    push(&pi,3);
    for(int i=0;i<5;i++)
    {
        int top;
        push(&pi,pop(&pi,&top));
    }
    imprimir_pilha(&pi);

return 0;
}
