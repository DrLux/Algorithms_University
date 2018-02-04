#ifndef __COMMON__
	#include "common.h"
#endif

/*
 * Implementazione del quick_sort
 * array: l'array da ordinare
 * min_index: indice della parte minore
 * max_index: indice della parte maggiore
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void quick_sort(void** array, int min_index, int max_index, CompFunction compare);

/*
 * Implementazione del partition
 * array: l'array da ordinare
 * min_index: indice della parte minore
 * max_index: indice della parte maggiore
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
int partition (void** array, int min_index, int max_index, CompFunction compare);