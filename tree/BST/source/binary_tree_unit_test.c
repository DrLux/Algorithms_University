#include "binary_tree_unit_test.h"

void unit_test_binary_tree(){
  test_binary_tree_on_normal_input();
  test_binary_tree_on_ordered_input();
  test_binary_tree_on_reversed_order_input();
  test_binary_tree_on_null_input();
  test_binary_tree_on_equals_input();
}

void test_binary_tree_on_ordered_input() {
  struct Tree T; 
  make_tree(&T);
  struct Records* value = (struct Records*) malloc (sizeof(struct Records*));

  (*value).id = 1;
  strcpy((*value).string_field, "parola");
  (*value).numb_field = 2; 
  (*value).float_field = 3.45;
  float i = 0;

  
  for (i; i < 10; i++){
    insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(i), (void*)value), compare_key);
    check_node((void*)get_root(&T));
  }
  
  clean_tree((void*)&T);
}

void test_binary_tree_on_reversed_order_input() {
  struct Tree T; 
  make_tree(&T);
  struct Records* value = (struct Records*) malloc (sizeof(struct Records*));

  (*value).id = 1;
  strcpy((*value).string_field, "parola");
  (*value).numb_field = 2; 
  (*value).float_field = 3.45;
  float i = 0;
  
  for (i = 10; i > 1; i--){
    insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(i), (void*)value), compare_key);
    check_node((void*)get_root(&T));
  }
  
  clean_tree((void*)&T);
}

void test_binary_tree_on_equals_input() {
  struct Tree T; 
  make_tree(&T);
  struct Records* value = (struct Records*) malloc (sizeof(struct Records*));

  (*value).id = 1;
  strcpy((*value).string_field, "parola");
  (*value).numb_field = 2; 
  (*value).float_field = 3.45;
  float i = 0;
  
  for (i; i < 10; i++){
    insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(1), (void*)value), compare_key);
    check_node((void*)get_root(&T));
  }

  clean_tree((void*)&T);
}

void test_binary_tree_on_null_input() {
  struct Tree T; 
  make_tree(&T);
  check_node((void*)get_root(&T));
  clean_tree((void*)&T);
}

void test_binary_tree_on_normal_input() {
  struct Tree T; 
  make_tree(&T);

  struct Records* value = (struct Records*) malloc (sizeof(struct Records*));

  (*value).id = 1;
  strcpy((*value).string_field, "parola");
  (*value).numb_field = 2; 
  (*value).float_field = 3.45;

  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(5), (void*)value), compare_key);
  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(3), (void*)value), compare_key);
  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(8), (void*)value), compare_key);
  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(12), (void*)value), compare_key);
  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(2), (void*)value), compare_key);
  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(13), (void*)value), compare_key);
  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(6), (void*)value), compare_key);
  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(4), (void*)value), compare_key);
  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(1), (void*)value), compare_key);
  insert((void*)&T, (void*)new_node(FLOAT_KEY,(void*)new_float(7), (void*)value), compare_key);

  check_node((void*)get_root(&T));
  clean_tree((void*)&T);
}


void check_node(void* node){
  if (node != NULL && !is_leaf(node)){
    int key_type = get_key_type(node);
      if (get_left(node) != NULL && get_right(node) != NULL)
        assert((node == get_parent(get_left(node))) || (node == get_parent(get_right(node))));//io sia davvero padre dei miei figli    

      if (get_left(node) != NULL){
        switch (key_type) {
          case INT_KEY:
            assert(compare_int_key(node,tree_max(get_left(node))) > 0); //mia figlio sinistro sia minore di me
          break; 
          case FLOAT_KEY:
            assert(compare_float_key(node,tree_max(get_left(node))) > 0); //mia figlio sinistro sia minore di me
          break; 
          case STRING_KEY:
            assert(compare_string_key(node,tree_max(get_left(node))) > 0);
          break;    
        }
        assert(get_right(node) != get_left(node)); //figlio destro diverso da quello sinistro
        check_node(get_left(node));          
      }

      if (get_right(node) != NULL){
        switch (key_type) {
          case INT_KEY:
            assert(compare_int_key(node,tree_min(get_right(node))) < 0); //mia figlio sinistro sia minore di me
          break; 
          case FLOAT_KEY:
            assert(compare_float_key(node,tree_min(get_right(node))) < 0); //mia figlio sinistro sia minore di me
          break; 
          case STRING_KEY:
            assert(compare_string_key(node,tree_min(get_right(node))) < 0);
          break;    
        }
        assert(get_right(node) != get_left(node)); //figlio destro diverso da quello sinistro
        check_node(get_right(node));          
      }
  }
}


void clean_tree(void* tree){ 
  struct Node* min_max = NULL;
  struct Node* root = NULL;

  root = get_root(tree);  
  while(tree_min(root) != root || tree_max(root) != root){
    min_max = tree_min(root);
    if (min_max == root)
      min_max = tree_max(root);
    tree_delete(tree, min_max);
    assert(iterative_tree_search(root, (void*)get_key(min_max), compare_key_with_node ) == NULL);
    clean_node(min_max);//alla fine min_max == root
  }
  clean_node(root);  
  set_root(tree,NULL);
}
