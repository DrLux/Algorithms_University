#ifndef __COMMON__
	#include "common.h"
#endif

/*
 * Preparazione alla chiamata merge_sort
 * A: l'array da ordinare
 * l: indice sinistro
 * r: indice destro
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void mergesort(void** A, int l, int r, CompFunction compare);

/*
 * Implementazione del merge_sort
 * A: l'array da ordinare
 * B: array di appoggio per raccogliere i dati in modo ordinato
 * l: indice sinistro
 * r: indice destro
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void merge_sort(void** A, void** B, int l, int r, CompFunction compare);

/*
 * Funzione di merge
 * A: l'array da ordinare
 * B: array di appoggio per raccogliere i dati in modo ordinato
 * l: indice sinistro
 * q: indice di mezzo
 * r: indice destro
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void merge(void** A, void** B, int l, int q, int r, CompFunction compare);