#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* 2. Criem um programa em C que manipule um vetor de 10 posições de inteiro e possua os menus abaixo:
1-Preenche o Vetor
2-Ordena o Vetor por Bubble Sort
3-Imprime o Vetor
4-Sair */

	int vet[10];

	void preencheVet()//Função para prenchimento do vetor com 10 numeros.
	{
		for(int i = 0 ; i < 10 ; i++)
		{
			printf("%i numero: ",i+1);
			scanf("%d",&vet[i]);
		}
		system("cls");
	}
	
	
	void bublleSort() // Ordenador do vetor.
	{
		int aux;
		for(int j = 1 ; j < 10 ; j++)
		{
			for(int i = 0 ; i < 10-1 ; i++)
			{
				if(vet[i] > vet[i+1])
				{
					aux = vet[i];
					vet[i] = vet[i+1];
					vet[i+1] = aux;
				}
			}		
		}
	printf("\nNúmeros ordenas por Bubble Sort!!\n");
	}

	void imprimeVet() //Função para imprimir o vetor.
	{
		printf("\nNúmeros digitados: ");
		for(int i = 0 ; i < 10 ; i++)
		{
			printf("%d, ",vet[i]);
		}
	}
	
	
int main(){
	setlocale(LC_ALL, "portuguese");
	int op;
	
	printf("\nBem vindo!!");
	
do{	
	printf("\n\n1-Preenche o Vetor\n2-Ordena o Vetor por Bubble Sort\n3-Imprime o Vetor\n4-Sair\n");
	scanf("%d",&op);

	switch(op){
		case 1:
			preencheVet();
			break;
		case 2:
			bublleSort();
			break;
		case 3:
			imprimeVet();
			break;
		case 4:
			printf("\nSaindo do programa!!\n");
			return 0;
	}
}while(op !=4);
	
	system("pause");
	return 0;
}
