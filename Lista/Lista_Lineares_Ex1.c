#include <stdio.h>

typedef struct lse_int{
    int dado;
    struct lse_int *prox;
}lse_int;

void insere_inicio(){

}

void insere_final(){

}

void remove_inicio(){

}

void remove_final(){

}

void imprime_lista(){

}

int main(){
    char comando;
    lse_int *inicio = NULL, *final = NULL, elemento;
    
    do{
        scanf("%c", &comando);
        switch(comando){
            case 'I':
                scanf("%d", &elemento.dado)
                insere_inicio(&inicio, elemento.dado);
                break;

            case 'F':
                scanf("%d", &elemento.dado);
                insere_final(&final, elemento.dado);
                break;
            
            case 'P':
                remove_final(&final);
                break;
            
            case 'D':
                remove_inicio(&inicio);
                break;
            
            case 'X':
                imprime_lista(&inicio);
                break;
        }
    }
    while(comando != X);

    return 0;
}