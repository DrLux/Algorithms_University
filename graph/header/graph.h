#include "common.h"
#include <stdio.h>

//Variabile globale che scandisce il tempo nella visita dell' albero
extern long int timer;

//Inizializza e lancia la visita BFS
void bfs(void* g);
//Implementazione dell' algoritmo di visita BSF sul grafo "g" partendo dal nodo "s"
void bfs_visit(void* g, void* s);

//Inizializzione per la visita DFS
void init_dfs(void* g);
//Lancia visite DFS per tutto il grafo
void full_dfs(void* g);
//Implementazione dell' algoritmo di visita DFS sul grafo "g" partendo dal nodo "s"
void dfs_visit(void* g, void* s);
//Implementazione dell' algoritmo di visita DFS adattato per il calcolo di CFC
void dfs_cfc(void* g, void* s,void* l);
//Inizializza e lancia la visita Dfs_Topological
struct List* topological_sort(void* g);
//Implementazione dell' algoritmo di visita DFS adattato per il calcolo topologico
void dfs_topological(void* g, void* s,void* l);
//Calcola le cfc su un grafo non orientato
void* cfc_non_oriented(void* g);

//Inizializza il grafo e il vertice "s" per il calcolo di cammini minimi
void initializa_single_source(void* g, void* s);
//Implementazione dell' algoritmo di Dijkstra
void dijkstra(void* g);
/*
 * Implementazione dell' algoritmo di relax
 * u: vertice di destinazione
 * v: vertice di sorgente
 * w: distanza tra i due vertici
 * q: link alla coda di priorità
 */
void relax(void* u, void* v, float w,void* q);

//Funzione che stampa a schermo il contenuto del grafo
void print_graph(int real_size, void** graph);
//Funzione che lancia la stampa del path da "s" a "u"
void print_path(void* g, void* s, void* u);
//Funzione che stampa del path da "s" a "u" in modo ricorsivo
void print_path_ric(void* g, void* s, void* u);