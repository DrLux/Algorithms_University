#include "read_from_file.h"

void load_data(struct Data_File** record) {
  char* all_data;
  if (file_get_data(&all_data)){
 	parse_data(all_data, record);
   	free(all_data);
  } else {
  	printf("[Errore] Error during loading data from univer.csv\n");
  }
}

int file_get_data(char** all_data){
	int result = 0;
	FILE* fp = fopen(FILENAME_CSV, "r");
	if (fp){
		size_t filesize = file_len(fp);
		*all_data = (char*) malloc(sizeof(char)*filesize+1);
		fread(*all_data, filesize, 1, fp);
		fclose(fp);
		(*all_data)[filesize] = '\0';
		result = 1;
	}
	return result;
}

size_t file_len(FILE *fp){
    size_t fileSize = -1;
    if (fp){
        fseek(fp, 0, SEEK_END); 
        fileSize = ftell(fp); // ritorna la distanza dall'inizio
        fseek(fp, 0, SEEK_SET); // torna all'inizio
    }
    return fileSize;
}

void parse_data(char* all_data, struct Data_File** full_file){
  	int dim_array = count_line(all_data);
  	struct Records** array_records = (struct Records**) malloc (dim_array*sizeof(struct Records*));
	int i;
	
	for (i = 0; i < dim_array; i++){
		char* line = strsep(&all_data, "\n");
		if (*line){
			array_records[i] = (struct Records*) malloc(sizeof(struct Records)); 

			(*array_records[i]).id = atoi(strsep(&line, ","));
			strcpy((*array_records[i]).string_field, strsep(&line, ","));
	        (*array_records[i]).numb_field = atoi(strsep(&line, ",")); 
	        (*array_records[i]).float_field = atof(strsep(&line, "\n"));	        
		}
		free(line);
	}

	*full_file = (struct Data_File*) malloc(sizeof(struct Data_File));
	(*full_file)->num_lines = dim_array;
	(*full_file)->lines = array_records;
}

int count_line(char *dataPointer){
	int counter = 1;
	while(*dataPointer){
		if (*dataPointer++ == '\n')
			counter++;
	}
	return counter;
}