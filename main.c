#include <stdio.h>
#include <stdlib.h>
#include "projeto1.h"

void clrscr()
{
    system("@cls||clear");
}

int main(){
	
	LISTA* lista = criar_lista();
	int id,n,id_aux, n_aux;
	float horas_estudo, nota_p1, nota_p2;

	printf("\t\tRELATÓRIO DE ALUNOS\n");

	while(n!=6){

		printf("MENU:\n");
		printf("(1) Inserir Registro\n");
		printf("(2) Remover Registro\n");
		printf("(3) Imprimir Registros\n");
		printf("(4) Relatório de Aprovação\n");
		printf("(5) Horas de estudo (Média)\n");
		printf("(6) Sair\n");

		scanf("%d", &n);
		clrscr();

		if (n>6){
			printf("NÚMERO INVÁLIDO\n");
		}

		switch (n)
		{
		
		case 1:
			printf("Entre com o id: \n");
			scanf("%d", &id);
			printf("Entre com as horas de estudo: \n");
			scanf("%f", &horas_estudo);
			printf("Entre com a nota da p1: \n");
			scanf("%f", &nota_p1);
			printf("Entre com a nota da p2: \n");
			scanf("%f", &nota_p2);
			inserir_lista(lista, id, horas_estudo, nota_p1, nota_p2);
			break;

		case 2:
			printf("Entre com o id a ser removido\n");
			scanf("%d", &id_aux);
			printf("(1) para remover todos os registros com esse id\n");
			printf("(2) para remover primeiro registro com esse id\n");
			scanf("%d", &n_aux);

			if(n_aux==1) remover_elementos_lista(lista,id_aux);
			else remover_1_elemento_lista(lista,id_aux);
			break;

		case 3:
			printar_lista(lista);
			break;

		case 4:
			aprovacoes_lista(lista);
			break;

		case 5:
			media_estudo_lista(lista);
			break;
		}
	}
	
	free_lista(lista);

	return 0;
}
