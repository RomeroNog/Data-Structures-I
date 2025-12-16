#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListaCruzada.c"
int main()
{
    srand(time(NULL));
    ListaCruzada lista;
    inicializarLC(&lista);

    for(int i=0;i<I;i++)
    {
        for(int j=0;j<J;j++)
        {
            int num = rand()%11 +1;
            inserirLC(&lista,num,i,j);
        }
    }
    imprimirLC(&lista);

    soma(&lista,2,5);
    imprimirLC(&lista);

    for(int i=0;i<I;i++)
    {
        for(int j=0;j<J;j++)
        {
            int elem;
            removerLC(&lista,i,j,&elem);
            printf("Elemento removido: %d\n",elem);
        }
    }
    imprimirLC(&lista);

    ListaCruzada lista2;
    inicializarLC(&lista2);
    inserirLC(&lista2,10,1,0);
    inserirLC(&lista2,10,1,2);
    inserirLC(&lista2,10,1,1);
    inserirLC(&lista2,10,0,1);
    inserirLC(&lista2,0,0,2);
    inserirLC(&lista2,7,3,3);

    imprimirLC(&lista2);

    soma(&lista2,0,7);

    imprimirLC(&lista2);

return 0;
}
