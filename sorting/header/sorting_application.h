#include "insertion_sort_unit_test.h"
#include "quick_sort_unit_test.h"
#include "heap_sort_unit_test.h"
#include "mergesort_unit_test.h"

#ifndef __READ_FROM_FILE__
	#include <read_from_file.h>
#endif

#include <time.h>
#include <math.h>

static clock_t start_time;
#define CHECK_STRING_FIELD 1
#define CHECK_NUMB_FIELD 2
#define CHECK_FLOAT_FIELD 3

/*
 * Inizia la sessione di test
 * msg: la stringa da stampare a schermo a inizio test
 */
void start_tests(const char* msg);

// Termina la sessione di test
void end_tests(); 

// Carica tutti i dati del file nella struct record (parametro)
void prepare_test(struct Data_File** record);

// Funzione principale che lancia tutte le altre
int main(int argc, char const *argv[]);

// Funzione che esegue tutte le operazioni richieste con l'insertion_sort
void test_insertion_sort(struct Data_File* record);

// Funzione che esegue tutte le operazioni richieste con il quick_sort
void test_quick_sort(struct Data_File* record);

// Funzione che esegue tutte le operazioni richieste con l'heap_sort
void test_heap_sort(struct Data_File* record);

// Funzione che esegue tutte le operazioni richieste con il merge_sort
void test_mergesort(struct Data_File* record);

// Libera la memoria utilizzata
void clean_resources (struct Data_File* record);

// Verifica il corretto funzionamento del programma
void check (struct Data_File* record, int options);


