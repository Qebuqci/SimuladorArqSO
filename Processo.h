#ifndef _PROCESSOS_H
#define _PROCESSOS_H

// Estrutura de Processo

typedef struct _processo {
	int pid;
	int ppid;
	float cpu_time;
	char *nome;	  // String para guardar o nome
	char *status; // String para guardar status
} Processo;

// Funções de Processo

/* Inicializa um Processo com:
 * 	ID do processo pai e nome especificado
*/
Processo *init_Processo (int ppid, char nome[]);

/* Desaloca um Processo */
void free_Processo (Processo *proc);

/* Imprime informações de um Processo */
void print_info (Processo *proc);

// Funções Auxiliares

/* Inicializa uma sequência de processos de um arquivo */
void init_procs_from_file(char nome_arq_txt[]);

/* Inicializa uma sequência de processos lendo o arquivo
 stdin (Entrada padrão ) */
Processo* init_procs_from_stdin();

#endif
