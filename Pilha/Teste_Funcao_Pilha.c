#include <stdio.h>

void push(char caractere,char pilha[101],int *topo){
    (*topo)++;
    pilha[*topo] = caractere;
}

char pop(char pilha[101], int *topo){
    if(*topo == 0)
        return 0;
    else{
        char aux = pilha[*topo];
        (*topo)--;
        return aux;
    }
}

int main(){
    char pilha[101];
    int topo = 0;

    push('{', pilha, &topo);
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

        push('[', pilha, &topo);
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

    push('(', pilha, &topo);
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

    push('{', pilha, &topo);
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

    push('(', pilha, &topo);
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

    printf("retirou-se o char %c da pilha. Nova pilha:\n", pop(pilha, &topo));
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

    printf("retirou-se o char %c da pilha. Nova pilha:\n", pop(pilha, &topo));
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

    printf("retirou-se o char %c da pilha. Nova pilha:\n", pop(pilha, &topo));
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

    printf("retirou-se o char %c da pilha. Nova pilha:\n", pop(pilha, &topo));
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

    printf("retirou-se o char %c da pilha. Nova pilha:\n", pop(pilha, &topo));
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

        printf("retirou-se o char %c da pilha. Nova pilha:\n", pop(pilha, &topo));
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");

        printf("retirou-se o char %c da pilha. Nova pilha:\n", pop(pilha, &topo));
    for(int i = topo; i > 0;i--)
        printf("%c esta na posicao %d do array\n", pilha[i], i);
    printf("------------------------------------------------------------------------------\n");
    return 0;
}