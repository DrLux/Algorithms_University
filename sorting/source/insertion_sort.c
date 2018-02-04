#include "insertion_sort.h"

void insertion_sort(void** array, int size, CompFunction compare) {
	int sorted = 0;
	int j = 0;
	for(sorted = 1; sorted<size; sorted++) {
		j = sorted;
		while (j>0 && compare(array[j-1], array[j]) > 0 ){
			swap(&array[j-1], &array[j]);
			j--; 
		}
	}
}