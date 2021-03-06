#include <unistd.h>
#include "insertion_sort.h"

// Lancia tutti gli altri unit_test
void unit_test_insertion_sort();

// Testa l' algoritmo su un array nullo
void test_insertion_sort_on_null_array();

// Testa l' algoritmo su un array gia ordinato
void test_insertion_sort_on_ordered_array();

// Testa l' algoritmo su un array con elementi tutti uguali
void test_insertion_sort_on_equals_array();

// Testa l' algoritmo su un array ordinato in senso inverso
void test_insertion_sort_on_reversed_array();

// Testa l' algoritmo su un array disordinato ma di piccole dimensioni
void test_insertion_sort_on_normal_array();