# include "rpn.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int addOperand(Stack new_stack){
	void *popAddress1,*popAddress2;
	int  pushAddress;
	popAddress1 = ((*new_stack.stackTop)->data) ;
	pop(new_stack);
	popAddress2 = ((*new_stack.stackTop)->data) ;
	pop(new_stack);
	pushAddress = *(int*)popAddress2 + *(int*)popAddress1;
	return pushAddress;
};

int subtractOperand(Stack new_stack){
	void *popAddress1,*popAddress2;
	int  pushAddress;
	popAddress1 = ((*new_stack.stackTop)->data) ;
	pop(new_stack);
	popAddress2 = ((*new_stack.stackTop)->data) ;
	pop(new_stack);
	pushAddress = *(int*)popAddress2 - *(int*)popAddress1;
	return pushAddress;
};

int multiplyOperand(Stack new_stack){
	void *popAddress1,*popAddress2;
	int  pushAddress;
	popAddress1 = ((*new_stack.stackTop)->data) ;
	pop(new_stack);
	popAddress2 = ((*new_stack.stackTop)->data) ;
	pop(new_stack);
	pushAddress = *(int*)popAddress2 * *(int*)popAddress1;
	return pushAddress;
};

int devideOperand(Stack new_stack){
	void *popAddress1,*popAddress2;
	int  pushAddress;
	popAddress1 = ((*new_stack.stackTop)->data) ;
	pop(new_stack);
	popAddress2 = ((*new_stack.stackTop)->data) ;
	pop(new_stack);
	pushAddress = *(int*)popAddress2 / *(int*)popAddress1;
	return pushAddress;
};


int evaluate(char *expression){
	int i=0;
	int  pushAddress;
	int data[strlen(expression)];
	Stack new_stack = createStack();
	while(expression[i]!='\0'){
		if(expression[i]>=48 && expression[i]<=57){
			data[i] = ((int)expression[i]-48);
			push(new_stack,&data[i] );
		}
		if(expression[i]==43){
			pushAddress = addOperand(new_stack);
			push(new_stack,&pushAddress);
		}
		if(expression[i]==45){
			pushAddress = subtractOperand(new_stack);
			push(new_stack,&pushAddress);
		}
		if(expression[i]==42){
			pushAddress = multiplyOperand(new_stack);
			push(new_stack,&pushAddress);
		}
		if(expression[i]==47){
			pushAddress = devideOperand(new_stack);
			push(new_stack,&pushAddress);
		}
		i++;
	}
	return *(int*)((*new_stack.stackTop)->data);
};
