#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Processo.h"

// Constantes

#define PROC_BOOT_ID 0
#define STRING_DEFAULT_SIZE 30

// Funções de Processo

/* Inicializa um Processo com:
 * 	ID do processo pai e nome especificado
*/
Processo *init_Processo (int ppid, char nome[]) {
	Processo *proc;
	proc = (Processo *) malloc (sizeof(Processo));

	// Inicialização de memória e valores para construir um Processo

	int pid = rand(); // Calcula um inteiro random
	float cpu_time = 0.0;
	proc->nome = (char *) malloc (STRING_DEFAULT_SIZE * sizeof(char));
	proc->status = (char *) malloc (STRING_DEFAULT_SIZE * sizeof(char));

	// Preenche a struct de Processo
	proc->pid = pid;
	proc->ppid = ppid;
	proc->cpu_time = cpu_time;
	strcpy(proc->nome, nome);
	strcpy(proc->status, "inicializado");

	return proc;

}

/* Desaloca um Processo */
void free_Processo (Processo *proc) {
	free(proc->nome);
	free(proc->status);
	free(proc);
}

/* Imprime informações de um Processo */
void print_info (Processo *proc) {
	int pid = proc->pid;
	int ppid = proc->ppid;
	char *nome = proc->nome;
	char *status = proc->status;
	float cpu_time = proc->cpu_time;

	printf("Processo \t\tID: %d\tNOME: %s\tSTATUS: %s\t PARENT_ID: %d\tCPU_TIME: %.3f\n",
		   pid, nome, status, ppid, cpu_time);

}

// Funções Auxiliares

/* Inicializa uma sequência de processos de um arquivo */
void init_procs_from_file(char nome_arq_txt[]) {
	// ToDo
}

/* Inicializa uma sequência de processos lendo o arquivo
 stdin (Entrada padrão )
	Ex: processo < lista_processos.txt
 */
Processo* init_procs_from_stdin() {

	// Análogo a Tabela de Processos na memória
	Processo *processos[4];

	char stdin_content[100];
	for (int i = 0; (stdin_content[i] = getchar()) != EOF ; i++);
	puts(stdin_content);

	// for (int i = 0; i < 4; i++) processos[i] = init_Processo()

	return 0;
}


int main() {

	Processo *proc = init_Processo(PROC_BOOT_ID, "random");
	print_info(proc);
	free_Processo(proc);

	// init_procs_from_stdin();
	return 0;
}
