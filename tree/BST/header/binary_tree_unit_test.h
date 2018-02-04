#include <unistd.h>
#include "binary_tree.h"

// Lancia tutti gli altri unit_test
void unit_test_binary_tree();

// Testa l' algoritmo su un input disordinato ma di piccole dimensioni
void test_binary_tree_on_normal_input();

// Testa l' algoritmo su un input gia ordinato
void test_binary_tree_on_ordered_input();

// Testa l' algoritmo su un input ordinato in senso inverso
void test_binary_tree_on_reversed_order_input();

// Testa l' algoritmo su un input nullo
void test_binary_tree_on_null_input();

// Testa l' algoritmo su un input con elementi tutti uguali
void test_binary_tree_on_equals_input();

// Svuota l' albero
void clean_tree(void* tree);

// Verifica il corretto funzionamento del programma
void check_node(void* node);

