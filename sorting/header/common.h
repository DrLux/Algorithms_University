/*
	Libreria di funzioni comuni tra i vari algoritmi di ordinamento
*/
#define __COMMON__

#ifndef __READ_FROM_FILE__
	#include <read_from_file.h>
#endif

#include <assert.h>

/*
 * Definizione un puntatore a funzione
 * Funzione di confronto tra due elementi dell'array
 * I paramentri sono 2 puntatori a void
 * Il return è intero e cambia in base al confronte del valore dei due parametri
 */  
typedef int (*CompFunction)(void*, void*);

/*
 * Dati due puntatori, ne inverte il contenuto
 * e1: puntatore al primo valore
 * e2: puntatore al secondo valore
 */
void swap(void** e1, void** e2);

/*
 * Compara il contenuto di 2 puntatori a intero
 *	ptr1: puntatore al primo elemento
 *	ptr2: puntatore al secondo elemento
 */
int compare_int_ptr(void* ptr1, void* ptr2);

/*
 * Compara il contenuto di 2 interi all' interno di una struct
 *	ptr1: puntatore alla prima struct
 *	ptr2: puntatore alla seconda struct
 */
int compare_int_struct(void* ptr1, void* ptr2);

/*
 * Compara il contenuto di 2 float all' interno di una struct
 *	ptr1: puntatore alla prima struct
 *	ptr2: puntatore alla seconda struct
 */
int compare_float_struct(void* ptr1, void* ptr2);

/*
 * Compara il contenuto di 2 stringhe all' interno di una struct
 *	ptr1: puntatore alla prima struct
 *	ptr2: puntatore alla seconda struct
 */
int compare_string_struct(void* ptr1, void* ptr2);

/*
 * Crea un array di "size" puntatori a struct
 *	array: indirizzo dove far puntare l' array
 *	size: grandezza dell'a rray
 */
void make_array(void** array, int size);

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
 * Torna la stringa interna alla struct
 * ptr: puntatore alla struct
 */
char* get_string_field(void* ptr);

/*
 * Torna l' int interno alla struct
 * ptr: puntatore alla struct
 */
int get_numb_field(void* ptr);

/*
 * Torna il float interno alla struct
 * ptr: puntatore alla struct
 */
float get_float_field(void* ptr);

/*
 * Torna il numero di elementi dell'array (le righe del file)
 * record: l' array contenente tutte le righe del file
 */
int get_lenght_arrray_struct(struct Data_File* record);