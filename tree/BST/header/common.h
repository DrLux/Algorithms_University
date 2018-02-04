#define __COMMON__

#ifndef __READ_FROM_FILE__
	#include <read_from_file.h>
#endif

#include <assert.h>

#define INT_KEY 1
#define FLOAT_KEY 2
#define STRING_KEY 3

/*
 * Definizione un puntatore a funzione
 * Funzione di confronto tra due elementi dell'array
 * I paramentri sono 2 puntatori a void
 * Il return è intero e cambia in base al confronte del valore dei due parametri
 */ 
typedef int (*CompFunction)(void*, void*);

// Crea l' albero di ricerca
void make_tree(struct Tree* t);

/* 
 * Crea un nodo dell' albero
 * key_type: definisce il tipo della chiave
 * key: puntatore alla key, campo del nodo
 * value: puntatore alla riga associata al nodo
 */
struct Node* new_node(int key_type, void* key, void* value);

//Stampa gli attributi del nodo
void print_node(void* node);

//Stampa solo la key del nodo
void print_key(void* node, const char* msg);

//Stampa solo il value del nodo
void print_value(void* node);

//Libera le risorse occupate dal nodo
void clean_node (void* node);

//Definisce se il nodo in questione è una foglia
int is_leaf(void* node);
//Definisce se il nodo in questione è il root
int is_root(void* node, void* tree);

//Torna il puntatore al root
void* get_root(void* tree);
//Setta il nodo passato come root dell' albero
void set_root(void* tree, void* node);

//Torna il puntatore al padre del nodo passato
void* get_parent(void* node);
//Setta node2 come padre di node1
void set_parent(void* node1, void* node2);

//Torna il puntatore al figlio sinistro del nodo passato
void* get_left(void* node);
//Setta node2 come figlio sinistro di node1
void set_left(void* node1, void* node2);

//Torna il puntatore al figlio destro del nodo passato
void* get_right(void* node);
//Setta node2 come figlio destro di node1
void set_right(void* node1,void* node2);

//Torna il puntatore alla key del nodo passato
void* get_key(void* node);
//Setta key come chiave di node
void set_key(void* node, void* key);

//Torna il puntatore alla value del nodo passato
void* get_value(void* node);
//Setta value come valore di node
void set_value(void* node, void* value);

//Torna il tipo della key del nodo passato
int get_key_type(void* node);
//Setta il tipo della chiave di node
void set_key_type(void*node, int key_type);

/*
 * Compara 2 key
 *	ptr1: puntatore alla prima key
 *	ptr2: puntatore alla seconda key
 */
int compare_key(void* ptr1, void* ptr2);

/*
 * Compara 2 key di tipo intero
 *	ptr1: puntatore alla prima key
 *	ptr2: puntatore alla seconda key
 */
int compare_int_key(void* ptr1, void* ptr2);

/*
 * Compara 2 key di tipo float
 *	ptr1: puntatore alla prima key
 *	ptr2: puntatore alla seconda key
 */
int compare_float_key(void* ptr1, void* ptr2);

/*
 * Compara 2 key di tipo string
 *	ptr1: puntatore alla prima key
 *	ptr2: puntatore alla seconda key
 */
int compare_string_key(void* ptr1, void* ptr2);

/*
 * Compara una key con un nodo
 *	ptr1: puntatore alla key
 *	ptr2: puntatore al nodo
 */
int compare_key_with_node(void* ptr1, void*node);

/*
 * Compara il contenuto di 2 puntatori a intero
 *	ptr1: puntatore al primo elemento
 *	ptr2: puntatore al secondo elemento
 */
int compare_int_ptr(void* ptr1, void* ptr2);

/*
 * Compara il contenuto di 2 puntatori a float
 *	ptr1: puntatore al primo elemento
 *	ptr2: puntatore al secondo elemento
 */
int compare_float_ptr(void* ptr1, void* ptr2);

/*
 * Compara il contenuto di 2 puntatori a string
 *	ptr1: puntatore al primo elemento
 *	ptr2: puntatore al secondo elemento
 */
int compare_string_ptr(void* ptr1, void* ptr2);

/*
 * Torna un puntatore a int che ha come valore "value"
 *	value: valore da inserire nel puntatore
 */
int* new_int(int value);

/*
 * Torna un puntatore a float che ha come valore "value"
 *	value: valore da inserire nel puntatore
 */
float* new_float(float value);

/*
 * Torna un puntatore a string che ha come valore "value"
 *	value: valore da inserire nel puntatore
 */
char* new_string(char* word);

//Elimina node2 e lo rimpiazza con node1
void replace_node(void* node1, void* node2);