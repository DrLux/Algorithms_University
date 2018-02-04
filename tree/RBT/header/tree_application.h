#include "redblack_tree_unit_test.h"

#ifndef __READ_FROM_FILE__
	#include <read_from_file.h>
#endif

#include <time.h>
#include <math.h>

static clock_t start_time;

// Funzione principale che lancia tutte le altre
int main(int argc, char const *argv[]);

/*
 * Funzione che esegue tutte le operazioni richieste sull' albero rosso-nero
 * record: struct che contiene tutti i dati del file
 * tree: albero di riferimento
 */
void test_redblack_tree(struct Data_File* record, struct Tree* tree);

// Libera la memoria utilizzata
void clean_resources (struct Data_File* record);

/*
 * Inizia la sessione di test
 * msg: la stringa da stampare a schermo a inizio test
 */
void start_tests(const char* msg);

// Termina la sessione di test
void end_tests();

/*
 * Carica l' albero con tutti gli elementi presenti nell' array record
 * record: struct che contiene tutti i dati del file
 * tree: albero di riferimento
 * key_type: indica il tipo della key che si vuole utilizzare
 */ 
void array_to_tree(struct Data_File* record, struct Tree* tree, int key_type);

/*
 * Esegue funzioni di ricerca ed eliminazione all' interno dell'albero
 * record: struct che contiene tutti i dati del file
 * tree: albero di riferimento
 * key_type: indica il tipo della key che si vuole utilizzare
 */ 
void tree_access(struct Data_File* record, struct Tree* tree, int key_type);

//Genera un numero random compreso tra i due estremi dati
int get_random(int min, int max);