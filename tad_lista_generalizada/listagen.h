typedef struct{
    char nome[20];
    int bytes;
}Arquivo;
typedef struct{
    char name[30];
    int byts;
    struct NoLista *sublista;
}Diretorio;
typedef union{
    Arquivo arq;
    Diretorio dir;
}Dado;
typedef struct NoLista{
    int tipo; //ou vai ser para arq+byte(0) ou sublist(1)
    Dado atomo;
    struct NoLista *prox;
    struct NoLista *ant;
}NoLista;
typedef struct{
    NoLista *inicio;
    NoLista *fim;
}ListaGen;
void inicializarLG(ListaGen* listg);
void inserirInicioArquivoLG(ListaGen* listg,char nome[],int tamanho);
void inserirInicioDiretorioLG(ListaGen* listg,char nome[],int tamanho);
void removerInicioLG(ListaGen* listg);
void imprimirListaGen(ListaGen *listg);
void imprimirLGRecur(NoLista *no);
void buscaNome(ListaGen *listg,char nomearq[],int tamanho);
int verifVaziaLG(ListaGen* listg);
