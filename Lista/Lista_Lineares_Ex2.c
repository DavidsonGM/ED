#include <stdio.h>
#include <stdlib.h>

typedef struct lse_int{
    int dado;
    struct lse_int *prox;
}lse_int;

void insere_inicio(lse_int **lista, int data){
    lse_int *aux = malloc(sizeof(lse_int));
    aux->dado = data;
    if(*lista == NULL){
        aux->prox = NULL;
        *lista = aux; 
    }
    else{
        aux->prox = *lista;
        *lista = aux;
    }
}

void insere_final(lse_int **lista, int data){
    lse_int *aux = malloc(sizeof(lse_int));
    aux->dado = data;
    if(*lista == NULL){
        aux->prox = NULL;
        *lista = aux;
    }
    else{
        lse_int *aux1 = *lista;
        while(aux1->prox != NULL){
            aux1 = aux1->prox;
        }
        aux->prox = NULL;
        aux1->prox = aux;
    }

}

int remove_inicio(lse_int **lista){
    if(*lista == NULL){
        return -1;
    }    
    else{
        int aux;
        aux = (*lista)->dado;
        *lista = (*lista)->prox;
        return aux;              
    }
}

int remove_final(lse_int **lista){
    if(*lista == NULL){
        return -1;
    }
    else{
        lse_int *ptr_aux = *lista;
        int aux, i = 0, j;
        while(ptr_aux->prox != NULL){
            ptr_aux = ptr_aux->prox;
            i++;
        }
        aux = ptr_aux->dado;
        if(i == 0)
            *lista = NULL;
        else{
        aux = ptr_aux->dado;
        ptr_aux = *lista;
        for(j = 0; j < i -1; j++)
            ptr_aux = ptr_aux->prox;
        ptr_aux->prox = NULL;
        }
        return aux;
    }
}

void imprime_lista(lse_int *lista){
    lse_int *aux;
    aux = lista;
    if(aux == NULL){}
    else{
        do{
            printf("%d\n", aux->dado);
            aux = aux->prox;
        }
        while(aux!=NULL);
    }
}

int main(){
    char comando;
    lse_int *lista = NULL;
    int data;
    
    do{
        scanf("%c", &comando);
        switch(comando){
            case 'I':
                scanf("%d", &data);
                insere_inicio(&lista, data);
                break;
            case 'F':
                scanf("%d", &data);
                insere_final(&lista, data);
                break;
            
            case 'P':
                data = remove_final(&lista);
                if(data != -1) printf("%d\n", data);
                break;
            
            case 'D':
                data = remove_inicio(&lista);
                if(data != -1) printf("%d\n", data);
                break;
            
            case 'X':
                printf("\n");
                imprime_lista(lista);
                break;
        }
    }
    while(comando != 'X');

    return 0;
}