#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>


/*6. Criem um programa em C que manipule um vetor de 10 posições de inteiro e possua os menus abaixo, use como base o programa anterior:
1-Preenche o Vetor
2-Ordena o Vetor por Bubble Sort
3-Ordena o Vetor por Selection Sort 
4-Ordena o Vetor por Insertion Sort
5-Ordena o Vetor por Shell Sort
6-Desempenho 
	1.Quantidade de comparações 
	2.Quantidade de trocas
	3.Tempo de execução
7-Imprime o Vetor
8-Sair*/

	int vet[10];
	int compBubble=0, trocaBubble=0;
	int compSelection=0, trocaSelection=0;
	int compInsertion=0, trocaInsertion=0;
	int compShell=0, trocaShell=0;
	
	void preencheVet()//Função para prenchimento do vetor com 10 numeros.
	{
		for(int i = 0 ; i < 10 ; i++)
		{
			vet[i] = rand() % 100+1;
		}	
		printf("\nVetor preenchido!\n");
	}
	
	
	void bubbleSort() // Ordenador do vetor por Bubble Sort.
	{
		printf("\nOperação de ordenação concluida por Bubble Sort!\n");
		int troca;
		for(int j = 1 ; j < 10 ; j++) //Laço para percorrer cada posição do vetor. 
		{
			for(int i = 0 ; i < 10-1 ; i++) //Laço que faz as comparações.
			{
				if(vet[i] > vet[i+1]) //If que faz as trocas se necessario.
				{
					troca = vet[i];
					vet[i] = vet[i+1];
					vet[i+1] = troca;
					trocaBubble++; //Número de trocaSelection feitas.
				}
			compBubble++; //Número de comparações feita.		
			}
		}	
	}

	void selectionSort() // Função para ordenar por Selection Sort.
	{
		printf("\nOperação concluida por Selection Sort!\n");
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
		printf("\nOperação concluida por Insertion Sort");
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
		printf("\nOperação concluida por Shell Sort");
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
		printf("\n"); //Espaçar.
	}

	
int main(){ //Programa principal.
	setlocale(LC_ALL, "portuguese");
	int op; //Operação do menu principal.
	int subOP; //Operação do menu de desempenho.
	clock_t tempoBubble = 0; //Variável para armazenar o tempo.
	clock_t tempoSelection = 0; //Variável para armazenar o tempo.
	clock_t tempoInsertion =0; //Variável para armazenar o tempo.
	clock_t tempoShell =0; //Variável para armazenar o tempo.
	
	printf("BEM VINDO!");
do{	//Comando que segura loop do switch até ser exigida saida pelo usuário.
	printf("\n1-Preenche o Vetor\n2-Ordena o Vetor por Bubble Sort\n3-Ordenar vetor por Selection Sort\n");
	printf("4-Ordenar vetor por Insertion Sort\n5-Ordenar vetor por Shell Sort\n6-Desempenho\n");
	printf("   1.Quantidade de comparações\n   2.Quantidade de trocas\n   3.Tempo de execução\n7-Imprimir Vetor\n8-Sair\n");
	printf("Digite sua opção!\nOpção: ");
	scanf("%d",&op);

	switch(op){ //Menu de escolha.
		case 1:
			preencheVet();
			break;
		case 2:
			tempoBubble = clock(); //Pega o tempo de inicio de execução.
			bubbleSort(); //Chamado da função.
			tempoBubble = clock() - tempoBubble; //Pega o tempo final e diminui o pelo tempo inicial da execução, e obtem o tempo.
			break;
		case 3:
			tempoSelection = clock(); //Pega o tempo de inicio de execução.
			selectionSort(); //Chamado da função.
			tempoSelection = clock() - tempoSelection; //Pega o tempo final e diminui o pelo tempo inicial da execução, e obtem o tempo.
			break;
		case 4:
			tempoInsertion = clock(); //Pega o tempo de inicio de execução.
			insertionSort(); //Chamado da função.
			tempoInsertion = clock() - tempoInsertion; //Pega o tempo final e diminui o pelo tempo inicial da execução, e obtem o tempo.
			break;
		case 5:
			tempoShell = clock(); //Pega o tempo de inicio de execução.
			shellSort(); //Chamado da função.
			tempoShell = clock() - tempoShell; //Pega o tempo final e diminui o pelo tempo inicial da execução, e obtem o tempo.
			break;
		case 6:
			printf("1-Quantidade de comparações!\n2-Quantidade de trocas!\n3-Tempo de execução!\n");
			scanf("%d",&subOP);
				switch(subOP)
				{
			  	case 1:
					printf("\nComparações do Bubble Sort: %d\n",compBubble);
					printf("\nComparações do Selection Sort: %d\n",compSelection);
					printf("\nComparações do Insertion Sort: %d\n",compInsertion);
					printf("\nComparações do Shell Sort: %d\n",compShell);
					break;
				case 2:
					printf("\nTrocas do Bubble Sort: %d\n",trocaBubble);
					printf("\nTrocas do Selection Sort: %d\n",trocaSelection);
					printf("\nTrocas do Insertion Sort: %d\n",trocaInsertion);
					printf("\nTrocas do Shell Sort: %d\n",trocaShell);
					break;
				case 3:
					printf("\nTempo de execução Bubble Sort: %lf milissegundos",(tempoBubble)/(double)CLOCKS_PER_SEC/1000);
					printf("\nTempo de execução Selection Sort: %lf milissegundos",(tempoSelection)/(double)CLOCKS_PER_SEC/1000);
					printf("\nTempo de execução Insertion Sort: %lf milissegundos",(tempoInsertion) /(double)CLOCKS_PER_SEC/1000);
					printf("\nTempo de execução Shell Sort: %lf milissegundos\n\n",(tempoShell) /(double)CLOCKS_PER_SEC/1000);
					break;
				}break;
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
