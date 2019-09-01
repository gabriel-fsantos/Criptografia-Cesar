#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define alfb 26;

void velha(char str[], int tam);
void cesar(char str[], int tam);
void troca(char str[], int tam);
void troca2(char str[], int tam);
void print(char str[], int tam);

int main(){

	FILE *fp;
	char *str, *str1, *nome_arquivo;
	str = (char*) calloc (1000, sizeof(char));
	str1 = (char*) calloc (1000, sizeof(char));
	nome_arquivo = (char*) calloc (100, sizeof(char));

	printf("Digite o nome do arquivo: ");
	scanf("%s", nome_arquivo);

	fp = fopen(nome_arquivo, "r");
	fgets(str, 1000, fp);
	int tam = strlen(str);
	strcpy(str1, str);

	velha(str, tam);
	troca2(str, tam);
	troca(str, tam);
	cesar(str, tam);
	
	printf("\n");
	printf("--------------------\nMensagem codificada:\n--------------------\n");
	printf("%s\n", str1);
	printf("----------------------\nMensagem decodificada:\n----------------------\n");
	printf("%s", str);

	fclose(fp);
	free(str);
	free(str1);
	free(nome_arquivo);
	return 0;
}

void velha(char str[], int tam){
	for(int i=0; i<tam; i++){
		if(str[i] == '#'){
			str[i] = ' ';
		}
	}
}

void cesar(char str[], int tam){
	for(int i=0; i<tam-1; i++){
		if(str[i]!=' '){
			str[i] = str[i] - 3;
			if(str[i]<'a' && str[i]>'Z'){
				str[i] = str[i] + alfb;
			}
			else if(str[i]<'A'){
				str[i] = str[i] + alfb;
			}
		}
	}
}

void troca(char str[], int tam){
	char aux;
	for(int i=0; i<tam-1; i+=2){
		aux = str[i];
		str[i] = str[i+1];
		str[i+1] = aux;
	}
}

void troca2(char str[], int tam){
	char aux, aux1;
	tam-=2;
	for(int i=0; i<(tam/2); i+=4){
		aux = str[i];
		aux1 = str[i+1];
		str[i] = str[tam-i-1];
		str[i+1] = str[tam-i];
		str[tam-i] = aux1;
		str[tam-i-1] = aux;
	}
}

//debug only
void print(char str[], int tam){
	for(int i=0; i<tam; i++){
		printf("%d: %c\n", i, str[i]);
	}
}