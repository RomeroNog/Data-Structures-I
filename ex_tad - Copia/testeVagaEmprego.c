#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "VagaEmprego.c"
int main()
{
    int n=0;
    VagaEmprego pessoa[200];
    inserir("563267586","Igor Romero","(018)996-0087","Habiana 1",pessoa,&n);
    inserir("563267587","jakson","(018)996-0088","Habiana 2",pessoa,&n);
    inserir("563267588","Roberto","(018)996-0089","Habiana 3",pessoa,&n);
    inserir("563267589","Palmeiras","(018)996-0080","Habiana 4",pessoa,&n);


    remover(pessoa,"563267587",&n);

    alterar(pessoa,"563267588",n);

return 0;
}
