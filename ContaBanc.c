#include <stdio.h>
#include "ContaBanc.h"
void cadastro(ContaBank* conta,int num,float saldo)
{
    conta->num = num;
    conta->saldo = saldo;
}
void deposito(ContaBank* conta,float valor)
{
    conta->saldo +=valor;
}
void sacar(ContaBank* conta,float valor)
{
    conta->saldo -=valor;
}
void extrato(ContaBank conta)
{
    printf("Numero da conta: %d\n",conta.num);
    printf("Saldo da conta: %.2f\n",conta.saldo);
}
