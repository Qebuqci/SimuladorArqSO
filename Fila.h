#ifndef _FILA_H
#define _FILA_H

// Estrutura de Fila

typedef struct _fila {
	char *nome;
	int size;
	void **mem;
	int top; // pos topo da fila
	int back; // pos final da fila
} Fila;

// Funções de Fila

/* Inicializa uma fila */
Fila *init_fila (char *nome, int size);

/* Desaloca uma fila */
void free_fila(Fila *fila);

/* Função que checa se a fila está cheia */
int isFull(Fila* fila);

/* Insere um objeto no final da fila
	* Se a fila estiver cheia, então dobra de tamanho e insere
*/
void insere_fila (Fila *fila, void *obj);

/* Remove um elemento do topo da fila e retorna ele */
void *remove_fila (Fila *fila, void *obj);

/* Imprime o endereço dos objetos da fila */
void print_fila_addr(Fila *fila);

/* Dado uma fila de inteiros, imprime-os */
void print_fila_int(Fila *fl_int);

/* Imprime informações da fila */
void print_fila_info(Fila *fl);

#endif
