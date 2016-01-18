#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
Linked_list createList(){
	Linked_list list;
	list.head=NULL;
	list.tail=NULL;
	list.length =0;
	return list;
}
int add_to_list(Linked_list *list ,void *value){
	Element *e= (Element *)malloc(sizeof(Element));
	e->value = value;
	e->next= NULL;
	if(list->length == 0){
		list->head = list->tail = e;
	}
	else{
		list->tail->next = e;
		list->tail = e;
	}	
	list->length +=1;
	return list->length;
}

void *get_first_element(Linked_list list){
	return list.head->value;
}
void *get_last_element(Linked_list list){
	return list.tail->value;
}

void forEach(Linked_list list,ElementProcessor e){
	for(int i=0;i<list.length;i++){
		e(list.head->value);
		list.head = list.head->next;
	}
}	

void *getElementAt(Linked_list list, int index){
  for(int i=0;i<list.length;i++){
  	if(i==index)
      return list.head;
  	list.head = list.head->next;
  }
  return NULL;
}

int indexOf(Linked_list list, void *value){
	int i;
  for(i=0;i<list.length;i++){
    if(memcmp(list.head->value,value,sizeof(value))==0){
    	return i;
    }
    list.head=list.head->next;
  }
  return -1;
}

void *deleteElementAt(Linked_list *list, int index){
	Element *temp = list->head;
	if(index==0){
		list->head=temp->next;
		free(temp);
		list->length--;
		return list;
	}
	if(index==list->length-1){
		temp = getElementAt(*list,index-1);
		list->tail=temp;
		list->tail->next=NULL;
		list->length--;
		free(temp);
		return list;
	}
	else{
		Element *prev = getElementAt(*list,index-1);
		Element *ele =  getElementAt(*list,index);
		prev->next=ele->next;
		list->length--;
		free(ele);
		return list;
	};
	
	return NULL;
};

int asArray(Linked_list list, void **array, int maxElements){
	Element *e;	
	maxElements =list.length<maxElements?list.length:maxElements;
	for(int i=0;i<maxElements;i++){
		e=getElementAt(list,i);
		array[i]=e->value;
	}
	return maxElements;
}

Linked_list filter(Linked_list list,MatchFunc match,void *hint){
	Linked_list result = createList();
	for(int i=0;i<list.length;i++){
		if(1==match(hint,list.head->value)){
			add_to_list(&result,list.head->value);
		}
		list.head=list.head->next;
	}
	return result;
}
Linked_list reverse(Linked_list list){
	Linked_list ReversedList=createList();
	Element *e;
	for(int i=list.length-1;i>=0;i--){
		e=getElementAt(list,i);
		add_to_list(&ReversedList,e->value);
	}
	return ReversedList;
}
Linked_list map(Linked_list list, ConvertFunc convert, void *hint){
	Linked_list mapped = createList();
	Element *e = list.head;
	for(int i=0;i<list.length;i++){
		void *destination  = (void *)malloc(sizeof(void *));
		convert(hint,e->value,destination);
		add_to_list(&mapped,destination);
		e = e->next;
	}
	return mapped;
}
