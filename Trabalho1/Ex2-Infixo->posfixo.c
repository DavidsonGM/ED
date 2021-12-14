/** Matricula: 19/0056967
 *       Nome: David Gonçalves Mendes
 *      Turma: A */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
int prioridade(char operador){
    switch(operador){
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return 0;
}
void transforma(const char* infixa, char* posfixa) {
    char pilha[101], infix_vect[101];
    int topo_pilha = 0, topo_pos = 0, i = 0, j = 0;

    for(i = 0; i < 201; i++)
        posfixa[i] = '\0';
    
    for(i = 0; i < 101; i++){
        infix_vect[i] = '\0';
    }

    for(i = 0; i < 101; i++){
        if(infixa[i] == '\0')
            break;
        if(infixa[i] != ' ')
            push(infixa[i], infix_vect, &j);
    }

    i = 1;
    while(infix_vect[i] != '\0'){
        if(isdigit(infix_vect[i])){
            while(isdigit(infix_vect[i]) || infix_vect[i] == '.'){
                posfixa[topo_pos] = infix_vect[i];
                topo_pos++;
                i++;
            }
            posfixa[topo_pos] = ' ';
            topo_pos++;
        }
        else if(infix_vect[i] == '(')
            push(infix_vect[i], pilha, &topo_pilha);
        if(infix_vect[i] == ')'){
            while(pilha[topo_pilha] != '('){
                posfixa[topo_pos] = pop(pilha, &topo_pilha);
                posfixa[topo_pos + 1] = ' ';
                topo_pos += 2;
            }
            pop(pilha, &topo_pilha);
        }
        else if(infix_vect[i] == '{')
            push(infix_vect[i], pilha, &topo_pilha);
        if(infix_vect[i] == '}'){
            while(pilha[topo_pilha] != '{'){
                posfixa[topo_pos] = pop(pilha, &topo_pilha);
                posfixa[topo_pos + 1] = ' ';
                topo_pos += 2;
            }
            pop(pilha, &topo_pilha);
        }
        else if(infix_vect[i] == '[')
            push(infix_vect[i], pilha, &topo_pilha);
        if(infix_vect[i] == ']'){
            while(pilha[topo_pilha] != '['){
                posfixa[topo_pos] = pop(pilha, &topo_pilha);
                posfixa[topo_pos + 1] = ' ';
                topo_pos += 2;
            }
            pop(pilha, &topo_pilha);
        }
        if(isoperador(infix_vect[i])){
            while(topo_pilha != 0 && prioridade(infix_vect[i]) <= prioridade(pilha[topo_pilha])){
                posfixa[topo_pos] = pop(pilha, &topo_pilha);
                posfixa[topo_pos + 1] = ' ';
                topo_pos += 2;
            }
            push(infix_vect[i], pilha, &topo_pilha);
        }
        i++;
    } 
    while(topo_pilha != 0){

        posfixa[topo_pos] = pop(pilha, &topo_pilha); 
        posfixa[topo_pos + 1] = ' ';
        topo_pos += 2;  
    }
}

int main() {
    char infixa[101], posfixa[201];

    scanf("%100[^\n]", infixa);

    transforma(infixa, posfixa);
    printf("%s\n", posfixa);

    return 0;
}