#ifndef PROJETO1
#define PROJETO1

	#define PESSOA_H
	#define NODE_H
	#define LISTA_H
	#define INVALID_LIST		-1
	#define ELEMENTO_AUSENTE	-2
	
	typedef struct pessoa PESSOA;
	typedef struct node NODE;
	typedef struct lista LISTA;

	LISTA* criar_lista();

	void inserir_lista (LISTA* LE, int id, float horas_estudo, float nota_p1, float nota_p2);

	void printar_lista(LISTA* LE);

	void remover_elementos_lista(LISTA* LE, int id);

	void remover_1_elemento_lista(LISTA* LE, int id);

	void aprovacoes_lista(LISTA* LE);

	void media_estudo_lista(LISTA* LE);

	void free_lista(LISTA* LE);

#endif
