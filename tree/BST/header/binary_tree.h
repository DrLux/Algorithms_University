#ifndef __COMMON__
	#include "common.h"
#endif

/*
 * Inserisce un nodo all' interno dell' albero
 * T: albero in cui inserire
 * new_node: nodo da inserire
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void insert(void* T, void* new_node, CompFunction compare);

//Stampa inorder dell' albero
void inorder_print_tree(void* node);

/*
 * Ricerca di un nodo in modo iterativo
 * node: nodo da cui far partire la ricerca
 * key: valore da cercare
 * compare: funzione per valutare l'ordine di due elementi dell'array
 */
void* iterative_tree_search(void* node, void* key, CompFunction compare);

/*
 * Ricerca del nodo minimo
 * node: nodo da cui far partire la ricerca
 */
void* tree_min(void* node);

/*
 * Ricerca del nodo successore al nodo dato
 * node: nodo da cui far partire la ricerca
 */
void* tree_successor(void* node);

/*
 * Elimina dall' albero il nodo selezionato
 * T: albero
 * node: nodo da eliminare
 */
void* tree_delete(void* T, void* target_node);

/*
 * Ricerca del nodo massimo
 * node: nodo da cui far partire la ricerca
 */
void* tree_max(void* node);
