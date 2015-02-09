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

int isDigit(char* expression,int i);
int isOperatorIncludeBrace(char *expr,int i);

// char * infixToPostfix(char * expression);
// int handleDigitsInsertInQueue(char* expression,int i,int k,int * data,Queue new_queue);
// int handleDigitsInsertInQueue1(char* expression,int i,int k,Queue new_queue);
// void insertOperatorInQueue(Stack stack,Queue queue);

// int setPrecedenceOfOperator(int oper);
// int checkPrecedence(int operatorInStack,int operatorInString);
// void handleBrace(Stack stack,Queue queue,int oper);


//////////////////////////////////////////////////convert infix to postfix///////////////////////////////////////////////////////
void postfixString(char *result,Queue queue,int count);
int handleExpression(char *expression,int i,Stack stack,Queue queue,int k);
void insertOperatorInQueue(Stack stack,Queue queue);
int handleDigitsInsertInQueue(char* expression,int i,int k,Queue queue);
void handleOperatorInStack(int oper,Stack stack,Queue queue);
int checkPrecedence(int operatorInStack,int operatorInString);
void handleBrace(Stack stack,Queue queue,int oper);
int setPrecedenceOfOperator(int oper);
char * infixToPostfix(char * expression);