#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;


void InserirInicio(No **lista, int num);
void InserirFinal(No **lista, int num);
No *Remover(No **lista, int num);
void Imprimir(No *no);
