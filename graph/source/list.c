#include "list.h"

void* make_empty(){
	struct List* new_list = NULL;
	new_list = (struct List*)malloc(sizeof(struct List));
	(*new_list).sentinel = create_node(NULL);
	(*new_list).num_nodi = 0;
	return new_list;
}

void* create_node(void* ptr){
	struct Node* new_node = NULL;
	new_node = (struct Node*)malloc(sizeof(struct Node));
	(*new_node).next = NULL;
	(*new_node).cargo = ptr;
	return new_node;
}


void insert_first(void* l, void* n){
	set_next(n,get_first(l));
	set_first(l,n);
}

void remove_first(void* l){
	if (not_empty(l)){
		void* temp = get_first(l);
		set_first(l,get_next(temp));
		free(temp);
	}
}

void insert_last(void* l, void* n){
	if (not_empty(l))
        set_next(get_last(l), n);
	else 
		set_first(l,n);
}

int not_empty(void* l){
	return get_first(l) != NULL;
}

void* get_last(void* l){
	if (not_empty(l))
		return get_last_ric(get_first(l));
	else
		return NULL;
}

void* get_last_ric(void* n){
	if (get_next(n) == NULL)
		return n;
	else
		return get_last_ric(get_next(n));
}

void* get_first(void* list){
	return get_next(get_sentinel(list));
}

void* get_sentinel(void* list){
	return (*(struct List*)list).sentinel;	
}

void set_first(void* list,void* head){
	set_next(get_sentinel(list), head);
}

void* get_next(void* this){
	return (*(struct Node*)this).next;
}
void set_next(void* this,void* next){
	if (this != NULL)
		(*(struct Node*)this).next = (struct Node*)next;
}

void clean_list(void* stack){
	while(get_first(stack) != NULL)
		remove_first(stack);
}

void add(int choice,void* l, void* n){
	inc_num_node(l);
	if (choice == STACK) 
		insert_first(l,create_node(n));
	else
		insert_last(l,create_node(n));
}

void* get_cargo(void* node){
	return (*(struct Node*)node).cargo;
}

short int get_num_node(void* list){
	return (*(struct List*)list).num_nodi;
}

void inc_num_node(void* list){
	(*(struct List*)list).num_nodi +=1;
}

void delete_node(void* target, void* list){
	if (list != NULL){
		if (get_first(list) == target)
			set_first(list,get_next(get_first(list)));
		else
			delete_node_ric(target,get_first(list));
	}
}

void delete_node_ric(void* target, void* node){
	if (node != NULL){
		if (get_next(node) == target)
			set_next(node, get_next(get_next(node)));
		else
			delete_node_ric(target,get_next(node));
	}
}