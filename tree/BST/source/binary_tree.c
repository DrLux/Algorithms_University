#include "binary_tree.h"

void insert(void* T, void* new_node, CompFunction compare) {
	void* y = NULL;
	void* x = get_root(T);
	while ( x != NULL){
		y = x;
		if (compare(new_node,x) == 0){
			y = get_parent(x);
			replace_node(new_node,x);
			x = NULL;
		} else if (compare(new_node,x) < 0)
			x = get_left(x);
				else
					x = get_right(x);
	}
	set_parent(new_node,y);
	if ( y == NULL)
		set_root(T,new_node);
	else if (compare(new_node,y) < 0)
			set_left(y,new_node);
		else
			set_right(y,new_node);
}

void inorder_print_tree(void* node) {
	if (node != NULL){
		inorder_print_tree(get_left(node));
		print_node(node);
		inorder_print_tree(get_right(node));
	}
}

void* iterative_tree_search(void* node, void* key, CompFunction compare){
	while (node != NULL && (compare(key,node) < 0 || (compare(key,node) > 0)))
		if (compare(key,node) < 0)
			node = get_left(node);
		else
			node = get_right(node);
	return node;
}

void* tree_min(void* node){
	while (get_left(node) != NULL)
		node = get_left(node);
	return node;
}

void* tree_max(void* node){
	while (get_right(node) != NULL)
		node = get_right(node);
	return node;
}

void* tree_successor(void* node){
	if (node == NULL) return NULL;
	if ( get_right(node) != NULL)
		return tree_min( get_right(node));
	void* y = get_parent(node);
	while ( y != NULL && node == get_right(y)){
		node = y;
		y = get_parent(y);
	}
	return y;
}

void* tree_delete(void* T, void* target_node){
	void* x;
	void* y;

	if(target_node == NULL)
		return target_node;

	if (get_left(target_node) == NULL || get_right(target_node) == NULL)
		y = target_node;
	else
		y = tree_successor(target_node);

	if (get_left(y) != NULL)
		x = get_left(y);
	else
		x = get_right(y);

	if (x != NULL)
		set_parent(x,get_parent(y));

	if (get_parent(y) == NULL)
		set_root(T, x);
	else if (y == get_left(get_parent(y)))
			set_left(get_parent(y), x);
		 else 
		 	set_right(get_parent(y), x);

	if ( y != target_node){
		set_key(target_node, get_key(y));
		set_value(target_node, get_value(y));
	}
return y;
}
