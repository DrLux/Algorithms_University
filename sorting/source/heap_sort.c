#include "heap_sort.h"

void heap_sort(void** array, int array_lenght, CompFunction compare){
	if (array_lenght > 0){
		build_heap(array,array_lenght,compare);
		int heap_size = array_lenght;

		for (int i = array_lenght; i > 0; i--){
			swap(&array[0],&array[i]);
			heap_size--;
			heapify(array,0, heap_size,compare);
		}
	}
}

void heapify(void** array, int index, int heap_size, CompFunction compare){
	int left = index*2;
	int right = (index*2)+1;
	int largest = 0;

	if (left <= heap_size && compare(array[left], array[index]) > 0 ) 
		largest = left;
	else
		largest = index;

	if (right <= heap_size && compare(array[right], array[largest]) > 0 ) 
		largest = right;

	if (largest != index){
		swap(&array[index], &array[largest]);
		heapify(array, largest, heap_size, compare);
	}
}

void build_heap(void** array, int array_lenght, CompFunction compare){
	for (int i = array_lenght/2; i >= 0; i--)
		heapify(array,i,array_lenght,compare);
}