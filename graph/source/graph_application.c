#include "graph_application.h"

int main(int argc, char const *argv[]) {

  struct Data_File* record = NULL;
  struct Graph* graph = NULL;
  
  prepare_test(&record);
  array_to_graph(record,(void**)&graph, NOT_ORIENTED);
  clean_resources_from_file(record);

  strongly_connected_components((void*)graph, NOT_ORIENTED);

  min_path((void*)graph, search_vtx((void*)graph,"torino"));
  printf("\n\t(+)Minimum Distance: %4.2f km\n\n", (get_vtx_w(search_vtx((void*)graph,"catania"))/1000));
  print_path((void*)graph, search_vtx((void*)graph,"torino"), search_vtx((void*)graph,"catania"));
  puts("\n");

  delete_graph((void*)graph);

	printf("(#) Unit_Test Graph: ");
	unit_test_graph();
	printf("Successfully Performed.\n");  

	return 0;
}

void array_to_graph(struct Data_File* record, void** graph, int choice){
	start_tests("\n\t(+) Create Graph: ");
  	int num_records = (*record).num_lines;
  	(*graph) = (struct Graph*)malloc(sizeof(struct Graph));
  	void** vtx_array = (void**)malloc(sizeof(struct Vtx*)*num_records);
  	int num_vtx = 0;
  	int src_index = -1;
  	int dst_index = -1;

  	for (int i = 0; i < num_records; i++){
  		if (!search_vtx_by_string(vtx_array,get_lines_src(record,i),&src_index,num_vtx)){  			
  			vtx_array[num_vtx] = init_vtx();
  			src_index = num_vtx++;	
  			set_vtx_id(vtx_array[src_index],get_lines_src(record,i));
  		}
  		if (!search_vtx_by_string(vtx_array,get_lines_dest(record,i),&dst_index,num_vtx)){  			
  			vtx_array[num_vtx] = init_vtx();
  			dst_index = num_vtx++;
  			set_vtx_id(vtx_array[dst_index],get_lines_dest(record,i));
  		}
  		add_edge_to_list(vtx_array[src_index],vtx_array[dst_index],get_lines_dist(record,i));

  		if (choice == NOT_ORIENTED){
        if (!search_vtx_by_string(vtx_array,get_lines_dest(record,i),&src_index,num_vtx)){  			
  			 vtx_array[num_vtx] = init_vtx();
  			 src_index = num_vtx++;	
  			 set_vtx_id(vtx_array[src_index],get_lines_dest(record,i));
  		  }
  		  if (!search_vtx_by_string(vtx_array,get_lines_src(record,i),&dst_index,num_vtx)){  			
    			vtx_array[num_vtx] = init_vtx();
  			 dst_index = num_vtx++;
  			 set_vtx_id(vtx_array[dst_index],get_lines_src(record,i));
  		  }
      }
  		add_edge_to_list(vtx_array[src_index],vtx_array[dst_index],get_lines_dist(record,i));
  	}

  	set_numvtx_graph(*graph,num_vtx);
  	set_vtxarray_graph(*graph,(struct Vtx**)vtx_array);
	end_tests();
}

void reverse_graph(void* graph, void** t_graph){
	start_tests("\n\t(+) Reverse Graph: ");
	(*t_graph) = (struct Graph*)malloc(sizeof(struct Graph));
  	void** vtx_array_t = (void**)malloc(sizeof(struct Vtx*)*(*(struct Graph*)graph).num_vtx);
  	int num_vtx = 0;
  	struct Node* vtx_src = NULL;
  	char* tmp_string = NULL;
  	int src_index = -1;
  	int dst_index = -1;

  	for (int i = 0; i < (*(struct Graph*)graph).num_vtx; i++){
  		vtx_src = get_first(get_vtx_adj_list((*(struct Graph*)graph).vtx_array[i]));
  		for(vtx_src; vtx_src !=NULL; vtx_src = get_next(vtx_src)){
  			tmp_string = get_vtx_id(get_cargo(get_vtx_edge(vtx_src)));
	  		if (!search_vtx_by_string(vtx_array_t,tmp_string,&src_index,num_vtx)){  			
	  			src_index = num_vtx++;
	  			vtx_array_t[src_index] = init_vtx();
	  			set_vtx_id(vtx_array_t[src_index],tmp_string);
	  		}
	  		tmp_string = get_vtx_id((*(struct Graph*)graph).vtx_array[i]);
	  		if (!search_vtx_by_string(vtx_array_t,tmp_string,&dst_index,num_vtx)){  			
	  			dst_index = num_vtx++;
	  			vtx_array_t[dst_index] = init_vtx();
	  			set_vtx_id(vtx_array_t[dst_index],tmp_string);
	  		}
  			add_edge_to_list(vtx_array_t[src_index],vtx_array_t[dst_index],get_dist_edge(get_cargo(vtx_src)));
  		}
  	}

  	set_numvtx_graph(*t_graph,get_numvtx_graph(graph));
  	set_vtxarray_graph(*t_graph,(struct Vtx**)vtx_array_t);
  	end_tests();
}

void strongly_connected_components(void* g, int choice){
	printf("\n\t(+) Finding Strongly Connected Components: ");
	struct Graph* t_graph = NULL;
	void* vtx = NULL;

  struct Node* iterator = NULL;
  struct List* cfc = (make_empty());

  if (choice == NOT_ORIENTED){
    start_tests("");
    cfc = (struct List*)cfc_non_oriented(g);
  } else {
      struct Node* l = (get_first(topological_sort(g)));
      struct List* tree_cfc = NULL;
      reverse_graph(g, (void**)&t_graph);
    	start_tests("");
    	init_dfs((void*)t_graph);
    	timer = 0;
    	for(l; get_next(l) != NULL; l = get_next(l)){
    		vtx = search_vtx((void*)t_graph, get_vtx_id(get_cargo(l)));
    		if (get_vtx_color(vtx) == WHITE){
    			tree_cfc = make_empty();
    			dfs_cfc(t_graph,(vtx),tree_cfc);
    			add(STACK,cfc,tree_cfc);
    		}
    	}
  }

	printf("\n\t\tThere are %d connected components:\n",get_num_node(cfc));
	iterator = get_first(cfc);
	while(iterator != NULL){
		printf("\t\t\tThis cfc have %d elements\n",get_num_node(get_cargo(iterator)));
		//print_list_ric(get_first(get_cargo(iterator)),1);
		//printf(" EndList\n\n");
		iterator = get_next(iterator);
	}
	printf("\n\t(-)");
	end_tests();
}

void min_path(void* g, void*s){
	start_tests("\n\t(+) Searching min path: ");
	initializa_single_source(g,s);
	dijkstra(g);
	end_tests();
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
  start_tests("\n(+) Loading data from file: ");
  load_data(record);
  end_tests();
}

void delete_graph(void* graph){
  struct vtx** vtx_array = NULL;
  struct Node* iterator = NULL;

  vtx_array = (struct vtx**)get_vtxarray_graph(graph);
  for (int i = 0; i < (*(struct Graph*)graph).num_vtx; i++){
    iterator = get_first(get_vtx_adj_list(vtx_array[i]));
    while(iterator != NULL){
      delete_node(vtx_array[i],get_vtx_adj_list(get_cargo(iterator)));
      iterator = get_next(iterator);
    }
    free(vtx_array[i]);
  }
  free(graph);
}