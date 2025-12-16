#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.c"
void mandar_letras(Pilha *pi,char expre[]);
void mandar_op(Pilha *pi,char expre[]);
int tem_multidiv(char c);
int eh_letra(char expre);
int main()
{
    char expressao[20];
    printf("Digite a expressao: ");
    gets(expressao);

    Pilha pilha;
    inicializa_pilha(&pilha);

    int tam_expre = strlen(expressao);

    mandar_letras(&pilha,expressao);

    mandar_op(&pilha,expressao);

    Pilha pilh;
    inicializa_pilha(&pilh);

    while(!se_vazia(&pilha))
    {
        char caract;
        pop(&pilha,&caract);
        push(&pilh,caract);
    }
    while(!se_vazia(&pilh))
    {
        char topo;
        pop(&pilh,&topo);
        printf("%c ",topo);
    }

return 0;
}
void mandar_letras(Pilha *pi,char expre[])
{
    for(int i=0;expre[i]!='\0';i++)
    {
        if(eh_letra(expre[i]))
        {
            push(pi,expre[i]);
        }
    }


}
int eh_letra(char expre)
{
    int numero_sim=0;

    if(expre>='A' && expre<='Z')
    {
        return 1;
    }
    if(expre>='a' && expre<='z')
    {
        return 1;
    }
    return 0;
}
void mandar_op(Pilha *pi,char expre[])
{
    int multidiv=0;
    for(int i=0;expre[i]!='\0';i++)
    {
        if(tem_multidiv(expre[i]))
        {
            multidiv++;
        }
    }
    if(multidiv)
    {
        for(int i=0;expre[i]!='\0';i++)
        {
            if(expre[i] == '*' || expre[i] == '/')
            {
                push(pi,expre[i]);
            }
        }
        for(int i=0;expre[i]!='\0';i++)
        {
            if(expre[i] == '+' || expre[i] == '-')
            {
                push(pi,expre[i]);
            }
        }
    }
    else
    {
        for(int i=0;expre[i]!='\0';i++)
        {
            if(expre[i] == '+' || expre[i] == '-')
            {
                push(pi,expre[i]);
            }
        }
    }
}
int tem_multidiv(char c)
{
    if(c == '*' || c == '/')
    {
        return 1;
    }
    return 0;
}
