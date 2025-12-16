#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listagen.h"
void inicializarLG(ListaGen* listg)
{
    listg->inicio = NULL;
    listg->fim = NULL;
}
int verifVaziaLG(ListaGen* listg)
{
    if(!listg->inicio)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void inserirInicioArquivoLG(ListaGen* listg,char nome[],int tamanho)
{
    NoLista *novoNo = malloc(sizeof(NoLista));
    novoNo->tipo = 0;
    strcpy(novoNo->atomo.arq.nome,nome);
    novoNo->atomo.arq.bytes = tamanho;

    if(verifVaziaLG(listg))
    {
        listg->inicio = novoNo;
        listg->fim = novoNo;
        novoNo->ant = NULL;
        novoNo->prox = NULL;
    }
    else
    {
        listg->inicio->ant = novoNo;
        novoNo->prox = listg->inicio;
        listg->inicio = novoNo;
        novoNo->ant = NULL;
    }
}
void inserirInicioDiretorioLG(ListaGen* listg,char nome[],int tamanho)
{
    NoLista *noNovo = malloc(sizeof(NoLista));
    noNovo->tipo = 1;
    noNovo->atomo.dir.byts = tamanho;
    strcpy(noNovo->atomo.dir.name,nome);
    noNovo->atomo.dir.sublista = NULL;
    if(verifVaziaLG(listg))
    {
        listg->inicio = noNovo;
        listg->fim = noNovo;
        noNovo->ant = NULL;
        noNovo->prox = NULL;
    }
    else
    {
        listg->inicio->ant = noNovo;
        noNovo->prox = listg->inicio;
        listg->inicio = noNovo;
        noNovo->ant = NULL;
    }
}
void removerInicioLG(ListaGen* listg)
{
    if(verifVaziaLG(listg))
    {
        printf("Lista esta vazia!");
        return;
    }
    else
    {
        NoLista *temp;
        temp = listg->inicio;
        if(listg->inicio->tipo == 0)
        {
            listg->inicio = listg->inicio->prox;
            if(!listg->inicio)
            {
                listg->fim = NULL;
            }
            else
            {
                listg->inicio->ant = NULL;
            }
            free(temp);
            return;
        }
        else if(listg->inicio->tipo == 1)
        {
            NoLista *aux;
            aux = listg->inicio->atomo.dir.sublista;
            while(aux)
            {
                NoLista *aux2;
                aux2 = aux;
                aux = aux->prox;
                free(aux2);
            }
            listg->inicio = listg->inicio->prox;
            if(!listg->inicio)
            {
                listg->fim = NULL;
            }
            else
            {
                listg->inicio->ant = NULL;
            }
            free(temp);
        }
    }
}
void imprimirListaGen(ListaGen *listg)
{
    if (verifVaziaLG(listg)) {
        printf("Lista vazia!\n");
        return;
    }

    imprimirLGRecur(listg->inicio);
}
void imprimirLGRecur(NoLista *no)
{
    if(!no)
    {
        return;
    }
    printf("(");
    if(no->tipo==0)
    {
        printf("%s",no->atomo.arq.nome);
        printf("%d",no->atomo.arq.bytes);
    }
    else if(no->tipo==1)
    {
        printf("%s",no->atomo.dir.name);
        printf("%d",no->atomo.dir.byts);
        ListaGen subLista;
        subLista.inicio = no->atomo.dir.sublista;
        subLista.fim = NULL;
        imprimirListaGen(&subLista);
    }
    if(no->prox)
    {
        printf(";");
        imprimirLGRecur(no->prox);
    }
    printf(")");
}
void buscaNome(ListaGen *listg,char nomearq[],int tamanho)
{
    NoLista *temp = listg->inicio;
    if(verifVaziaLG(listg))
    {
        printf("A lista esta vazia!");
        return;
    }
    while(temp)
    {
        if(temp->tipo == 0)
        {
            if(strcmp(temp->atomo.arq.nome,nomearq)==0)
            {
                printf("Esta na lista");
                return;
            }
        }
        else
        {
            if(temp->tipo==1)
            {
                ListaGen subLista;
                subLista.inicio = temp->atomo.dir.sublista;
                subLista.fim = NULL;
                buscaNome(&subLista,nomearq,tamanho);
            }
        }
        temp = temp->prox;
    }
    printf("Nao esta na lista");

}
