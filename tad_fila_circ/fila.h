#define MAX 10
typedef struct{
    int vFila[MAX];
    int inicio;
    int fim;
    int contador_elem;
}Fila;
void inicializar(Fila *fila);
int se_vazia(Fila *fila);
int se_cheia(Fila *fila);
void inserir(Fila *fila,int elem);
void remover(Fila *fila,int *elem);
void obter_ini(Fila *fila,int *elem);
int qnt_elem(Fila *fila);
