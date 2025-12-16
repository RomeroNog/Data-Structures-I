#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
void inicializarDeque(Deque* deq)
{
    deq->inicio = NULL;
    deq->fim = NULL;
}
int verifVazia(Deque* deq)
{
    if(!deq->inicio)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void inserirInicio(Deque* deq,int elem)
{
    noDuplo *novoNo = malloc(sizeof(noDuplo));
    novoNo->elem = elem;

    if(verifVazia(deq))
    {
        deq->inicio = novoNo;
        deq->fim = novoNo;
        novoNo->ant = NULL;
        novoNo->prox = NULL;
    }
    else
    {
        deq->inicio->ant = novoNo;
        novoNo->ant = NULL;
        novoNo->prox = deq->inicio;
        deq->inicio = novoNo;
    }
}
void inserirFim(Deque* deq,int elem)
{
    noDuplo *novoNo = malloc(sizeof(noDuplo));
    novoNo->elem = elem;
    if(verifVazia(deq))
    {
        deq->inicio = novoNo;
        deq->fim = novoNo;
        novoNo->ant = NULL;
        novoNo->prox = NULL;
    }
    else
    {
        deq->fim->prox = novoNo;
        novoNo->prox = NULL;
        novoNo->ant = deq->fim;
        deq->fim = novoNo;
    }
}
void removerInicio(Deque* deq,int* elem)
{
    noDuplo *aux;
    if(verifVazia(deq))
    {
        printf("Deque vazio!\n");
        return;
    }
    else
    {
        aux = deq->inicio;
        *elem = aux->elem;
        deq->inicio = deq->inicio->prox;
        if(!deq->inicio)
        {
            deq->fim = NULL;
        }
        else
        {
            deq->inicio->ant = NULL;
        }
        free(aux);
    }
}
void removerFim(Deque* deq,int* elem)
{
    if(verifVazia(deq))
    {
        printf("Deque vazio!\n");
        return;
    }
    else
    {
        noDuplo *aux;
        aux = deq->fim;
        *elem = aux->elem;
        deq->fim = deq->fim->ant;
        if(!deq->fim)
        {
            deq->inicio = NULL;
        }
        else
        {
            deq->fim->prox = NULL;
        }
        free(aux);
    }
}
void consultaInicio(Deque* deq,int* elem)
{
    if(verifVazia(deq))
    {
        printf("Deque vazio!\n");
        return;
    }
    else
    {
        *elem = deq->inicio->elem;
    }
}
void consultaFim(Deque* deq,int* elem)
{
    if(verifVazia(deq))
    {
        printf("Deque vazio!\n");
        return;
    }
    else
    {
        *elem = deq->fim->elem;
    }
}

