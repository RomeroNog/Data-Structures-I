typedef struct{
    char rg[15];
    char nome[50];
    char telefone[14];
    char endereco[60];
}VagaEmprego;
void inserir(char *rg,char *nome,char *telefone,char *endereco,VagaEmprego *pessoa,int *n);
int pesquisa(VagaEmprego *pessoa,char *rg,int n);
void remover(VagaEmprego *pessoa,char *rg,int *n);
void alterar(VagaEmprego *pessoa,char *rg,int n);
