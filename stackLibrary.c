# include "stackLibrary.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

Stack createStack(void){
	LinkedList *  list= calloc(sizeof(LinkedList),1);
	Stack new_stack;
	new_stack.list = list;
	new_stack.stackTop = &list->tail;
	return new_stack;
};

int push(Stack stack, void * data){
	int pass;
	LinkedList* list = stack.list;
	node_ptr node = create_node(data);
	pass = add_to_list(list,node);
	return (pass)?stack.list->count:-1;
};

void * pop(Stack stack){
	void* deletedAddress;
	LinkedList* list = stack.list;
	deletedAddress = deleteElementAt(list,stack.list->count-1);
	return deletedAddress;
};
