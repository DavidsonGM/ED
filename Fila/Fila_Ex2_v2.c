#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Fila{
    char *nome;
    struct Fila *prox;
}Pessoa;

int main(){
    int n_interacoes = 0, i = -1, j;
    char *linha, *palavra;
    Pessoa *pessoa = malloc(sizeof(Pessoa));
    Pessoa *inicio = pessoa, *final, *aux;

    scanf("%s[^\n]", linha);
    palavra = strtok(linha, " ");
    pessoa->nome = palavra;
    aux = pessoa;
    while(palavra != NULL){
        pessoa->prox = aux++;
        pessoa++;
        i++;
        palavra = strtok(NULL, " ");
        pessoa->nome = palavra;
    }
    pessoa -= 2;
    final = pessoa;
    
    pessoa = inicio;

    for(j = 0; j < i + 1; j++){
        n_interacoes = strtol(pessoa->nome, '\0', 10);
        if(n_interacoes != 0)
            break;
        pessoa++;
    }

    pessoa = inicio;
    final->prox = NULL;
    /*for(j = 0; j < n_interacoes; j++){
        inicio->prox = NULL;
        final++;
        strcpy(final->nome, inicio->nome);
        inicio++;
    }*/  
    if(inicio->prox == NULL)
        printf(" nulo");
    /*for(j = 0; j < n_interacoes; j++){
        final->prox = inicio;
        final = inicio;
        //inicio = inicio->prox;
        
        final->prox = NULL;
    }*/
    aux = inicio;
    for(j = 0; j < n_interacoes; j++){
        final->prox = inicio;
        final = inicio;
        inicio = aux->prox;
        aux = inicio;
    }
  
    printf("Pessoa da frente: %s\nPessoa do fim: %s\n", inicio->nome, final->nome); 

    return 0;
}