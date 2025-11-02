#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct pilha {
    int n;
    int v[MAX];
};

Pilha *pilha_cria(void) {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));

    if (p == NULL) {
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }

    p->n = 0;
    return p;
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info) {
    if (p->n == MAX) {
        printf("Capacidade da Pilha Estourou!!!\n");
        exit(1);
    }

    p->v[p->n] = info;
    p->n = p->n + 1;
}

/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p) {
    int i;
    for (i = p->n - 1; i >= 0; i--) {
        printf("%d\n", p->v[i]);
    }
}

/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p) {
    free(p);
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p) {
    return p->n == 0;
}

/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p) {
    int a;
    if (pilha_vazia(p)) {
        printf("Pilha Vazia!!!\n");
        exit(1);
    }

    a = p->v[p->n - 1];
    p->n--;
    return a;
}

/*Função que retorna o elemento do topo de uma pilha sem removê-lo.*/
int topo(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha Vazia!!!\n");
        exit(1);
    }

    return *(p->v + p->n - 1);
}

/*Função que conta o número de elementos ímpares em uma pilha.*/
int impares(Pilha *p) {
    int count = 0;

    for (int i = 0; i < p->n; i++) {
        if (p->v[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

/*Função que empilha os elementos pares de uma pilha p1 em outra pilha p2.*/
Pilha *empilha_pares(Pilha *p1, Pilha *p2) {
    int i = p1->n - 1; // Começa no topo de p1

    while (i >= 0) {

        if (p1->v[i] % 2 == 0) {
            pilha_push(p2, p1->v[i]);
        }

        i--;
    }
    return p2;
}
