#include <iostream>

extern "C" {
    #include "pilha.h"
}


int main()
{
    Pilha testpi;
    int valor;

    inicializa_pilha(&testpi);

    push(&testpi,10);
    push(&testpi,20);
    push(&testpi,30);

    obter_topo(&testpi,&valor);

    std::cout << "Topo da pilha: " << valor << std::endl;

    pop(&testpi,&valor);

    std::cout << "Elemento removido: " << valor << std::endl;

    reinicializa(&testpi);

    std::cout << "Hello World!" << std::endl;

return 0;
}

