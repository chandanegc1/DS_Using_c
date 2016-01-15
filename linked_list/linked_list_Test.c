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
void test_getElementAt_returns_the_value_at_index_int_type_of_list(){
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
  
  Element *e=getElementAt(list,0);

  assert(TYPEINT(e->value)==22);
  assert(getElementAt(list,9)==NULL);
} 

void test_getElementAt_returns_the_value_at_index_char_type_of_list(){
  Linked_list list = createList();
  int _0th,_1st,_2nd,_3rd,_4th;
  _0th ='A';
  _1st ='B';
  _2nd ='b';
  _3rd ='a';
  _4th ='A';
  add_to_list(&list ,&_0th);
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);
  add_to_list(&list ,&_4th);
  
  Element *e0=getElementAt(list,0);
  Element *e1=getElementAt(list,1);
  Element *e2=getElementAt(list,2);
  Element *e3=getElementAt(list,3);
  Element *e4=getElementAt(list,4);


  assert(TYPECHAR(e0->value)=='A');
  assert(TYPECHAR(e1->value)=='B');
  assert(TYPECHAR(e2->value)=='b');
  assert(TYPECHAR(e3->value)=='a');
  assert(TYPECHAR(e4->value)=='A');

  assert(getElementAt(list,9)==NULL);
}


void test_getElementAt_returns_the_value_at_index_float_type_of_list(){
  Linked_list list = createList();
  float _0th,_1st,_2nd;
  _0th =6.50;
  _1st =99.0;
  _2nd =10.5;
  add_to_list(&list ,&_0th);
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  
  
  Element *e0=getElementAt(list,0);
  Element *e1=getElementAt(list,1);
  Element *e2=getElementAt(list,2);
 


  assert(TYPEFLOAT(e0->value)==6.50);
  assert(TYPEFLOAT(e1->value)==99.0);
  assert(TYPEFLOAT(e2->value)==10.5);
  

  assert(getElementAt(list,9)==NULL);
}

void test_getElementAt_returns_the_value_at_index_double_type_of_list(){
  Linked_list list = createList();
  double _0th,_1st,_2nd;
  _0th =6.50000000000000000000000000000000000000;
  _1st =99.9999999999876787657865467865786547876546545456754567865478654786546786546754675467546754657545650;
  _2nd =_2nd+1876578654678654675678546750.5;
  add_to_list(&list ,&_0th);
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  
  
  Element *e0=getElementAt(list,0);
  Element *e1=getElementAt(list,1);
  Element *e2=getElementAt(list,2);
 


  assert(TYPEDOUBLE(e0->value)==6.50000000000000000000000000000000000000);
  assert(TYPEDOUBLE(e1->value)==99.9999999999876787657865467865786547876546545456754567865478654786546786546754675467546754657545650);
  assert(TYPEDOUBLE(e2->value)==_2nd);
  

  assert(getElementAt(list,9)==NULL);
}

void test_getElementAt_returns_the_value_at_index_of_any_structure_type_of_list(){
  Linked_list list = createList();

  typedef struct Intern{
    int age;
    char *name;
    char *companyName;
  }intern;

    intern i,j;
    i.age=23;
    i.name="Seeta";
    i.companyName="ThoughtWorks";
  
  add_to_list(&list ,&i);
  
  Element *e0=getElementAt(list,0);
  j= *(intern*)e0->value;

  assert(i.age==j.age); 
  assert(i.name==j.name);
  assert(i.companyName==j.companyName);
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


