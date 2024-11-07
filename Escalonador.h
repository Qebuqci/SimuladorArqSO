#ifndef _ESCALONADOR_H
#define _ESCALONADOR_H

#include "Processo.h"
#include "Fila.h"

// Estrutura do Escalonador

typedef struct _escalonador {
	Processo **processos;
	int nprocessos;
	Fila *ativos, *execucao, *bloqueados;
} Escalonador;

// Funções do Escalonador

/* Inicialização */
Escalonador *init_schedule(Processo *procs[], int nprocs);

/* Desalocação */
void free_escalonador(Escalonador *schedule);

/* Imprime os nomes dos processos ativos */
void print_active_procs(Escalonador *sch);

#endif
