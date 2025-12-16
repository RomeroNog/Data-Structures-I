#include <stdio.h>
#include <stdlib.h>
#include "ListaCruzada.h"
void inicializarLC(ListaCruzada* listC)
{
    for(int i=0;i<I;i++)
    {
        listC->linha[i] = NULL;
    }
    for(int j=0;j<J;j++)
    {
        listC->coluna[j] = NULL;
    }
}
void inserirLC(ListaCruzada* listC,int elem,int lin,int col)
{
    No *novo = malloc(sizeof(No));
    novo->elem = elem;
    novo->linha = lin;
    novo->coluna = col;
    novo->direita = NULL;
    novo->baixo = NULL;

    //linha vazia
    if(!listC->linha[lin])
    {
        listC->linha[lin] = novo;
    }
    //se a linha nao for vazia
    else
    {
        //2 nos para percorrer, um para o atual e outro do anterior para facilitar o manuseio
        No *percorreLinAnt = NULL;
        No *percorreLinAtual = listC->linha[lin];
        //vai percorrendo a linha(passa da 1 ate a ultima col, enqt eu nao no prox existente ao que eu quero)
        while(percorreLinAtual && col>percorreLinAtual->coluna)
        {
            percorreLinAnt = percorreLinAtual;
            percorreLinAtual = percorreLinAtual->direita;
        }
        //se atual nao for nulo
        if(percorreLinAtual)
        {
            //verifico se ja nao existe
            if(col == percorreLinAtual->coluna)
            {
                printf("Elemento ja existente nessa coluna!\n");
                return;
            }
            //caso oq eu for inserir seja no inicio (1 elem)
            if(!percorreLinAnt)
            {
                listC->linha[lin] = novo;
                novo->direita  = percorreLinAtual;
            }
            //insere no meio da linha (onde eu quero)
            else
            {
                novo->direita = percorreLinAtual;
                percorreLinAnt->direita = novo;
            }
        }
        //se o atual for nulo ent ele щ o ultimo, logo щ uma inserчуo no fim
        else
        {
            percorreLinAnt->direita = novo;
        }
    }
    //agora nao esquecer de ligar em relaчуo a coluna
    //ve se a coluna esta vazia 1А
    if(!listC->coluna[col])
    {
        listC->coluna[col] = novo;
    }
    //se nao estiver vazia devemos ver onde vamos inserir em rela a col
    else
    {
        //dois ptr para percorrer, o ant щ para aux
        No *percorreColAtual = listC->coluna[col];
        No *percorreColAnt = NULL;
        //atualiza o percorre enqt ele nao for nulo e ficara no final no nó da linha a frente ao desejado, seja o atual nulo  ou nao
        while(percorreColAtual && lin>percorreColAtual->linha)
        {
            percorreColAnt = percorreColAtual;
            percorreColAtual = percorreColAtual->baixo;
        }

        //com o atual nao nulo
        if(percorreColAtual)
        {
            //vejo se na linha que o atual ja existe
            if(lin == percorreColAtual->linha)
            {
                printf("Elemento ja existente nessa linha!\n");
                return;
            }
            //caso o que eu for inserir for na 1 linha  o anterior serс nulo
            if(!percorreColAnt)
            {
                listC->coluna[col] = novo;
                novo->baixo = percorreColAtual;
            }
            //insere no meio
            else
            {
                novo->baixo = percorreColAtual;
                percorreColAnt->baixo = novo;
            }
        }
        //caso o atualCol for nulo (percorre da linha 0 a N),ultimo elem da col
        else
        {
            percorreColAnt->baixo = novo;
        }
    }
}
void imprimirLC(ListaCruzada* listC)
{
    printf("\n");
    for(int i=0;i<I;i++)
    {
        No *aux = listC->linha[i];
        for(int j=0;j<J;j++)
        {
            if(aux && aux->coluna == j)
            {
                printf("%d ",aux->elem);
                aux = aux->direita;
            }
            else
            {
                printf("0 ");
            }

        }

        printf("\n");
    }
    printf("\n");
}
void removerLC(ListaCruzada* listC,int lin,int col,int* elem)
{
    No *auxAtualLinha = listC->linha[lin];
    No *auxAntLinha = NULL;

    No *auxAtualCol = listC->coluna[col];
    No *auxAntCol = NULL;

    if(!listC->linha[lin])
    {
        printf("Elemento nao existente!\n");
        return;
    }
    else
    {
        while(auxAtualLinha->coluna<col && auxAtualLinha)
        {
            auxAntLinha = auxAtualLinha;
            auxAtualLinha = auxAtualLinha->direita;
        }
        if(auxAtualLinha && auxAtualLinha->coluna == col)
        {
            if(!auxAntLinha)
            {
                *elem = auxAtualLinha->elem;
                listC->linha[lin] = auxAtualLinha->direita;
            }
            else
            {
                *elem = auxAtualLinha->elem;
                auxAntLinha->direita = auxAtualLinha->direita;
            }
        }
        else
        {
            printf("Elemento nao existente!\n");
            return;
        }
    }
    if(!listC->coluna[col])
    {
        printf("Elemento nao existente!\n");
        return;
    }
    else
    {
        while(auxAtualCol->linha<lin && auxAtualCol)
        {
            auxAntCol = auxAtualCol;
            auxAtualCol = auxAtualCol->baixo;
        }
        if(auxAtualCol && auxAtualCol->linha == lin)
        {
            if(!auxAntCol)
            {
                listC->coluna[col] = auxAtualCol->baixo;
            }
            else
            {
                auxAntCol->baixo = auxAtualCol->baixo;
            }
            free(auxAtualCol);
        }
        else
        {
            printf("Elemento nao existente!\n");
            return;
        }
    }
}
void soma(ListaCruzada* listC,int lin,int constante)
{
    No *aux = listC->linha[lin];
    for(int j=0;j<J;j++)
    {
        if(aux && aux->coluna == j)
        {
            aux->elem +=constante;
            aux = aux->direita;
        }
        else
        {
            inserirLC(listC,constante,lin,j);
        }
    }
}
