#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a;
    Pilha *p1 = pilha_cria();
    pilha_push(p1, 11);
    pilha_push(p1, 15);
    pilha_push(p1, 28);
    pilha_push(p1, 30);
    a = pilha_pop(p1);
    pilha_imprime(p1);
    printf("Elemento no topo da pilha p1 : % d\n", topo(p1));
    printf("Qde elems impares na pilha p1 : % d\n", impares(p1));
    Pilha *p2 = pilha_cria();
    pilha_push(p2, 7);
    pilha_push(p2, 8);
    pilha_push(p2, 9);
    p2 = empilha_pares(p1, p2);
    pilha_imprime(p2);
    pilha_libera(p1);
    pilha_libera(p2);
    system("PAUSE");
    return 0;
}
