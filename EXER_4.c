#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


/*4. Criem um programa em C que manipule um vetor de 10 posições de inteiro e possua os menus abaixo, use como base o programa anterior:
1-Preenche o Vetor
2-Ordena o Vetor por Bubble Sort
3-Ordena o Vetor por Selection Sort 
4-Desempenho 
	1.Quantidade de comparações 
	2.Quantidade de trocas
5-Imprime o Vetor
6-Sair*/

	int vet[10] = {29,32,9,3,43,12,1,5,7,10};
	int compBubble=0, trocaBubble=0;
	int compSelection=0, trocaSelection=0;

	void preencheVet()//Função para prenchimento do vetor com 10 numeros.
	{
		int vet[10];
		printf("Vetor preenchido!\n");
	}
	
	
	void bubbleSort() // Ordenador do vetor por Bubble Sort.
	{
		printf("Operação de ordenação concluida por Bubble Sort!\n");
		int aux;
		for(int j = 1 ; j < 10 ; j++) //Laço para percorrer cada posição do vetor. 
		{
			for(int i = 0 ; i < 10-1 ; i++) //Laço que faz as comparações.
			{
				if(vet[i] > vet[i+1]) //If que faz as trocas se necessario.
				{
					aux = vet[i];
					vet[i] = vet[i+1];
					vet[i+1] = aux;
					trocaBubble++; //Número de trocaSelection feitas.
				}
			compBubble++; //Número de comparações feita.		
			}
		}
	}

	void selectionSort() // Função para ordenar por Selection Sort.
	{
		printf("Operação concluida por Selection Sort!\n");
		int troca, menor;
		for(int j = 0 ; j < 10-1 ; j++) //Laço para comparar todas as posições do vetor.
		{
			menor=j;
			for(int i = j+1 ; i < 10 ; i++) //Laço para alocar o menor valor para a posiçõo certa.
			{
				if(vet[i] < vet[menor])
					menor = i;
					compSelection++; //Contador de comparações
			}
			if(j != menor) //Verifica se a posição j[0] do vetor é diferente da menor posição declarada, caso seja faz a troca.
			{
				troca = vet[j];
				vet[j] = vet[menor];
				vet[menor] = troca;
				trocaSelection++; //Contador de trocaSelection
			}
		}
	}  

	void imprimeVet() //Função para imprimir o vetor.
	{
		printf("\nNúmeros digitados: ");
		for(int i = 0 ; i < 10 ; i++)
		{
			printf("%d, ",vet[i]);
		}
	}
	
	
int main(){ //Programa principal.
	setlocale(LC_ALL, "portuguese");
	int op;
	
	printf("\nBem vindo!!");
	
do{	//Comando que segura loop do switch até ser exigida saida pelo usuário.
	printf("\n1-Preenche o Vetor\n2-Ordena o Vetor por Bubble Sort\n3-Ordenar vetor por Selection Sort\n4-Desempenho\n5-Imprimir Vetor\n6-Sair\n");
	scanf("%d",&op);

	switch(op){ //Menu de escolha.
		case 1:
			preencheVet();
			break;
		case 2:
			bubbleSort();
			break;
		case 3:
			selectionSort();
			break;
		case 4:
			printf("\n1°-Trocas do Bubble Sort: %d",trocaBubble);
			printf("\n2°-Comparações do Bubble Sort: %d\n",compBubble);
			printf("\n1°-Trocas do Selection Sort: %d",trocaSelection);
			printf("\n2°-Comparações do Selection Sort: %d\n",compSelection);
			break;
		case 5:
			imprimeVet();
			break;
		case 6:
			printf("\nSaindo do programa!!\n");
			return 0;
		default :
			printf("Opção inválida!\nTente novamente por favor!\n");
	}
}while(op !=6);
	
	system("pause");
	return 0;
}
