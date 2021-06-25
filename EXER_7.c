#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>


/*6. Criem um programa em C que manipule um vetor de 10 posi��es de inteiro e possua os menus abaixo, use como base o programa anterior:
1-Preenche o Vetor
2-Ordena o Vetor por Bubble Sort
3-Ordena o Vetor por Selection Sort 
4-Ordena o Vetor por Insertion Sort
5-Ordena o Vetor por Shell Sort
6-Desempenho 
	1.Quantidade de compara��es 
	2.Quantidade de trocas
	3.Tempo de execu��o
7-Imprime o Vetor
8-Sair*/

	int vet[10];
	int compBubble=0, trocaBubble=0;
	int compSelection=0, trocaSelection=0;
	int compInsertion=0, trocaInsertion=0;
	int compShell=0, trocaShell=0;
	
	void preencheVet()//Fun��o para prenchimento do vetor com 10 numeros.
	{
		for(int i = 0 ; i < 10 ; i++)
		{
			vet[i] = rand() % 100+1;
		}	
		printf("\nVetor preenchido!\n");
	}
	
	
	void bubbleSort() // Ordenador do vetor por Bubble Sort.
	{
		printf("\nOpera��o de ordena��o concluida por Bubble Sort!\n");
		int troca;
		for(int j = 1 ; j < 10 ; j++) //La�o para percorrer cada posi��o do vetor. 
		{
			for(int i = 0 ; i < 10-1 ; i++) //La�o que faz as compara��es.
			{
				if(vet[i] > vet[i+1]) //If que faz as trocas se necessario.
				{
					troca = vet[i];
					vet[i] = vet[i+1];
					vet[i+1] = troca;
					trocaBubble++; //N�mero de trocaSelection feitas.
				}
			compBubble++; //N�mero de compara��es feita.		
			}
		}	
	}

	void selectionSort() // Fun��o para ordenar por Selection Sort.
	{
		printf("\nOpera��o concluida por Selection Sort!\n");
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
		printf("\nOpera��o concluida por Insertion Sort");
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

	void shellSort() //Fun��o para ordenar por Shell Sort.
	{
		printf("\nOpera��o concluida por Shell Sort");
		int i, j, troca;
		
		int h = 1; 
		while(h < 10) //Procura o valor da sequiencia Knuth {1,4,13,40...} para realizar os saltos no vetor.
		{
			h = 3*h+1;	
		}
		 while(h > 0)
		 {
				for(i = h ; i < 10 ; i++) //Loop que faz as compara��es de cada posi��o.
				{
					troca = vet[i];
					j = i;
					compShell++; //Contador de compara��es
					 while(j > h-1 && troca <= vet[j-h]) //Testa as posi��es e faz a troca.
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
	
	void imprimeVet() //Fun��o para imprimir o vetor.
	{
		printf("\nN�meros digitados: ");
		for(int i = 0 ; i < 10 ; i++)
		{
			printf("%d, ",vet[i]);
		}
		printf("\n"); //Espa�ar.
	}

	
int main(){ //Programa principal.
	setlocale(LC_ALL, "portuguese");
	int op; //Opera��o do menu principal.
	int subOP; //Opera��o do menu de desempenho.
	clock_t tempoBubble = 0; //Vari�vel para armazenar o tempo.
	clock_t tempoSelection = 0; //Vari�vel para armazenar o tempo.
	clock_t tempoInsertion =0; //Vari�vel para armazenar o tempo.
	clock_t tempoShell =0; //Vari�vel para armazenar o tempo.
	
	printf("BEM VINDO!");
do{	//Comando que segura loop do switch at� ser exigida saida pelo usu�rio.
	printf("\n1-Preenche o Vetor\n2-Ordena o Vetor por Bubble Sort\n3-Ordenar vetor por Selection Sort\n");
	printf("4-Ordenar vetor por Insertion Sort\n5-Ordenar vetor por Shell Sort\n6-Desempenho\n");
	printf("   1.Quantidade de compara��es\n   2.Quantidade de trocas\n   3.Tempo de execu��o\n7-Imprimir Vetor\n8-Sair\n");
	printf("Digite sua op��o!\nOp��o: ");
	scanf("%d",&op);

	switch(op){ //Menu de escolha.
		case 1:
			preencheVet();
			break;
		case 2:
			tempoBubble = clock(); //Pega o tempo de inicio de execu��o.
			bubbleSort(); //Chamado da fun��o.
			tempoBubble = clock() - tempoBubble; //Pega o tempo final e diminui o pelo tempo inicial da execu��o, e obtem o tempo.
			break;
		case 3:
			tempoSelection = clock(); //Pega o tempo de inicio de execu��o.
			selectionSort(); //Chamado da fun��o.
			tempoSelection = clock() - tempoSelection; //Pega o tempo final e diminui o pelo tempo inicial da execu��o, e obtem o tempo.
			break;
		case 4:
			tempoInsertion = clock(); //Pega o tempo de inicio de execu��o.
			insertionSort(); //Chamado da fun��o.
			tempoInsertion = clock() - tempoInsertion; //Pega o tempo final e diminui o pelo tempo inicial da execu��o, e obtem o tempo.
			break;
		case 5:
			tempoShell = clock(); //Pega o tempo de inicio de execu��o.
			shellSort(); //Chamado da fun��o.
			tempoShell = clock() - tempoShell; //Pega o tempo final e diminui o pelo tempo inicial da execu��o, e obtem o tempo.
			break;
		case 6:
			printf("1-Quantidade de compara��es!\n2-Quantidade de trocas!\n3-Tempo de execu��o!\n");
			scanf("%d",&subOP);
				switch(subOP)
				{
			  	case 1:
					printf("\nCompara��es do Bubble Sort: %d\n",compBubble);
					printf("\nCompara��es do Selection Sort: %d\n",compSelection);
					printf("\nCompara��es do Insertion Sort: %d\n",compInsertion);
					printf("\nCompara��es do Shell Sort: %d\n",compShell);
					break;
				case 2:
					printf("\nTrocas do Bubble Sort: %d\n",trocaBubble);
					printf("\nTrocas do Selection Sort: %d\n",trocaSelection);
					printf("\nTrocas do Insertion Sort: %d\n",trocaInsertion);
					printf("\nTrocas do Shell Sort: %d\n",trocaShell);
					break;
				case 3:
					printf("\nTempo de execu��o Bubble Sort: %lf milissegundos",(tempoBubble)/(double)CLOCKS_PER_SEC/1000);
					printf("\nTempo de execu��o Selection Sort: %lf milissegundos",(tempoSelection)/(double)CLOCKS_PER_SEC/1000);
					printf("\nTempo de execu��o Insertion Sort: %lf milissegundos",(tempoInsertion) /(double)CLOCKS_PER_SEC/1000);
					printf("\nTempo de execu��o Shell Sort: %lf milissegundos\n\n",(tempoShell) /(double)CLOCKS_PER_SEC/1000);
					break;
				}break;
		case 7:
			imprimeVet();
			break;
		case 8:
			printf("\nSaindo do programa!!\n");
			return 0;
		default :
			printf("Op��o inv�lida!\nTente novamente por favor!\n");
	}
}while(op !=8);
	
	system("pause");
	return 0;
}
