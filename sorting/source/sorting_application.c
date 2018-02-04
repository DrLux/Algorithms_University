#include "sorting_application.h"

int main(int argc, char const *argv[]) {
  struct Data_File* record = NULL;

  test_mergesort(record);
  test_quick_sort(record);    
  test_heap_sort(record); 
  test_insertion_sort(record);

  return 0;
}

void test_insertion_sort(struct Data_File* record){
  prepare_test(&record);

  printf("\n   (#) Unit_Test Insertion Sort: ");
  unit_test_insertion_sort();
  puts(" Successfully performed.");

  puts("\n\t(*) Inserion sort (String Field)");
  start_tests("\t\t- Test ");
  insertion_sort((void**)(*record).lines, ((*record).num_lines), compare_string_struct);
  end_tests();
  check(record,CHECK_STRING_FIELD);

  puts("\n\t(*) Inserion sort (Numb Field)");
  start_tests("\t\t- Test ");
  insertion_sort((void**)(*record).lines, ((*record).num_lines), compare_int_struct);
  end_tests();
  check(record,CHECK_NUMB_FIELD);

  puts("\n\t(*) Inserion sort (Float Field)");
  start_tests("\t\t- Test ");
  insertion_sort((void**)(*record).lines, ((*record).num_lines), compare_float_struct);
  end_tests();
  check(record,CHECK_FLOAT_FIELD);

  clean_resources(record);
}

void test_heap_sort(struct Data_File* record){
  prepare_test(&record);

  printf("\n   (#) Unit_Test Heap Sort: ");
  unit_test_heap_sort();
  puts(" Successfully performed.");

  puts("\n\t(*) Heap sort (String Field)");
  start_tests("\t\t- Test ");  
  heap_sort((void**)(*record).lines, (get_lenght_arrray_struct(record)-1), compare_string_struct);
  end_tests();
  check(record,CHECK_STRING_FIELD);
  
  puts("\n\t(*) Heap sort (Numb Field)");
  start_tests("\t\t- Test ");  
  heap_sort((void**)(*record).lines, (get_lenght_arrray_struct(record)-1), compare_int_struct);
  end_tests();
  check(record,CHECK_NUMB_FIELD);

  puts("\n\t(*) Heap sort (Float Field)");
  start_tests("\t\t- Test ");  
  heap_sort((void**)(*record).lines, (get_lenght_arrray_struct(record)-1), compare_float_struct);
  end_tests();
  check(record,CHECK_FLOAT_FIELD);
  
  clean_resources(record);
}

void test_mergesort(struct Data_File* record){
  prepare_test(&record);

  printf("\n   (#) Unit_Test MergeSort: ");
  unit_test_mergesort();
  puts(" Successfully performed.");

  puts("\n\t(*) Merge sort (String Field)");
  start_tests("\t\t- Test ");
  mergesort((void**)(*record).lines, 0, (get_lenght_arrray_struct(record)-1), compare_string_struct);
  end_tests();
  check(record,1);

  puts("\n\t(*) Merge sort (Numb Field)");
  start_tests("\t\t- Test ");
  mergesort((void**)(*record).lines, 0, (get_lenght_arrray_struct(record)-1), compare_int_struct);
  end_tests();
  check(record,CHECK_NUMB_FIELD);

  puts("\n\t(*) Merge sort (Float Field)");
  start_tests("\t\t- Test ");
  mergesort((void**)(*record).lines, 0, (get_lenght_arrray_struct(record)-1), compare_float_struct);
  end_tests();
  check(record,CHECK_FLOAT_FIELD);

  clean_resources(record);
}

void test_quick_sort(struct Data_File* record){
  prepare_test(&record);

  printf("\n   (#) Unit_Test Quick Sort: ");
  unit_test_quick_sort();
  puts(" Successfully performed.");

  puts("\n\t(*) Quick sort (String Field)");
  start_tests("\t\t- Test ");
  quick_sort((void**)(*record).lines, 0, (get_lenght_arrray_struct(record)-1), compare_string_struct);
  end_tests();
  check(record,CHECK_STRING_FIELD);

  puts("\n\t(*) Quick sort (Numb Field)");
  start_tests("\t\t- Test ");
  quick_sort((void**)(*record).lines, 0, (get_lenght_arrray_struct(record)-1), compare_int_struct);
  end_tests();
  check(record,CHECK_NUMB_FIELD);

  puts("\n\t(*) Quick sort (Float Field)");
  start_tests("\t\t- Test ");
  quick_sort((void**)(*record).lines, 0, (get_lenght_arrray_struct(record)-1), compare_float_struct);
  end_tests();
  check(record,CHECK_FLOAT_FIELD);

  clean_resources(record);
}

void check (struct Data_File* record, int options){
  if (options == CHECK_STRING_FIELD)
    for(int i=0; i<(get_lenght_arrray_struct(record)-1); i++) {
      assert(compare_string_struct((void*)(*record).lines[i], (void*)(*record).lines[i+1]) <= 0);
    }
  if (options == CHECK_NUMB_FIELD)
    for(int i=0; i<(get_lenght_arrray_struct(record)-1); i++) {
      assert(compare_int_struct((void*)(*record).lines[i], (void*)(*record).lines[i+1]) <= 0);
    }
  if (options == CHECK_FLOAT_FIELD)
    for(int i=0; i<(get_lenght_arrray_struct(record)-1); i++) {
      assert(compare_float_struct((void*)(*record).lines[i], (void*)(*record).lines[i+1]) <= 0);
    }
}

void clean_resources (struct Data_File* record){
  printf("\n (/) Cleaning resources... ");
  for (int j=0; j<get_lenght_arrray_struct(record); j++)
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

void prepare_test(struct Data_File** record){
  puts("\n(+) Loading data from univer.csv ");
  load_data(record);
}