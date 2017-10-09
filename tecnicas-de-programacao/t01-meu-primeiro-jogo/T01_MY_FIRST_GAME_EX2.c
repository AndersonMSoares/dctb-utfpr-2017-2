/*
    Nome: Cl�udia de Oliveira Ramos
    Turma: ES21 - Engenharia de Software/2o per�odo
    Trabalho 01: Jogo de batalha com 3 rounds e 2 jogadores.
*/

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include <locale.h>
#define TAM 2

typedef struct Heroes{
    char name[50];
    int hp, strength, spell, b;
    enum classe {mage = 0, archer = 1, dwarf = 2}heroes;
} typeHeroes;

void readData(typeHeroes * v);
float randomNumber();
int damage(typeHeroes * v);
void printResults(typeHeroes * v);

int main (){
	setlocale(LC_ALL, "Portuguese");
    typeHeroes v[TAM];
    readData(v);
    printResults(v);

    return 0;
}

void readData(typeHeroes * v){
    int i;
    for(i = 0; i < TAM; i++){
        printf("Insira o nome do %d� her�i: ", i+1);
        fflush(stdin);
        gets(v[i].name);
        while(v[i].name[0] == '\0'){
            printf("Propriedade inv�lida, insira um nome para o her�i: ");
            fflush(stdin);
            gets(v[i].name);
        }
        printf("Insira a vida (0 a 100): ");
        scanf("%d", &v[i].hp);
        while(v[i].hp < 0 || v[i].hp > 100){
            printf("Propriedade inv�lida, insira um n�mero entre 0 e 100: ");
            scanf("%d", &v[i].hp);
        }
        printf("Insira a forca (50 a 100): ");
        scanf("%d", &v[i].strength);
        while(v[i].strength < 50 || v[i].strength > 100){
            printf("Propriedade inv�lida, insira um n�mero entre 50 e 100: ");
            scanf("%d", &v[i].strength);
        }
        printf("Insira a magia (50 a 100): ");
        scanf("%d", &v[i].spell);
        while(v[i].spell < 50 || v[i].spell > 100){
            printf("Propriedade inv�lida, insira um n�mero entre 50 e 100: ");
            scanf("%d", &v[i].spell);
        }
        printf("Insira o n�mero da classe (1 - MAGO | 2 - ARQUEIRO | 3 - AN�O): ");
        scanf("%d", &v[i].heroes);
        while(v[i].heroes < 1 || v[i].heroes > 3){
            printf("Classe inv�lida, insira um n�mero entre 1 e 3: ");
            scanf("%d", &v[i].heroes);
		}
            if(v[i].heroes == 0){
				v[i].b = 3;
			} else
				if(v[i].heroes == 1){
				   	v[i].b = 2;
				} else {
					v[i].b = 5;
				}
        printf("\n");

    }
}

float randomNumber(){
    return ((10+(rand() % 21))/100.00);
}

int damage(typeHeroes * v){
	int aux1 = v[0].hp, aux2= v[1].hp;
	int dam1, dam2, r;
	float ra;

	do{
		ra = randomNumber();
		dam1 = (((v[1].strength + v[1].spell)/2) + v[1].b) * ra;
		aux1 -= dam1;
		
		ra = randomNumber();
		dam2 = (((v[0].strength + v[0].spell)/2) + v[0].b) * ra;
		aux2 -= dam2;
		
		printf("Vida do 1� her�i: %d \tVida do 2� her�i: %d\n", aux1, aux2);
		printf("Dano causado: %d \tDano causado: %d\n", dam2, dam1);
		printf("Dano tomado: %d \tDano tomado: %d\n\n", dam1, dam2);
	} while ((aux1 > 0) && (aux2 > 0));  
	
	if (aux1 > aux2) {
		r = 1;
	} else 
	if (aux2 > aux1) {
		r = 2;
	} 
	
	return r;
}

void printResults(typeHeroes * v){
	int r, c1 = 0, c2 = 0, round;
	
	for(r = 0; r < 3; r++){
		printf("\t\t%d� ROUND\n\n", r+1);		
		round = damage(v);
		if (round == 1) {
			c1 = c1 + 1;
			printf("O primeiro her�i venceu este round!\n\n");
			printf("Nome: %s\n", v[0].name);
			switch(v[0].heroes){
			case 1:
				printf("Classe: Mago\n");
				break;
			case 2:
				printf("Classe: Arqueiro\n");
				break;
			default:
				printf("Classe: An�o\n");
				break;
			}	
			printf("\n--------------------------------------------\n\n");
		}else
			if (round == 2) {
				c2 = c2 + 1;
				printf("O segundo her�i venceu este round!\n\n");
				printf("Nome: %s\n", v[1].name);
			   	switch(v[1].heroes){
				case 1:
					printf("Classe: Mago\n");
					break;
				case 2:
					printf("Classe: Arqueiro\n");
					break;
				default:
					printf("Classe: An�o\n");
					break;
				}
			   	printf("\n--------------------------------------------\n\n");
			} else {
				printf("\tEmpate!\n");
				printf("\n--------------------------------------------\n\n");
			}	
	}
	
	printf("\t\tRESULTADO FINAL\n");
	if(c1 > c2){
		printf("\nO vencedor da batalha foi o primeiro her�i!\n");
		printf("\nNome: %s\n", v[0].name);
		switch(v[0].heroes){
		case 1:
			printf("Classe: Mago\n");
			break;
		case 2:
			printf("Classe: Arqueiro\n");
			break;
		default:
			printf("Classe: An�o\n");
			break;
		}	
	} else
		if(c2 > c1){
			printf("\nO vencedor da batalha foi o segundo her�i!\n");	
			printf("\nNome: %s\n", v[1].name);
			switch(v[1].heroes){
			case 1:
				printf("Classe: Mago\n");
				break;
			case 2:
				printf("Classe: Arqueiro\n");
				break;
			default:
				printf("Classe: An�o\n");
				break;
			}	
		} else {
			printf("\nOs her�is empataram!\n");
		}
}	