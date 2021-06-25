#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*3. Acrescente no exerc�cio anterior um menu Desempenho para informar quantas compara��es foram feitas e quantas trocas foram feitas.
Criem um programa em C que manipule um vetor de 10 posi��es de inteiro e possua os menus abaixo:
1-Preenche o Vetor
2-Ordena o Vetor por Bubble Sort
3-Desempenho
4-Imprime o Vetor
5-Sair */ 


	int vet[10] = {29,32,9,3,43,12,1,5,7,10};
	int comp=0, troca=0;

	void preencheVet()//Fun��o para prenchimento do vetor com 10 numeros.
	{
		int vet[10];
		printf("Vetor preenchido!\n");
	}
	
	
	void bublleSort() // Ordenador do vetor.
	{
		printf("Opera��o de ordena��o concluida!\n");
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
					troca++; //N�mero de trocas feitas.
				}
			comp++; //N�mero de compara��es feita.		
			}
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
	printf("\n1-Preenche o Vetor\n2-Ordena o Vetor por Bubble Sort\n3-Desempenho\n4-Imprimir Vetor\n5-Sair\n");
	scanf("%d",&op);

	switch(op){ //Menu de escolha.
		case 1:
			preencheVet();
			break;
		case 2:
			bublleSort();
			break;
		case 3:
			printf("\nN�mero de trocas do Bublle Sort: %d",troca);
			printf("\nNumero de compara��es do Bublle Sort: %d\n",comp);
			break;
		case 4:
			imprimeVet();
			break;
		case 5:
			printf("\nSaindo do programa!!\n");
			return 0;
	}
}while(op !=5);
	
	system("pause");
	return 0;
}
