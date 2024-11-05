#ifndef _FILA_H
#define _FILA_H

// Estrutura de Fila

typedef struct _fila {
	int size;
	int pos_livre;
	void *mem;
} Fila;

// Funções de Fila

/* Inicializa uma fila */
Fila *init_fila (int size, int pos_livre);

/* Desaloca uma fila */
void free_fila(Fila *fila);

/* Insere numa fila */
void insere_fila (Fila *fila, void *elemento);

/* Remove elemento da fila */
void remove_fila (Fila *fila, void *elemento);

/* Remove elemento atendido da fila - FIFO or LIFO */
void remove_a_fila (Fila *fila);

/* Imprime a fila */
void print_fila(Fila *fila);


#endif
