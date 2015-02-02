#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rpn.h"
#include "expr_assert.h"

void test_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_plus(){
	char* expression = "2 3 +";
	int result;
	result = evaluate(expression);
	assertEqual(result,5);
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
	char* expression = "1 2 3 4 5 * * * *";
	int result;
	result = evaluate(expression);
	assertEqual(result,120);
};
