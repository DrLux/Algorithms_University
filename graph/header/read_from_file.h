#define __READ_FROM_FILE__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Path dove si trova il file.csv
#define FILENAME_CSV "../csv/univer.csv"

/*
 * Struct che rappresenta le righe di ogni file
 * src: stringa che rappresenta la città di origine
 * dst: stringa che rappresenta la città di destinazione
 * dist: rappresenta la distanza tra le due città
 */
struct Records {
	char src[40];
	char dst[40];
	float dist;
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