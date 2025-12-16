#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct Strdim
{
    char c;
    struct Strdim *prox;
}Strdim;
void criar_lista(Strdim** string);
void reinicializa_lista(Strdim** string);
void imprimir_lista(Strdim* string);
void inserir_caracter_ini(char caract,Strdim** string);
void inserir_caract_fim(char caract,Strdim** string);
void remover_caract(int qnt,int posi_ini,Strdim** string);
void inserir_substr(Strdim** substr,Strdim** string,int ini);
void verifica_substrings(Strdim** substr,Strdim** string);
int compara_strings(Strdim** string,Strdim** string2);
int compara_tam(Strdim** string,Strdim** string2);
int tamanho_lista(Strdim* string);
int main()
{
    setlocale(LC_ALL,"Portuguese");
    Strdim* palavra;

    criar_lista(&palavra);
    reinicializa_lista(&palavra);
    /*
    while(1)
    {
        char deseja;
        printf("Quer adicionar algum caracter?(s ou n) ");
        scanf("%c",&deseja);
        fflush(stdin);
        if(deseja == 's')
        {
            char caracter;
            printf("Digite o caracter: ");
            scanf("%c",&caracter);
            inserir_caracter_ini(caracter,&palavra);
            fflush(stdin);
        }
        else
        {
            break;
        }
    }
    */
    char str1[20];

    strcpy(str1,"cachorro");
    int tam_str1 = strlen(str1);

    for(int i=tam_str1-1;i>=0;i--)
    {
        inserir_caracter_ini(str1[i],&palavra);
    }

    imprimir_lista(palavra);
    int tamanho = tamanho_lista(palavra);
    printf("tamanho da lista: %d\n",tamanho);


    Strdim* palavra2;
    Strdim* temp;
    Strdim* temp2;

    criar_lista(&palavra2);

    //copiar da palavra pra palavra2
    temp2 = palavra;
    criar_lista(&temp);
    for(int j=0;j<tam_str1;j++)
    {
        inserir_caracter_ini(temp2->c,&temp);
        temp2= temp2->prox;
    }
    temp2 = temp;
    for(int j=0;j<tam_str1;j++)
    {
        inserir_caracter_ini(temp->c,&palavra2);
        temp = temp->prox;
    }

    imprimir_lista(palavra2);

    //Concatenar/Esqueci de fazer por função
    Strdim* palavra3;
    criar_lista(&palavra3);

    temp2 = palavra;
    while(temp2)
    {
        inserir_caract_fim(temp2->c,&palavra3);
        temp2 = temp2->prox;
    }
    temp2 = palavra2;
    while(temp2)
    {
        inserir_caract_fim(temp2->c,&palavra3);
        temp2 = temp2->prox;
    }
    imprimir_lista(palavra3);

    int tama = tamanho_lista(palavra3);
    printf("tamanho da lista 3 : %d\n",tama);

    remover_caract(3,5,&palavra3);
    imprimir_lista(palavra3);


    Strdim* subpalavra;
    criar_lista(&subpalavra);

    char substr[20];
    strcpy(substr,"dog");
    int tam_substr = strlen(substr);
    for(int i=tam_substr-1;i>=0;i--)
    {
        inserir_caracter_ini(substr[i],&subpalavra);
    }
    imprimir_lista(subpalavra);

    inserir_substr(&subpalavra,&palavra,5);
    imprimir_lista(palavra);

    printf("String1 menor que a 2: ");

    int menor = compara_tam(&palavra,&palavra2);
    if(menor>0)
    {
        printf("TRUE");
    }
    if(menor<0)
    {
        printf("FALSE");
    }
    else
    {
        printf("Tamanhos iguais");
    }

    Strdim* palavra4;
    Strdim* temp0;
    Strdim* temp02;

    criar_lista(&palavra4);

    temp02 = palavra2;
    criar_lista(&temp0);
    for(int j=0;j<tam_str1;j++)
    {
        inserir_caracter_ini(temp02->c,&temp0);
        temp02= temp02->prox;
    }
    temp02 = temp0;
    for(int j=0;j<tam_str1;j++)
    {
        inserir_caracter_ini(temp0->c,&palavra4);
        temp0 = temp0->prox;
    }
    printf("\n");
    imprimir_lista(palavra4);
    imprimir_lista(palavra2);

    printf("Strings são iguais: ");
    int comp_str = compara_strings(&palavra2,&palavra4);
    if(comp_str>0)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    printf("Strings são iguais: ");
    int cmp = compara_strings(&palavra,&palavra4);
    if(cmp>0)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    Strdim* palavra5;
    criar_lista(&palavra5);

    char strings[20];
    strcpy(strings,"cho");

    int tam_strings = strlen(strings);
    for(int i=tam_strings-1;i>=0;i--)
    {
        inserir_caracter_ini(strings[i],&palavra5);
    }

    imprimir_lista(palavra5);

    verifica_substrings(&palavra5,&palavra4);

return 0;
}
void criar_lista(Strdim** string)
{
    *string = NULL;
}
void reinicializa_lista(Strdim** string)
{
    Strdim* temp;
    Strdim* percorre = *string;
    while(percorre)
    {
         temp = percorre;
         percorre = percorre->prox;
         free(temp);
    }
    *string = NULL;
}
void imprimir_lista(Strdim* string)
{
    if(!string)
    {
        printf("Vazia\n");
    }
    else
    {
        while(string)
        {
            printf("%c",string->c);
            string = string->prox;
        }
        printf("\n");
    }
}
void inserir_caracter_ini(char caract,Strdim** string)
{
    Strdim* novo_no = malloc(sizeof(Strdim));
    novo_no->c = caract;
    novo_no->prox = *string;
    *string = novo_no;
}
int tamanho_lista(Strdim* string)
{
    int i=0;
    Strdim* percorre = string;
    while(percorre)
    {
        i++;
        percorre = percorre->prox;
    }
    return i;
}
void inserir_caract_fim(char caract,Strdim** string)
{
    Strdim* novo_no = malloc(sizeof(Strdim));
    novo_no->c = caract;
    novo_no->prox = NULL;
    Strdim* percorre = *string;

    if(!*string)
    {
        *string = novo_no;
    }
    else
    {
        while(percorre->prox)
        {
            percorre = percorre->prox;
        }
        percorre->prox = novo_no;
    }
}
void remover_caract(int qnt,int posi_ini,Strdim** string)
{
    int contador=0;
    Strdim* percorre = *string;
    while(percorre->prox)
    {
        if(contador == posi_ini)
        {
            Strdim *aux1 = percorre;
            while(qnt>0)
            {
                Strdim* temp;
                temp = percorre;
                percorre = percorre->prox;
                free(temp);
                qnt--;
            }
            aux1->prox = percorre->prox;
            break;
        }
        contador++;
    }
}
void inserir_substr(Strdim** substr,Strdim** string,int ini)
{
    int contador = 0;
    Strdim* atual = *string;
    Strdim* anterior = NULL;
    Strdim* percorresub = *substr;

    while (atual)
    {
        if(contador==ini)
        {
            while (percorresub->prox)
            {
                percorresub = percorresub->prox;
            }
            percorresub->prox = atual;

            if (anterior)
            {
                anterior->prox = *substr;
            }
            else
            {
                *string = *substr;
            }
        }
        anterior = atual;
        atual = atual->prox;
        contador++;
    }
}
int compara_tam(Strdim** string,Strdim** string2)
{
    Strdim* pala1 = *string;
    Strdim* pala2 = *string2;
    int str1 = tamanho_lista(pala1);
    int str2 = tamanho_lista(pala2);
    if(str1<str2)
    {
      return 1;
    }
    if(str1>str2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int compara_strings(Strdim** string,Strdim** string2)
{
    int tamanhos = compara_tam(string,string2);
    if(tamanhos!=0)
    {
        return -1;
    }
    else
    {
        Strdim* percorre1 = *string;
        Strdim* percorre2 = *string2;
        while(percorre1 && percorre2)
        {
            if(percorre1->c!=percorre2->c)
            {

                return -1;
            }
            percorre1 = percorre1->prox;
            percorre2 = percorre2->prox;
        }
        return 1;
    }
}
void verifica_substrings(Strdim** substr,Strdim** string)
{
    Strdim* percorrestr = *string;
    int posi=0;
    while(percorrestr)
    {
        int encontrou=1;
        Strdim* percorresub = *substr;
        Strdim* aux2 = percorrestr;
        while(percorresub)
        {
            if(percorresub->c != aux2->c || !aux2)
            {
                encontrou=0;
                break;
            }
            percorresub = percorresub->prox;
            aux2 = aux2->prox;
        }
        if(encontrou)
        {
            printf("Está contida na posi %d\n",posi);
            return;
        }
        percorrestr = percorrestr->prox;
        posi++;
    }
    printf("Não está contida\n");
}
