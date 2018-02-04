#ifndef __COMMON__
	#include "common.h"
#endif


/*
 * Implementazione dell' heap_sort sul' array passato
 * array: l'array da ordinare
 * array_lenght: grandezza reale dell' array
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void heap_sort(void** array, int array_lenght, CompFunction compare);

/*
 * Implementazione dell build_heap sul' array passato
 * array: l'array da ordinare
 * array_lenght: grandezza reale dell' array
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void build_heap(void** array, int array_lenght, CompFunction compare);

/*
 * Implementazione dell' heapify sul' array passato
 * array: l'array da ordinare
 * index: indice selezionato su cui lanciare l'heapify
 * heap_size: grandezza virtuale dell' array
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void heapify(void** array, int index, int heap_size, CompFunction compare);