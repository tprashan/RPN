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

void test_18_evaluate_expression_will_give_0_as_a_result_error_when_whiteSpace_found_in_expression(){
	Result result;
	char *expression = "100000    10   1 1 *  @ + 20 $ + 1000 /";
	result =  evaluate(expression);
	assertEqual(result.status,0);
	assertEqual(result.error,0);
}

void test_19_find_operator_will_give_0_as_a_result_when_no_operator_found_in_that_index(){
	int result,index=2;
	char *expression = "100+43-745";
	result =  isOperator(expression,index);
	assertEqual(result,0);

}

void test_20_find_operator_will_give_1_as_a_result_when_operator_found_in_that_index(){
	int result,index=4;
	char *expression = "43+3*234/698";
	result =  isOperator(expression,index);
	assertEqual(result,1);
}

void test_21_find_operator_will_give_1_as_a_result_when_operator_found_in_that_index_13(){
	int result,index=13;
	char *expression = "43+3 * 2 3 4 /69 8";
	result =  isOperator(expression,index);
	assertEqual(result,1);
}

void test_22_find_operator_will_give_0_as_a_result_when_operator_found_in_that_index_4(){
	int result,index=4;
	char *expression = "43+3 * 2 3 4 /69 8";
	result =  isOperator(expression,index);
	assertEqual(result,0);
}

void test_23_find_whiteSpace_will_give_0_as_a_result_when_no_whiteSpace_found_in_that_index_4(){
	int result,index=4;
	char *expression = "43+3 * 2 3 4 /69 8";
	result =  findWhiteSpace(expression,index);
	assertEqual(result,0);
}

void test_24_find_whiteSpace_will_give_1_as_a_result_when_whiteSpace_found_in_that_index_4(){
	int result,index=4;
	char *expression = "43+3@ * 2 3 4 /69 8";
	result =  findWhiteSpace(expression,index);
	assertEqual(result,1);
}

void test_25_handleOperator_gives_resultValue_after_evaluating_given_values(){
	int result,data1=4,data2=11;
	Stack stack = createStack();push(stack,(void*)data1);push(stack,(void*)data2);
	result =  handleOperator(stack,'+');
	assertEqual(result,15);
}

void test_26_handleOperator_gives_resultValue_after_evaluating_given_values_80(){
	int result,data1=4,data2=20;
	Stack stack = createStack();push(stack,(void*)data1);push(stack,(void*)data2);
	result =  handleOperator(stack,'*');
	assertEqual(result,80);
}

void test_27_handleOperator_gives_resultValue_after_evaluating_given_values_minus_16(){
	int result,data1=4,data2=20;
	Stack stack = createStack();push(stack,(void*)data1);push(stack,(void*)data2);
	result =  handleOperator(stack,'-');
	assertEqual(result,-16);
}

void test_28_handleOperator_gives_resultValue_after_evaluating_given_values_0(){
	int result,data1=4,data2=20;
	Stack stack = createStack();push(stack,(void*)data1);push(stack,(void*)data2);
	result =  handleOperator(stack,'/');
	assertEqual(result,0);
}

void test_29_handleOperator_gives_resultValue_after_evaluating_given_values_10(){
	int result,data1=30,data2=20;
	Stack stack = createStack();push(stack,(void*)data1);push(stack,(void*)data2);
	result =  handleOperator(stack,'-');
	assertEqual(result,10);
}

void test_30_handleOperator_gives_resultValue_after_evaluating_given_values_2(){
	int result,data1=4,data2=2;
	Stack stack = createStack();push(stack,(void*)data1);push(stack,(void*)data2);
	result =  handleOperator(stack,'/');
	assertEqual(result,2);
}

void test_31_handleOperator_gives_resultValue_after_evaluating_given_values_0(){
	int result,data1=4,data2=0;
	Stack stack = createStack();push(stack,(void*)data1);push(stack,(void*)data2);
	result =  handleOperator(stack,'/');
	assertEqual(result,0);
}

void test_32_check_precedence_of_plus_is_2(){
	int result;
	result = setPrecedenceOfOperator('+');
	assertEqual(result,2);
}

void test_33_check_precedence_of_minus_is_2(){
	int result;
	result = setPrecedenceOfOperator('-');
	assertEqual(result,2);
}

void test_34_check_precedence_of_multiply_is_3(){
	int result;
	result = setPrecedenceOfOperator('*');
	assertEqual(result,3);
}

void test_35_check_precedence_of_divide_is_3(){
	int result;
	result = setPrecedenceOfOperator('/');
	assertEqual(result,3);
}

void test_36_check_precedence_of_cap_is_4(){
	int result;
	result = setPrecedenceOfOperator('^');
	assertEqual(result,4);
}

void test_37_check_precedence_of_end_brace_is_1(){
	int result;
	result = setPrecedenceOfOperator(')');
	assertEqual(result,1);
}

void test_38_check_precedence_of_open_brace_is_minus_1(){
	int result;
	result = setPrecedenceOfOperator('(');
	assertEqual(result,1);
}

void test_39_check_plus_has_less_precedence_than_multiply(){
	int result;
	result = checkPrecedence('+','*');
	assertEqual(result,0);
}

void test_40_check_devide_has_greater_precedence_than_minus(){
	int result;
	result = checkPrecedence('/','-');
	assertEqual(result,1);
}

void test_41_check_perticular_index_of_expression_is_a_digit(){
	int result;
	char *expression = "10 5 + 6";
	result = isDigit(expression,3);
	assertEqual(result,1);
}

void test_42_check_perticular_index_of_expression_is_not_a_digit(){
	int result;
	char *expression = "10 5 + 6";
	result = isDigit(expression,5);
	assertEqual(result,0);
}

void test_43_convert_it_to_an_equivalent_valid_Postfix_expression(){
	char *result,*expected="3 4 +";
	char *expression = "3 + 4";
	result = infixToPostfix(expression);
	assertEqual(strcmp(result,expected),0);
}

void test_44_convert_it_to_an_equivalent_valid_Postfix_expression(){
	char *result;
	char *expected="3 4 * 2 +";
	char *expression = "3 * 4 + 2";
	result = infixToPostfix(expression);
	assertEqual(strcmp(result,expected),0);
}

void test_45_convert_it_to_an_equivalent_valid_Postfix_expression(){
	char *result;
	char *expected="3 4 * 2 * 9 + 6 2 / - 4 +";
	char *expression = "3 * 4 * 2 + 9 - 6 / 2 + 4";
	result = infixToPostfix(expression);
	assertEqual(strcmp(result,expected),0);
}

void test_46_convert_it_to_an_equivalent_valid_Postfix_expression(){
	char *result;
	char *expected="5 6 7 ^ * 8 +";
	char *expression = "5 * 6 ^ 7 + 8";
	result = infixToPostfix(expression);
	assertEqual(strcmp(result,expected),0);
}

void test_47_convert_it_to_an_equivalent_valid_Postfix_expression(){
	char *result;
	char *expected="1 2 3 * +";
	char *expression = "1 + 2 * 3";
	result = infixToPostfix(expression);
	assertEqual(strcmp(result,expected),0);
}

// void test_48_convert_it_to_an_equivalent_valid_Postfix_expression(){
// 	char *result;
// 	char *expected="1 2 3 + *";
// 	char *expression = "1 * ( 2 + 3 )";
// 	result = infixToPostfix(expression);
// 	assertEqual(strcmp(result,expected),0);
// }

// void test_46_convert_it_to_an_equivalent_valid_Postfix_expression(){
// 	char *result;
// 	char *expected="3 4 2 * 1 5 - 2 3 ^ ^ / +";
// 	char *expression = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
// 	result = infixToPostfix(expression);

// 	printf("----------%s\n",result );
// 	// printf("outPut----3 4 2 * / +   - (  2 ^ 3 ^ )\n");
// 	printf("expected--3 4 2 * 1 5 - 2 3 ^ ^ / +\n");

// 	assertEqual(strcmp(result,expected),0);
// }