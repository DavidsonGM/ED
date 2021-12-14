/** Matricula: 19/0056967
 *       Nome: David Gonçalves Mendes
 *      Turma: A */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isoperador(char caractere){
    switch(caractere){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
    }
    return 0;
}

double calcula(const char* posfixa) {
    double pilha[100], aux = 0;
    int topo = 0;
    char *ptr;

    for(int i = 0; i < 100; i++)
        pilha[i] = 0;

    pilha[0] = strtol(posfixa, &ptr, 10);
    while(*ptr != '\0'){
        if(isdigit(*ptr))
            pilha[++topo] = strtol(ptr, &ptr, 10);
        if(*ptr == '.'){
            ptr++;
            aux = strtol(ptr, &ptr, 10);
            while(aux  > 1)
                aux /= 10;
            pilha[topo] += aux;
        }
        if(isoperador(*ptr)){
            switch(*ptr){
                case '*':
                    pilha[topo - 1] *= pilha[topo];
                    topo--;
                        break;
                case '/': 
                    pilha[topo - 1] /= pilha[topo];
                    topo--;
                        break;
                case '+':
                    pilha[topo - 1] += pilha[topo];
                    topo--;
                        break;
                case '-':
                    pilha[topo - 1] -= pilha[topo];
                    topo--;
                        break;
                case '^':
                    pilha[topo - 1] = pow(pilha[topo - 1], pilha[topo]);
                    topo--;
            }
        }

        ptr++;
    }
    return pilha[topo];            
}

int main() {
    char posfixa[201];

    scanf("%200[^\n]", posfixa);
    printf("%.5lf\n", calcula(posfixa));

    return 0;
}