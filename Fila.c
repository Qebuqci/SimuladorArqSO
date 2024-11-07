#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"

// Constantes Default
#define TAM_NOME_FILA 50

/* Inicializa uma fila */
Fila *init_fila (char *nome, int size) {
	Fila *fila = (Fila *) malloc (sizeof (Fila));
	fila->nome = (char *) malloc (sizeof(char) * TAM_NOME_FILA);
	strcpy(fila->nome, nome);
	fila->size = size;
	fila->top = fila -> back = 0;
	fila->mem = (void **) malloc(size * sizeof(void*));
}

/* Desaloca uma fila */
void free_fila(Fila *fila) {
	free(fila->nome);
	free(fila->mem);
	free(fila);
}

/* Função que checa se a fila está cheia */
int isFull(Fila* fila) { return (fila->back == fila->size - 1); }

/* Insere um objeto no final da fila
	* Se a fila estiver cheia, então dobra de tamanho e insere
*/
void insere_fila (Fila *fila, void *elemento) {

	// Está ocasionando esse essa mensagem: free(): invalid next size (fast) ??

	if (isFull(fila)) {
		fila->mem = (void **) realloc (fila->mem, 2 * fila->size);
		fila->size *= 2;
	}

	int fim = fila->back;
	fila->mem[fim] = elemento;
	fila->back += 1;
}

/* Remove um elemento do topo da fila e retorna ele */
void *remove_fila (Fila *fila, void *elemento) {
	int inicio = fila->top;
	void* obj_atendido = fila->mem[inicio];
	fila->top += 1;

	// Realocar memoria depois de atender??

	// Se a fila esvaziar
	if (fila->top > fila->back) fila->top = fila->back = 0;

    return obj_atendido;
}

/* Imprime o endereço dos objetos da fila */
void print_fila_addr(Fila *fila) {
	printf("Endereços: ");
	for (int i = 0; i < fila->back; i++) printf("%p ", fila->mem[i]);
	puts("");
}

/* Dado uma fila de inteiros, imprime-os */
void print_fila_int(Fila *fl_int) {
	printf("Objetos : ");
	for (int i = 0; i < fl_int->back; i++) {
		int *obj = fl_int->mem[i];
		printf("%d ", *obj);
	}
	printf("\n");

}

/* Imprime informações da fila */
void print_fila_info(Fila *fl) {
	puts("# Informações da fila #");
	printf("\b\b\b | Nome: %s\n \b\b\b | Size: %d\n \b\b\b | ", fl->nome, fl->size);
	print_fila_addr(fl);
}

/*
int main() {

	// Inicializa dois tipos de filas
	Fila *fila_chars = init_fila("Fila de Characteres", 2);
	Fila *fila_ints = init_fila("Fila de Inteiros", 10);

 	// Insere characteres na fila de characteres
 	char cha = 'a', chb = 'b', chc = 'c';
    insere_fila(fila_chars, &cha);
    insere_fila(fila_chars, &chb);
    insere_fila(fila_chars, &chc);

 	// Imprime a fila de chars
 	print_fila_addr(fila_chars);

 	// Insere inteiros na fila de ints
 	int n1 = 1, n2 = 2;
 	insere_fila(fila_ints, &n1);
 	insere_fila(fila_ints, &n2);

 	// Imprimir os inteiros da fila de integers
 	print_fila_int(fila_ints);

 	// Imprime informações de ambas filas
 	print_fila_info(fila_chars);
	print_fila_info(fila_ints);

 	// Remover da fila de teste

 	return 0;

}
*/

