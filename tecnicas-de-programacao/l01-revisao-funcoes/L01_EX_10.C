/* Fa�a um programa que apresente o seguinte menu para o usu�rio:

      Controle de Notas
      ==============
      <1> - Adicionar notas de um aluno
      <2> - Listar todas as notas e m�dias
      <3> - Listar a maior nota na prova 1 e na prova 2
      <4> - Sair
      Qual op��o escolhida?

    O usu�rio poder� entrar no m�ximo com as notas de 30 alunos.
    Para isto crie uma matriz de reais de duas colunas, onde cada uma
    armazenar� a nota de uma prova. Na op��o 1 o usu�rio entrar� com as
    duas notas de um aluno. Caso o usu�rio tente executar as op��es 2 ou 3
    e n�o exista nenhuma nota cadastrada mostre uma mensagem de alerta.
    Caso o usu�rio tente cadastrar os dados de um novo aluno e n�o exista
    mais espa�o na matriz de uma mensagem de erro. Na op��o 2 liste em
    formato de tabela as notas e m�dias de todos os alunos. Na op��o 3
    apresente a maior nota da prova 1 e da prova 2 cadastradas. Caso o
    usu�rio escolha a op��o 4 use a fun��o exit(int) para encerrar o
    programa. Caso escolha uma op��o inv�lida de uma mensagem de erro e
    retorne ao menu. As op��es de 1 a 3 devem chamar fun��es especificas
    para realizar as atividades propostas, passando-se a matriz com par�metro.
    Utilize a estrutura switch com break, e a do/while para fazer o menu,
    e constantes para controlar os limites da matriz. */

#include<stdio.h>
#include<stdlib.h>

#define TOTAL_ALUNOS 4

void adicionar(double[TOTAL_ALUNOS][2],    int*);
void listarTodas(double[TOTAL_ALUNOS][2],  int);
void listarMaiores(double[TOTAL_ALUNOS][2],int);

int main(){

    double alunos[TOTAL_ALUNOS][2];
    int    opcao, pos = 0;

    do{
      printf("\n Controle de Notas");
      printf("\n =================");
      printf("\n <1> - Adicionar notas de um aluno");
      printf("\n <2> - Listar todas as notas e medias");
      printf("\n <3> - Listar a maior nota na prova 1 e na prova 2");
      printf("\n <4> - Sair");

      printf("\n\n Qual opcao escolhida? ");
      fflush(stdin);
      if (scanf("%d", &opcao) == 0){
          opcao = -1; // For�a valor invalido caso o scanf nao leia nada
      }

      switch(opcao){

        case  1:adicionar(alunos,   &pos); // Passagem de pos por refer�ncia
                break;

        case  2:listarTodas(alunos,  pos); // Passagem de pos por valor
                break;

        case  3:listarMaiores(alunos,pos); // Passagem de pos por valor
                break;

        case  4:exit(0);
                break;

        default:printf("\n\a Opcao invalida!\n");
      }
    }while(1);
}

void adicionar(double notas[TOTAL_ALUNOS][2], int* posAtual){

    if (*posAtual == TOTAL_ALUNOS){
        printf("\n\a Nao existe espaco para cadastrar!\n");
        return;
    }

    printf("\n Entre com as notas do aluno %d", *posAtual + 1);
    printf("\n ===============================\n");

    printf("  Nota da prova 1: ");
    scanf("%lf", &notas[*posAtual][0]);

    printf("  Nota da prova 2: ");
    scanf("%lf", &notas[*posAtual][1]);

    (*posAtual)++; // Obrigat�rio o par�nteses, sen�o incrementa o endere�o do ponteiro

    printf("\n Cadastro realizado com sucesso!\n");
}

void listarTodas(double notas[TOTAL_ALUNOS][2], int posAtual){

    double mediaAluno, somaProva1 = 0, somaProva2 = 0;
    int    indice;


    if (posAtual == 0){
        printf("\n\a Nenhuma nota cadastrada!\n");
        return;
    }

    printf("\n Listagem geral de notas");
    printf("\n =======================\n");
    printf("\n Nr.\tNota 1\tNota 2\tMedia");

    for (indice = 0; indice < posAtual; indice++){

        mediaAluno = (notas[indice][0] + notas[indice][1])/2;

        printf("\n %3d\t%4.1lf\t%4.1lf\t%4.1lf",indice + 1,
                                                   notas[indice][0],
                                                   notas[indice][1],
                                                   mediaAluno);

        somaProva1 += notas[indice][0];
        somaProva2 += notas[indice][1];
    }

    printf("\n Medias\t%4.1lf\t%4.1lf\t%4.1lf\n",somaProva1/posAtual,
                                                 somaProva2/posAtual,
                                                (somaProva1 + somaProva2)/(posAtual*2));
}

void listarMaiores(double notas[TOTAL_ALUNOS][2], int posAtual){

    int indice, posMaiorProva1 = 0, posMaiorProva2 = 0;

    if (posAtual == 0){
        printf("\n\a Nenhuma nota cadastrada!\n");
        return;
    }

    for (indice = 1; indice < posAtual; indice++){

        if (notas[indice][0] > notas[posMaiorProva1][0]){
            posMaiorProva1 = indice;
        }
        if (notas[indice][1] > notas[posMaiorProva2][1]){
            posMaiorProva2 = indice;
        }
    }

    printf("\n Maiores notas");
    printf("\n =============\n");
    printf("\n Prova 1 eh %4.1lf e pertence ao aluno %d",  notas[posMaiorProva1][0], posMaiorProva1+1);
    printf("\n Prova 2 eh %4.1lf e pertence ao aluno %d\n",notas[posMaiorProva2][1], posMaiorProva2+1);
}
