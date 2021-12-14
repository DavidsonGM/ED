#include <stdio.h>
#include <string.h>

int main(){
    int n, aux = 0;
    scanf("%d", &n);
    char nome[n][20], auxiliar[20];
    int contador[n];

    for(int i = 0; i < n; i++){
        nome[i][0] = '\0';
        contador[i] = -1;
    }

    for(int i = 0; i < n; i++){
        aux = 0;
        scanf("%s", auxiliar);
        for(int j = 0; j < i; j++){
            if(!strcmp(auxiliar, nome[j])){
                contador[j]++;
                aux = 1;
            }
        }
        if(aux == 0){
            strcpy(nome[i], auxiliar);
            contador[i]++;
        }
    }

    for(int i = 0; i < n; i++){
        if(contador[i] != -1)
            printf("%s %d\n", nome[i], contador[i]);
    }

return 0;

}