#include <stdio.h>
#include <stdlib.h>
typedef struct NoPilha {
    int disco;
    struct NoPilha *prox;
} NoPilha;
typedef struct {
    NoPilha *topo;
} Pilha;
void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}
int estaVazia(Pilha *p) {
    return p->topo == NULL;
}
void push(Pilha *p, int disco) {
    NoPilha *novoNo = (NoPilha *)malloc(sizeof(NoPilha));
    if (!novoNo) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoNo->disco = disco;
    novoNo->prox = p->topo;
    p->topo = novoNo;
}
int pop(Pilha *p) {
    if (estaVazia(p)) {
        return -1; // Indicador de erro
    }
    NoPilha *temp = p->topo;
    int disco = temp->disco;
    p->topo = temp->prox;
    free(temp);
    return disco;
}
void imprimirPilha(Pilha *p, char nome) {
    printf("%c: [ ", nome);
    NoPilha *temp = p->topo;
    while (temp) {
        printf("%d ", temp->disco);
        temp = temp->prox;
    }
    printf("]\n");
}

// Move um disco entre pilhas
void moverDisco(Pilha *origem, Pilha *destino, char origemNome, char destinoNome) {
    int disco = pop(origem);
    push(destino, disco);
    printf("Mover disco %d de %c para %c\n", disco, origemNome, destinoNome);
}

// Função recursiva para resolver a Torre de Hanói
void torreHanoi(int n, Pilha *origem, Pilha *aux, Pilha *destino, char nomeOrigem, char nomeAux, char nomeDestino) {
    if (n == 1) {
        moverDisco(origem, destino, nomeOrigem, nomeDestino);
        return;
    }

    torreHanoi(n - 1, origem, destino, aux, nomeOrigem, nomeDestino, nomeAux);
    moverDisco(origem, destino, nomeOrigem, nomeDestino);
    torreHanoi(n - 1, aux, origem, destino, nomeAux, nomeOrigem, nomeDestino);
}

// Função principal para executar o programa
int main() {
    int n = 3; // Número de discos

    Pilha origem, aux, destino;
    inicializarPilha(&origem);
    inicializarPilha(&aux);
    inicializarPilha(&destino);

    // Preenchendo a pilha de origem com os discos
    for (int i = n; i >= 1; i--) {
        push(&origem, i);
    }

    printf("Estado inicial das pilhas:\n");
    imprimirPilha(&origem, 'A');
    imprimirPilha(&aux, 'B');
    imprimirPilha(&destino, 'C');

    printf("\nPassos para resolver a Torre de Hanói:\n");
    torreHanoi(n, &origem, &aux, &destino, 'A', 'B', 'C');

    printf("\nEstado final das pilhas:\n");
    imprimirPilha(&origem, 'A');
    imprimirPilha(&aux, 'B');
    imprimirPilha(&destino, 'C');

    return 0;
}
