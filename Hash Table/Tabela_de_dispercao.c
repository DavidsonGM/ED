/* A constante global TAM_MAX já foi definida. */
/* A constante global TAM_NOME já foi definida. */
#define TAM_NOME 10
#define TAM_MAX 10
#include <stdio.h>

typedef struct {
    unsigned int num_elementos;
    char dados[TAM_MAX][TAM_NOME];
} tab_disp_str;

/* Retorna o endereço do dado, se existir, NULL caso contrário. */
char *busca(tab_disp_str* tabela, int chave) {
    if(tabela->dados[chave%TAM_MAX] != NULL)
        return tabela->dados[chave%TAM_MAX];
    else 
        return NULL;    
}

int main(){}