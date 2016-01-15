#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#define TYPECHAR *(char *)
#define TYPEINT *(int *)
#define TYPEFLOAT *(float *)
#define TYPEDOUBLE *(double *)
void test_create_impty_linked_list(){
    Linked_list list =createList();
    assert(list.length==0);
    assert(list.head ==NULL);
    assert(list.tail==NULL);

}

void test_add_to_list_can_add_int_type_value_at_the_end_of_list(){
  Linked_list list = createList();
  int first = 23;
  assert(1==add_to_list(&list ,&first));
  assert(list.head == list.tail);
  assert(TYPEINT(list.head->value)==23);
  assert(TYPEINT(list.tail->value)==23);
  assert(list.length==1);
}

void test_add_to_list_can_add_float_type_value_at_the_end_of_list(){
  Linked_list list = createList();
  float _1st = 23.5;
  assert(1==add_to_list(&list ,&_1st));
  assert(list.head == list.tail);
  assert(TYPEFLOAT(list.head->value)==23.5);
  assert(TYPEFLOAT(list.tail->value)==23.5);
  assert(list.length==1);
}


void test_add_to_list_can_add_double_type_value_at_the_end_of_list(){
  Linked_list list = createList();
  
  double _1st = 23.9999999999999999999999999999999999999999999999999999999999999995;
  double _2nd =999999999999999999999.99990567876546785467854678546785467854678546754678654567435675467543567654567545675456754;
  assert(1==add_to_list(&list ,&_1st));
  assert(list.head == list.tail);
  assert(TYPEDOUBLE(list.head->value)==23.9999999999999999999999999999999999999999999999999999999999999995);
  assert(TYPEDOUBLE(list.tail->value)==23.9999999999999999999999999999999999999999999999999999999999999995);
  assert(list.length==1);

  assert(2==add_to_list(&list ,&_2nd));
  assert(TYPEDOUBLE(list.tail->value)==999999999999999999999.99990567876546785467854678546785467854678546754678654567435675467543567654567545675456754);
  assert(list.length==2);
}

void test_get_first_element_returns_first_element_from_the_int_type_of_list(){
  Linked_list list = createList();
  int _1st,_2nd,_3rd;
  _1st =23;
  _2nd =24;
  _3rd =25;

  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);

  assert(TYPEINT(get_first_element)(list)==23);
}


void test_get_last_element_returns_last_element_from_the_list(){
   Linked_list list = createList();
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
  assert(TYPEINT(get_last_element(list))==27);
}



void doSomething(void *value){
  TYPEINT(value)+=1;
}

void test_forEach_can_do_something_with_each_element(){
  Linked_list list = createList();
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
  assert(TYPEINT(list.head->value)==24);
}
void test_getElementAt_returns_the_value_at_index(){
  Linked_list list = createList();
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
  
  assert(TYPEINT(getElementAt(list,0))==22);
  assert(TYPEINT(getElementAt(list,1))==23);
  assert(TYPEINT(getElementAt(list,2))==24);
  assert(TYPEINT(getElementAt(list,3))==25);
  assert(TYPEINT(getElementAt(list,4))==26);
  assert(TYPEINT(getElementAt(list,5))==27);
  assert(getElementAt(list,9)==NULL);
} 

void test_indexOf_can_find_the_index_of_int_type_of_element_from_array(){
  Linked_list list = createList();
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


void test_indexOf_can_find_the_index_of_char_type_of_element_from_array(){
  Linked_list list = createList();
  char _0th,_1st,_2nd;
  _0th ='S';
  _1st ='a';
  _2nd ='4';
  add_to_list(&list ,&_0th);
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);

  assert(indexOf(list,&_0th)==0);
  assert(indexOf(list,&_1st)==1);
  assert(indexOf(list,&_1st)==1);

}

void test_indexOf_can_find_the_index_of_float_type_of_element_from_list(){
  Linked_list list  =createList();
  float _0th,_1st,_2nd;
  _0th =5.5;
  _1st =99.0;
  _2nd =3.5;
  add_to_list(&list ,&_0th);
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);

  assert(indexOf(list,&_0th)==0);
  assert(indexOf(list,&_1st)==1);
  assert(indexOf(list,&_1st)==1);

}


void test_indexOf_can_find_the_index_of_double_type_of_element_from_list(){
  Linked_list list  =createList();
  double _0th,_1st,_2nd;
  _0th =5.0090000000000000000000000000000000000000000000;
  _1st =99.90546789087656789087657890876546789087654789087654678908765467890876978690870;
  _2nd =_0th+_1st+3.5009876567897654765456786545678654678654367865467654567546767567546754654657434567434567436754367654;
  add_to_list(&list ,&_0th);
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);

  assert(indexOf(list,&_0th)==0);
  assert(indexOf(list,&_1st)==1);
  assert(indexOf(list,&_1st)==1);

}