#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


/*5. Criem um programa em C que manipule um vetor de 10 posi��es de inteiro e possua os menus abaixo, use como base o programa anterior:
1-Preenche o Vetor
2-Ordena o Vetor por Bubble Sort
3-Ordena o Vetor por Selection Sort 
4-Ordena o Vetor por Insertion Sort
5-Desempenho 
	1.Quantidade de compara��es 
	2.Quantidade de trocas
6-Imprime o Vetor
7-Sair*/

	int vet[10] = {29,32,9,3,43,12,1,5,7,10};
	int compBubble=0, trocaBubble=0;
	int compSelection=0, trocaSelection=0;
	int compInsertion=0, trocaInsertion=0;
	
	void preencheVet()//Fun��o para prenchimento do vetor com 10 numeros.
	{
		int vet[10];
		printf("Vetor preenchido!\n");
	}
	
	
	void bubbleSort() // Ordenador do vetor por Bubble Sort.
	{
		printf("Opera��o de ordena��o concluida por Bubble Sort!\n");
		int aux;
		for(int j = 1 ; j < 10 ; j++) //La�o para percorrer cada posi��o do vetor. 
		{
			for(int i = 0 ; i < 10-1 ; i++) //La�o que faz as compara��es.
			{
				if(vet[i] > vet[i+1]) //If que faz as trocas se necessario.
				{
					aux = vet[i];
					vet[i] = vet[i+1];
					vet[i+1] = aux;
					trocaBubble++; //N�mero de trocaSelection feitas.
				}
			compBubble++; //N�mero de compara��es feita.		
			}
		}
	}

	void selectionSort() // Fun��o para ordenar por Selection Sort.
	{
		printf("Opera��o concluida por Selection Sort!\n");
		int troca, menor;
		for(int j = 0 ; j < 10-1 ; j++) //La�o para comparar todas as posi��es do vetor.
		{
			menor=j;
			for(int i = j+1 ; i < 10 ; i++) //La�o para alocar o menor valor para a posi��o certa.
			{
				if(vet[i] < vet[menor])
					menor = i;
					compSelection++; //Contador de compara��es
			}
			if(j != menor) //Verifica se a posi��o j[0] do vetor � diferente da menor posi��o declarada, caso seja faz a troca.
			{
				troca = vet[j];
				vet[j] = vet[menor];
				vet[menor] = troca;
				trocaSelection++; //Contador de trocaSelection
			}
		}
	}  

	void insertionSort() //Fun��o para ordenar por Insertion Sort.
	{
		printf("Opera��o concluida por Insertion Sort");
		int i, j ,troca;
		for( i = 1 ; i < 10 ; i++) //La�o para percorres o vertor.
		{
			compInsertion++; //Contador de compara��es.
			troca = vet[i]; 
			j = i-1;
			while((j >= 0) && (troca < vet[j]))
			{
				vet[j+1] = vet[j];
				trocaInsertion++; //Contador de trocas.
				j--;
			}
			vet[j+1] = troca; 
		}
	}

	void imprimeVet() //Fun��o para imprimir o vetor.
	{
		printf("\nN�meros digitados: ");
		for(int i = 0 ; i < 10 ; i++)
		{
			printf("%d, ",vet[i]);
		}
	}
	
	
int main(){ //Programa principal.
	setlocale(LC_ALL, "portuguese");
	int op;
	
	printf("\nBem vindo!!");
	
do{	//Comando que segura loop do switch at� ser exigida saida pelo usu�rio.
	printf("\n1-Preenche o Vetor\n2-Ordena o Vetor por Bubble Sort\n3-Ordenar vetor por Selection Sort\n");
	printf("4-Ordenar vetor por Insertion Sort\n5-Desempenho\n6-Imprimir Vetor\n7-Sair\n");
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
			insertionSort();
			break;
		case 5:
			printf("\n1�-Trocas do Bubble Sort: %d",trocaBubble);
			printf("\n2�-Compara��es do Bubble Sort: %d\n",compBubble);
			printf("\n1�-Trocas do Selection Sort: %d",trocaSelection);
			printf("\n2�-Compara��es do Selection Sort: %d\n",compSelection);
			printf("\n1�-Trocas do Insertion Sort: %d",trocaInsertion);
			printf("\n2�-Compara��es do Insertion Sort: %d\n",compInsertion);
			break;
		case 6:
			imprimeVet();
			break;
		case 7:
			printf("\nSaindo do programa!!\n");
			return 0;
		default :
			printf("Op��o inv�lida!\nTente novamente por favor!\n");
	}
}while(op !=7);
	
	system("pause");
	return 0;
}
