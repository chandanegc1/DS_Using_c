#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "array_util_lib.h"

int num_of_test = 0;

void ArrayUtil_can_hold_the_char_type(){
	printf("--------\n-->ArrayUtil_can_hold_the_int_type \n");
	ArrayUtil numbers = create(sizeof(char) , 5);

	char *c = (char *)numbers.base;
	c[0] = 4, c[1] = 'B', c[2] = 'C';

	assert(c[0]==4);
	assert(c[1] =='B');
	// assert(strcmp(c[2],'C'));
	// assert(c[3] == 0);

	num_of_test++;
}

void ArrayUtil_can_hold_the_int_type(){
	printf("--------\n-->ArrayUtil_can_hold_the_int_type \n");
	ArrayUtil numbers = create(sizeof(int) , 5);

	int *s = (int *)numbers.base;
	s[0] = 92, s[1] = 70, s[2] = 30;

	assert(s[0] == 92);
	assert(s[1] == 70);
	assert(s[2] == 30);
	assert(s[4] == 0);

	num_of_test++;
}

void ArrayUtil_can_hold_the_float_type(){
	printf("--------\n-->ArrayUtil_can_hold_the_float_type \n");
	ArrayUtil numbers = create(sizeof(float) , 10);

	float *f = (float *)numbers.base;
	f[0] = 0.5, f[1] = 0.50, f[2] = 5.0 ,f[3] = 9.0 ,f[4] = 67.0 ,f[5] = 10.50;

	assert(f[0] == 0.5);
	assert(f[1] == 0.50);
	assert(f[2] == 5.0);
	assert(f[3] == 9.0);
	assert(f[4] == 67.0);
	assert(f[5] == 10.50);

	num_of_test++;
}

void ArrayUtil_can_hold_the_double_type(){
	printf("--------\n-->ArrayUtil_can_hold_the_double_type \n");
	ArrayUtil numbers = create(sizeof(double) , 10);

	double *d = (double *)numbers.base;
	d[0] = 0.5, d[1] = 0.50, d[2] = 5.0 ,d[3] = 9.0 ,d[4] = 67.6 ,d[5] = 10.10;

	assert(d[0] == 0.5);
	assert(d[1] == 0.50);
	assert(d[2] == 5.0);
	assert(d[3] == 9.0);
	assert(d[4] == 67.6);
	assert(d[5] == 10.10);

	num_of_test++;
}

void create_can_create_the_array_of_given_typeSize_and_given_length(){
	printf("--------\n-->create_can_create_the_array_of_given_typeSize_and_given_length \n");
	ArrayUtil numbers = create(4 , 8);
	assert(numbers.length == 8);
	assert(numbers.type_size == 4);

	num_of_test++;
}

void resize_can_resize_the_array_with_given_new_size_and_keep_the_old_value_if_new_size_is_greater_then_old(){
	printf("--------\n-->resize_can_resize_the_array_with_given_new_size_and_keep_the_old_value_if_new_size_is_greater_then_old \n");
	ArrayUtil numbers ,numbers_;
	numbers= create(4 , 8);
	float *f = (float *)numbers.base;
	f[0]=2.5;
	f[1]=5.0;
	assert(f[0]==2.5);
	assert(f[1]==5.0);

	assert(numbers.type_size == 4);
	assert(numbers.length == 8);
	
	numbers_ = resize(numbers,16);
	assert(numbers_.type_size == 4);
	assert(numbers_.length == 16);
	f[0]=2.5;
	f[1]=5.0;
	assert(f[0]==2.5);
	assert(f[1]==5.0);
	num_of_test++;
}

void areEqual_can_compare_two_ArrayUtil_whether_they_are_equla_or_not(){
	printf("--------\n-->areEqual_can_compare_two_ArrayUtil_whether_they_are_equla_or_not\n");

	ArrayUtil numbers ,_numbers;
	assert(areEqual(numbers,_numbers)==0);
	num_of_test++;
}

int main(void){
	
	create_can_create_the_array_of_given_typeSize_and_given_length();
	resize_can_resize_the_array_with_given_new_size_and_keep_the_old_value_if_new_size_is_greater_then_old();
	ArrayUtil_can_hold_the_char_type();
	ArrayUtil_can_hold_the_int_type();
	ArrayUtil_can_hold_the_float_type();
	ArrayUtil_can_hold_the_double_type();
	areEqual_can_compare_two_ArrayUtil_whether_they_are_equla_or_not();
	printf("%d passed\n",num_of_test);
	return 0;
}
