#include <stdio.h>
#include <stdlib.h>
#include "listcircular.h"

void criarLista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserirNoInicio(Lista *lista, int num){
    No *novo = malloc(sizeof(NULL));

    if (novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        if (lista->fim == NULL){
            lista->fim = novo;
        }
        lista->fim->proximo = lista->inicio;
        lista->tam++;
    }else {
        printf("Erro!");
    }   
}

void inserirFim(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(NULL));

    if (novo){
        novo->valor = num;

        if (lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;;
        }else {
            lista->fim->proximo = novo;
            lista->fim = novo;
            //lista->fim->proximo = lista->inicio;
            novo->proximo = lista->inicio;
        }
        lista->tam++;

    }else {
        printf("Erro!");
    }   
}

No *remover(Lista *lista, int num){
    No *aux, *removi = NULL;

    if (lista->inicio){
        if (lista->inicio == lista->fim && lista->inicio->valor == num){
           removi = lista->inicio;
           lista->inicio = NULL;
           lista->fim = NULL;
           lista->tam--;
        }else if (lista->inicio->valor == num){
            removi = lista->inicio;
            lista->inicio = removi->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
        }else{
            aux = lista->inicio;
            while (aux->proximo != lista->inicio && aux->proximo->valor != num){
                aux = aux->proximo;
            }if (aux->proximo->valor == num){
                if (lista->fim == aux->proximo){
                    removi = aux->proximo;
                    aux->proximo = removi->proximo;
                    lista->fim = aux;
                }else {
                    removi = aux->proximo;
                    aux->proximo = removi->proximo;
                }
                lista->tam--;
            } 
        }
    }
    return removi;
}

void imprimir(Lista lista){
    No *no = lista.inicio;
    if (no){
        do {
            printf("\nLista: %d ", no->valor);
            no = no->proximo;
        }while(no != lista.inicio);
    }
    printf("\n");
}


int main(){
    Lista lista;
    int opc, valor;
    No *removi;

    criarLista(&lista);

        do{
        printf("\n----MENU----");
        printf("\n0- Sair \n1- Inserir no Inicio \n2-Inserir no Final \n3- Remover \n4- Imprimir\n");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserirNoInicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserirFim(&lista, valor);
            break;
        case 3:
            printf("Digite um valor para ser removido: ");
            scanf("%d", &valor);
            removi = remover(&lista, valor);
            if (removi) {
                printf("Elemento a ser removido: %d\n", removi->valor);
                free(removi);
            }
            break;
        case 4:
            imprimir(lista);
            break;
        
        default:
            if (opc != 0){
                printf("Opção invalida!");
            }
        }
    }while (opc != 0);          
}
