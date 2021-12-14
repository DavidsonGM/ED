#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Fila{
    char *nome;
    //int posicao;
    struct Fila *frente, *atras;
}Pessoa;

int main(){
    int n_interacoes = 0, i = -1, j;
    char *pos = malloc(1000), *aux;
    Pessoa *pessoa = malloc(sizeof(Pessoa));
    Pessoa *inicio = pessoa, *auxiliar;

    scanf("%[^\n]", pos);
    aux = strtok(pos, " ");
    pessoa->nome = aux;
    while(aux != NULL){
        //printf("%s\n", aux);
        pessoa++;
        i++;
        aux = strtok(NULL, " ");
        pessoa->nome = aux;
    }

    pessoa = inicio;

    for(j = 0; j < i; j++){
        //pessoa->posicao = j;
        n_interacoes = strtol(pessoa->nome, '\0', 10);
        if(n_interacoes != 0)
            break;
        pessoa++;
    }

    /*pessoa = inicio;  
    for(j = 0; j < i; j++){
        printf("%s esta na posicao numero %d da fila\n",pessoa->nome, pessoa->posicao);
        pessoa++;
    }
    printf("%d\n", i);*/
    pessoa = inicio;

    for(j = 0; j < i; j++){
        if(j == (i)){
            pessoa->atras = NULL;
            pessoa->frente = pessoa++;
            pessoa--;          
        }
        else if(j == 0){
            pessoa->frente = NULL;
            pessoa->atras = pessoa--;
            pessoa++;
        }
        else{
            pessoa->frente = pessoa++;
            pessoa--;
            pessoa->atras = pessoa--;
            pessoa++;
        }
        pessoa++;
    }
    pessoa = inicio;   
    auxiliar = inicio;


    //for(int l = 0; l < n_interacoes; l++){
        for(j = 0; j < i; j++){
            if(pessoa->frente == NULL){
                (pessoa->atras)->frente = NULL;
                for(int k = 0; k < i; k++){
                    if(auxiliar->atras == NULL){
                        pessoa->frente = auxiliar;
                        pessoa->atras = NULL;
                        auxiliar->atras = pessoa;
                        auxiliar = inicio;
                    }
                auxiliar++;
                }

            }
            pessoa++;
    }  
    pessoa = inicio;
    auxiliar = inicio;
    //}

    for(j = 0; j < i; j++){
        if(pessoa->frente == NULL)
            printf("proximo: %s\n", pessoa->nome);
        if(pessoa->atras == NULL)
            printf("ultimo: %s\n", pessoa->nome);
        pessoa++;
    }

    return 0;
}