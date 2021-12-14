#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TAM_MAX 1000
#define TAM_NOME 20

typedef struct {
    unsigned int num_elementos;
    char dados[TAM_MAX];
} tab_disp_char;

int hash(int chave){
    return(chave%1000);
}

/* Retorna o endereço do dado, se existir, NULL caso contrário. */
/*char *busca(Tab_disp_char *tabela, int chave) {
    int i = hash(chave);
    if(tabela->dados[i] == '\0')
        return NULL;
    else
        return
            tabela->dados[i];
}*/
_Bool insere(tab_disp_char* td, int chave, char dado){
    int i = hash(chave);
    if(td->dados[i] == '\0'){
        td->dados[i] = dado;
        td->num_elementos++;
        return true;
    }   
    return false;
}

int main(){
    tab_disp_char Tab_disp_char;
    Tab_disp_char.num_elementos = 0;
    for(int i = 0; i < TAM_MAX; i++){
        Tab_disp_char.dados[i] = '\0';
    }
    Tab_disp_char.dados[hash(928)] =  'J';
    if(true == insere(&Tab_disp_char, 190099123, 'F'))
        printf("foi possivel inserir\n");
    else
        printf("houve colisao");
    printf("%d\n", Tab_disp_char.num_elementos);
        //if(busca(&Tab_disp_char, 918)!= NULL)
            //printf("%s\n", busca(&Tab_disp_char, 928));
        //else
          //  printf("chave nao está associada a nenhum elemento\n");

    return 0;

}