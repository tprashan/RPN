# include "queue.h"
# include <stdio.h>
# include <stdlib.h>

Queue createQueue(void){
	LinkedList *  list= calloc(sizeof(LinkedList),1);
	Queue new_queue;
	new_queue.list = list;
	new_queue.Front = &list->head;
	new_queue.Rear = &list->tail;
	return new_queue;
};

int insert(Queue queue, void * data){
	int pass;
	LinkedList* list = queue.list;
	node_ptr node = create_node(data);
	pass = add_to_list(list,node);
	return (pass)?queue.list->count:-1;
};

void * deleteFront(Queue queue){
	void* deletedAddress;
	LinkedList* list = queue.list;
	deletedAddress = deleteElementAt(list,0);
	return deletedAddress;
};