#include "common.h"

//VTX
void* init_vtx(){
	struct Vtx* new_vtx = (struct Vtx*)malloc(sizeof(struct Vtx));
	strcpy((*new_vtx).id, "null");
	(*new_vtx).w = INF;
	(*new_vtx).adj_list = make_empty();
	(*new_vtx).color = 0;
	(*new_vtx).parent = NULL;
	(*new_vtx).discovered_time = INIT_TIME;
	(*new_vtx).f_time = INIT_TIME;
	(*new_vtx).grade = 0;
	return new_vtx;
}

int search_vtx_by_string(void** graph,char* string, int* index,int num_vtx){
	int bool = 1;
	for(int i = 0; i < num_vtx && bool ; i++){
		if (!strcmp((char*)(get_vtx_id(graph[i])),string) ) {
			*index = i;
			bool = 0;
		}
	}
	return !bool;
}

void set_vtx_parent(void* vertix, void* prt){
	(*(struct Vtx*)vertix).parent = (struct Vtx*)prt;
}

void* get_vtx_parent (void* vertix){
	return (*(struct Vtx*)vertix).parent;
}	

void set_vtx_d_time(void* vertix, long int t){
	(*(struct Vtx*)vertix).discovered_time = t;
}

long int get_vtx_d_time(void* vertix){
	return (*(struct Vtx*)vertix).discovered_time;
}

void set_vtx_f_time(void* vertix, long int t){
	(*(struct Vtx*)vertix).f_time = t;
}

long int get_vtx_f_time(void* vertix){
	return (*(struct Vtx*)vertix).f_time;
}	

void set_vtx_color(void* vertix, long int c){
	(*(struct Vtx*)vertix).color = c;
}

long int get_vtx_color(void* vertix){
	return (*(struct Vtx*)vertix).color;
}

void set_vtx_w(void* vertix, float w){
	(*(struct Vtx*)vertix).w = w;
}

float get_vtx_w(void* vertix){
	return (*(struct Vtx*)vertix).w;
}

void set_vtx_adj_list(void* vertix, void* list){
	(*(struct Vtx*)vertix).adj_list = (struct List*)list;
}

void* get_vtx_adj_list(void* vertix){
	return (*(struct Vtx*)vertix).adj_list;
}

void dec_vtx_grade(void* vertix){
	(*(struct Vtx*)vertix).grade--;
}

void inc_vtx_grade(void* vertix){
	(*(struct Vtx*)vertix).grade++;
}

void set_vtx_grade(void* vertix,long int n){
	(*(struct Vtx*)vertix).grade = n;
}

long int get_vtx_grade(void* vertix){
	return (*(struct Vtx*)vertix).grade;
}

void set_vtx_id(void* vertix, void* id){
	strcpy((*(struct Vtx*)vertix).id, (char*)id);
}

void* get_vtx_id(void* vertix){
	return (*(struct Vtx*)vertix).id;
}

void print_vtx(char* msg, void* vtx, char* msg_2){
	printf("%s %s %s", msg, (char*)get_vtx_id(vtx), msg_2);
}

struct Vtx* search_vtx(void* g, char*id){
	struct Vtx** vtx_array = (get_vtxarray_graph(g));
	for(int i =0; i < get_numvtx_graph(g); i++){
		if (!strcmp(get_vtx_id(vtx_array[i]),id))
			return vtx_array[i];
	}
	puts("search vtx = null");
	return NULL;
}


//ARCHI
void* make_edge(void* vertix, float dist){
	struct Edge* new_edge = (struct Edge*)malloc(sizeof(struct Edge));
	(*new_edge).vtx_edge = (struct Vtx*)vertix;
	(*new_edge).dist = dist;
	(*new_edge).next = NULL;
	return new_edge;
}

void add_edge_to_list(void* vtx_target,void* vtx_list,float dist){
	void* edge = make_edge(vtx_list,dist);
	add(STACK,get_vtx_adj_list(vtx_target),edge);
	inc_vtx_grade(vtx_target);
}

void* get_vtx_edge(void* this){
	return (*(struct Edge*)this).vtx_edge;
}

float get_dist_edge(void* this){
	return (*(struct Edge*)this).dist;
}

void set_vtx_edge(void* this,void* vertix){
	if (this != NULL)
		(*(struct Edge*)this).vtx_edge = (struct Vtx*)vertix;
}



//LIST
void print_list(void* l){
	if (not_empty(l)){
		printf("Adj_List (%d elements): ",get_num_node(l));
		print_list_ric(get_first(l),EDGE_LIST);
		printf(" EndList\n");
	} else
		puts("List Null");
}

void print_list_ric(void* n,int choice){ 
	if (choice == VTX_LIST){	
		print_vtx("",get_cargo(n)," -> "); 
	}
	if (choice == EDGE_LIST){
		printf("(D:%4.5f)",get_dist_edge(get_cargo(n)));
		print_vtx("",get_vtx_edge(get_cargo(n))," -> "); 
	}
	if (get_next(n) != NULL)
		print_list_ric(get_next(n),choice);
}

//PATH
int check_path(void* s, void* u){
	int ret = 1;
	if (u == s){		
		printf("Source and dest are the same vtx\n");
		print_vtx("src = dst =",u,"\n");
		return 0;
	}
	if (get_vtx_parent(u) == NULL){
		printf("No path from %s to %s \n",(char*)get_vtx_id(s),(char*)get_vtx_id(u));
		return 0;		
	}
	return ret;
}
	

//HEAP
void* make_priority_queue(void* g){
	struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
  	struct Vtx** vtx_heap = (struct Vtx**)malloc(sizeof(struct Vtx*)*get_numvtx_graph(g));
  	struct Vtx** vtx_graph = (struct Vtx**)(get_vtxarray_graph(g));
	for (int i = 1; i <= get_numvtx_graph(g); i++)
		vtx_heap[i] = vtx_graph[i-1];
	(*heap).array = vtx_heap;
	(*heap).heap_size = (get_numvtx_graph(g));
	return heap;
}

void* extract_min(void* heap){
	void** array = (void**)get_heap_array(heap);
	if (get_heap_size(heap) < 1)
		return NULL;
	void* min = array[1];
	array[1] = array[get_heap_size(heap)];
	dec_heap_size(heap);
	heapify((void**)get_heap_array(heap),1,get_heap_size(heap));

	return min;
}

void sort_heap(void* heap){
	int temp_size = get_heap_size(heap);

	for (int i = temp_size/2; i >= 1; i--)
		heapify((void**)get_heap_array(heap),i,temp_size);
}
   
void heapify(void** array, int index, int heap_size){
	int left = index*2;
	int right = (index*2)+1;
	int largest = 0;

	if (left <= heap_size && compare(array[left], array[index]) < 0 ) 
		largest = left;
	else
		largest = index;

	if (right <= heap_size && compare(array[right], array[largest]) < 0 ) 
		largest = right;

	if (largest != index){
		swap(&array[index], &array[largest]);
		heapify(array, largest, heap_size);
	}
}

int heap_not_empty(void* heap){
	return get_heap_size(heap);
}

struct Vtx** get_heap_array(void* heap){
	return (*((struct Heap*)heap)).array;
}

int get_heap_size(void* heap){
	return (*((struct Heap*)heap)).heap_size;	
}

void dec_heap_size(void* heap){
	(*((struct Heap*)heap)).heap_size--;	
}

int compare(void* ptr1, void* ptr2) {
  float i1 =  get_vtx_w(ptr1);
  float i2 =  get_vtx_w(ptr2);

  if (i1 < i2) return -1;
  if (i1 == i2) return 0;
  return 1;
}

void swap(void** e1, void** e2) {
  void* tmp = *e1;
  *e1 = *e2;
  *e2 = tmp;
}

//GRAPH
struct Vtx** get_vtxarray_graph(void* graph){
	return (*(struct Graph*)graph).vtx_array;
}

int get_numvtx_graph(void* graph){
	return (*(struct Graph*)graph).num_vtx;	
}

void set_numvtx_graph(void* graph, int num_vtx){
	(*(struct Graph*)graph).num_vtx = num_vtx;
}

void set_vtxarray_graph(void* graph, struct Vtx** vtx_array){
	(*(struct Graph*)graph).vtx_array = vtx_array;
}


//FILE
int get_lenght_arrray_struct(struct Data_File* record){
  return (*record).num_lines;
}

char* get_lines_src(struct Data_File* record, int index){
	return (*(*record).lines[index]).src;
}

char* get_lines_dest(struct Data_File* record, int index){
	return (*(*record).lines[index]).dst;
}

float get_lines_dist(struct Data_File* record, int index){
	return (*(*record).lines[index]).dist;	
}

void clean_resources_from_file (struct Data_File* record){
  for (int j=0; j<get_lenght_arrray_struct(record); j++)
    free((*record).lines[j]);
  free((*record).lines);
  free(record);
}