#define __LIST__

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define STACK 1
#define QUEUE 0

//Struttura che rappresenta il nodo di una lista
struct Node{
	void* cargo;
	struct Node* next;
};

//Struttura che rappresenta la lista (Tipologia con sentinella)
struct List{
	short int num_nodi;
	struct Node* sentinel;
};

//Crea una nuova lista vuota e ne torna l'indirizzo
void* make_empty();
//Inserisce il nodo "n" in testa alla lista "l"
void insert_first(void* l, void* n);
//Rimuove il nodo in testa alla lista "l"
void remove_first(void* l);
//Inserisce il nodo "n" in coda alla lista "l"
void insert_last(void* l, void* n);
//Torna false se la lista "l" è vuota
int not_empty(void* l);
//Torna l' indirizzo della coda
void* get_last(void* l);
//Trova l' indirizzo della coda in modo ricorsivo
void* get_last_ric(void* n);
//Torna l' indirizzo dell' elemento in testa alla lista
void* get_first(void* list);
//Setta l' indirizzo dell' elemento in testa alla lista
void set_first(void* list,void* head);
//Torna l' indirizzo dell' elemento prossimo al nodo "this"
void* get_next(void* this);
//Setta l' indirizzo dell' elemento prossimo al nodo "this"
void set_next(void* this,void* next);
//Rimuove i nodi dalla lista "stack"
void clean_list(void* stack);
//Aggiunge il nodo "n" alla lista "l" secondo il criterio stabilito da "choice"
void add(int choice,void* l, void* n);
//Crea un nuovo nodo avente come cargo l' indirizzo "ptr"
void* create_node(void* ptr);
//Torna l' indirizzo della sentinella
void* get_sentinel(void* list);
//Torna il valore del cargo del nodo
void* get_cargo(void* node);
//Torna il valore dei nodi contenuti nella lista
short int get_num_node(void* list);
//Incrementa il valore dei nodi contenuti nella lista
void inc_num_node(void* list);
//Elimina un nodo dalla lista
void delete_node(void* target, void* list);
//Ricerca ricorsivamente ed elimina il nodo dalla lista
void delete_node_ric(void* target, void* list);
