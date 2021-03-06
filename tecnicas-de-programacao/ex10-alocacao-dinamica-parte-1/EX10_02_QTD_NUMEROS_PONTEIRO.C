#include<stdio.h>
#include<stdlib.h>
int main(){
	int  quantidade, indice;
	int* pontInt;
	printf("\n Quantos inteiros quer armazenar? ");
	scanf("%d", &quantidade);
	if (quantidade <= 0){
		printf("\a\n Quantidade nao pode ser menor ou igual a zero!\n");
		return -1;
	}
	/*
		Atribui��o do endere�o da �rea de mem�ria alocada para o ponteiro
		Como � alocada uma quantidade de int, na pr�tica � um vetor din�mico
	*/
	pontInt = (int*) malloc(quantidade * sizeof(int));
	if (pontInt == NULL){
		printf("\a\n Erro na alocacao de memoria!\n");
		return -2;
	}
	printf("\n Alocacao realizada com sucesso!");
	printf("\n Endereco armazenado no ponteiro: %p\n\n", pontInt);
	for (indice = 0; indice < quantidade; indice++){
		printf(" Entre com inteiro %d: ", indice + 1);
		scanf("%d", pontInt + indice);
	}
	printf("\n Impressao dos valores");
	printf("\n =====================\n\n");
	for (indice = 0; indice < quantidade; indice++){
		printf(" %d = %d\n", indice + 1, *(pontInt + indice));
	}
	// Libera a mem�ria alocada
	free(pontInt);
	return 0;
}