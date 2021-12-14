#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int potencia(int base, int expoente){
    int resultado = 1;

    for(int i = 0; i < expoente; i++)
        resultado *= base;
    
    return resultado;
}

typedef struct no{
    char data;
    struct no *q1, *q2, *q3, *q4;
}no;

no *cria_arvore(char dado){
    no *raiz = (no *)malloc(sizeof(no));
    if(!raiz)
        return NULL;
    raiz->data = dado;
    raiz->q1 = NULL;
    raiz->q2 = NULL;
    raiz->q3 = NULL;
    raiz->q4 = NULL;
    return raiz;
}

no *insere(no* raiz, char linha[2048], int *i){
    if(!raiz)
        raiz = cria_arvore(linha[*i]);
    if(linha[*i] == 'p'){
        (*i)++;
        raiz->q1 = insere(raiz->q1, linha, i);
        (*i)++;
        raiz->q2 = insere(raiz->q2, linha, i);
        (*i)++;
        raiz->q3 = insere(raiz->q3, linha, i);
        (*i)++;
        raiz->q4 = insere(raiz->q4, linha, i);
    }
    else
        raiz->data = linha[*i];   
    return raiz;
}

void mostra_arvore(no* raiz){
    if(!raiz)
        printf("(");
    else{
        printf("(%c", raiz->data);
        printf(" ");
        mostra_arvore(raiz->q1);
        printf(" ");
        mostra_arvore(raiz->q2);
        printf(" ");
        mostra_arvore(raiz->q3);
        printf(" ");
        mostra_arvore(raiz->q4);
        printf(" ");

    }
    printf(")");
}

void transforma_em_array(no *arvore, char imagem[1024], int n, int *i, int *aux){
    if(arvore->data == 'p'){
        n++;
        transforma_em_array(arvore->q1, imagem, n, i, aux);
        transforma_em_array(arvore->q2, imagem, n, i, aux);
        transforma_em_array(arvore->q3, imagem, n, i, aux);
        transforma_em_array(arvore->q4, imagem, n, i, aux);
    }
    else{
        *aux += 1024/potencia(4, n);
        for(*i = *i; *i < *aux; (*i)++){
            imagem[*i] = arvore->data;
        }
    }    
} 

int main(){
    char linha1[2048], linha2[2048], imagem1[1024], imagem2[1024];
    int i = 0, j = 0, n_pretos = 0;
    scanf("%s", linha1);
    scanf("%s", linha2);
    no *raiz1 = NULL, *raiz2 = NULL;
    raiz1 = insere(raiz1, linha1, &i);
    i = 0;
    raiz2 = insere(raiz2, linha2, &i);
    i = 0;
    transforma_em_array(raiz1, imagem1, 0, &i, &j);
    i = 0;
    j = 0;
    transforma_em_array(raiz2, imagem2, 0, &i, &j);
    for(i = 0; i < 1024; i++){
        if(imagem1[i] == 'f' || imagem2[i] == 'f')
            n_pretos++;
    }
    printf("%d\n", n_pretos);

    return 0;
}