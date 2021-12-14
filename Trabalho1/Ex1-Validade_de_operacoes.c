#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

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

int main() {
    char expressao[101];
    
    scanf("%100[^\n]", expressao);
    
    if (valida(expressao))
        printf("VALIDA\n");
    else
        printf("INVALIDA\n");
        
    return 0;
}