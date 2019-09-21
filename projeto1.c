#include <stdio.h>
#include <stdlib.h>
#include "projeto1.h"

struct pessoa{
	int id;
	float horas_estudo;
	float nota_p1;
	float nota_p2;
};

struct node{
	struct pessoa* aluno;
	struct node* next;
};

struct lista{
	struct node* first;
	struct node* last;
	int tamanho;
};

LISTA* criar_lista(){
	return (LISTA*)malloc(sizeof(LISTA));
}

void inserir_lista(LISTA* LE, int id, float horas_estudo, float nota_p1, float nota_p2){

	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->aluno = (PESSOA*)malloc(sizeof(PESSOA));
	new->aluno->id = id;
	new->aluno->horas_estudo = horas_estudo;
	new->aluno->nota_p1 = nota_p1;
	new->aluno->nota_p2 = nota_p2;

	if (LE->first == NULL){				//caso seja a primeira insercao
		LE->first = new;
		LE->last = new;
		LE->tamanho=1; 			
	}
	else{									//caso ja tenha cadastros na lista
		LE->last->next = new;
		LE->last = new;
		LE->tamanho++;
	}
}

void printar_lista_aux (NODE* node_atual){
	
	printf("| %d | ",node_atual->aluno->id);
	printf("%.2f | ",node_atual->aluno->horas_estudo);
	printf("%.2f | ",node_atual->aluno->nota_p1);
	printf("%.2f | ",node_atual->aluno->nota_p2);
	printf("\n");
	if(node_atual->next!=NULL){
		printar_lista_aux(node_atual->next);
	}
	else{
		printf("\n");
	}
}

void printar_lista(LISTA* LE){
	if (LE->first!=NULL){
	printar_lista_aux(LE->first);
	}
	else{
		printf("LISTA VAZIA\n");
	}
}


void remover_elementos_lista(LISTA* LE, int id){
	NODE* p = LE->first;
	NODE* prev;

	while(p){
		if (p->aluno->id == id){
			if (p == LE->first){			//caso seja o primeiro elemento a ser removido
				LE->first = p->next;
				free(p);
			}
			else{						//caso nao seja o primeiro
			prev->next = p->next;
			free(p);
			}
		}
		else
			prev = p;					//caso o id nao seja achado, avanca pra o proximo node armazenando o anterior
			p=p->next;
	}
}

void remover_1_elemento_lista(LISTA* LE, int id){
	NODE* p = LE->first;
	NODE* prev;

	while(p){
		if (p->aluno->id == id){
			if (p == LE->first){ 			//caso seja o primeiro elemento a ser removido
				LE->first = p->next;
				free(p);
			}
			else{						//caso nao seja o primeiro
			prev->next = p->next;
			free(p);
			}
			break;
		}
		else
			prev = p;					//caso o id nao seja achado, avanca pra o proximo node armazenando o anterior
			p=p->next;
	}
}

void aprovacoes_lista(LISTA* LE){
	if (LE->first!=NULL){
		NODE* p = LE->first;
		while(p){
			printf("%d\t", p->aluno->id);
			if(p->aluno->nota_p1 + p->aluno->nota_p2 >= 10)
				printf("Aprovado\n");
			else
				printf("Reprovado\n");
			p = p->next;
		}
	}
	else
		printf("LISTA VAZIA\n");
}

void media_estudo_lista(LISTA* LE){
	if (LE->first!=NULL){
		float soma = 0;
		NODE* p = LE->first;
		while(p){
			soma += p->aluno->horas_estudo;
			p = p->next;
		}
		printf("Média de horas de estudo:\t%.2f\n",(float)soma/LE->tamanho);
	}
	else
		printf("LISTA VAZIA\n");
}

void free_lista(LISTA* LE){
	if(LE == NULL) printf("LISTA INVALIDA\n");
	else{
		NODE* p = LE->first;
		NODE* aux;

		while(p){
			aux = p->next;
			free(p);
			p = aux;
		}

		free (LE);
	}	
}