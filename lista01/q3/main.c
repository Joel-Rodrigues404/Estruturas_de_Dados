#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, qtd;
    Fila *f1 = fila_cria();
    fila_insere(f1, 21);
    fila_insere(f1, 33);
    fila_insere(f1, 45);
    fila_insere(f1, 57);
    fila_insere(f1, 65);
    a = fila_remove(f1);
    printf("Valor removido da fila f1 : % d\n", a);
    fila_imprime(f1);
    Fila *f2 = inverte(f1);
    fila_imprime(f2);
    qtd = qtd_maior(f1, 30);
    printf("Núm.de elem.maiores que 30 em f1 : % d\n", qtd);
    printf("Qtd.elem.pares na fila f1 : % d\n", pares(f1));
    fila_libera(f1);
    fila_libera(f2);
    system("PAUSE");
    return 0;
}
