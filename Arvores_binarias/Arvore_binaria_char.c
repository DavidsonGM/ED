#include <stdio.h>
#include <stdlib.h>

typedef struct ab_char{
    char dado;
    struct ab_char *esq, *dir;
}ab_char;

ab_char *cria_arvore(char data){
    ab_char *raiz = (ab_char *)malloc(sizeof(ab_char));
    if(!raiz)
        return NULL;
    raiz->dado = data;
    raiz->esq = NULL;
    raiz->dir = NULL;
    return raiz;
}

int altura(ab_char *raiz) {
    if(!raiz)
        return 0;
    int altura_esq, altura_dir;
    altura_esq = altura(raiz->esq);
    altura_dir = altura(raiz->dir);

    return (altura_dir > altura_esq ? altura_dir : altura_esq) + 1;
}

void insere(ab_char** p_raiz, ab_char *e){
    if(!e)
        return;
    if(!*p_raiz)
        *p_raiz = e;
    else if(altura((*p_raiz)->dir) <= altura((*p_raiz)->esq))
        insere(&(**p_raiz).dir, e);
    else
        insere(&(**p_raiz).esq, e);
}
void mostra_arvore(ab_char* raiz){
    if(!raiz)
        printf("(");
    else{
        printf("(%c", raiz->dado);
        printf(" ");
        mostra_arvore(raiz->esq);
        printf(" ");
        mostra_arvore(raiz->dir);

    }
    printf(")");
}

void rotaciona_esquerda(ab_char **p_raiz) {
    if(!*p_raiz || !(*p_raiz)->dir)
        return;
    ab_char *aux = *p_raiz;   
    *p_raiz = (*p_raiz)->dir;
    aux->dir = (*p_raiz)->esq;
    (*p_raiz)->esq = aux;
}

/*void em_lista(ab_char **p_raiz){
    if(p_raiz){
        while((*p_raiz)->dir)
            rotaciona_esquerda(p_raiz);
        if((*p_raiz)->esq)
            em_lista(&(*p_raiz)->esq);
    }
}*/

void em_lista(ab_char **p_raiz){
    if(p_raiz){
        if(*p_raiz){
            while((*p_raiz)->dir)
                rotaciona_esquerda(p_raiz);
        em_lista(&(*p_raiz)->esq);
        }
    }
}

int main(){
    ab_char *raiz = NULL;
    ab_char e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;
    e1.dado = 'I';
    e1.esq = NULL;
    e1.dir = NULL;
    e2.dado = 'G';
    e2.esq = NULL;
    e2.dir = NULL;
    e3.dado = 'H';
    e3.esq = NULL;
    e3.dir = NULL;
    e4.dado = 'C';
    e4.esq = NULL;
    e4.dir = NULL;
    e5.dado = 'J';
    e5.esq = NULL;
    e5.dir = NULL;
    e6.dado = 'F';
    e6.esq = NULL;
    e6.dir = NULL;
    e7.dado = 'A';
    e7.esq = NULL;
    e7.dir = NULL;
    e8.dado = 'B';
    e8.esq = NULL;
    e8.dir = NULL;
    e9.dado = 'D';
    e9.esq = NULL;
    e9.dir = NULL;
    e10.dado = 'E';
    e10.esq = NULL;
    e10.dir = NULL;

    insere(&raiz, &e1);
    insere(&raiz, &e2);
    insere(&raiz, &e3);
    insere(&raiz, &e4);
    insere(&raiz, &e5);
    insere(&raiz, &e6);
    insere(&raiz, &e7);
    insere(&raiz, &e8);
    insere(&raiz, &e9);
    insere(&raiz, &e10);

    mostra_arvore(raiz);
    printf("\n");
    em_lista(&(raiz->esq));
    mostra_arvore(raiz);
    em_lista(&(raiz->dir));
    printf("\n");
    mostra_arvore(raiz);
        printf("\n");
        
    return 0;
}