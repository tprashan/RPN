# include "stackLibrary.h"

typedef struct result Result;

struct result {
  int error;
  int status;
};

typedef struct queue Queue;

struct queue{
	LinkedList* list;
	node_ptr* Front;
	node_ptr* Rear;
};

Queue createQueue(void);
int insert(Queue queue, void * data);
void * deleteFront(Queue queue);



int handleOperator(Stack new_stack,int operators);
int handleDigits(char* expression,int i,int k,int * data,Stack new_stack);
int findWhiteSpace(char *expr,int i);
int isOperator(char *expression,int i);
Result evaluate(char * expression);
char * infixToPostfix(char * expression);
int handleDigitsInsertInQueue(char* expression,int i,int k,int * data,Queue new_queue);
int isOperatorIncludeBrace(char *expr,int i);
