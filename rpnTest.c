#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rpn.h"
#include "expr_assert.h"

void test_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_plus(){
	char* expression = "25 3 +";
		int result;
	result = evaluate(expression);
	assertEqual(result,28);
};

void test_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_minus(){
	char* expression = "2 3 -";
	int result;
	result = evaluate(expression);
	assertEqual(result,-1);
};

void test_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_multiply(){
	char* expression = "2 3 *";
	int result;
	result = evaluate(expression);
	assertEqual(result,6);
};

void test_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_devide(){
	char* expression = "2 3 /";
	int result;
	result = evaluate(expression);
	assertEqual(result,0);
};

void test_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_4_with_multiOperator(){
	char* expression = "2 3 4 + -";
	int result;
	result = evaluate(expression);
	assertEqual(result,-5);
};

void test_RPN_calculator_that_can_evaluate_such_as_1_2_3_4_5_with_multiOperator(){
	int result;
	char* expression = "1 2 3 4 5 * * * *";
	result = evaluate(expression);
	assertEqual(result,120);
};

void test_RPN_calculator_that_can_evaluate_parentessis_with_multiOperator(){
	char* expression = "5 1 2 + 4 * + 3 -";
	int result;
	result = evaluate(expression);
	assertEqual(result,14);
};

void test_RPN_calculator_that_can_evaluate_parentessis_return_7(){
	int result;
	char* expression = "2 2 2 * 2 - 3 + + ";
	result = evaluate(expression);
	assertEqual(result,7);
};

void test_RPN_calculator_that_can_evaluate_parentessis_return_20(){
	int result;
	char* expression = "2 2 2 2 2 * * 2 + + 2 - *";
	result = evaluate(expression);
	assertEqual(result,20);
};

void test_RPN_calculator_that_can_evaluate_parentessis_return_0(){
	int result;
	char* expression = "2 2 - 2 2 2 * 2 - - -";
	result = evaluate(expression);
	assertEqual(result,0);
};

void test_evaluate_expression_will_give_402(){
	char *expression = "2 1000 600 - +";
	int result = evaluate(expression);

	assertEqual(result,402);
}

void test_evaluate_expression_will_give_1002(){
	char *expression = "1000 200 100 / +";
	int result = evaluate(expression);

	assertEqual(result,1002);
}

void test_evaluate_expression_will_give_and_1000(){
	int result;
	char *expression = "100000    10   1 1 / / /";
	result =  evaluate(expression);

	assertEqual(result,10000);
}