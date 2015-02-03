# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "linkedList.h"

LinkedList createList(){
	LinkedList *new_list = calloc(sizeof(LinkedList),1);
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->count = 0;
	return *new_list;
};

Node * create_node(void *data){
	Node * new_node = malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
};

int add_to_list(LinkedList *list ,Node * node){
	if(list->head==NULL)
		list->head=node;
	else
		list->tail->next = node;
	list->tail=node;
	list->count++;
	return list->count;
};

void *get_first_element(LinkedList list){
	return list.head;
};

void *get_last_element(LinkedList list){
	return list.tail;
};

void traverse(LinkedList list, traverseFunction add){
	while(list.head!=NULL){
		add(&(list.head->data));
		list.head = list.head->next;
	}
};

void * getElementAt(LinkedList list, int index){
	int i= 0;
	if(list.count<index || index<0)
		return NULL;
	while(i<=index){
		if(i==index)
			return list.head->data;
		list.head = list.head->next;
		i++;
	}
	return NULL;
};

int indexOf(LinkedList list, void * element){
	int i= 0;
	while(i<list.count){
		if(list.head->data == element)
			return i;
		i++;
		list.head = list.head->next;
	}
	return -1;
};

void * deleteElementAt(LinkedList * list, int index){
	int i= 0;
	node_ptr listHead =list->head;
	node_ptr prevAddress=NULL;
	void* data;

	if(list->count<=index || index<0)
		return NULL;

	while(i<index){
		prevAddress = listHead;
		listHead = listHead->next;
		i++;
	}
	
	if(list->tail==listHead){
		list->tail=prevAddress;
	}
	data= listHead->data;
	prevAddress?(prevAddress->next =listHead->next):(list->head =list->head->next);

	list->count--;
	free(listHead);
	return data;
};

int asArray(LinkedList list, void ** array){
	int i=0;
	for(i=0;i<list.count;i++){
		array[i] = list.head;
		list.head = list.head->next;
	}
	return i;
};

LinkedList * filter(LinkedList list, filterFunction* isEven){
	int data;
	LinkedList* filterList = malloc(sizeof(LinkedList));
	*filterList = createList();

	while(list.head!=NULL){
		data = isEven(list.head->data);
		if(data==1){
			add_to_list(filterList,list.head);
		}
		list.head = list.head->next;
	}
	return filterList;
};
