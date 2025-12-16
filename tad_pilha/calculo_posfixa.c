#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "pilha.c"
void calculo(Pilha* pi,char expre[]);
int nivel_op(char caract);
int main()
{
    setlocale(LC_ALL,"Portuguese");

    char expressao[20];
    printf("Digite um expressao pos-fixa: ");
    gets(expressao);

    int tam_expre = strlen(expressao);
    expressao[tam_expre]='\0';

    Pilha pilha;
    inicializa_pilha(&pilha);

    calculo(&pilha,expressao);

    int result;

    obter_topo(&pilha,&result);
    printf("Resultado: %d",result);
return 0;
}
void calculo(Pilha* pi,char expre[])
{
    for(int i=0;expre[i]!='\0';i++)
    {
        if(!nivel_op(expre[i]))
        {
            int valor = expre[i]-'0';
            push(pi,valor);
        }
        else
        {
            if(expre[i]=='+')
            {
                int n1;
                pop(pi,&n1);
                int n2;
                pop(pi,&n2);
                push(pi,(n2+n1));
            }
            if(expre[i]=='-')
            {
                int n1;
                pop(pi,&n1);
                int n2;
                pop(pi,&n2);
                push(pi,(n2-n1));
            }
            if(expre[i]=='*')
            {
                int n1;
                pop(pi,&n1);
                int n2;
                pop(pi,&n2);
                push(pi,(n2*n1));
            }
            if(expre[i]=='/')
            {
                int n1;
                pop(pi,&n1);
                int n2;
                pop(pi,&n2);
                if(n1!=0)
                {
                    push(pi,(n2/n1));
                }
                else
                {
                    printf("impossivel dividir por 0!\n");
                    return;
                }
            }
        }
    }

}
int nivel_op(char caract)
{
    if(caract=='+' ||caract=='-' ||caract=='*' ||caract=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
