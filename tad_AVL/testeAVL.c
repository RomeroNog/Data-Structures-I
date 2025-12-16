#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "AVL.c"

int main()
{
    setlocale(LC_ALL,"Portuguese");
    noAvl *arvore;
    inicializarAvl(&arvore);

    printf("Inserindo elementos na AVL...\n");
    inserirAvl(&arvore, 50);
    inserirAvl(&arvore, 30);
    inserirAvl(&arvore, 70);
    inserirAvl(&arvore, 20);
    inserirAvl(&arvore, 40);
    inserirAvl(&arvore, 60);
    inserirAvl(&arvore, 80);

    printf("\n¡rvore em prÈ-ordem:\n");
    imprimirPreOrdemAvl(&arvore);
    printf("\n");

    printf("\n¡rvore em ordem:\n");
    imprimirEmOrdemAvl(&arvore);
    printf("\n");

    printf("\n¡rvore em pÛs-ordem:\n");
    imprimirPosOrdemAvl(&arvore);
    printf("\n");

    printf("\nBuscando elemento 40...\n");
    noAvl *busca = buscaNoAvl(&arvore, 40);
    if(busca) printf("Elemento %d encontrado.\n", busca->elem);
    else printf("Elemento n„o encontrado.\n");

    printf("\nRemovendo elemento 30...\n");
    removerNoAvl(&arvore, 30);

    printf("\n¡rvore em ordem apÛs remoÁ„o:\n");
    imprimirEmOrdemAvl(&arvore);
    printf("\n");

    // Salvar no arquivo e recuperar

    printf("\nRecuperando ·rvore do arquivo...\n");
    noAvl *arvoreRecuperada;
    inicializarAvl(&arvoreRecuperada);

    FILE *arq = fopen("palmeiras.bin", "rb");
    if(!arq)
    {
        printf("Arquivo n„o encontrado ou vazio!\n");
    }
    else
    {
        recuperarAvlArq(&arvoreRecuperada, arq);
        fclose(arq);

        printf("\n¡rvore recuperada (em ordem):\n");
        imprimirEmOrdemAvl(&arvoreRecuperada);
        printf("\n");
    }


    FILE *a = fopen("porco.bin","wb");
    if(!a)
    {
        printf("Erro!\n");
        return 0;
    }
    salvarAvlArq(&arvore,a);
    fclose(a);

    // Testando se È ABB
    if(EhBB(&arvore))
        printf("\n\n… ABB (¡rvore Bin·ria de Busca)\n");
    else
        printf("\n\nN„o È ABB\n");

    // Testando se È AVL
    if(EhAvl(&arvore))
        printf("… AVL (Balanceada)\n");
    else
        printf("N„o È AVL (Desbalanceada)\n");

    return 0;
}
