#define I 5
#define J 5
typedef struct No{
    int elem,linha,coluna;
    struct No *direita;
    struct No *baixo;
}No;
typedef struct{
    No *linha[I];
    No *coluna[J];
}ListaCruzada;
void inicializarLC(ListaCruzada* listC);
void inserirLC(ListaCruzada* listC,int elem,int lin,int col);
void imprimirLC(ListaCruzada* listC);
void removerLC(ListaCruzada* listC,int lin,int col,int* elem);
void soma(ListaCruzada* listC,int lin,int constante);
