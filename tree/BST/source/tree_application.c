#include "tree_application.h"

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  struct Data_File* record = NULL;
  struct Tree tree; 
  make_tree(&tree);
  test_binary_tree(record,&tree);

  return 0;
}

void test_binary_tree(struct Data_File* record, struct Tree* tree){  
  printf("\n   (#) Unit_Test BinaryTree: \n");
  unit_test_binary_tree();
  puts("\n Successfully Performed.");

  load_data(&record);

  puts("\n\t(*) BinaryTree (STRING Key)");
  array_to_tree(record, tree, STRING_KEY);
  check_node((void*)get_root(tree));
  tree_access(record, tree, STRING_KEY);
  check_node((void*)get_root(tree));
  clean_tree((void*)tree);

  puts("\n\t(*) BinaryTree (INT Key)");
  array_to_tree(record, tree, INT_KEY);
  check_node((void*)get_root(tree));
  tree_access(record, tree, INT_KEY);
  check_node((void*)get_root(tree));
  clean_tree((void*)tree);

  puts("\n\t(*) BinaryTree (Float Key)");
  array_to_tree(record, tree, FLOAT_KEY);
  check_node((void*)get_root(tree));
  tree_access(record, tree, FLOAT_KEY);
  check_node((void*)get_root(tree));
  clean_tree((void*)tree);
  
  clean_resources(record);
}

void clean_resources (struct Data_File* record){
  printf("\n (/) Cleaning resources... ");
  for (int j=0; j<(*record).num_lines; j++)
    free((*record).lines[j]);
  free((*record).lines);
  free(record);
  puts("completed!\n");
}

void start_tests(const char* msg) {
  start_time = clock();
  printf("%s", msg);
}

void end_tests() {
  double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
  printf("Completed in %4.5f seconds\n", elapsed_time);
}

void array_to_tree(struct Data_File* record, struct Tree* tree, int key_type){
  start_tests("\t\t(+) Insert data: ");
  int num_records = (*record).num_lines;
  int i = 0;
  
  for (i; i < num_records; i++){
    switch (key_type) {
      case STRING_KEY:
        insert((void*)tree, (void*)new_node(key_type,(void*)(*(*record).lines[i]).string_field, (void*)(*record).lines[i]), compare_key);
      break;
      case INT_KEY:
        insert((void*)tree, (void*)new_node(key_type,(void*)&(*(*record).lines[i]).numb_field, (void*)(*record).lines[i]), compare_key);
      break; 
      case FLOAT_KEY:
        insert((void*)tree, (void*)new_node(key_type,(void*)&(*(*record).lines[i]).float_field, (void*)(*record).lines[i]), compare_key);      
      break; 
      default:
      break;
    }
  }
  end_tests();
}

void tree_access(struct Data_File* record, struct Tree* tree, int key_type){
  start_tests("\t\t(+) Accessing to the tree: ");
  struct Node* target = NULL;
  int i = 0;
  
  for (i; i < MAX_RANDOM; i++){
    switch (key_type) {
      case STRING_KEY:
        target = iterative_tree_search((void*)get_root((void*)tree), (void*)&(*(*record).lines[get_random(0,MAX_RANDOM)]).string_field, compare_key_with_node );
        tree_delete((void*)tree, (void*)target);      
      break;
      case INT_KEY:
        target = iterative_tree_search((void*)get_root((void*)tree), (void*)&(*(*record).lines[get_random(0,MAX_RANDOM)]).numb_field, compare_key_with_node );
        tree_delete((void*)tree, (void*)target);      
      break; 
      case FLOAT_KEY:
        target = iterative_tree_search((void*)get_root((void*)tree), (void*)&(*(*record).lines[get_random(0,MAX_RANDOM)]).float_field, compare_key_with_node );
        tree_delete((void*)tree, (void*)target);      
      default:
      break;
    }
  }
  end_tests();
}

int get_random(int min, int max){
  return rand()%((max +1) - min) + min; 
}




















/*
rand() will return an integer from 0 to 32767 depending on implementation, so you must work with that.

rand () % (100 - 85 + 1) + 85Placing this in to a function is appropriate,
int myRand(int low, int high) {
   srand(time(NULL));
   return rand() % (high - low + 1) + low;
}The % is the modulus operator to return a remainder, useful for limiting larger numbers.

This will essentially return a random number between 1 and 15, then add low again to make it between 85 and 100. 
*/