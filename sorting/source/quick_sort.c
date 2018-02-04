#include "quick_sort.h"

void quick_sort(void** array, int l, int r, CompFunction compare) {
 if (l < r){
 	int p = partition(array, l, r, compare);
 	quick_sort(array, l, p, compare);
 	quick_sort(array, p+1, r, compare);
 }
}

int partition (void** array, int l, int r, CompFunction compare){
	void* x = array[(l+r)/2];
	int i = l-1, j = r+1, bool = 1;
 	while (bool) {
 		while(compare(array[--j], x) > 0 ); 		
 		while(compare(array[++i], x) < 0);
 		if((bool = (i < j)))	 
			swap(&array[i], &array[j]);
 	}
 	return j;
 }