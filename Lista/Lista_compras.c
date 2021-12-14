#include <stdio.h>
#include <string.h>

typedef struct Produto{
	char nome[20];
	float preco;
	struct Produto *prox;
}Produto;

void Insere(Produto **produto, ){
	Produto *aux;
	if(*produto==NULL){
		aux->prox = NULL;
		*produto = aux;
	}
	else{
		aux->prox = *produto;
		*produto = aux;
	}

}

void Remove(Produto **produto){

}

int main(){
	
	Produto *produto = NULL;
	int i, j = 0;

	
	do{
		scanf("%s", produto->nome);
	
		if(!strcmp(produto->nome, "fim")) 
			break;
		
		if(!strcmp(produto->nome, "-")){
			Remove(&produto);
			j--;
		}
		
		else{
			scanf("%f", &produto->preco);
			Insere(&produto);
			j++;
		}
	}
	while(strcmp(produto->nome, "fim"));



	for(i=0; i<j;i++)
		printf("%s: %f reais\n", produto[i].nome, produto[i].preco);
		
	return 0;
}