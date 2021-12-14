/** Matricula:SUA MATRÍCULA
 *       Nome: SEU NOME
 *      Turma: SUA TURMA */

#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

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
    int pilha[2], i, j, topo = 0;
    char aux[200];
    i = 0;
    while(posfixa[i] != '\0'){
        for(j = 0; j < 200; j++)
            aux[j] = '\0';
        j = 0;
        while(posfixa[i] != ' '){
            aux[j] = posfixa[i];
            j++;
            i++;
        }
        if(topo == 0){
            pilha[0] = strtol(aux, '\0', 10);
            topo++;
        }
        else{
            if(isdigit(posfixa[i]))
                pilha[1] = strtol(aux, '\0', 10);
            else if(isoperador(posfixa[i])){
                switch(posfixa[i]){
                    case '*':
                        pilha[0] *= pilha[1];
                        break;
                    case '/': 
                        pilha[0] /= pilha[1];
                        break;
                    case '+':
                        pilha[0] += pilha[1];
                        break;
                    case '-':
                        pilha[0] -= pilha[1];
                        break;
                    case '^':
                        pilha[0] = pow(pilha[0], pilha[1]);
                }
            } 
        }     
        i++;
    }
    return pilha[0];
            
}

int main() {
    char posfixa[201];

    scanf("%200[^\n]", posfixa);
    printf("%.5lf\n", calcula(posfixa));

    return 0;
}