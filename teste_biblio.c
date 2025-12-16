#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ContaBanc.c"
#include "fila_din.c"
int main()
{
    setlocale(LC_ALL,"Portuguese");
    ContaBank conta00;
    cadastro(&conta00,204,4183);
    extrato(conta00);
    deposito(&conta00, 500);
    sacar(&conta00,450);
    extrato(conta00);

    Fila fila;
    inicializar(&fila);
    for(int i=0;i<5;i++)
    {
        int teste;
        inserir(&fila,remover(&fila,&teste));
    }
return 0;
}
