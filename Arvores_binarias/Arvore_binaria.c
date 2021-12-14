#include <stdio.h>
#include <stdlib.h>

typedef struct ab_int{
    int dado;
    struct ab_int *esq, *dir;
}ab_int;

ab_int *cria_arvore(int data){
    ab_int *raiz = (ab_int *)malloc(sizeof(ab_int));
    if(!raiz)
        return NULL;
    raiz->dado = data;
    raiz->esq = NULL;
    raiz->dir = NULL;
    return raiz;
}

void rotaciona_direita(ab_int **p_raiz){
    if(!*p_raiz || !(*p_raiz)->esq)
        return;
    ab_int *aux = *p_raiz;   
    *p_raiz = (*p_raiz)->esq;
    aux->esq = (*p_raiz)->dir;
    (*p_raiz)->dir = aux;
}

void rotaciona_esquerda(ab_int **p_raiz) {
    if(!*p_raiz || !(*p_raiz)->dir)
        return;
    ab_int *aux = *p_raiz;   
    *p_raiz = (*p_raiz)->dir;
    aux->dir = (*p_raiz)->esq;
    (*p_raiz)->esq = aux;
}

ab_int *insere(ab_int* raiz, int data){
    if(!raiz)
        return cria_arvore(data);
    if(raiz->dado >= data)
        raiz->esq = insere(raiz->esq, data);
    else
        raiz->dir = insere(raiz->dir, data);
    return raiz;
}

void mostra_arvore(ab_int* raiz){
    if(!raiz)
        printf("(");
    else{
        printf("(%d", raiz->dado);
        printf(" ");
        mostra_arvore(raiz->esq);
        printf(" ");
        mostra_arvore(raiz->dir);

    }
    printf(")");
}
int altura(ab_int *raiz) {
    if(!raiz)
        return 0;
    int altura_esq, altura_dir;
    altura_esq = altura(raiz->esq);
    altura_dir = altura(raiz->dir);

    return (altura_dir > altura_esq ? altura_dir : altura_esq) + 1;
}


void em_lista(ab_int **p_raiz){
    if(p_raiz && *p_raiz){
        while((*p_raiz)->esq)
            rotaciona_direita(p_raiz);
        em_lista(&(*p_raiz)->dir);
        }
    }

void comprime(ab_int **p_raiz, int rotacoes){
    if(rotacoes != 0 && p_raiz && *p_raiz){
        rotaciona_esquerda(p_raiz);
        comprime(&(*p_raiz)->dir, rotacoes - 1);
    }
}   


void dsw(ab_int **p_raiz){
    em_lista(p_raiz);
    int r = (altura(*p_raiz) - 1)/2;
    while(altura((*p_raiz)->dir) > altura((*p_raiz)->esq)){
        comprime(p_raiz, r);
        r /= 2;
    }
}

int main(){
    ab_int *raiz = NULL;
    int n, i;
    scanf("%d", &n);
    int dados[n];
    for(i = 0; i < n; i++)
        scanf("%d", &dados[i]);
    for(i = 0; i < n; i++)  
        raiz = insere(raiz, dados[i]); 
    /*raiz = insere(raiz, 5);
    raiz = insere(raiz, 7);
    raiz = insere(raiz, 6);
    raiz = insere(raiz, 8);
    raiz = insere(raiz, 3);
    raiz = insere(raiz, 4);
    raiz = insere(raiz, 2);*/

    mostra_arvore(raiz);
    printf("\n");
    dsw(&raiz);
    mostra_arvore(raiz);
    printf("\n");
    return 0;
}