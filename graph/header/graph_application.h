#include "unit_test_graph.h"

#include <time.h>
#include <math.h>

static clock_t start_time;

// Funzione principale che lancia tutte le altre
int main(int argc, char const *argv[]);

// Carica tutti i dati del file nella struct record (parametro)
void prepare_test(struct Data_File** record);

/*
 * Carica il grafo con tutti gli elementi presenti nell' array record
 * record: struct che contiene tutti i dati del file
 * graph: grafo da riempire
 */ 
void array_to_graph(struct Data_File* record, void** graph, int choice);

//Trasla il grafo dato nell' indirizzo "t_graph"
void reverse_graph(void* graph, void** t_graph);

//Calcola le parti fortemente connesse
void strongly_connected_components(void* g,int choice);

//Calcola il cammino minimo dal vertice "s" nel grafo "g"
void min_path(void* g, void*s);
//Libera tutte le risorse occupate
void delete_graph(void* graph);
/*
 * Inizia la sessione di test
 * msg: la stringa da stampare a schermo a inizio test
 */
void start_tests(const char* msg);
// Termina la sessione di test
void end_tests();
