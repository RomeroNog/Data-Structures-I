typedef struct{
    int num;
    float saldo;
}ContaBank;
void cadastro(ContaBank* conta,int num,float saldo);
void deposito(ContaBank* conta,float valor);
void sacar(ContaBank* conta,float valor);
void extrato(ContaBank conta);
