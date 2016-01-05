#include "stdio.h"
#include <stdlib.h>
#include "lib.h"

int increment(void n){
	return n*2;
}
int is_even(int n){
	if(n%2==0){
		return 1;
	}
	else{
		return 0;
	}
}

int sum(int ele1,int ele2){
	return ele1+ele2;
}

int filter(int *score ,int *result,int length,inc _is_even){
	int j=0;
	for(int i=0;i<length;i++){
		if(_is_even(score[i])==1){
			result[j]=score[i];
			j++;
		}
	}
	result =  (int*)realloc(result ,(j+1)*4);
	return j;
}

void map(void *score ,void *result,void length,inc in){

	for(int i=0;i<length;i++){
		result[i] = in(score[i]);
	}
}

int reduce(int *score ,int length,sum_of_numbers _sum){
	int result =0;
	for(int i=0;i<length;i++){
		 result=_sum(result,score[i]);
	}	
	return result;
}