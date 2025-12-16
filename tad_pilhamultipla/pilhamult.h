#define TAM_PILHA 30
#define NUM_PILHA 2
typedef struct
{
    int pilha[TAM_PILHA];
    int topo[NUM_PILHA];
    int base[NUM_PILHA];
    int num_elemp;
}Pilhamult;
void inicializa_pilhas(Pilhamult *pm);
int se_cheia(Pilhamult *pm,int num_pilha);
int se_vazia(Pilhamult *pm,int num_pilha);
void push(Pilhamult *pm,int num_pilha,char caract);
void pop(Pilhamult *pm,int num_pilha,char *caract);
void obtertopo(Pilhamult *pm,int num_pilha,char *carct);
