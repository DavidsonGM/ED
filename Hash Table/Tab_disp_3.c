#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 1000
#define TAM_NOME 20

typedef struct {
    unsigned int num_elementos;
    char dados[TAM_MAX][TAM_NOME];
} Tab_disp_str;

int hash(int chave){
    return(chave%1000);
}

/* Retorna o endereço do dado, se existir, NULL caso contrário. */
char *busca(Tab_disp_str *tabela, int chave) {
    int i = hash(chave);
    if(tabela->dados[i][0] == '\0')
        return NULL;
    else
        return
            tabela->dados[i];
}

int main(){
    Tab_disp_str tab_disp_str;// = malloc(sizeof(Tab_disp_str));
    for(int i = 0; i < TAM_MAX; i++){
        tab_disp_str.dados[i][0] = '\0';
    }
    strcpy(tab_disp_str.dados[hash(928)], "Jhon");

        if(busca(&tab_disp_str, 918)!= NULL)
            printf("%s\n", busca(&tab_disp_str, 928));
        else
            printf("chave nao está associada a nenhum elemento\n");

    return 0;

}