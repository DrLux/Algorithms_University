#include <unistd.h>
#include "redblack_tree.h"

// Lancia tutti gli altri unit_test
void unit_test_redblack_tree();

// Testa l' algoritmo su un input disordinato ma di piccole dimensioni
void test_redblack_tree_on_normal_input();

// Testa l' algoritmo su un input ordinato
void test_redblack_tree_on_ordered_input();

// Testa l' algoritmo su un input ordinato in senso inverso
void test_redblack_tree_on_reversed_order_input();

// Testa l' algoritmo su un input nullo
void test_redblack_tree_on_null_input();

// Testa l' algoritmo su un input con elementi tutti uguali
void test_redblack_tree_on_equals_input();

//Verifica che le proprità dell' albero R-N siano sempre rispettate
void check_rbt_prop(void* tree, void* node);

// Verifica il corretto funzionamento del programma
void check_node(void* node);

// Svuota l' albero
void clean_tree(void* tree);


