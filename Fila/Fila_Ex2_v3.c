#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Fila{
    struct Fila *prox;
    char nome[];
}Pessoa;

Pessoa *aloca_pessoa(char *palavra){
    Pessoa *aux = malloc(sizeof(Pessoa));
    strcpy(aux->nome, palavra);
    aux->prox = NULL;
    return aux;
}

int main(){
    int n_interacoes = 0, i = 0, j;
    char *linha, *palavra;
    Pessoa *pessoa, *inicio, *final;

    scanf("%[^\n]", linha);
    palavra = strtok(linha, " ");
    pessoa = aloca_pessoa(palavra);
    inicio = pessoa;
    while(palavra != NULL){        
        palavra = strtok(NULL, " ");
        if(palavra == NULL)
            break;
        pessoa->prox = aloca_pessoa(palavra);
        pessoa = pessoa->prox;
        i++;
    }
    final = pessoa;
    pessoa = inicio;


    for(j = 0; j < i; j++){
        //if(j = (i - 1))  
          //  final = pessoa->prox;
        n_interacoes = strtol(pessoa->nome, '\0', 10);
        if(n_interacoes != 0)
            break;
        pessoa = pessoa->prox;
    }
    pessoa = inicio;


    /*for(j = 0; j < n_interacoes; j++){
        final->prox = inicio;
        inicio = inicio->prox;
        final = final->prox;
        final->prox = NULL;
    }*/
    
    //printf("Pessoa da frente: %s\nPessoa do fim: %s\n", inicio->nome, final->nome); 
    return 0;
}