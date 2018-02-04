#include "list.h"
#include "read_from_file.h"

#include <limits.h>
#include <float.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define INF FLT_MAX  
#define INIT_TIME INT_MAX 

#define VTX_LIST 1
#define EDGE_LIST 2

#define ORIENTED 1
#define NOT_ORIENTED 2

/*
 * Struct che rappresente il grafo
 * num_vtx: numero di vertici
 * vtx_array: array di vertici del grafo
 */
struct Graph{
	int num_vtx;
	struct Vtx** vtx_array;
};

/*
 * Struct che rappresenta un vertice dell grafo
 * w: distanza di un vertice (dijkstra)
 * id: stringa usata come nominativo del vertice
 * grado: grado del vertice
 * adj_list: lista di adiacenza del vertice
 * color: colore del vertice
 * parent: puntatore al padre del vertice
 * discovered_time: tempo di scoperta del vertice
 * f_time: tempo di chiusura del nodo
 */
struct Vtx{
	float w;
	char id[40];
	short int grade;
	struct List* adj_list;
	short int color;
	struct Vtx* parent;
	long int discovered_time;
	long int f_time;
};

/*
 * Struct che rappresente un Arco
 * vtx_edge: vertice appartenente all' arco
 * dist: dist allegata al vtx
 * next: puntatore all' arco successivo
 */
struct Edge{
	struct Vtx* vtx_edge;
	float dist;
	struct Edge* next;
};

//Struttura che rappresenta uno Heap
struct Heap{
	int heap_size;
	struct Vtx** array;
};

#include <string.h>

//VTX: classe di funzioni legate all' uso di Vertici

//Crea un nuovo vertice e ne ritorna l' indirizzo
void* init_vtx();

//Setta "ptr" come parent di "Vertix"
void set_vtx_parent(void* vertix, void* prt);
//Torna il puntatore al parent di "vertix"
void* get_vtx_parent (void* vertix);

//Setta "t" come discovery time di "vertix"
void set_vtx_d_time(void* vertix, long int t);
//Torna il discovery time di "vertix"
long int get_vtx_d_time(void* vertix);

//Setta "t" come finish time di "vertix"
void set_vtx_f_time(void* vertix, long int t);
//Torna il finish time di "vertix"
long int get_vtx_f_time(void* vertix);

//Setta "c" come colore di "vertix"
void set_vtx_color(void* vertix, long int c);
//Torna il colore di "vertix"
long int get_vtx_color(void* vertix);

//Setta "list" come lista di adiacenza di "vertix"
void set_vtx_adj_list(void* vertix, void* list);
//Torna l' inidirizzo della lista di adiacenza di "vertix"
void* get_vtx_adj_list(void* vertix);

//Decrementa il grado di "vertix"
void dec_vtx_grade(void* vertix);
//Incrementa il grado di "vertix"
void inc_vtx_grade(void* vertix);
//Setta il grado di "vertix"
void set_vtx_grade(void* vertix, long int n);
//Torna il grado di "vertix"
long int get_vtx_grade(void* vertix);

//Setta l' "id" di "vertix"
void set_vtx_id(void* vertix, void* id);
//Torna l' "id" di "vertix"
void* get_vtx_id(void* vertix);

//Setta ls dist "i" di "vertix"
void set_vtx_w(void* vertix, float i);
//Torna ls dist "i" di "vertix"
float get_vtx_w(void* vertix);

//Stampa gli attributi del "vtx" apponendo prima e dopo di essi "msg" ed "msg_2"
void print_vtx(char* msg, void* vtx, char* msg_2);

/*
 * Esegue una ricerca del vtx. Segnala la ricerca va a buon fine o meno
 * graph: il grafo di riferimento
 * string: la stringa da ricercare
 * index: l' indice da aggionrnare con il valore del vtx trovato. (altrimenti non viene modificato)
 * num_vtx: il numero totale di vertici presenti
 */
int search_vtx_by_string(void** graph,char* string, int* index,int num_vtx);
//Torna il vtx del grafo "g" avente "id" come indice
struct Vtx* search_vtx(void* g, char*id);




//EDGE: Classi di funzioni legate all' uso di Archi

/*
 * Crea un nuovo arco e ne ritorna l' indirizzo
 * vertix: vertice dell' arco
 * dist: dist dell' arco
 */
void* make_edge(void* vertix, float dist);

//Torna il vertice dell' arco "this"
void* get_vtx_edge(void* this);
//Setta il vertice dell' arco "this"
void set_vtx_edge(void* this,void* vertix);

//Torna la dist dell' arco "this"
float get_dist_edge(void* this);
/*
 * Aggiunge l'arco alla lista di adiacenza di "vtx_target"
 * vtx_target: nodo a cui verrra aggiunto l' arco
 * vtx_list: vertice che verrà inserito all' arco
 * dist: dist che verrà inserita nell' arco
 */
void add_edge_to_list(void* vtx_target,void* vtx_list,float dist);

//LIST
//Lancia la stampa della lista
void print_list(void* l);
/*
 * Stampa la lista in modo dicorsivo, 
 * choice: stabilisce il contenuto della lista (vertici o archi)
 */
void print_list_ric(void* n,int choise);


//PATH: Funzione ausiliaria per la corretta stampa di path

//Controlla la consistenza del path tra "s" e "u"
int check_path(void* s, void* u);

//HEAP: Classi di funzioni per la realizzazione di una coda di priorità fatta con l' heap

//Crea una coda di priorità con i vertici di "g"
void* make_priority_queue(void* g);
//Estrae l' elemento più piccolo della cosa
void* extract_min(void* heap);
//Riordina la coda
void sort_heap(void* heap);

/*
 * Implementazione dell' heapify sul' array passato
 * array: l'array da ordinare
 * index: indice selezionato su cui lanciare l'heapify
 * heap_size: grandezza virtuale dell' array
 */
void heapify(void** array, int index, int heap_size);
//Torna la lista di vertici della coda di heap
struct Vtx** get_heap_array(void* heap);
//Torna la grandezza della coda di heap
int get_heap_size(void* heap);
//Decrementa la grandezza della coda di heap
void dec_heap_size(void* heap);
//Valuta l'ordine di due puntatori
int compare(void* ptr1, void* ptr2);
//Scambia l'ordine di due puntatori
void swap(void** e1, void** e2);
//Torna false se l' heapsize è 0
int heap_not_empty(void* heap);

//GRAPH: classe di funzioni legate all' uso di Grafi
//Torna il vettore di vtx del grafo
struct Vtx** get_vtxarray_graph(void* graph);
//Torna il numero di vtx del grafo
int get_numvtx_graph(void* graph);
//Torna il numero di vtx del grafo
void set_numvtx_graph(void* graph, int num_vtx);
//Aggiunge il vettore di Vtx all' grafo
void set_vtxarray_graph(void* graph, struct Vtx** vtx_array);

//FILE: Classe di funzioni per l' interazione con i dati del File

//Torna la dimensione dell'array che contiene tutte le righe del file 
int get_lenght_arrray_struct(struct Data_File* record);
//Torna il valore della stringa di destinazione all' indice "index"
char* get_lines_dest(struct Data_File* record, int index);
//Torna il valore della dist all' indice "index"
float get_lines_dist(struct Data_File* record, int index);
//Torna il valore della stringa sorgente all' indice "index"
char* get_lines_src(struct Data_File* record, int index);
//Libera le risorse occupate dai dati letti dal file
void clean_resources_from_file (struct Data_File* record);
