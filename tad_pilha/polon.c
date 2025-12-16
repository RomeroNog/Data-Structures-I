#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct noPilha
{
    char elemento;
    struct noPilha *prox;
}noPilha;
typedef struct
{
    struct noPilha *topo;
}Pilha;
void pos_fixa(char expre[],char result[],Pilha *pi,int tam);
int niveis_op(char op);
int eh_operador(char expre);
void inicializa_pilha(Pilha* pilha);
void reinicializa(Pilha *pilha);
void obter_topo(Pilha* pilha,char *elem);
void pop(Pilha* pilha,char *elem);
void push(Pilha* pilha,char elem);
int se_vazia(Pilha* pilha);

int main() {
    const char* teste = "sin_r(60*4)+cos_r(23*3)";
    char expressao[100], polonesa[100];
    strcpy(expressao, teste);
    Pilha pilha;
    inicializa_pilha(&pilha);
    pos_fixa(expressao, polonesa, &pilha, strlen(expressao));
    printf("Entrada: %s\nSaída em Polonesa Reversa: %s\n", expressao, polonesa);
    return 0;
}
//falta tratar: o sen cos e tg de acordo com graus e radianos
void pos_fixa(char expre[], char result[], Pilha *pi, int tam) {
    int j = 0;
    for (int i = 0; i < tam; i++) {
        char atual = expre[i];

        if ((atual >= '0' && atual <= '9')) {
            while ((atual >= '0' && atual <= '9') || atual == '.') {
                result[j++] = atual;
                if (i + 1 >= tam) break;
                i++;
                atual = expre[i];
            }
            result[j++] = ';';
            i--;
            continue;
        }

        if (atual == 'p' && i + 1 < tam && expre[i + 1] == 'i') {
            strcpy(&result[j], "3.14;");
            j += 5;
            i++;
            continue;
        }

        if (atual == 'e') {
            strcpy(&result[j], "2.71;");
            j += 5;
            continue;
        }

        if (atual == '!') {
            result[j++] = atual;
            result[j++] = ';';
            continue;
        }

        if (i + 5 < tam) {
            if (strncmp(&expre[i], "sin_d", 5) == 0) {
                i += 5;
                push(pi, 'S');
                push(pi, '(');
                continue;
            } else if (strncmp(&expre[i], "sin_r", 5) == 0) {
                i += 5;
                push(pi, 's');
                push(pi, '(');
                continue;
            } else if (strncmp(&expre[i], "cos_d", 5) == 0) {
                i += 5;
                push(pi, 'C');
                push(pi, '(');
                continue;
            } else if (strncmp(&expre[i], "cos_r", 5) == 0) {
                i += 5;
                push(pi, 'c');
                push(pi, '(');
                continue;
            } else if (strncmp(&expre[i], "tan_d", 5) == 0) {
                i += 5;
                push(pi, 'T');
                push(pi, '(');
                continue;
            } else if (strncmp(&expre[i], "tan_r", 5) == 0) {
                i += 5;
                push(pi, 't');
                push(pi, '(');
                continue;
            }
        }

        if (eh_operador(atual)) {
            while (!se_vazia(pi)) {
                char topo;
                obter_topo(pi, &topo);
                if (niveis_op(topo) >= niveis_op(atual)) {
                    result[j++] = topo;
                    result[j++] = ';';
                    pop(pi, &topo);
                } else break;
            }
            push(pi, atual);
            continue;
        }

        if (atual == '(') {
            push(pi, atual);
            continue;
        }

        if (atual == ')') {
            char topo;
            while (!se_vazia(pi)) {
                obter_topo(pi, &topo);
                if (topo == '(') {
                    pop(pi, &topo);
                    break;
                }
                result[j++] = topo;
                result[j++] = ';';
                pop(pi, &topo);
            }

            if (!se_vazia(pi)) {
                obter_topo(pi, &topo);
                if (topo == 's' || topo == 'c' || topo == 't' ||
                    topo == 'S' || topo == 'C' || topo == 'T' ||
                    topo == 'l' || topo == 'n') {
                    result[j++] = topo;
                    result[j++] = ';';
                    pop(pi, &topo);
                }
            }
            continue;
        }
    }

    while (!se_vazia(pi)) {
        char topo;
        pop(pi, &topo);
        result[j++] = topo;
        result[j++] = ';';
    }

    if (j > 0 && result[j - 1] == ';')
        j--;

    result[j] = '\0';
}
int niveis_op(char expre)
{
    if(expre == '+' || expre == '-')
    {
        return 1;
    }
    else if (expre == '*' || expre == '/')
    {
        return 2;
    }
    else if (expre == '^')
    {
        return 3;
    }
    else if (expre == '~')
    {
        return 4;
    }
    return 0;
}
int eh_operador(char expre)
{
    if (expre == '+' || expre == '-' || expre == '*' || expre == '/' || expre == '^' || expre == '~')
    {
        return 1;
    }
    return 0;
}
void inicializa_pilha(Pilha* pilha)
{
    pilha->topo=NULL;
}
int se_vazia(Pilha* pilha)
{
    if(!pilha->topo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(Pilha* pilha,char elem)
{
    noPilha* novo_no = malloc(sizeof(noPilha));
    novo_no->elemento = elem;
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
}
void pop(Pilha* pilha,char *elem)
{
    if(se_vazia(pilha))
    {
        printf("Sem elementos!\n");
        return;
    }
    else
    {
        noPilha* aux = malloc(sizeof(noPilha));
        aux = pilha->topo;
        *elem = aux->elemento;
        pilha->topo = pilha->topo->prox;
        free(aux);
    }
}
void obter_topo(Pilha* pilha,char *elem)
{
    if(se_vazia(pilha) || !pilha->topo)
    {
        printf("Pilha vazia!\n");
        return;
    }
    else
    {
        *elem = pilha->topo->elemento;
    }
}
void reinicializa(Pilha *pilha)
{
    if(se_vazia(pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }
    else
    {
        while(pilha->topo)
        {
            noPilha* temp = malloc(sizeof(noPilha));
            temp = pilha->topo;
            pilha->topo = pilha->topo->prox;
            free(temp);
        }
        printf("Pilha esvaziada!\n");
        return;
    }
}
