typedef struct node Node;
typedef struct node * node_ptr;
typedef struct linked_list LinkedList;
typedef void traverseFunction (void *);
typedef int filterFunction (void *);

struct node{
	void* data;
	node_ptr next;
};


struct linked_list{
	node_ptr head;
	node_ptr tail;
	int count;
};

typedef struct student{
	int id;
	int eng_score;
    char* name;
	
}Student;

LinkedList createList(void);
Node * create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList, void (*)(void *data));
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList list, void ** array);
LinkedList * filter(LinkedList, int (*)(void *)); 