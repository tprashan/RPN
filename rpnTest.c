#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rpn.h"
#include "expr_assert.h"

void test_1_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_plus(){
	Result result;
	char* expression = "25 3 +";
	result = evaluate(expression);
	assertEqual(result.status,28);
};

void test_2_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_minus(){
	Result result;
	char* expression = "2 3 -";
	result = evaluate(expression);
	assertEqual(result.status,-1);
};

void test_3_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_multiply(){
	Result result;
	char* expression = "2 3 *";
	result = evaluate(expression);
	assertEqual(result.status,6);
};

void test_4_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_devide(){
	Result result;
	char* expression = "2 3 /";
	result = evaluate(expression);
	assertEqual(result.status,0);
};

void test_5_RPN_calculator_that_can_evaluate_simple_expressions_such_as_2_3_4_with_multiOperator(){
	Result result;
	char* expression = "2 3 4 + -";
	result = evaluate(expression);
	assertEqual(result.status,-5);
};

void test_6_RPN_calculator_that_can_evaluate_such_as_1_2_3_4_5_with_multiOperator(){
	Result result;
	char* expression = "1 2 3 4 5 * * * *";
	result = evaluate(expression);
	assertEqual(result.status,120);
};

void test_7_RPN_calculator_that_can_evaluate_parentessis_with_multiOperator(){
	Result result;
	char* expression = "5 1 2 + 4 * + 3 -";
	result = evaluate(expression);
	assertEqual(result.status,14);
};

void test_8_RPN_calculator_that_can_evaluate_parentessis_return_7(){
	Result result;
	char* expression = "2 2 2 * 2 - 3 + + ";
	result = evaluate(expression);
	assertEqual(result.status,7);
};

void test_9_RPN_calculator_that_can_evaluate_parentessis_return_20(){
	Result result;
	char* expression = "2 2 2 2 2 * * 2 + + 2 - *";
	result = evaluate(expression);
	assertEqual(result.status,20);
};

void test_10_RPN_calculator_that_can_evaluate_parentessis_return_0(){
	Result result;
	char* expression = "2 2 - 2 2 2 * 2 - - -";
	result = evaluate(expression);
	assertEqual(result.status,0);
};

void test_11_evaluate_expression_will_give_402(){
	Result result;
	char *expression = "2 1000 600 - +";
	result = evaluate(expression);
	assertEqual(result.status,402);
}

void test_12_evaluate_expression_will_give_1002(){
	Result result;
	char *expression = "1000 200 100 / +";
	result = evaluate(expression);

	assertEqual(result.status,1002);
}

void test_13_evaluate_expression_will_give_and_1000(){
	Result result;
	char *expression = "100000    10   1 1 / / /";
	result =  evaluate(expression);

	assertEqual(result.status,10000);
};

void test_14_evaluate_expression_will_give_and_1000_as_a_result_structure(){
	Result result;
	char *expression = "100000    10   1 1 / / /";
	result =  evaluate(expression);

	assertEqual(result.status,10000);
}

void test_15_evaluate_expression_will_give_0_as_a_result_structure_error(){
	Result result;
	char *expression = "100000    10   1 1 / / / /";
	result =  evaluate(expression);

	assertEqual(result.error,0);
}

void test_16_evaluate_expression_will_give_0_as_a_result_error(){
	Result result;
	char *expression = "100000    10   1 1 * / * / + 20 + 1000 /";
	result =  evaluate(expression);
	assertEqual(result.status,0);
	assertEqual(result.error,0);
}

void test_17_evaluate_expression_will_give_0_as_a_result_status_when_operator_is_less_as_expected(){
	Result result;
	char *expression = "100000    10   1 1 *  + 20 + 1000 /";
	result =  evaluate(expression);
	assertEqual(result.status,0);
	assertEqual(result.error,0);
}

void test_17_evaluate_expression_will_give_0_as_a_result_error_when_whiteSpace_found_in_expression(){
	Result result;
	char *expression = "100000    10   1 1 *  @ + 20 $ + 1000 /";
	result =  evaluate(expression);
	assertEqual(result.status,0);
	assertEqual(result.error,0);
}
