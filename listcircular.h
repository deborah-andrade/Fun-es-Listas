#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

void criarLista(Lista *lista);
void inserirNoInicio(Lista *lista, int num);
void inserirFim(Lista *lista, int num);
No *remover(Lista *lista, int num);
void imprimir(Lista lista);
