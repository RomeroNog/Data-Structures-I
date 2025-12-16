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
