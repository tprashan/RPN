// # include "../../LinkedList/-LinkedListADT/linkedList.h"
# include "linkedList.h"

typedef struct stack Stack;

struct stack{
	LinkedList* list;
	node_ptr* stackTop;
};

Stack createStack(void);
int push(Stack stack, void * data);
void * pop(Stack stack);