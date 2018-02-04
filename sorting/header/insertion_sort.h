#ifndef __COMMON__
	#include "common.h"
#endif


/*
 * Implementa l' insertion_sort sul' array passato
 * array: l'array da ordinare
 * size: intero che rappresenta il numero di elementi dell' array
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void insertion_sort(void** array, int size, CompFunction compare);