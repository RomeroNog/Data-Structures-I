#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
void inicializarAvl(noAvl **avl)
{
    *avl = NULL;
}
int verif_vaziaAvl(noAvl *avl)
{
    if(!avl) return 1;
    return 0;
}
int alturaAvl(noAvl *avl)
{
    int he,hd;
    if(!avl) return -1;
    else
    {
        he = alturaAvl(avl->esq);
        hd = alturaAvl(avl->dir);
        if(he<hd) return hd+1;
        return he+1;
    }
}
void inserirAvl(noAvl **avl,int elem)
{
    noAvl *newNo = malloc(sizeof(noAvl));
    newNo->elem = elem;
    newNo->fb = 0;
    newNo->esq = NULL;
    newNo->dir = NULL;
    newNo->pai = NULL;

    if(verif_vaziaAvl(*avl))
    {
        *avl = newNo;
        printf("Elemento %d inserido com sucesso!\n",elem);
        refazerBalanAvl(avl);
        salvarEmArq(newNo);
        return;
    }
    else
    {
        noAvl *aux = *avl;
        if(aux->elem == elem)
        {
            printf("Elemento ja se encontra na arvore!\n");
            return;
        }
        if(aux->elem > elem)
        {
            if(!aux->esq)
            {
                aux->esq = newNo;
                newNo->pai = aux;
                printf("Elemento %d inserido com sucesso!\n",elem);
                refazerBalanAvl(avl);
                salvarEmArq(newNo);
                return;
            }
            else
            {
                free(newNo);
                inserirAvl(&(aux->esq),elem);
            }
        }
        if(aux->elem<elem)
        {
            if(!aux->dir)
            {
                aux->dir = newNo;
                newNo->pai = aux;
                printf("Elemento %d inserido com sucesso!\n",elem);
                refazerBalanAvl(avl);
                salvarEmArq(newNo);
                return;
            }
            else
            {
                free(newNo);
                inserirAvl(&(aux->dir),elem);
            }
        }
    }
}
void refazerBalanAvl(noAvl **avl)
{
    if(!*avl) return;

    refazerBalanAvl(&((*avl)->esq));
    refazerBalanAvl(&((*avl)->dir));
    (*avl)->fb = alturaAvl((*avl)->dir)-alturaAvl((*avl)->esq);


    if((*avl)->fb == -2)
    {
        if((*avl)->esq && (*avl)->esq->fb <=0)
        {
            rotacaoDirAvl(avl);
        }
        else
        {
            rotacaoEsqAvl(&((*avl)->esq));
            rotacaoDirAvl(avl);
        }
    }
    if((*avl)->fb == 2)
    {
        if((*avl)->dir && (*avl)->dir->fb >=0)
        {
            rotacaoEsqAvl(avl);
        }
        else
        {
            rotacaoDirAvl(&((*avl)->dir));
            rotacaoEsqAvl(avl);
        }
    }


}
void rotacaoEsqAvl(noAvl **avl)
{
    noAvl *q, *temp;
    q = (*avl)->dir;
    temp = q->esq;
    q->esq = *avl;
    (*avl)->dir = temp;

    q->pai = (*avl)->pai;
    (*avl)->pai = q;
    if(temp) temp->pai = *avl;


    (*avl)->fb = alturaAvl((*avl)->dir) - alturaAvl((*avl)->esq);
    q->fb = alturaAvl(q->dir) - alturaAvl(q->esq);
    *avl = q;


}
void rotacaoDirAvl(noAvl **avl)
{
    noAvl *q,*temp;
    q = (*avl)->esq;
    temp = q->dir;
    q->dir = *avl;
    (*avl)->esq = temp;

    q->pai = (*avl)->pai;
    (*avl)->pai = q;
    if(temp) temp->pai = *avl;

    //recalculo do fb pos balancear
    (*avl)->fb = alturaAvl((*avl)->dir) - alturaAvl((*avl)->esq);
    q->fb = alturaAvl(q->dir) - alturaAvl(q->esq);
    *avl = q;

}
noAvl* buscaNoAvl(noAvl **avl,int elem)
{
    if(verif_vaziaAvl(*avl))
    {
        return NULL;
    }
    else
    {
        noAvl *aux = *avl;
        if(aux->elem == elem)
        {
            printf("Elemento encontrado!\n");
            return aux;
        }
        if(aux->elem>elem)
        {
            return buscaNoAvl(&((*avl)->esq),elem);
        }
        else
        {
            return buscaNoAvl(&((*avl)->dir),elem);
        }
    }
}
noAvl* buscaAntecessorAvl(noAvl **avl,int elem,noAvl *ant)
{
    if(verif_vaziaAvl(*avl))
    {
        return NULL;
    }
    else
    {
        noAvl *aux = *avl;
        if(aux->elem == elem)
        {
            return ant;
        }
        if(aux->elem > elem)
        {
            return buscaAntecessorAvl(&((*avl)->esq),elem,aux);
        }
        else
        {
            return buscaAntecessorAvl(&((*avl)->dir),elem,aux);
        }
    }




}
noAvl* buscaSubstAvl(noAvl **avl,int elem)
{
    if(verif_vaziaAvl(*avl))
    {
        return NULL;
    }
    else
    {
        noAvl *aux = *avl;
        if(aux->elem == elem)
        {
            printf("Elemento encontrado!\n");
            noAvl *antaux = NULL;
            if(aux->esq)
            {
                antaux = aux;
                aux = aux->esq;
                while(aux->dir)
                {
                    antaux = aux;
                    aux = aux->dir;
                }
                return aux;
            }
            if(aux->dir)
            {
                antaux = aux;
                aux = aux->dir;
                while(aux->esq)
                {
                    antaux = aux;
                    aux = aux->esq;
                }
                return aux;
            }
            else
            {
                return NULL;
            }

        }
        if(aux->elem > elem)
        {
            return buscaSubstAvl(&((*avl)->esq),elem);
        }
        else
        {
            return buscaSubstAvl(&((*avl)->dir),elem);
        }

    }
}
void removerNoAvl(noAvl **avl,int elem)
{
    if(verif_vaziaAvl(*avl))
    {
        return;
    }
    else
    {
        noAvl *remocao = buscaNoAvl(avl,elem);
        if(!remocao)
        {
            printf("Elemento não encontrado!\n");
            return;
        }
        noAvl *ant = buscaAntecessorAvl(avl,elem,NULL);
        if(!remocao->esq && !remocao->dir)
        {
            if(ant)
            {
                if(ant->esq == remocao) ant->esq = NULL;
                else ant->dir = NULL;
            }
            else
            {
                *avl = NULL;
            }
            free(remocao);
            removerEmArq(elem);
        }
        else if(!remocao->esq || !remocao->dir)
        {
            noAvl *fi;
            if(remocao->esq) fi = remocao->esq;
            else fi = remocao->dir;
            if(ant)
            {
                if(ant->esq == remocao) ant->esq = fi;
                else ant->dir = fi;
            }
            else
            {
                *avl = fi;
            }

            free(remocao);
            removerEmArq(elem);
        }
        else
        {
            noAvl *subst = buscaSubstAvl(avl,elem);
            if(subst)
            {
                int v = subst->elem;
                removerNoAvl(avl,v);
                remocao->elem = v;
            }
        }
        refazerBalanAvl(avl);
    }
}
void imprimirPreOrdemAvl(noAvl **avl)
{
    noAvl *aux = *avl;
    if(aux)
    {
        printf("%d ",aux->elem);
        imprimirPreOrdemAvl(&(aux->esq));
        imprimirPreOrdemAvl(&(aux->dir));
    }
}
void imprimirEmOrdemAvl(noAvl **avl)
{
    noAvl *aux = *avl;
    if(aux)
    {
        imprimirEmOrdemAvl(&(aux->esq));
        printf("%d ",aux->elem);
        imprimirEmOrdemAvl(&(aux->dir));
    }
}
void imprimirPosOrdemAvl(noAvl **avl)
{
    noAvl *aux = *avl;
    if(aux)
    {
        imprimirPosOrdemAvl(&(aux->esq));
        imprimirPosOrdemAvl(&(aux->dir));
        printf("%d ",aux->elem);
    }
}
void salvarEmArq(noAvl *avl)
{
    FILE *arq = fopen("palmeiras.bin", "ab");
    if(!arq)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fwrite(avl, sizeof(noAvl), 1, arq);

    fclose(arq);
}
void removerEmArq(int elem)
{
    FILE *arq = fopen("palmeiras.bin","rb");
    FILE *arqaux = fopen("temp.bin","wb");
    if(!arq || !arqaux)
    {
        printf("Erro ao abrir um dos arquivo!\n");
        return;
    }
    noAvl aux;
    while(fread(&aux,sizeof(noAvl),1,arq)==1)
    {
        if(aux.elem!=elem)
        {
            fwrite(&aux,sizeof(noAvl),1,arqaux);
        }
    }
    fclose(arq);
    fclose(arqaux);
    remove("palmeiras.bin");
    rename("temp.bin","palmeiras.bin");
}
noAvl* recuperarAvlArq(noAvl **avl,FILE *arq)
{
    noAvl temp;
    if(fread(&temp,sizeof(noAvl),1,arq)==1)
    {
        inserirAvl(avl,temp.elem);
        recuperarAvlArq(avl,arq);

    }
}
void salvarAvlArq(noAvl **avl,FILE *arq)
{
    noAvl *aux = *avl;
    if(*avl)
    {
        fwrite(*avl,sizeof(noAvl),1,arq);
        salvarAvlArq(&((*avl)->esq),arq);
        salvarAvlArq(&((*avl)->dir),arq);
    }
}
int EhBB(noAvl **avl)
{
    if(!*avl) return 1;

    if(!EhBB(&((*avl)->esq))) return 0;
    if(!EhBB(&((*avl)->dir))) return 0;

    noAvl *aux = *avl;
    int esq = verifEsq(aux);
    int dir = verifDir(aux);


    if(esq && dir) return 1;
    else return 0;
}
int verifEsq(noAvl *avl)
{
    if(!avl || !avl->esq) return 1;

    if(avl->elem < avl->esq->elem) return 0;

    noAvl *temp = avl->esq;
    while (temp->dir) temp = temp->dir;

    if (temp->elem >= avl->elem) return 0;
    return 1;
}
int verifDir(noAvl *avl)
{
    if(!avl || !avl->dir) return 1;

    if(avl->dir->elem <= avl->elem) return 0;

    noAvl *temp = avl->dir;
    while (temp->esq) temp = temp->esq;

    if (temp->elem <= avl->elem) return 0;
    return 1;
}
int EhAvl(noAvl **avl)
{
    if(!*avl) return 1;

    if(!EhBB(avl)) return 0;

    if(!EhAvl(&((*avl)->esq))) return 0;
    if(!EhAvl(&((*avl)->dir))) return 0;

    noAvl *aux = *avl;
    if(aux->fb>1 || aux->fb<-1) return 0;
    else return 1;
}
