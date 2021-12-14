#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


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
 
 _Bool valida(const char* expressao){
    int i = 0;        
    int topo_pilha = 0, topo_pilha2 = 0;       
    char pilha[101], pilha2[101];

    for(i = 0; i < 101; i++){ 
        switch(expressao[i]){
            case '(':
                push('(', pilha, &topo_pilha);
                break;

            case ')':
                if('(' != pop(pilha, &topo_pilha))
                    return false;
                break;

            case '{':
                push('{', pilha, &topo_pilha);
                break;

            case '}':
                if('{' != pop(pilha, &topo_pilha))
                    return false;
                break;

            case '[':
                push('[', pilha, &topo_pilha);
                break;

            case ']':
                if('[' != pop(pilha, &topo_pilha))
                    return false;
                break;

            case '\0':
                i = 101;
                break;
        }        
    }

    if(topo_pilha != 0)
        return false;


    for(i = 0; i < 101; i++)
        pilha2[i] = '\0';
    for(i = 0; i < 101; i++){
        if(expressao[i] == '\0')
            break;
        if(expressao[i] != ' ')
            push(expressao[i], pilha2, &topo_pilha2);
    }
    
    i = 0;
    while(expressao[i] != '\0'){
        if(isdigit(expressao[i])){
            while(isdigit(expressao[i]))
                i++;
            if(expressao[i] == '.' && expressao[i + 1] == ' ')
                return false;
            if(expressao[i] == ' '){
                while(expressao[i] == ' ')
                    i++;
                if(isdigit(expressao[i]))
                    return false;
                i++;
            }
        }
        else
            i++;
    }            

    i = 1;
    while(pilha2[i] != '\0'){
        if(pilha2[i] == '[' || pilha2[i] == '{' || pilha2[i] == '('){
            i++;
            if(pilha2[i] == ']' || pilha2[i] == '}' || pilha2[i] == ')')
                return false;
        }
        else if(pilha2[i] == ']' || pilha2[i] == '}' || pilha2[i] == ')')
            i++;
        else if(pilha2[i] == '*' || pilha2[i] == '+' || pilha2[i] == '-' || pilha2[i] == '/' || pilha2[i] == '^'){
            if(i == 1)
                return false;
            if(pilha2[i - 1] == '(' || pilha2[i - 1] == '[' || pilha2[i - 1] == '{' || pilha2[i - 1] == '*' || pilha2[i - 1] == '-' || pilha2[i - 1] == '+' || pilha2[i - 1] == '/' || pilha2[i - 1] == '^')
                return false;
            i++;
        }

        else if(isdigit(pilha2[i])){
            while(isdigit(pilha2[i]))
                i++;
            switch(pilha2[i]){
                case '\0':
                    return true;
                case '.':
                    i++;
                    if(!isdigit(pilha2[i]))
                        return false;
                    while(isdigit(pilha2[i]))
                        i++;
                    if(pilha2[i] == '.')
                        return false;
                    i--;
                    break;

                case '*':
                    i++;
                    if(pilha2[i] == ']' || pilha2[i] == '}' || pilha2[i] == ')' || pilha2[i] == '\0')
                        return false;
                    break;

                case '-':
                    i++;
                    if(pilha2[i] == ']' || pilha2[i] == '}' || pilha2[i] == ')' || pilha2[i] == '\0')
                        return false;
                    break;

                case '^':
                    i++;
                    if(pilha2[i] == ']' || pilha2[i] == '}' || pilha2[i] == ')' || pilha2[i] == '\0')
                        return false;
                    break;

                case '+':
                    i++;
                    if(pilha2[i] == ']' || pilha2[i] == '}' || pilha2[i] == ')' || pilha2[i] == '\0')
                        return false;
                    break;

                case '/':
                    i++;
                    if(pilha2[i] == ']' || pilha2[i] == '}' || pilha2[i] == ')' || pilha2[i] == '\0')
                        return false;
                    break;

                case ')':
                    i++;
                    if(isdigit(pilha2[i]) || pilha2[i] == '[' || pilha2[i] == '{' || pilha2[i] == '(')
                        return false;
                    break;

                case ']':
                    i++;
                    if(isdigit(pilha2[i] || pilha2[i] == '[' || pilha2[i] == '{' || pilha2[i] == '('))
                        return false;
                    break;

                case '}':
                    i++;
                    if(isdigit(pilha2[i]) || pilha2[i] == '[' || pilha2[i] == '{' || pilha2[i] == '(')
                        return false;
                    break;

                case '(':
                    return false;

                case '{':
                    return false;

                case '[':
                    return false;


                return false;
            }             
        }
        else
            return false;
    }
    return true;
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
    char expressao[101];
    
    printf("Digite a expressao a ser calculada:\n");
    scanf("%100[^\n]", expressao);
    
    while(!valida(expressao)){        
        getchar();
        printf("EXPRESSAO INVALIDA.\nDigite a expressao a ser calculada:\n");
        scanf("%100[^\n]", expressao);

        
    }
    char posfixa[201];

    transforma(expressao, posfixa);
    printf("%.5lf\n", calcula(posfixa));
    
    return 0;
}