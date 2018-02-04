#include "common.h"

void swap(void** e1, void** e2) {
  void* tmp = *e1;
  *e1 = *e2;
  *e2 = tmp;
}

int compare_int_struct(void* ptr1, void* ptr2) {
  int p1 = get_numb_field(ptr1);
  int p2 = get_numb_field(ptr2);
  return p1-p2;
}

int compare_float_struct(void* ptr1, void* ptr2) {
  float p1 = get_float_field(ptr1);
  float p2 = get_float_field(ptr2);

  if (p1 < p2) return -1;
  if (p1 == p2) return 0;
  return 1;
/*Qui non posso fare direttamente p1-p2 perche il return deve essere un int, 
  e nel cast a int avrei una perdita di dati significativa. Es: 12.05 e 12.99 diventerebbero entrambi 12.*/
}

int compare_string_struct(void* ptr1, void* ptr2) {
  char* p1 = get_string_field(ptr1);
  char* p2 = get_string_field(ptr2);
  return (strcmp(p1,p2));
}

int compare_int_ptr(void* ptr1, void* ptr2) {
  int i1 =  *(int*)ptr1;
  int i2 =  *(int*)ptr2;
  return i1-i2;
}

void make_array( void** array, int size){
  struct Records** array_temp = (struct Records**) malloc (size*sizeof(struct Records*));
  array = (void**)array_temp;
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


char* get_string_field(void* ptr){
  return (*((struct Records*)ptr)).string_field;  
}

int get_numb_field(void* ptr){
  return (*((struct Records*)ptr)).numb_field;  
}

float get_float_field(void* ptr){
  return (*((struct Records*)ptr)).float_field;  
}

int get_lenght_arrray_struct(struct Data_File* record){
  return (*record).num_lines;
}

