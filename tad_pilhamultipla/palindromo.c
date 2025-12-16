#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "pilhamult.c"
int main()
{
     setlocale(LC_ALL,"Portuguese");

    char palavra[15];
    printf("Digite um palavra para ver se eh um palindromo: ");
    gets(palavra);

    Pilhamult pilham;
    inicializa_pilhas(&pilham);

    int tam_palavra=strlen(palavra);
    for(int i=0;i<tam_palavra;i++)
    {
        push(&pilham,0,palavra[i]);
    }

    while(!se_vazia(&pilham,0))
    {
        char caracter;
        pop(&pilham,0,&caracter);
        push(&pilham,1,caracter);
    }

    for(int i=0;i<tam_palavra;i++)
    {
        push(&pilham,0,palavra[i]);
    }
    int iguais=1;
    while(!se_vazia(&pilham,0) && !se_vazia(&pilham,1))
    {
        char c1,c2;
        pop(&pilham,0,&c1);
        pop(&pilham,1,&c2);
        if(c1!=c2)
        {
            iguais=0;
        }
    }
    if(iguais)
    {
        printf("A palavra é um palíndromo!\n");
    }
    else
    {
        printf("A palavra não é um palíndromo!\n");
    }



return 0;
}
