#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


/*6. Criem um programa em C que manipule um vetor de 10 posições de inteiro e possua os menus abaixo, use como base o programa anterior:
1-Preenche o Vetor
2-Ordena o Vetor por Bubble Sort
3-Ordena o Vetor por Selection Sort 
4-Ordena o Vetor por Insertion Sort
5-Ordena o Vetor por Shell Sort
6-Desempenho 
	1.Quantidade de comparações 
	2.Quantidade de trocas
7-Imprime o Vetor
8-Sair*/

	int vet[10] = {29,32,9,3,43,12,1,5,7,10};
	int compBubble=0, trocaBubble=0;
	int compSelection=0, trocaSelection=0;
	int compInsertion=0, trocaInsertion=0;
	int compShell=0, trocaShell=0;
	
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

	void insertionSort() //Função para ordenar por Insertion Sort.
	{
		printf("Operação concluida por Insertion Sort");
		int i, j ,troca;
		for( i = 1 ; i < 10 ; i++) //Laço para percorres o vertor.
		{
			compInsertion++; //Contador de comparações.
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

	void shellSort() //Função para ordenar por Shell Sort.
	{
		printf("Operação concluida por Shell Sort");
		int i, j, troca;
		
		int h = 1; 
		while(h < 10) //Procura o valor da sequiencia Knuth {1,4,13,40...} para realizar os saltos no vetor.
		{
			h = 3*h+1;	
		}
		 while(h > 0)
		 {
				for(i = h ; i < 10 ; i++) //Loop que faz as comparações de cada posição.
				{
					troca = vet[i];
					j = i;
					compShell++; //Contador de comparações
					 while(j > h-1 && troca <= vet[j-h]) //Testa as posições e faz a troca.
					 {
					 	vet[j] = vet[j-h];
					 	j = j - h;
					 	trocaShell++; //Contador de trocas.
					 }
				 vet[j] = troca; 
				}
				h = h/3;
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
	printf("\n1-Preenche o Vetor\n2-Ordena o Vetor por Bubble Sort\n3-Ordenar vetor por Selection Sort\n");
	printf("4-Ordenar vetor por Insertion Sort\n5-Ordenar vetor por Shell Sort\n6-Desempenho\n7-Imprimir Vetor\n8-Sair\n");
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
			shellSort();
			break;
		case 6:
			printf("\n1°-Trocas do Bubble Sort: %d",trocaBubble);
			printf("\n2°-Comparações do Bubble Sort: %d\n",compBubble);
			printf("\n1°-Trocas do Selection Sort: %d",trocaSelection);
			printf("\n2°-Comparações do Selection Sort: %d\n",compSelection);
			printf("\n1°-Trocas do Insertion Sort: %d",trocaInsertion);
			printf("\n2°-Comparações do Insertion Sort: %d\n",compInsertion);
			printf("\n1°-Trocas do Shell Sort: %d",trocaShell);
			printf("\n2°-Comparações do Shell Sort: %d\n",compShell);
			break;
		case 7:
			imprimeVet();
			break;
		case 8:
			printf("\nSaindo do programa!!\n");
			return 0;
		default :
			printf("Opção inválida!\nTente novamente por favor!\n");
	}
}while(op !=8);
	
	system("pause");
	return 0;
}
