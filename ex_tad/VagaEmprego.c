#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "VagaEmprego.h"
int pesquisa(VagaEmprego *pessoa,char *rg,int n)
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(pessoa[i].rg,rg) == 0)
        {
            return i;
        }
    }
    return -1;
}
void inserir(char *rg,char *nome,char *telefone,char *endereco,VagaEmprego *pessoa,int *n)
{
    if(pesquisa(pessoa,rg,*n)!=-1)
    {
        printf("Rg já cadstrado");
    }
    else
    {
        strcpy(pessoa[*n].rg,rg);
        strcpy(pessoa[*n].nome,nome);
        strcpy(pessoa[*n].telefone,telefone);
        strcpy(pessoa[*n].endereco,endereco);
        (*n)++;
    }
}
void remover(VagaEmprego *pessoa,char *rg,int *n)
{
    int pos = pesquisa(pessoa,rg,*n);
    if(pos != 0)
    {
        printf("Pessoa a ser removida: \n");
        printf("%s\n",pessoa[pos].rg);
        printf("%s\n",pessoa[pos].nome);
        printf("%s\n",pessoa[pos].telefone);
        printf("%s\n",pessoa[pos].endereco);

        strcpy(pessoa[pos].rg,pessoa[(*n)-1].rg);
        strcpy(pessoa[pos].nome,pessoa[(*n)-1].nome);
        strcpy(pessoa[pos].telefone,pessoa[(*n)-1].telefone);
        strcpy(pessoa[pos].endereco,pessoa[(*n)-1].endereco);
        (*n)--;
    }
    else
    {
        printf("Rg nao encontrado!\n");
    }
}
void alterar(VagaEmprego *pessoa,char *rg,int n)
{
    int dado;
    int posi = pesquisa(pessoa,rg,n);
    if(posi!=-1)
    {
        printf("\n\nDados do rg que sera alterado: \n");
        printf("%s\n",pessoa[posi].rg);
        printf("%s\n",pessoa[posi].nome);
        printf("%s\n",pessoa[posi].telefone);
        printf("%s\n",pessoa[posi].endereco);

        while(1)
        {
            printf("Qual dado quer alterar(1-3): ");
            scanf("%d",&dado);
            fflush(stdin);
            if(dado==1)
            {
                char palavra[60];
                printf("Digite o novo nome: ");
                gets(palavra);
                int tam = strlen(palavra);
                palavra[tam] = '\0';
                strcpy(pessoa[posi].nome,palavra);
            }
            if(dado==2)
            {
                char palavra2[60];
                printf("Digite o novo telefone: ");
                gets(palavra2);
                int tam2 = strlen(palavra2);
                palavra2[tam2] = '\0';
                strcpy(pessoa[posi].telefone,palavra2);
            }
            if(dado==3)
            {
                char palavra3[60];
                printf("Digite o novo endereco: ");
                gets(palavra3);
                int tam3 = strlen(palavra3);
                palavra3[tam3] = '\0';
                strcpy(pessoa[posi].endereco,palavra3);
            }
            char alte;
            printf("Deseja realizar mais alguma alteracao(s ou n): ");
            scanf("%c",&alte);
            if(alte == 'n')
            {
                break;
            }
        }
        printf("\nDados atualizados:\n");
        printf("rg: %s\n", pessoa[posi].rg);
        printf("nome: %s\n", pessoa[posi].nome);
        printf("telefone: %s\n", pessoa[posi].telefone);
        printf("endereço: %s\n", pessoa[posi].endereco);
    }
}
