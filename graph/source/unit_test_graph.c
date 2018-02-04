#include "unit_test_graph.h"

void unit_test_graph(){
  unit_test_cfc();
  unit_test_dijkstra();
}

void unit_test_dijkstra(){
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    void** vtx = (void**)malloc(sizeof(struct Vtx*)*5);

    for (int y = 0; y < 5; y++)
      vtx[y] = init_vtx();

    set_vtx_id(vtx[0],"S");
    set_vtx_id(vtx[1],"U");
    set_vtx_id(vtx[2],"X");
    set_vtx_id(vtx[3],"V");
    set_vtx_id(vtx[4],"Y");
    

    add_edge_to_list(vtx[0],vtx[1],10);
    add_edge_to_list(vtx[0],vtx[2],5);
    add_edge_to_list(vtx[1],vtx[2],2);
    add_edge_to_list(vtx[1],vtx[3],1);
    add_edge_to_list(vtx[2],vtx[1],3);
    add_edge_to_list(vtx[2],vtx[4],2);
    add_edge_to_list(vtx[2],vtx[3],9);
    add_edge_to_list(vtx[3],vtx[4],4);
    add_edge_to_list(vtx[4],vtx[0],7);
    add_edge_to_list(vtx[4],vtx[3],6);
  
    (*g).num_vtx = 5;
    (*g).vtx_array = (struct Vtx**)vtx;
    
    initializa_single_source((void*)g, search_vtx((void*)g,"S"));
    dijkstra((void*)g);

    assert(get_vtx_w(search_vtx((void*)g,"S")) == 0);
    assert(get_vtx_w(search_vtx((void*)g,"X")) == 5);
    assert(get_vtx_w(search_vtx((void*)g,"U")) == 8);
    assert(get_vtx_w(search_vtx((void*)g,"V")) == 9);
    assert(get_vtx_w(search_vtx((void*)g,"Y")) == 7);
    
    for (int y = 0; y < 5; y++)
      free(vtx[y]);
    free(g);
}

void unit_test_cfc(){
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    void** vtx = (void**)malloc(sizeof(struct Vtx*)*8);

    for (int y = 0; y < 8; y++)
      vtx[y] = init_vtx();

    set_vtx_id(vtx[0],"A");
    set_vtx_id(vtx[1],"B");
    set_vtx_id(vtx[2],"C");
    set_vtx_id(vtx[3],"D");
    set_vtx_id(vtx[4],"E");
    set_vtx_id(vtx[5],"F");
    set_vtx_id(vtx[6],"G");
    set_vtx_id(vtx[7],"H");
    
    add_edge_to_list(vtx[0],vtx[4],1);
    add_edge_to_list(vtx[4],vtx[0],1);
    add_edge_to_list(vtx[3],vtx[3],1);
    add_edge_to_list(vtx[1],vtx[2],1);
    add_edge_to_list(vtx[2],vtx[1],1);
    add_edge_to_list(vtx[6],vtx[7],1);
    add_edge_to_list(vtx[2],vtx[6],1);
    add_edge_to_list(vtx[6],vtx[2],1);
    add_edge_to_list(vtx[6],vtx[5],1);
    add_edge_to_list(vtx[5],vtx[7],1);
    add_edge_to_list(vtx[5],vtx[6],1);
    add_edge_to_list(vtx[5],vtx[1],1);
    add_edge_to_list(vtx[1],vtx[5],1);
    add_edge_to_list(vtx[7],vtx[5],1);
    add_edge_to_list(vtx[7],vtx[6],1);

    (*g).num_vtx = 8;
    (*g).vtx_array = (struct Vtx**)vtx;

    struct Node* l = (get_first(topological_sort(g)));

    struct List* cfc = (make_empty());
    struct List* tree_cfc = NULL;
    struct Node* iterator = NULL;
    void* tmp = NULL;
  
    init_dfs((void*)g);
    for(l; get_next(l) != NULL; l = get_next(l)){
        tmp = search_vtx((void*)g, get_vtx_id(get_cargo(l)));
        if (get_vtx_color(tmp) == WHITE){
            tree_cfc = make_empty();
            dfs_cfc(g,(tmp),tree_cfc);
            add(STACK,cfc,tree_cfc);
        }
    }

    assert(get_num_node(cfc) == 3);
    iterator = get_first(cfc);
    assert(get_num_node(get_cargo(iterator)) == 2);
    iterator = get_next(iterator);
    assert(get_num_node(get_cargo(iterator)) == 5);
    iterator = get_next(iterator);
    assert(get_num_node(get_cargo(iterator)) == 1);
    

    for (int y = 0; y < 8; y++)
      free(vtx[y]);
    free(g);
}