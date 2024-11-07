#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Escalonador.h"

/* Inicialização */
Escalonador *init_schedule(Processo **procs, int nprocs) {
	Escalonador *sch = (Escalonador *) malloc (sizeof (Escalonador) );

	sch->processos = (Processo **) malloc (sizeof(Processo *) * nprocs);
	memcpy(sch->processos, procs, sizeof(Processo *) * nprocs);
	sch->nprocessos = nprocs;

	sch->ativos = init_fila("Ativos", 6);
	sch->execucao = init_fila("Execucao", 2);
	sch->bloqueados = init_fila("Bloqueados", 2);

	// Insere os processos na fila de ativos
	for (int i = 0; i < nprocs; i++) {
		Processo *processo_i = sch->processos[i];
		insere_fila(sch->ativos, processo_i);
	}

	return sch;
}

/* Desalocação */
void free_escalonador(Escalonador *schedule) {
	for (int i = 0; i < schedule->nprocessos ; i++)
		free_Processo(schedule->processos[i]);

	free_fila(schedule->ativos);
	free_fila(schedule->execucao);
	free_fila(schedule->bloqueados);

	free(schedule);

}

/* Imprime os nomes dos processos ativos */
void print_active_procs(Escalonador *sch) {
	printf("# Escalonador \n\b\b\b > Lista de Processos Ativos : \n");
	for (int i = 0; i < sch->nprocessos; i++) {
		Processo *p = (Processo *) sch->ativos->mem[i];
		printf(" \b\b\b\b\b\b | %s \tPID : %d\n", p->nome, p->pid);
	}
	puts("");
}

int main() {

	int nprocessos_criados = 7;

	// Inicializa 7 processos
	Processo *proc0 = init_Processo(0, "boot");
	Processo *proc1 = init_Processo(1, "init");
	Processo *proc2 = init_Processo(1, "python");
	Processo *proc3 = init_Processo(1, "kate");
	Processo *proc4 = init_Processo(32131, "Chrome");
	Processo *proc5 = init_Processo(1923, "Firefox");
	Processo *proc6 = init_Processo(10912, "Notepad.exe");

	// Cria um vetor de 7 processos
	Processo *procs[nprocessos_criados];
	procs[0] = proc0;
	procs[1] = proc1;
	procs[2] = proc2;
	procs[3] = proc3;
	procs[4] = proc4;
	procs[5] = proc5;
	procs[6] = proc6;

	// Imprime informações dos processos criados
	for (int i = 0; i < nprocessos_criados; i++ ) print_info_process(procs[i]);

	// Constroi um escalonador para os 7 processos
	Escalonador *sch = init_schedule(procs, 7);

	// Imprime os processos ativos
	print_active_procs(sch);

	// Imprime informações quanto a fila de processos ativos
	print_fila_info(sch->ativos);

	// Desaloca o escalonador
	free_escalonador(sch);

	return 0;
}
