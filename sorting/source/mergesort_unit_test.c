#include "mergesort_unit_test.h"

void unit_test_mergesort(){
  test_mergesort_on_normal_array();
  test_mergesort_on_ordered_array();
  test_mergesort_on_null_array();
  test_mergesort_on_equals_array();
  test_mergesort_on_reversed_array();
}


void test_mergesort_on_null_array() {
  long int* array = NULL;
  mergesort((void**) array, 0, 0, compare_int_ptr);
  assert( NULL == array );
}

void test_mergesort_on_ordered_array() {
  int* array[10];
  for(int i=0; i<10; i++) 
    array[i] = new_int(i+1);

  mergesort((void**) array, 0, 9, compare_int_ptr);

  for(int i=0; i<9; i++) 
    assert(*array[i] <= *array[i+1]);

  for(int i=0; i<10 ; i++) 
    free(array[i]);
}

void test_mergesort_on_equals_array() {
  int* array[10];
  for(int i=0; i<10; i++) 
    array[i] = new_int(1);

  mergesort((void**) array, 0, 9, compare_int_ptr);

  for(int i=0; i<9; i++) 
    assert(*array[i] <= *array[i+1]);

  for(int i=0; i<10 ; i++) 
    free(array[i]);
}

void test_mergesort_on_reversed_array() {
  int* array[10];
  for(int i=9; i>=0; i--) 
    array[9-i] = new_int(i+1);

  mergesort((void**) array, 0, 9, compare_int_ptr);

  for(int i=0; i<9; i++) 
    assert(*array[i] <= *array[i+1]);

  for(int i=0; i<10 ; i++) 
    free(array[i]);
}

void test_mergesort_on_normal_array() {
  int* array[10];
  array[0] = new_int(0);
  array[1] = new_int(7);
  array[2] = new_int(9);
  array[3] = new_int(4);
  array[4] = new_int(6);
  array[5] = new_int(8);
  array[6] = new_int(2);
  array[7] = new_int(3);
  array[8] = new_int(1);
  array[9] = new_int(5);

  mergesort((void**) array, 0, 9, compare_int_ptr);

  for(int i=0; i<9; i++) 
    assert(*array[i] <= *array[i+1]);

  for(int i=0; i<10 ; i++) 
    free(array[i]);
}