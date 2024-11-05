#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "Fila.h"

/* Inicializa uma fila */
Fila *init_fila (int size, int pos_livre) {
	// To Do
	return 0;
}

/* Desaloca uma fila */
void free_fila(Fila *fila) {
	// To Do
}

/* Insere numa fila */
void insere_fila (Fila *fila, void *elemento) {
	// To Do
}

/* Remove elemento da fila */
void remove_fila (Fila *fila, void *elemento) {
	// To Do
}

/* Remove elemento atendido da fila - FIFO or LIFO */
void remove_a_fila (Fila *fila) {
	// To Do
}

/* Imprime a fila */
void print_fila(Fila *fila) {
	// To Do
}


int main() {

	// Inicializar uma fila de teste
	Fila *fila_teste = init_fila(100, 0);

	// Inserir na fila de teste
	// insere_fila(fila_teste, elemento)

	// Remover da fila de teste

	// Imprimir a fila de teste

	return 0;

}
