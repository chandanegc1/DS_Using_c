 #include <assert.h>
      #include <stdlib.h>
      #include <stdio.h>
      #include "linked_list.h"
  void test_create_impty_linked_list(){
    Linked_list list =createList();
    assert(list.length==0);
    assert(list.head ==NULL);
    assert(list.tail==NULL);

  }

void test_add_the_value_at_the_end_of_list(){
  Linked_list list;
  int first = 23;
  assert(1==add_to_list(&list ,&first));
  assert(list.head == list.tail);
  assert(*(int *)list.head->value==23);
  assert(*(int *)list.tail->value==23);
  assert(list.length==1);
}

void test_get_first_element_returns_first_element_from_the_list(){
  Linked_list list;
  int _1st,_2nd,_3rd,_4th,_5th;
  _1st =23;
  _2nd =24;
  _3rd =25;
  _4th =26;
  _5th =27;
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);
  add_to_list(&list ,&_4th);
  add_to_list(&list ,&_5th);

  assert(*(int *)get_first_element(list)==23);
}

void test_get_last_element_returns_last_element_from_the_list(){
   Linked_list list;
  int _1st,_2nd,_3rd,_4th,_5th;
  _1st =23;
  _2nd =24;
  _3rd =25;
  _4th =26;
  _5th =27;
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);
  add_to_list(&list ,&_4th);
  add_to_list(&list ,&_5th);
  assert(*(int *)get_last_element(list)==27);
}



void doSomething(void *value){
  *(int*)value+=1;
}

void test_forEach_can_do_something_with_each_element(){
  Linked_list list;
  int _1st,_2nd,_3rd,_4th,_5th;
  _1st =23;
  _2nd =24;
  _3rd =25;
  _4th =26;
  _5th =27;
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);
  add_to_list(&list ,&_4th);
  add_to_list(&list ,&_5th);
  forEach(list,doSomething);
  assert(*(int *)list.head->value==24);
}
void test_getElementAt_returns_the_value_at_index(){
  Linked_list list;
  int _0th,_1st,_2nd,_3rd,_4th,_5th;
  _0th =22;
  _1st =23;
  _2nd =24;
  _3rd =25;
  _4th =26;
  _5th =27;
  add_to_list(&list ,&_0th);
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);
  add_to_list(&list ,&_4th);
  add_to_list(&list ,&_5th);
  
  assert(*(int *)getElementAt(list,0)==22);
  assert(*(int *)getElementAt(list,1)==23);
  assert(*(int *)getElementAt(list,2)==24);
  assert(*(int *)getElementAt(list,3)==25);
  assert(*(int *)getElementAt(list,4)==26);
  assert(*(int *)getElementAt(list,5)==27);
  assert(getElementAt(list,9)==NULL);
} 

void test_indexOf_can_find_the_first_index_of_element_in_array(){
  Linked_list list;
  int _0th,_1st,_2nd,_3rd,_4th,_5th,_6th;
  _0th =22;
  _1st =23;
  _2nd =22;
  _3rd =29;
  _4th =26;
  _5th =27;
  _6th =27;
  add_to_list(&list ,&_0th);
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);
  add_to_list(&list ,&_4th);
  add_to_list(&list ,&_5th);
  add_to_list(&list ,&_6th);

  assert(indexOf(list,&_0th)==0);
  assert(indexOf(list,&_1st)==1);
  assert(indexOf(list,&_1st)==1);
  assert(indexOf(list,&_4th)==4);
  assert(indexOf(list,&_5th)==5); 

}
