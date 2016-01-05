#include "lib.h"
#include <stdio.h>
#include "stdlib.h"

int main(void){
	void *result;
	result = (void*)malloc(sizeof(void)*10);
	int len,length = 5;
	void score[] = {'a','b','c','d','e'};
	map(score,result,length,increment);
	//len= filter(score,result,length,is_even);
	printf("%s\n", result[0]);
	// printf("%d\n",reduce(score,length,sum));
	return 0;

}