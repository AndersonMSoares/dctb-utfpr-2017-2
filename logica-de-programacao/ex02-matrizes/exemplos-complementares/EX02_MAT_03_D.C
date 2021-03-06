/* Exemplo 3D de uso de matrizes com textos

   Nesta solu��o foi trocada a fun��o gets pela fgets.

   Com a fun��o fgets pode-se impedir que o seja armazenado um texto maior que o
   tamanho do vetor.

   Caso o usu�rio digite uma quantidade de caracteres menor que o tamanho do vetor
   a fun��o gets armazena o enter digitado, por isso deve ser eliminado posteriormente

   Neste exemplo � calculado o preenchimento de espacos em branco para manter a
   impress�o em colunas, de acordo com a quantidade m�xima de caracteres suportada
   pelo matriz de nomes. Com esta solu��o caso se queira mudar a quantidade m�xima de
   um nome suportada pelo programa basta alterar a constante, e o programa se adapta.
   Uma �TIMA SOLU��O.

   Nesta solu��o tamb�m foi criada uma biblioteca chamada LEITURA.C onde foram
   colocadas fun��es para leitura do texto (usando fgets), e para a leitura de INT,
   usado para ler a idade.
*/

#include<conio.h>
#include<stdio.h>
#include<string.h>

#include "LEITURA.C" // Biblioteca criada pelo programador

#define QUANT_PESSOAS     3
#define MAXIMO_CARACTERES 20
#define IDADE_MAXIMA      150 // Valor m�ximo de idade aceita neste programa

char nomes[QUANT_PESSOAS][MAXIMO_CARACTERES];
int  idades[QUANT_PESSOAS];

void leitura();  // Prot�tipo da fun��o
void listagem(); // Prot�tipo da fun��o

int main(){

    leitura();
    listagem();
    pararPrograma();

	return 0;
}

void leitura(){
   int linha;

   for(linha = 0; linha < QUANT_PESSOAS; linha++){

	   printf("\nDados da pessoa %d\n",linha+1);
       printf("Entre com o nome : ");

       lerTexto(nomes[linha],MAXIMO_CARACTERES);

	   idades[linha] = lerInt("Entre com a idade: ",1,IDADE_MAXIMA);
    }
}

void listagem(){
    int indice, linha, tamanho;

    printf("\n Nr Nome");
    for (indice = 1; indice <= MAXIMO_CARACTERES - 2; indice++){
       printf(" ");
    }

    printf("Idade");

    for(linha = 0; linha < QUANT_PESSOAS; linha++){

	   printf("\n%3d %s",linha+1,nomes[linha]);
       tamanho = strlen(nomes[linha]);

       /* Calcula quantos espacoes em branco deve imprimir para alinhar em coluna de
          acordo com o tamanho do nome atual */

       for (indice = 1;indice <= MAXIMO_CARACTERES - tamanho + 2; indice++){
            printf(" ");
       }

       printf("%3d",idades[linha]);
    }
}
