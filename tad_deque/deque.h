typedef struct noDuplo{
    int elem;
    struct noDuplo *prox;
    struct noDuplo *ant;
}noDuplo;
typedef struct{
    noDuplo *inicio;
    noDuplo *fim;
}Deque;
void inicializarDeque(Deque* deq);
void inserirInicio(Deque* deq,int elem);
void inserirFim(Deque* deq,int elem);
void removerInicio(Deque* deq,int* elem);
void removerFim(Deque* deq,int* elem);
int verifVazia(Deque* deq);
void consultaInicio(Deque* deq,int *elem);
void consultaFim(Deque* deq,int* elem);
