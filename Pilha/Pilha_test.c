#include <stdio.h>

void push(int *fim, int pilha[10],int elemento){
    if(*fim == 10)
        printf("Impossivel inserir elemento: pilha cheia\n");
    else{
        pilha[(*fim)] = elemento;
        (*fim)++;
    }
}

int pop(int* fim, int pilha[10]){
    if(*fim == 0){
        printf("Impossivel retirar um elemento, a pilha esta vazia\n");
        return 0;
    }    
    else{
        int aux = *fim;
        (*fim)--;
        return aux;
    }
}


int main (){
    int pilha[10];
    int topo = 0;

    push(&topo, pilha, 30);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");
    
    push(&topo, pilha, 45);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }
        
    printf("----------------------------------------------------\n");

    push(&topo, pilha, 27);  
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    } 

    printf("----------------------------------------------------\n");

    push(&topo, pilha, 20);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");
    
    push(&topo, pilha, 45);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }
        
    printf("----------------------------------------------------\n");

    push(&topo, pilha, 27);  
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    } 

    printf("----------------------------------------------------\n");

    push(&topo, pilha, 20);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");

push(&topo, pilha, 45);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }
        
    printf("----------------------------------------------------\n");

    push(&topo, pilha, 27);  
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    } 

    printf("----------------------------------------------------\n");

    push(&topo, pilha, 20);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");

    pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");

    pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }
    printf("----------------------------------------------------\n");

    pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");

    pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");

    pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");

pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");

    pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }
    printf("----------------------------------------------------\n");

    pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");

    pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");

    pop(&topo, pilha);
    printf("topo:%d\n", topo);
    for(int i = topo - 1; i >= 0; i--){
        printf("%d\n", pilha[i]);
    }

    printf("----------------------------------------------------\n");


    return 0;
}