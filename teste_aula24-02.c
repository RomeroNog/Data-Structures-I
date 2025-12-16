//Algorit recursivo com a struct de aula para imprimir os elem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct{
    int *vetor;
    int num_elem;
}Vetores;
void imprimir_reverso(Vetores veto);
void imprimir_ordem(Vetores vet,int inicio);
int main()
{
    setlocale(LC_ALL,"Portuguese");

    Vetores vetor1;
    vetor1.num_elem = 123;
    vetor1.vetor = malloc(vetor1.num_elem*sizeof(int));
    printf("%d \n",vetor1.num_elem);

    for(int i=0;i<vetor1.num_elem;i++)
    {
        vetor1.vetor[i] = i;
    }
    imprimir_ordem(vetor1,0);
    printf("\n");
    imprimir_reverso(vetor1);

    free(vetor1.vetor);
return 0;
}
void imprimir_ordem(Vetores vet,int inicio)
{
    if(vet.num_elem == 0)
    {
        printf("Vetor nulo!\n");
    }
    if(inicio<vet.num_elem)
    {
        printf("%d ",vet.vetor[inicio]);
        imprimir_ordem(vet,inicio+1);
    }
}
void imprimir_reverso(Vetores veto)
{
    if(veto.num_elem-1<-1)
    {
        printf("Vetor nulo!\n");
    }
    if(veto.num_elem>0)
    {
        printf("%d ",veto.vetor[veto.num_elem-1]);
        veto.num_elem -=1;
        imprimir_reverso(veto);
    }
}
