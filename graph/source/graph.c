#include "graph.h"
long int timer;


//VISITA IN AMPIEZZA

void bfs(void* g){
	struct Vtx** vtx_array = (get_vtxarray_graph(g));
	for(int i =0; i < get_numvtx_graph(g); i++){
		set_vtx_color(vtx_array[i],WHITE);
		set_vtx_parent(vtx_array[i],NULL);
		set_vtx_d_time(vtx_array[i], INIT_TIME);
	}
	bfs_visit(g,(void*)vtx_array[0]);
}	

void bfs_visit(void* g, void* s){
	void* l;
	void* u;
	void* v;
	void* white_hunter;

	l = make_empty();
	set_vtx_color(s, 1);
	set_vtx_d_time(s,0);
	add(QUEUE,l,s);
	while (not_empty(l)){
		u = get_cargo(get_first(l));
		white_hunter = get_first(get_vtx_adj_list(u));
		while (white_hunter != NULL){
			v = get_vtx_edge(get_cargo(white_hunter));
			if (get_vtx_color(v) == 0){
				set_vtx_color(v, 1);
				set_vtx_parent(v,u);
				set_vtx_d_time(v, get_vtx_d_time(u)+1);
				add(QUEUE,l,v);
			}
			white_hunter = get_next(white_hunter);
		}
		set_vtx_color(u, 2);
		remove_first(l);
	}
}


//VISITE IN PROFONDITA	

void init_dfs(void* g){
	struct Vtx** vtx_array = (get_vtxarray_graph(g));
	for(int i =0; i < get_numvtx_graph(g); i++){
		set_vtx_color(vtx_array[i],WHITE);
		set_vtx_parent(vtx_array[i],NULL);
		set_vtx_d_time(vtx_array[i], INIT_TIME);
		set_vtx_f_time(vtx_array[i], INIT_TIME);
	}
}

void full_dfs(void* g){
	init_dfs(g);
	long int timer = 0;
	struct Vtx** vtx_array = (get_vtxarray_graph(g));
	for(int i =0; i < get_numvtx_graph(g); i++)
		if (get_vtx_color(vtx_array[i]) == WHITE)
			dfs_visit(g,(void*)vtx_array[i]);
}

void dfs_visit(void* g, void* s){	
	void* white_hunter;
	void* v;
	set_vtx_color(s, GRAY);
	set_vtx_d_time(s,timer);
	timer+=1;
	white_hunter = get_first(get_vtx_adj_list(s));
	while (white_hunter != NULL){
		v = get_vtx_edge(get_cargo(white_hunter));
		if (get_vtx_color(v) == WHITE){
			set_vtx_parent(v, s);
			dfs_visit(g, v);
		}
	white_hunter = get_next(white_hunter);
	}
	set_vtx_f_time(s,timer);
	timer+=1;
	set_vtx_color(s, BLACK);
}

void dfs_cfc(void* g, void* s,void* l){	
	void* white_hunter;
	void* v;
	set_vtx_color(s, GRAY);
	set_vtx_d_time(s,timer);
	white_hunter = get_first(get_vtx_adj_list(s));
	while (white_hunter != NULL){
		v = get_vtx_edge(get_cargo(white_hunter));
		if (get_vtx_color(v) == WHITE){
			set_vtx_parent(v, s);
			dfs_cfc(g,v,l);
		}
	white_hunter = get_next(white_hunter);
	}
	set_vtx_f_time(s,timer);
	timer+=1;
	set_vtx_color(s, BLACK);
	add(STACK,l,s);
}

struct List* topological_sort(void* g){
	void* topo_list = make_empty();
	init_dfs(g);
	long int timer = 0;
	struct Vtx** vtx_array = (get_vtxarray_graph(g));
	for(int i =0; i < get_numvtx_graph(g); i++){
		if (get_vtx_color(vtx_array[i]) == WHITE)
			dfs_topological(g,(void*)vtx_array[i],topo_list);
	}
	return topo_list;
}

void dfs_topological(void* g, void* s,void* l){
	void* white_hunter;
	void* v;
	set_vtx_color(s, GRAY);
	set_vtx_d_time(s,timer);
	timer+=1;
	white_hunter = get_first(get_vtx_adj_list(s));
	while (white_hunter != NULL){
		v = get_vtx_edge(get_cargo(white_hunter));
		if (get_vtx_color(v) == WHITE){
			set_vtx_parent(v, s);
			dfs_topological(g, v, l);
		}
	white_hunter = get_next(white_hunter);
	}
	set_vtx_f_time(s,timer);
	timer+=1;
	set_vtx_color(s, BLACK);
	add(STACK,l,s);
}

void* cfc_non_oriented(void* g){

  struct Node* iterator = NULL;
  struct List* tree_cfc = NULL;
  struct List* cfc = (make_empty());
  
  init_dfs(g);
  long int timer = 0;
  struct Vtx** vtx_array = (get_vtxarray_graph(g));
  for(int i =0; i < get_numvtx_graph(g); i++){
    if (get_vtx_color(vtx_array[i]) == WHITE){
      tree_cfc = make_empty();
      dfs_cfc(g,(void*)vtx_array[i],tree_cfc);
      add(STACK,cfc,tree_cfc);
    }
  }
  return cfc;
}

//CAMMINI MINIMI

void initializa_single_source(void* g, void* s){
	struct Vtx** vtx_array = (get_vtxarray_graph(g));
	for(int i =0; i < get_numvtx_graph(g); i++){
		set_vtx_parent(vtx_array[i],NULL);
		set_vtx_w(vtx_array[i],INF);
	}
	set_vtx_w(s,0);
	swap((void*)&vtx_array[0],(void*)&s);
}

void dijkstra(void* g){
	void* u = NULL;//vtx
	void* iter = NULL;
	void* e = NULL;//edge from adjlist
	void* q = make_priority_queue(g);
	while (heap_not_empty(q)){
		u = extract_min(q);
		iter = get_first(get_vtx_adj_list(u));
		while (iter != NULL){
			e = (get_cargo(iter));
			relax(u,get_vtx_edge(e),get_dist_edge(e),q);
			iter = get_next(iter);
		}

	}
}

void relax(void* u, void* v, float w,void* q){
	if (get_vtx_w(v) > (get_vtx_w(u)+ w)){
		set_vtx_w(v,(get_vtx_w(u)+ w));
		set_vtx_parent(v,u);
		sort_heap(q);
	}
}


//STAMPA GRAFO E PATH

void print_graph(int real_size, void** graph){
	for (int y = 0; y < real_size; y++){
		printf("%d)", y+1);
		print_vtx("Vertice:",graph[y],": ");
		printf("Colore: %ld | Peso:%ld \n",get_vtx_color(graph[y]),get_vtx_grade(graph[y]));
		print_list(get_vtx_adj_list(graph[y]));
		printf("\n");
	}
}

void print_path(void* g, void* s, void* u){
	if (check_path(s,u)){
		print_vtx("Source Node: (",s,")");	
		print_path_ric(g,s,u);
	}

}

void print_path_ric(void* g, void* s, void* u){
	if (u != s){
		print_path_ric(g, s, get_vtx_parent(u));
		print_vtx(" -> ",u,"");
	}
}
