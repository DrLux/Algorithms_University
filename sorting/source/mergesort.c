#include "mergesort.h"

void mergesort(void** A, int l, int r, CompFunction compare){
  struct Records** B = (struct Records**) malloc ((r-l+1)*sizeof(struct Records*));
  merge_sort(A, (void**)B, l, r, compare);
  free(B);
}

void merge_sort(void** A, void** B, int l, int r, CompFunction compare){
  if (r > l){
    int p = (l + r)/2;
    merge_sort(A, B, l, p, compare);
    merge_sort(A, B, p+1, r, compare);
    merge(A, B, l, p, r, compare);
  }
}

void merge(void** A, void** B, int l, int p, int r, CompFunction compare) {
  int i = l, j = p+1 , k;
  for (k = l; k <= r; k++)
    if (i > p)
      B[k] = A[j++];
    else if (j > r)
          B[k] = A[i++];
        else if ( compare(A[i], A[j]) <= 0 )
              B[k] = A[i++];
            else
              B[k] = A[j++];

  for ( k = l; k <= r; k++ )
    A[k] = B[k];
}