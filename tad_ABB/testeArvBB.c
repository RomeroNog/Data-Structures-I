#include <stdio.h>
#include <stdio.h>
#include <locale.h>
#include "ArvBB.c"
int main()
{
    setlocale(LC_ALL,"Portuguese");
    noArvBB *raiz;

    inicializanoArvBB(&raiz);

    // Inserindo os elementos na ordem especificada
    inserirnoArvBB(&raiz, 10);
    inserirnoArvBB(&raiz, 5);
    inserirnoArvBB(&raiz, 15);
    inserirnoArvBB(&raiz, 12);
    inserirnoArvBB(&raiz, 18);
    inserirnoArvBB(&raiz, 2);
    inserirnoArvBB(&raiz, 8);

    imprimirPreOrdem(&raiz);
    printf("\n");
    imprimirEmOrdem(&raiz);
    printf("\n");
    imprimirPosOrdem(&raiz);
    printf("\n");

    noArvBB *invertida = inverter_arv(raiz);
    imprimirEmOrdem(&invertida);

    printf("\n--- Testes de busca ---\n");
    buscanoArvBB(&raiz, 10);
    buscanoArvBB(&raiz, 8);
    buscanoArvBB(&raiz, 20); // não existe

    printf("\n--- Testes de antecessor ---\n");
    noArvBB *ant = buscaAntecessorArvBB(&raiz, 8, NULL);
    if (ant) printf("Pai de 8 é: %d\n", ant->elem);
    ant = buscaAntecessorArvBB(&raiz, 10, NULL);
    if (ant) printf("Pai de 10 é: %d\n", ant->elem);
    else printf("10 é a raiz e não tem pai.\n");


    printf("\n--- Teste de busca de substituto para 10 ---\n");
    noArvBB *subst = buscaSubstArvBB(&raiz, &(raiz->elem));
    if (subst) printf("Substituto de 10 é: %d\n", subst->elem);


    printf("\n--- Testes de remoção ---\n");

    // Caso 1: Remove folha
    int v2 = 2;
    printf("\nRemovendo folha 2...\n");
    removerNoArvBB(&raiz, &v2);
    buscanoArvBB(&raiz, 2); // deve dizer que não está

    // Caso 2: Remove nó com 1 filho
    printf("\nRemovendo nó com um filho 15...\n");
    removerNoArvBB(&raiz, &(int){15});
    buscanoArvBB(&raiz, 15); // deve dizer que não está

    // Caso 3: Remove nó com dois filhos
    printf("\nRemovendo nó com dois filhos 10...\n");
    removerNoArvBB(&raiz, &(int){10});
    buscanoArvBB(&raiz, 10); // deve dizer que não está



    return 0;
}
