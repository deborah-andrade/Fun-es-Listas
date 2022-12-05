#include <stdio.h>
#include <stdlib.h>
#include "listdupla.h"



void InserirInicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if (novo){
        novo->valor = num;
        novo->proximo = *lista;
        novo->anterior = NULL;
        if (*lista){
            (*lista)->anterior = novo;
        }
        *lista = novo;
    }else{
        printf("Erro!");
    }
    
}

void InserirFinal(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;

        if (*lista == NULL){
            *lista = novo;
            novo->anterior = NULL;
        }else {
            aux = *lista;
            while (aux->proximo) {
                aux = aux->proximo;
            } 
            aux->proximo = novo;
            novo->anterior = aux;
        } 
    }else{
        printf("Erro!");
    }
}

No *Remover(No **lista, int num){
    No *aux, *remover = NULL;

    if (*lista){
        if ((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
            if (*lista){
                (*lista)->anterior = NULL;
            }
        }else {
            aux = *lista;
            while (aux->proximo && aux->proximo->valor!=num){
                aux = aux->proximo;
            }
            if (aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if (aux->proximo) {
                    aux->proximo->anterior = aux;
                }
            }
        }
    }
    return remover;
}

void Imprimir(No *no){
    printf("\nLista: ");
    while (no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
}


int main(){
    int opc, valor;
    No *remove, *lista = NULL;

    do{
    printf("\n----MENU----");
        printf("\n0- Sair \n1- Inserir no Inicio \n2-Inserir no Final \n3- Remover \n4- Imprimir\n");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            InserirInicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            InserirFinal(&lista, valor);
            break;
        case 3:
            printf("Digite um valor para ser removido: ");
            scanf("%d", &valor);
            remove = Remover(&lista, valor);
            if (remove) {
                printf("Elemento a ser removido: %d\n", remove->valor);
                free(remove);
            }
            break;
        case 4:
            Imprimir(lista);
            break;
        
        default:
            if (opc != 0){
                printf("Opção invalida!");
            }
        }
    }while (opc != 0);
    
    return 0;
}

