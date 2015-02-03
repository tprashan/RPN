# include "rpn.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

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


int handleOperator(Stack new_stack,int operator){
	int popAddress1,popAddress2;
	int  pushAddress;
	popAddress1 = (int)((*new_stack.stackTop)->data) ;
	pop(new_stack);
	popAddress2 = (int)((*new_stack.stackTop)->data) ;
	pop(new_stack);

	switch(operator){
		case '+': pushAddress = popAddress2 + popAddress1; break;
		case '-': pushAddress = popAddress2 - popAddress1; break;
		case '*': pushAddress = popAddress2 * popAddress1; break;
		case '/': pushAddress = popAddress2 / popAddress1; break;
		default : printf("Notation is wrong.Give valid notation" );
	}

	return pushAddress;
}

int evaluate(char *expression){
	int i=0,k=-1;
	int  pushAddress;
	int data[strlen(expression)];
	Stack new_stack = createStack();
	while(expression[i]!='\0'){

		if(expression[i]>='0' && expression[i]<='9'){

			k = (expression[i+1]!=' ' && k==-1) ? i : k;
		
			if(expression[i+1]==' '){ 
				data[i] = (k<0) ? atoi(&expression[i]) : atoi(&expression[k]);
				push(new_stack,(void*)data[i]);
				k = -1;
			}
		}
		if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/'){
			pushAddress = handleOperator(new_stack,expression[i]);
			push(new_stack,(void*)pushAddress);

		}
		i++;
	}
	return (int)((*new_stack.stackTop)->data);
};

