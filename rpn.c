# include "rpn.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>


int handleOperator(Stack new_stack,int operator){
	int popValue1,popValue2,pushValue;
	popValue1 = (int)((*new_stack.stackTop)->data) ;pop(new_stack);
	popValue2 = (int)((*new_stack.stackTop)->data) ;pop(new_stack);
	if(operator=='/'&&popValue1==0) return 0;
	switch(operator){
		case '+': pushValue = popValue2 + popValue1; break;
		case '-': pushValue = popValue2 - popValue1; break;
		case '*': pushValue = popValue2 * popValue1; break;
		case '/': pushValue = popValue2 / popValue1; break;
		default : printf("Notation is wrong.Give valid notation" );
	}
	return pushValue;
}

int handleDigitsAndPushInStack(char* expression,int i,int k,int * data,Stack new_stack){
	k = (expression[i+1]!=' ' && k==-1) ? i : k;	
	if(expression[i+1]==' ' || i==strlen(expression)-1){ 
		data[i] = (k<0) ? atoi(&expression[i]) : atoi(&expression[k]);
		push(new_stack,(void*)data[i]); k = -1;
	}
	return k;
};

int findWhiteSpace(char *expr,int i){
	int j;char *operators="+-*/)^(' '0123456789";
	for(j=0;j<strlen(operators);j++) if(operators[j]==expr[i]) return 0;
	return 1;
}

int isDigit(char* expression,int i){
	if(expression[i]>='0' && expression[i]<='9') return 1;
	return 0;
}

int isOperator(char *expression,int i){
	int j;char *operators="+-*/)^(";
	for(j=0;j<strlen(operators);j++) if(operators[j]==expression[i]) return 1;
	return 0;
}

Result evaluate(char *expression){
	int i=0,k=-1,pushValue,data[strlen(expression)];
	Stack new_stack = createStack();
	Result result;result.status=0;

	while(expression[i]!='\0'){
		if(findWhiteSpace(expression,i)){result.error=0;return result;}

		if(isDigit(expression,i)){k = handleDigitsAndPushInStack(expression,i,k,data,new_stack);}
			
		if(isOperator(expression,i)){
			if(new_stack.list->count<2){result.error=0;return result;}
			pushValue = handleOperator(new_stack,expression[i]);
			push(new_stack,(void*)pushValue);
		}
		i++;
	}
	result.status = (new_stack.list->count==1)? (int)((*new_stack.stackTop)->data) : 0 ;
	return result;
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// char *expression = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
// char *expected="3 4 2 * 1 5 - 2 3 ^ ^ / +";

int setPrecedenceOfOperator(int operator){
	switch(operator){
		case '(': return  1;
		case ')': return  1;
		case '+': return  2; 
		case '-': return  2;
		case '*': return  3;
		case '/': return  3;
		case '^': return  4;
		default : printf("Notation is wrong.Give valid notation" );
	}
	return 0;
};

int checkPrecedence(int operatorInStack,int operatorInString){
	int precedenceInStack,precedenceInString;
	precedenceInStack = setPrecedenceOfOperator(operatorInStack);
	precedenceInString = setPrecedenceOfOperator(operatorInString);
	if(precedenceInStack>=precedenceInString) return 1;
	return 0;
}

void handleOperatorInStack(int operator,Stack stack,Queue queue){
	int operatorInStack,count,i;
	count = stack.list->count;
	if(count){
		for(i=0;i<count;i++){
			operatorInStack = (char)((*stack.stackTop)->data);
				(checkPrecedence(operatorInStack,operator)) && pop(stack) && 
					insert(queue, (void *)operatorInStack) && insert(queue, (void *)' ');
		}
	}
	(operator!=')') && push(stack,(void*)operator);
}

int handleDigitsInsertInQueue1(char* expression,int i,int k,Queue queue){
	char data = expression[i];
	if(expression[i]==' ' && k==1) return k=0;
	if(k!=1) insert(queue,(void*)data);
	if(expression[i]==' ') k=1;
	return k;
}

void insertOperatorInQueue(Stack stack,Queue queue){
	int i,stackCount = stack.list->count;
	char topOfStack;
	for(i=0;i<stackCount;i++){
		topOfStack = (char)((*stack.stackTop)->data);
		insert(queue, (void *)' ');pop(stack);insert(queue, (void *)topOfStack);
	}
}


char * infixToPostfix(char * expression){
	int i=0,j=0,k=-1,count,brace=0;
	char operator;
	char *result = malloc(sizeof(char)*strlen(expression));
	Stack stack = createStack();
	Queue queue = createQueue();

	while(expression[i]!='\0'){
		if(findWhiteSpace(expression,i)){return 0;}
			
		if(isOperator(expression,i)){ operator = expression[i]; handleOperatorInStack(operator,stack,queue);}

		if(isDigit(expression,i) || expression[i]==32) k = handleDigitsInsertInQueue1(expression,i,k,queue);

		i++;
	};

	insertOperatorInQueue(stack,queue);
	count = queue.list->count;

	for(j=0;j<count;j++){
		result[j] = (char)((*queue.Front)->data); deleteFront(queue);
	}
	return result;
}






































Stack splitExpression(char *expression){
	int i,j=0,k=0,l=0,number=0,length,value[strlen(expression)];
	int number1[strlen(expression)];
	Stack stack = createStack();
	length = strlen(expression);
	for(i=length-1;i>=0;i--){
		if(expression[i]!=32){
			value[j] = expression[i];
			j++; 
		}
		if(expression[i]==32 || i==0){
			for(k=0;k<j;k++){

				if(value[k]>=48 && value[k]<=57){
					number = (number) + (value[k]-48)*(int)pow(10,l);
					l++;
				}

				if(value[k]==43 || value[k]==45 || value[k]==42 || value[k]==47)
					number = value[k];
			}
			number1[i] = number;
			push(stack,&number1[i]);	
			number = 0;j=0,l=0;	
		}
	};
	return stack;
}