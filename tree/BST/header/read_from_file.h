#define __READ_FROM_FILE__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Limite richiesto di numeri generati randomicamente
#define MAX_RANDOM 1000000

//Path dove risiede il file.csv
#define FILENAME_CSV "../csv/univer.csv"

/*
 * Struct che rappresenta le righe di ogni file
 * id: primo campo di ogni riga
 * string_field: secondo campo di ogni riga
 * numb_field: terzo campo di ogni riga
 * float_field: quart campo di ogni riga
 */
struct Records {
	int id; 
	char string_field[30];
	int numb_field;
	float float_field;
};

/*
 * Struct che raccoglie in ram i dati del file
 * num_lines: il numero di righe del file
 * lines: array di puntatori a struct di tipo lines
 */
struct Data_File {
	int num_lines;
	struct Records** lines;  
};

/*
 * Struct che rappresenta un nodo dell' albero
 * key: campo con cui si effettuano i confronti tra nodi
 * value: riga del file connessa al nodo
 * key_type: definisce se il confronto è fatto su int,float o string
 * left: figlio sinistro
 * parent: nodo padre
 * right: figlio destro
 */
struct Node{
	void* key;
	void* value;
	int key_type;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
};

//Struct che rappresente l' albero BST
struct Tree {
	struct Node* root;  
};

//Da come risultato la linghezza totale in byte del file
size_t file_len(FILE *fp);

/*
 * Legge tutto il file e torna true o false in base al successo dell' operazione
 * all_data: stringa nella heap che conterra tutto il contenuto del file
 */
int file_get_data(char** all_data);

/*
 * Routine principale che lancia le altre
 * record: struct principale che rappresenta il file in memoria ram
 */
void load_data(struct Data_File** record);

/*
 * Conta il numero di righe del file
 * datapointer: puntatore agli elementi del file (ogni singolo char)	
 */
int count_line(char *dataPointer);

/*
 * Parser che analizza ogni riga dividendone gli elementi
 * all_data: puntatore alla stringa che contiene tutto il testo
 * record: struct che conterrà le varie righe del file
 */
void parse_data(char* all_data, struct Data_File** record);