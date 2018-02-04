#include "common.h"

int compare_key(void* node1, void* node2){
  switch (get_key_type(node1)) {
    case INT_KEY:
      return compare_int_key(node1,node2);
    break; 
    case FLOAT_KEY:
      return compare_float_key(node1,node2);
    break; 
    case STRING_KEY:
      return compare_string_key(node1,node2);
    break; 
    default:
      return 0;
  }
}

int compare_int_key(void* ptr1, void* ptr2) {
  int p1  = *(int*)get_key(ptr1);
  int p2  = *(int*)get_key(ptr2);

  return p1-p2;
}

int compare_float_key(void* ptr1, void* ptr2) {
  float p1  = *(float*)get_key(ptr1);
  float p2  = *(float*)get_key(ptr2);

  if(p1<p2) return -1;
  if(p1==p2) return 0;
  return 1;
}

int compare_string_key(void* ptr1, void* ptr2) {
  char* p1  = (char*)get_key(ptr1);
  char* p2  = (char*)get_key(ptr2);
  return (strcmp(p1,p2));
}

int compare_int_ptr(void* ptr1, void* ptr2) {
  int p1 =  *(int*)ptr1;
  int p2 =  *(int*)ptr2;

  return p1-p2;
}

int compare_float_ptr(void* ptr1, void* ptr2) {
  float p1 =  *(float*)ptr1;
  float p2 =  *(float*)ptr2;

  if(p1 < p2) return -1;
  if(p1 == p2) return 0;
  
  return 1;
}

int compare_string_ptr(void* ptr1, void* ptr2) {
  char* p1  = (char*)ptr1;
  char* p2  = (char*)ptr2;
  return strcmp(p1,p2);
}

int compare_key_with_node(void* key, void*node){
  switch ((*((struct Node*)node)).key_type) {
    case INT_KEY:
      return compare_int_ptr(key,get_key(node));
    break; 
    case FLOAT_KEY:
      return compare_float_ptr(key,get_key(node));
    break; 
    case STRING_KEY:
      return compare_string_ptr(key,get_key(node));
    break; 
    default:
      return 0;
  }
}

int* new_int(int value) {
  int* result = (int*) malloc(sizeof(int));
  *result = value;
  return result;
}

float* new_float(float value) {
  float* result = (float*) malloc(sizeof(float));
  *result = value;
  return result;
}

char* new_string(char* word){
  char* result = (char*) malloc (30*sizeof(char));
    strcpy(result, word);
  return result;
}

void* get_root(void* tree){
  if (tree != NULL)
    return (*((struct Tree*)tree)).root;
  else
    return NULL;
}


void set_root(void* tree, void* node){
  (*((struct Tree*)tree)).root = (struct Node*)node;
}

void* get_parent(void* node){
  return (*((struct Node*)node)).parent;
}

void set_parent(void* node1, void* node2){
  (*((struct Node*)node1)).parent = (struct Node*)node2;
}

void* get_left(void* node){
  if (node != NULL)
    return (*((struct Node*)node)).left;
  else
    return NULL;
}

void set_left(void* node1, void* node2){
  if (node2 != NULL){
    (*((struct Node*)node1)).left = (struct Node*)node2;
    (*((struct Node*)node2)).parent = (struct Node*)node1;
  } else
    (*((struct Node*)node1)).left = NULL;
}

void* get_right(void* node){
  if (node != NULL)
    return (*((struct Node*)node)).right;
  else
    return NULL;
}

void set_right(void* node1,void* node2){
  if (node2 != NULL){
    (*((struct Node*)node1)).right = (struct Node*)node2;
    (*((struct Node*)node2)).parent = (struct Node*)node1;
  } else
    (*((struct Node*)node1)).right = NULL;
}

void* get_key(void* node){
  if (node != NULL)
    return (*((struct Node*)node)).key;
  else
    return NULL;
}

void set_key(void* node, void* key){
  switch (get_key_type(node)) {
    case INT_KEY:
      (*((struct Node*)node)).key =  (int*)key;
    break; 
    case FLOAT_KEY:
      (*((struct Node*)node)).key =  (float*)key;
    break; 
    case STRING_KEY:
      (*((struct Node*)node)).key =  (char*)key;
    break; 
  }
}

void* get_value(void* node){
  if (node != NULL)
    return (*((struct Node*)node)).value;
  else
    return NULL;
}

void set_value(void* node, void* value){
  (*((struct Node*)node)).value =  (struct Records*)value;
}

void print_key(void* node, const char* msg){
  if (node == NULL)
    printf("\nNULL");
  else
    switch (get_key_type(node)) {
    case INT_KEY:
      printf("%s: %d \n", msg, *(int*)get_key(node));
    break; 
    case FLOAT_KEY:
      printf("%s: %4.5f \n", msg, *(float*)get_key(node));
    break; 
    case STRING_KEY:
      printf("%s: %s \n", msg, (char*)get_key(node));
    break; 
  }
}

void make_tree(struct Tree* t){
  (*t).root = NULL;
}

void print_node(void* node){
  if (get_parent(node) == NULL)
   print_key(node,"Key Nodo ROOT");
  else if (is_leaf(node))
          print_key(node,"Key Nodo FOGLIA");
        else
          print_key(node,"Key Nodo INTERNO");

 if (node == NULL)
    printf("\nNULL");
  else{
    if (get_value(node) != NULL)
      print_value(node);
    if (get_parent(node) != NULL)
      print_key(get_parent(node)," - Parent");
    if (get_left(node) != NULL)
      print_key(get_left(node)," - Left");
    if (get_right(node) != NULL)
      print_key(get_right(node)," - Right");
  }
  puts("\n");
}

struct Node* new_node(int key_type, void* key, void* value){
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));;
  set_key_type((void*)new_node,key_type);
  set_key((void*)new_node,key);
  set_value((void*)new_node,value);
  set_left((void*)new_node, NULL);
  set_right((void*)new_node, NULL);
  set_parent((void*)new_node, NULL);
  return new_node;
}

int is_leaf(void* node){
  if ((get_right(node) == NULL && get_left(node) == NULL)) 
    return 1;
  return 0;
} 

int is_root(void* node, void* tree){
  if (node == get_root(tree)) 
    return 1;
  return 0;
} 

void clean_node (void* node){
  if (node != NULL){
    free(node);
  }
}

void print_value(void* node){
  struct Records* record = (struct Records*) malloc (sizeof(struct Records));
  *record = *(struct Records*)get_value(node);
  printf("\n - Valore nodo: %d,%s,%d,%4.5f\n", (*record).id, (*record).string_field, (*record).numb_field, (*record).float_field);
  free((void*)record);
}

void replace_node(void* node1, void* node2){
  set_left(node1,get_left(node2));
  set_right(node1,get_right(node2));
  clean_node(node2);
}

int get_key_type(void* node){
  if (node != NULL)
    return (*((struct Node*)node)).key_type;
  else
    return 0;
}

void set_key_type(void* node, int key_type){
  if (node != NULL)
    (*((struct Node*)node)).key_type = key_type;
}

