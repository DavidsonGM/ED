#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Lista_de_tarefas{
    struct Lista_de_tarefas *prox;
    char *tarefa;
}Lista_de_tarefas;


int main(){
    Lista_de_tarefas *lista[10], *auxiliar[10];
    char *linha = malloc(1000), *palavra, *aux;
    int n_atividades, prioridade = 0, i = 0, n_tarefas = 0, j = 0;

    for(i = 0; i < 10; i++){
        lista[i] = malloc(sizeof(Lista_de_tarefas));
        lista[i]->prox = NULL;
        auxiliar[i] = lista[i];
    }
    scanf("%[^\n]", linha);
    scanf("%d", &n_atividades);

    palavra = strtok(linha, " ");
    aux = palavra;
    palavra = strtok(NULL, " ");
    prioridade = strtol(palavra, '\0', 10);
    prioridade--;
    n_tarefas++;
    lista[prioridade]->tarefa = aux;
     while(palavra != NULL){
        palavra = strtok(NULL, " ");
        if(palavra == NULL)
            break;
        prioridade = strtol(palavra, '\0', 10);
        if(prioridade == 0)
            aux = palavra;
        if(prioridade != 0){
            prioridade--;
            auxiliar[prioridade]->prox = malloc(sizeof(Lista_de_tarefas));
            auxiliar[prioridade] = auxiliar[prioridade]->prox; 
            auxiliar[prioridade]->prox = NULL;
            lista[prioridade]->tarefa = aux;
            n_tarefas++;
        }
    }

    for(i = 0; i < 10; i++)
        auxiliar[i] = lista[i];
    printf("tamanho da lista: %d\n",n_tarefas - n_atividades);
    for(int i = 0; i < 10; i++){
        while(lista[i] != NULL){
            if(lista[i]->tarefa != NULL){
                j++;
                if(j > n_atividades)
                    printf("Tarefa: %s Prioridade #%d\n", lista[i]->tarefa, i + 1);
            }
            lista[i] = lista[i]->prox;
        }
    }

    return 0;
}