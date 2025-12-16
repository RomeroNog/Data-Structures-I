#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11
typedef struct AlunoH{
    int ra;
    char nome[40];
    struct AlunoH *prox;
    struct AlunoH *ant;
}AlunoH;
typedef struct{
    AlunoH *tabela;
    AlunoH *fim;
}Hash;
int func_hash(char nome[])
{
    int sum=0;
    for(int i=0;nome[i]!='\0';i++)
    {
        sum+=i*nome[i];
    }
    return sum%MAX;

}
int verifVaziaHS(Hash *tabhs[],int chave)
{
    if(!tabhs[chave] || !tabhs[chave]->tabela)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void inicializarHS(Hash *tabhs[])
{
    for(int i=0;i<MAX;i++)
    {
        tabhs[i] = malloc(sizeof(Hash));
        tabhs[i]->tabela = NULL;
        tabhs[i]->fim = NULL;
    }
}
void inserirHS(Hash *tabhs[],int ra,char nome[])
{
    int chave = func_hash(nome);
    AlunoH *temp = malloc(sizeof(AlunoH));
    strcpy(temp->nome,nome);
    temp->ra = ra;
    if(verifVaziaHS(tabhs,chave))
    {
        tabhs[chave]->tabela = temp;
        tabhs[chave]->fim = temp;
        temp->prox = NULL;
        temp->ant = NULL;
    }
    else
    {
        AlunoH *percorreLinhaAtu = tabhs[chave]->tabela;
        AlunoH *percorreLinhaAnt = NULL;
        while(percorreLinhaAtu)
        {
            //primeiro elem a inserçao
            if(!percorreLinhaAnt && ra<=percorreLinhaAtu->ra)
            {
                temp->prox = tabhs[chave]->tabela;
                tabhs[chave]->tabela->ant = temp;
                tabhs[chave]->tabela = temp;
                temp->ant = NULL;
                break;
            }
            //no meio a inserçao
            if(percorreLinhaAnt && ra<=percorreLinhaAtu->ra)
            {
                temp->prox = percorreLinhaAtu;
                percorreLinhaAnt->prox = temp;
                temp->ant = percorreLinhaAnt;
                percorreLinhaAtu->ant = temp;
                break;
            }
            percorreLinhaAnt =percorreLinhaAtu;
            percorreLinhaAtu = percorreLinhaAtu->prox;
        }
        //se for no ultimo a inserçao
        if(!percorreLinhaAtu)
        {
            temp->ant = tabhs[chave]->fim;
            temp->prox = NULL;
            tabhs[chave]->fim->prox = temp;
            tabhs[chave]->fim = temp;
        }
    }
}
void removerHS(Hash *tabhs[],char nome[],int ra)
{
    int chave = func_hash(nome);
    AlunoH *temp = malloc(sizeof(AlunoH));
    strcpy(temp->nome,nome);
    temp->ra = ra;

    if(verifVaziaHS(tabhs,chave))
    {
        printf("Tabela ou chave vazia!\n");
    }

    AlunoH *percorreLinhaAtu = tabhs[chave]->tabela;
    AlunoH *percorreLinhaAnt = NULL;

    while(percorreLinhaAtu && ra!=percorreLinhaAtu->ra)
    {
        percorreLinhaAnt = percorreLinhaAtu;
        percorreLinhaAtu = percorreLinhaAtu->prox;
    }
    if(!percorreLinhaAtu)
    {
        printf("Elemento nao existe para ser removido!\n");
    }
    else
    {
        //elem unico
        if(!percorreLinhaAnt && !percorreLinhaAtu->prox)
        {
            AlunoH *aux = percorreLinhaAtu;
            tabhs[chave]->tabela = NULL;
            tabhs[chave]->fim = NULL;
            free(aux);
            printf("Elemento removido!\n");
            return;
        }
        //remove o primeiro elem
        if(!percorreLinhaAnt)
        {
            AlunoH *aux = percorreLinhaAtu;
            tabhs[chave]->tabela = percorreLinhaAtu->prox;
            tabhs[chave]->tabela->ant = NULL;
            free(aux);
            printf("Elemento removido!\n");
            return;
        }
        //remove o ultimo
        if(!percorreLinhaAtu->prox)
        {
            AlunoH *aux = percorreLinhaAtu;
            tabhs[chave]->fim = percorreLinhaAnt;
            percorreLinhaAnt->prox = NULL;
            free(aux);
            printf("Elemento removido!\n");
            return;

        }
        //remove do meio
        else
        {
            AlunoH *aux = percorreLinhaAtu;
            percorreLinhaAnt->prox = percorreLinhaAtu->prox;
            percorreLinhaAtu->prox->ant = percorreLinhaAnt;
            free(aux);
            printf("Elemento removido!\n");
            return;
        }

    }
}
void buscaHS(Hash *tabhs[],int ra,char nome[])
{
    int chave = func_hash(nome);
    AlunoH *temp = malloc(sizeof(AlunoH));
    strcpy(temp->nome,nome);
    temp->ra = ra;

    if(verifVaziaHS(tabhs,chave))
    {
        printf("Tabela ou chave vazia!\n");
        return;
    }

    AlunoH *percorreLinhaAtu = tabhs[chave]->tabela;
    AlunoH *percorreLinhaAnt = NULL;

    while(percorreLinhaAtu && ra>percorreLinhaAtu->ra)
    {
        percorreLinhaAnt = percorreLinhaAtu;
        percorreLinhaAtu = percorreLinhaAtu->prox;
    }
    if(percorreLinhaAtu && ra==percorreLinhaAtu->ra)
    {
        printf("Elemento se encontra na linha da tabela!");
    }
    else
    {
        printf("Elemento nao se encontra na linha da tabela!");
    }
}
void printTabela(Hash *tabhs[])
{
    printf("\n===== Tabela Hash =====\n");

    for (int i = 0; i < MAX; i++)
    {
        printf("Posição %d: ", i);
        if (verifVaziaHS(tabhs, i))
        {
            printf("[Vazia]\n");
        }
        else
        {
            AlunoH *atual = tabhs[i]->tabela;
            while (atual)
            {
                printf(" -> [RA: %d, Nome: %s] ", atual->ra, atual->nome);
                atual = atual->prox;
            }
            printf("\n");
        }
    }

    printf("=======================\n");
}
void salvarTabelaBinario(Hash *tabhs[], const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");

    if (!arquivo) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < MAX; i++) {
        AlunoH *atual = tabhs[i] ? tabhs[i]->tabela : NULL;

        while (atual) {
            fwrite(atual, sizeof(AlunoH), 1, arquivo);  // Escreve cada elemento no arquivo
            atual = atual->prox;
        }
    }

    fclose(arquivo);
    printf("Tabela hash salva no arquivo binário '%s' com sucesso!\n", nomeArquivo);
}
int main() {
    Hash *tabelaHash[MAX];
    inicializarHS(tabelaHash);

    printf("Inserindo elementos...\n");
    inserirHS(tabelaHash, 101, "Alice");
    inserirHS(tabelaHash, 202, "Bob");
    inserirHS(tabelaHash, 303, "Charlie");
    inserirHS(tabelaHash, 404, "David");

    printf("\nEstado da Tabela Hash após inserção:\n");
    printTabela(tabelaHash);

    salvarTabelaBinario(tabelaHash, "tabelaHash.bin");

    printf("\nBuscando elementos...\n");
    buscaHS(tabelaHash, 202, "Bob");      // Deve encontrar
    buscaHS(tabelaHash, 505, "Eve");      // Não deve encontrar

    printf("\nRemovendo elementos...\n");
    removerHS(tabelaHash, "Charlie", 303); // Remove Charlie
    printf("\nEstado da Tabela Hash após remoção:\n");
    printTabela(tabelaHash);

    buscaHS(tabelaHash, 303, "Charlie");  // Não deve encontrar mais

    printf("\nRemovendo um elemento inexistente...\n");
    removerHS(tabelaHash, "Eve", 505); // Elemento não existe

    printf("\nEstado final da Tabela Hash:\n");
    printTabela(tabelaHash);

    printf("\nTestes finalizados!\n");

    return 0;
}
