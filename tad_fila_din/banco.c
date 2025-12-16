#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "fila_din.c"

#define NUM_CAIXAS 4

typedef struct{
    int chegada;
    int saida;
    int num_fila;
    int tempEspera;
}Cliente;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int tempTotal = 500;
    int tempAtual = 0;
    int chegada = 0;
    int tempAtendimento = 0;
    int num_cliente = 1;

    Cliente cliente[1000];
    int tempoEsperaFila[NUM_CAIXAS];

    Fila fila[NUM_CAIXAS];
    int num_pessoas_fila[NUM_CAIXAS];

    int atendedente[NUM_CAIXAS];
    int atendimento_atendente[NUM_CAIXAS];

    int tempChegadaFila[NUM_CAIXAS];
    int tempSaidaFila[NUM_CAIXAS];

    for(int i=0;i<NUM_CAIXAS;i++)
    {
        inicializar(&fila[i]);
        num_pessoas_fila[i] = 0;
        atendimento_atendente[i] = 0;
        tempoEsperaFila[i] =0;
    }

    for(int i=0;i<1000;i++)
    {
        cliente[i].chegada = 0;
        cliente[i].saida = 0;
        cliente[i].num_fila = 0;
        cliente[i].tempEspera = 0;
    }
    chegada += (rand()%4)+1;
    tempAtendimento +=chegada + (rand()%20)+1;
    while(tempTotal)
    {
        if(chegada == tempAtual)
        {
            int menor = num_pessoas_fila[0];
            int indice = 0;
            for(int i=1;i<NUM_CAIXAS;i++)
            {
                if(menor>num_pessoas_fila[i])
                {
                    menor = num_pessoas_fila[i];
                    indice = i;
                }
            }
            inserir(&fila[indice],num_cliente);
            cliente[num_cliente].chegada = tempAtual;
            cliente[num_cliente].num_fila = indice;
            num_cliente++;
            num_pessoas_fila[indice]++;
            chegada += (rand()%4+1);
        }

        if(tempAtendimento == tempAtual)
        {
            for(int i=0;i<NUM_CAIXAS;i++)
            {
                if(!vazia(&fila[i]))
                {
                    int cliente_;
                    remover(&fila[i],&cliente_);
                    cliente[cliente_].saida = tempAtual;
                    num_pessoas_fila[i]--;
                    atendimento_atendente[i]++;
                }
            }

            tempAtendimento += (rand()%20+1);
        }

        tempTotal--;
        printf("Tempo %d\n",tempAtual);
        for(int i=0;i<NUM_CAIXAS;i++)
        {
            imprimir_fila(&fila[i]);

        }
        printf("\n");
        tempAtual++;
    }
    printf("Número total de clientes: %d\n",num_cliente);

    int clientes_atendidos = 0;

    for(int i=0;i<num_cliente;i++)
    {
        if(cliente[i].saida)
        {
            cliente[i].tempEspera = cliente[i].saida - cliente[i].chegada;
        }
    }

    for(int i=0;i<num_cliente;i++)
    {
        if(cliente[i].num_fila==0)
        {
            tempoEsperaFila[0] += cliente[i].tempEspera;
        }
        if(cliente[i].num_fila==1)
        {
            tempoEsperaFila[1] += cliente[i].tempEspera;
        }
        if(cliente[i].num_fila==2)
        {
            tempoEsperaFila[2] += cliente[i].tempEspera;
        }
        if(cliente[i].num_fila==3)
        {
            tempoEsperaFila[3] += cliente[i].tempEspera;
        }
    }
    int maior = cliente[0].tempEspera;
    for(int i=0;i<num_cliente;i++)
    {
        if(maior<cliente[i].tempEspera)
        {
            maior = cliente[i].tempEspera;
        }
    }


    for(int i=0;i<NUM_CAIXAS;i++)
    {
        printf("Atendimentos do caixa %d: %d\n",i+1,atendimento_atendente[i]);
        clientes_atendidos +=atendimento_atendente[i];
        printf("Tempo de espera médio do caixa %d: %.2f\n",i+1,(float)tempoEsperaFila[i]/(float)atendimento_atendente[i]);
        printf("\n");
    }

    int tempotot = 0;

    for(int i=0;i<NUM_CAIXAS;i++)
    {
        tempotot += tempoEsperaFila[i];
    }
    printf("Tempo médio de espera total: %.2f\n\n",(float)tempotot/(float)clientes_atendidos);

    printf("Total de cliente atendidos: %d\n\n",clientes_atendidos);
    printf("Total de cliente não atendidos: %d\n\n",num_cliente - clientes_atendidos);
    printf("Maior tempo de espera de um clietnte: %d\n",maior);

return 0;
}
