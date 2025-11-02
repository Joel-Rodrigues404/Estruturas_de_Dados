typedef struct lista Lista;
/* Cria uma lista vazia.*/
Lista *lst_cria();
/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l);
/* Insere um elemento no início da lista.*/
Lista *lst_insere(Lista *l, int info);
/* Busca um elemento em uma lista.*/
Lista *lst_busca(Lista *l, int info);
/* Imprime uma lista.*/
void lst_imprime(Lista *l);
/* Imprime uma lista de forma recursiva e invertida.*/
void lst_imprime_invertida_rec(Lista *l);
/* Remove um elemento de uma lista.*/
Lista *lst_remove(Lista *l, int info);
/* Imprime uma lista de forma recursiva e invertida.*/
Lista *lst_remove_rec(Lista *l, int info);
/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l);
/* função que calcule o número de nós de uma lista */
int comprimento(Lista *l);
/* função que calcule o número de nós de uma lista cujo valor seja menor que n */
int menores(Lista *l, int n);
/* função que calcule a soma dos valores dos elementos de uma lista */
int soma(Lista *l);
/* função que calcule o número de elementos primos de uma lista */
int primos(Lista *l);
/* função que concatene duas listas */
Lista *lst_conc(Lista *l1, Lista *l2);
/* função que modifica as listas para remover diferença entre duas listas */
Lista *lst_diferenca(Lista *l1, Lista *l2);
