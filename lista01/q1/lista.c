#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    Lista *prox;
};

/* Cria uma lista vazia.*/
Lista *lst_cria() {
    return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l) {
    return (l == NULL);
}

/* Insere um elemento no início da lista.*/
Lista *lst_insere(Lista *l, int info) {
    Lista *ln = (Lista *)malloc(sizeof(Lista));
    ln->info = info;
    ln->prox = l;
    return ln;
}

/* Busca um elemento em uma lista.*/
Lista *lst_busca(Lista *l, int info) {
    Lista *lAux = l;

    while (lAux != NULL) {
        if (lAux->info == info)
            return lAux;
        lAux = lAux->prox;
    }
    return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l) {
    Lista *lAux = l;
    while (lAux != NULL) {
        printf("Info = %d\n", lAux->info);
        lAux = lAux->prox;
    }
}

/* Imprime uma lista de forma recursiva e invertida.*/
void lst_imprime_invertida_rec(Lista *l) {
    if (lst_vazia(l))
        return;
    else {
        lst_imprime_invertida_rec(l->prox);
        printf("info: %d\n", l->info);
    }
}

/* Remove um elemento de uma lista.*/
Lista *lst_remove(Lista *l, int info) {
    if (l != NULL) {
        Lista *lAux = l->prox;
        if (l->info == info) {
            free(l);
            return lAux;
        } else {
            Lista *lAnt = l;
            while (lAux != NULL) {
                if (lAux->info == info) {
                    lAnt->prox = lAux->prox;
                    free(lAux);
                    break;
                } else {
                    lAnt = lAux;
                    lAux = lAux->prox;
                }
            }
        }
    }
    return l;
}

/* Remove um elemento de uma lista de forma recursiva.*/
Lista *lst_remove_rec(Lista *l, int info) {
    if (!lst_vazia(l))
        if (l->info == info) {
            Lista *lAux = l;
            l = l->prox;
            free(lAux);
        } else {
            l->prox = lst_remove_rec(l->prox, info);
        }
    return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l) {
    Lista *lProx;
    while (l != NULL) {
        lProx = l->prox;
        free(l);
        l = lProx;
    }
}

int comprimento(Lista *l) {
    if (l == NULL) {
        return 0;
    }

    return 1 + comprimento(l->prox);
}

int menores(Lista *l, int n) {
    int count = 0;

    for (Lista *lAux = l; lAux != NULL; lAux = lAux->prox) {
        if (lAux->info < n) {
            count++;
        }
    }

    return count;
}

int soma(Lista *l) {
    if (l == NULL) {
        return 0;
    }

    return l->info + soma(l->prox);
}

static int ehPrimo(int n) {
    if (n <= 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    if (n % 2 == 0) {
        return 0;
    }

    int i;
    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int primos(Lista *l) {
    int count = 0;

    for (Lista *lAux = l; lAux != NULL; lAux = lAux->prox) {

        if (ehPrimo(lAux->info)) {
            count++;
        }
    }

    return count;
}

Lista *lst_conc(Lista *l1, Lista *l2) {
    Lista *l_nova = lst_cria();
    Lista *l_fim = NULL;

    Lista *lAux;

    for (lAux = l1; lAux != NULL; lAux = lAux->prox) {

        Lista *novo_no = (Lista *)malloc(sizeof(Lista));
        novo_no->info = lAux->info;
        novo_no->prox = NULL;

        if (l_nova == NULL) {
            l_nova = novo_no;
            l_fim = novo_no;
        } else {
            l_fim->prox = novo_no;
            l_fim = novo_no;
        }
    }

    for (lAux = l2; lAux != NULL; lAux = lAux->prox) {

        Lista *novo_no = (Lista *)malloc(sizeof(Lista));
        novo_no->info = lAux->info;
        novo_no->prox = NULL;

        if (l_nova == NULL) {
            l_nova = novo_no;
            l_fim = novo_no;
        } else {
            l_fim->prox = novo_no;
            l_fim = novo_no;
        }
    }

    return l_nova;
}

Lista *lst_diferenca(Lista *l1, Lista *l2) {
    Lista *lIndice;

    for (Lista *lAux = l2; lAux != NULL; lAux = lAux->prox) {

        lIndice = lst_busca(l1, lAux->info);

        if (lIndice != NULL) {
            l1 = lst_remove(l1, lIndice->info);
        }
    }

    return l1;
}
