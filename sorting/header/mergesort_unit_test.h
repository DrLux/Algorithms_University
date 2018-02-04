#include <unistd.h>
#include "mergesort.h"

// Lancia tutti gli altri unit_test
void unit_test_mergesort();

// Testa l' algoritmo su un array nullo
void test_mergesort_on_null_array();

// Testa l' algoritmo su un array gia ordinato
void test_mergesort_on_ordered_array();

// Testa l' algoritmo su un array con elementi tutti uguali
void test_mergesort_on_equals_array();

// Testa l' algoritmo su un array ordinato in senso inverso
void test_mergesort_on_reversed_array();

// Testa l' algoritmo su un array disordinato ma di piccole dimensioni
void test_mergesort_on_normal_array();