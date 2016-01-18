#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#define TYPECHAR *(char *)
#define TYPEINT *(int *)
#define TYPEFLOAT *(float *)
#define TYPEDOUBLE *(double *)
void test_for_create_impty_linked_list(){
    Linked_list list =createList();
    assert(list.length==0);
    assert(list.head ==NULL);
    assert(list.tail==NULL);

}

void test_for_add_to_list_it_add_int_type_value_at_the_end_of_list(){
  Linked_list list = createList();
  int first = 23;
  assert(1==add_to_list(&list ,&first));
  assert(list.head == list.tail);
  assert(TYPEINT(list.head->value)==23);
  assert(TYPEINT(list.tail->value)==23);
  assert(list.length==1);
}

void test_for_add_to_list_it_add_float_type_value_at_the_end_of_list(){
  Linked_list list = createList();
  float _1st = 23.5;
  assert(1==add_to_list(&list ,&_1st));
  assert(list.head == list.tail);
  assert(TYPEFLOAT(list.head->value)==23.5);
  assert(TYPEFLOAT(list.tail->value)==23.5);
  assert(list.length==1);
}


void test_for_add_to_list_it_add_double_type_value_at_the_end_of_list(){
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

void test_for_add_to_list_it_add_CHAR_type_ELEMENT_at_the_end_of_list(){
  Linked_list list = createList();
  char _1st = 'K',_2nd='9';
  assert(1==add_to_list(&list ,&_1st));
  assert(2==add_to_list(&list ,&_2nd));

  assert(TYPECHAR(list.head->value)=='K');
  assert(TYPECHAR(list.tail->value)=='9');
  assert(list.length==2);

  assert(getElementAt(list,9)==NULL);
}

void test_for_add_to_list_it_add_STRUCTURE_type_ELEMENT_at_the_end_of_list(){
  Linked_list list = createList();

  typedef struct Intern{
    int age;
    char *name;
    char *companyName;
  }intern;

    intern i,j,k;
    i.age=23;
    i.name="Seeta";
    i.companyName="ThoughtWorks";
  
  assert(1==add_to_list(&list ,&i));

  j=*(intern *)list.head->value;

  assert(i.age==j.age); 
  assert(i.name==j.name);
  assert(i.companyName==j.companyName);
  assert(getElementAt(list,9)==NULL);
}
void test_for_get_first_element_returns_first_element_from_the_int_type_of_list(){
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

void test_for_get_first_element_returns_first_element_from_the_STRUCTURE_type_of_list(){
  Linked_list list = createList();
  typedef struct Intern{
    int age;
    char *name;
    char *companyName;
  }intern;
    intern i,j,k;
    i.age=23;
    i.name="Seeta";
    i.companyName="ThoughtWorks";
  
  add_to_list(&list ,&i);
  j=*(intern *)get_first_element(list);
  assert(i.age==j.age);
  assert(i.name==j.name);
  assert(i.companyName==j.companyName);

}

void test_for_get_last_element_returns_last_element_from_the_INT_type_of_list(){
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


void test_for_get_last_element_returns_last_element_from_the_CHAR_type_of_list(){
  Linked_list list = createList();
  char _1st,_2nd,_3rd;
  _1st ='a';
  _2nd ='g';
  _3rd ='9';
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);
  assert(TYPECHAR(get_last_element(list))=='9');
}


void test_for_get_last_element_returns_last_element_from_the_float_type_of_list(){
  Linked_list list = createList();
  float _1st,_2nd,_3rd;
  _1st =905.5;
  _2nd =87.0;
  _3rd =78.50;
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);
  assert(TYPEFLOAT(get_last_element(list))==78.50);
}


void test_for_get_last_element_returns_last_element_from_the_double_type_of_list(){
  Linked_list list = createList();
  double _1st,_2nd,_3rd;
  _1st =999999999999.555555559587439857349508734958374598347598373948573948;
  _2nd =857349857349857349857349857349857349587.0;
  _3rd =7840583409584309583409583409583409583405934.5093740932487329048320943029482309482309;
  add_to_list(&list ,&_1st);
  add_to_list(&list ,&_2nd);
  add_to_list(&list ,&_3rd);
  assert(TYPEDOUBLE(get_last_element(list))==_3rd);
}
void test_for_get_LAST_element_returns_LAST_element_from_the_STRUCTURE_type_of_list(){
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
  int k=23;
  add_to_list(&list ,&k);
  add_to_list(&list,&i);
  j=*(intern *)get_last_element(list);
  assert(i.age==j.age);
  assert(i.name==j.name);
  assert(i.companyName==j.companyName);

}


void doSomething(void *value){
  TYPEINT(value)+=1;
}

void test_for_forEach_it_do_something_with_each_element(){
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
void test_for_getElementAt_returns_the_value_at_index_int_type_of_list(){
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

void test_for_getElementAt_returns_the_value_at_index_char_type_of_list(){
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


void test_for_getElementAt_returns_the_value_at_index_float_type_of_list(){
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

void test_for_getElementAt_returns_the_value_at_index_double_type_of_list(){
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

void test_for_getElementAt_returns_the_value_at_index_of_any_structure_type_of_list(){
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
void test_for_indexOf_it_find_the_index_of_int_type_of_element_from_array(){
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


void test_for_indexOf_it_find_the_index_of_char_type_of_element_from_array(){
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

void test_for_indexOf_it_find_the_index_of_float_type_of_element_from_list(){
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


void test_for_indexOf_it_find_the_index_of_double_type_of_element_from_list(){
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

void test_for_deleteElement_it_delete_the_first_element_of_int_type_from_list(){
  Linked_list list=createList();
  int _1st =22,_2nd=23,_3rd=24;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPEINT(list.head->value)==22);
  assert(TYPEINT(list.tail->value)==24);


  deleteElementAt(&list,0);
   
  assert(TYPEINT(list.head->value)==23);
  assert(TYPEINT(list.tail->value)==24);
  assert(list.length==2);

}


void test_for_deleteElement_it_delete_the_first_element_of_CHAR_type_from_list(){
  Linked_list list=createList();
  char _1st ='A',_2nd='a',_3rd='b';
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPECHAR(list.head->value)=='A');
  assert(TYPECHAR(list.tail->value)=='b');


  deleteElementAt(&list,0);
   
  assert(TYPECHAR(list.head->value)=='a');
  assert(TYPECHAR(list.tail->value)=='b');
  assert(list.length==2);


}

void test_for_deleteElement_it_delete_the_first_element_of_float_type_from_list(){
  Linked_list list=createList();
  float _1st =22.5,_2nd=23.0,_3rd=24.50;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPEFLOAT(list.head->value)==22.5);
  assert(TYPEFLOAT(list.tail->value)==24.50);


  deleteElementAt(&list,0);
   
  assert(TYPEFLOAT(list.head->value)==23.0);
  assert(TYPEFLOAT(list.tail->value)==24.50);
  assert(list.length==2);


}

void test_for_deleteElement_it_delete_the_first_element_of_DOUBLE_type_from_list(){
  Linked_list list=createList();
  double _1st =229876897678976578976786.59087657896578965785908765789657896578590876578965789657859087657896578965785908765789657896578590876578965789657859087657896578965785908765789657896578590876578965789657859087657896578965785908765789657896578590876578965789657859087657896578965785908765789657896578;
  double _2nd=2300000000.00000099999999999999;
  double _3rd=_1st+24.50;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPEDOUBLE(list.head->value)==_1st);
  assert(TYPEDOUBLE(list.tail->value)==_3rd);


  deleteElementAt(&list,0);
   
  assert(TYPEDOUBLE(list.head->value)==_2nd);
  assert(TYPEDOUBLE(list.tail->value)==_3rd);
  assert(list.length==2);

}

void test_for_deleteElement_it_delete_the_LAST_element_of_int_type_from_list(){
  Linked_list list=createList();
  int _1st =22,_2nd=23,_3rd=24;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPEINT(list.head->value)==_1st);
  assert(TYPEINT(list.tail->value)==_3rd);


  deleteElementAt(&list,list.length-1);
   
  assert(TYPEINT(list.head->value)==_1st);
  assert(TYPEINT(list.tail->value)==_2nd);
  assert(list.length==2);

}


void test_for_deleteElement_it_delete_the_LAST_element_of_CHAR_type_from_list(){
  Linked_list list=createList();
  char _1st ='A',_2nd='a',_3rd='b';
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPECHAR(list.head->value)==_1st);
  assert(TYPECHAR(list.tail->value)==_3rd);


  deleteElementAt(&list,list.length-1);
   
  assert(TYPECHAR(list.head->value)==_1st);
  assert(TYPECHAR(list.tail->value)==_2nd);
  assert(list.length==2);


}

void test_for_deleteElement_it_delete_the_LAST_element_of_float_type_from_list(){
  Linked_list list=createList();
  float _1st =22.5,_2nd=23.0,_3rd=24.50;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPEFLOAT(list.head->value)==_1st);
  assert(TYPEFLOAT(list.tail->value)==_3rd);


  deleteElementAt(&list,list.length-1);
   
  assert(TYPEFLOAT(list.head->value)==_1st);
  assert(TYPEFLOAT(list.tail->value)==_2nd);
  assert(list.length==2);


}

void test_for_deleteElement_it_delete_the_LAST_element_of_DOUBLE_type_from_list(){
  Linked_list list=createList();
  double _1st =229876897678976578976786.5908765789657896578;
  double _2nd=2300000000.00000099999999999999;
  double _3rd=_1st+24.50;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPEDOUBLE(list.head->value)==_1st);
  assert(TYPEDOUBLE(list.tail->value)==_3rd);


  deleteElementAt(&list,list.length-1);
   
  assert(TYPEDOUBLE(list.head->value)==_1st);
  assert(TYPEDOUBLE(list.tail->value)==_2nd);
  assert(list.length==2);

}


void test_for_deleteElement_it_delete_the_ANY_element_of_int_type_from_list(){
  Linked_list list=createList();
  int _1st =22,_2nd=23,_3rd=24;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPEINT(list.head->value)==22);
  assert(TYPEINT(list.head->next->value)==23);
  assert(TYPEINT(list.tail->value)==24);


  deleteElementAt(&list,1);
   
  assert(TYPEINT(list.head->value)==22);
  assert(TYPEINT(list.head->next->value)==24);
  assert(TYPEINT(list.tail->value)==24);
  assert(list.length==2);

}


void test_for_deleteElement_it_delete_the_ANY_element_of_CHAR_type_from_list(){
  Linked_list list=createList();
  char _1st ='A',_2nd='a',_3rd='b';
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPECHAR(list.head->value)=='A');
  assert(TYPECHAR(list.head->next->value)=='a');
  assert(TYPECHAR(list.tail->value)=='b');


  deleteElementAt(&list,1);
   
  assert(TYPECHAR(list.head->value)=='A');
  assert(TYPECHAR(list.tail->value)=='b');
  assert(list.length==2);


}

void test_for_deleteElement_it_delete_the_ANY_element_of_float_type_from_list(){
  Linked_list list=createList();
  float _1st =22.5,_2nd=23.0,_3rd=24.50;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPEFLOAT(list.head->value)==22.5);
  assert(TYPEFLOAT(list.head->next->value)==23.0);
  assert(TYPEFLOAT(list.tail->value)==24.50);


  deleteElementAt(&list,1);
   
  assert(TYPEFLOAT(list.head->value)==22.5);
  assert(TYPEFLOAT(list.head->next->value)==24.50);
  assert(TYPEFLOAT(list.tail->value)==24.50);

  assert(list.length==2);


}


void test_for_deleteElement_it_delete_the_ANY_element_of_DOUBLE_type_from_list(){
  Linked_list list=createList();
  double _1st =9.9;
  double _2nd=23;
  double _3rd=4.50;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);

  
  assert(list.length==3);
  assert(TYPEDOUBLE(list.head->value)==_1st);
  assert(TYPEDOUBLE(list.tail->value)==_3rd);


  deleteElementAt(&list,2);
   
  assert(TYPEDOUBLE(list.head->value)==_1st);
  assert(TYPEDOUBLE(list.tail->value)==_2nd);
  assert(list.length==2);

}

void test_for_asArray_it_can_test_for_int(){
  Linked_list list=createList();
  int _1st=23,_2nd =24,_3rd=25;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);
  void *array[3];
  assert(asArray(list,array,3)==3);
  Element e1,e2,e3;
  assert(TYPEINT(array[0])==23);
  assert(TYPEINT(array[1])==24);
  assert(TYPEINT(array[2])==25);

}


void test_for_asArray_it_can_test_for_float(){
  Linked_list list=createList();
  float _1st=23.50,_2nd =24.5,_3rd=25.00;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);
  void *array[3];
  assert(asArray(list,array,3)==3);
  Element e1,e2,e3;
  assert(TYPEFLOAT(array[0])==23.50);
  assert(TYPEFLOAT(array[1])==24.5);
  assert(TYPEFLOAT(array[2])==25.00);

}


void test_for_asArray_it_can_test_for_double(){
  Linked_list list=createList();
  double _1st=239876890.532468798435168480,_2nd =2455.85585,_3rd=2585.6576854346900;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);
  void *array[3];
  assert(asArray(list,array,3)==3);
  Element e1,e2,e3;
  assert(TYPEDOUBLE(array[0])==_1st);
  assert(TYPEDOUBLE(array[1])==_2nd);
  assert(TYPEDOUBLE(array[2])==_3rd);

}

void test_for_asArray_it_can_test_for_STRUCTURE(){
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
  j = *(intern *)list.head->value;
  void *array[3];
  assert(asArray(list,array,1) == 1);
  j =*(intern *)array[0];
  assert(i.age==j.age); 
  assert(i.name==j.name);
  assert(i.companyName==j.companyName);
}

int isEven(void *hint,void *item){
    int _item=TYPEINT(item);
    if(_item%2==0){
      return 1;
    }
    return 0;
}

void test_for_filter_it_can_filter_the_elements_from_array(){
  Linked_list list = createList();
  Linked_list result =createList();
  int _1st=23,_2nd=24,_3rd=25;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);
  result = filter(list,isEven,NULL);
  assert(TYPEINT(result.head->value)==24);
}

void test_for_reverse_it_can_reverse_the_int_type_of_list(){
  Linked_list list=createList();
  int _1st=22,_2nd=23,_3rd=24;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);
  Linked_list reversed_list = reverse(list);
  assert(TYPEINT(reversed_list.head->value)==24);
  assert(TYPEINT(reversed_list.tail->value)==22);

}

void increment(void *hint,void *sourceItem,void *destination){
  int _sourceItme=TYPEINT(sourceItem);
  int *_destination = (int *)(destination);
  *_destination = _sourceItme+1;
}
void test_for_map_it_can_map_the_int_type_elements_from_list(){
  Linked_list list=createList();
  Linked_list result=createList();
  int _1st=22,_2nd=26,_3rd=28;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);
  int hint=0;
  result = map(list,increment,&hint);
  assert(TYPEINT(result.head->value)==23);
}

void *sum(void *hint,void *previousItem,void *item){
  int _item = TYPEINT(item);
  int *_previousItem = (int *)previousItem;
  *_previousItem =*_previousItem+_item;
  return _previousItem;
}

void test_for_reduce_it_can_reduce_the_int_type_of_element_from_list(){
  Linked_list list=createList();
  void *result;
  int _1st=22,_2nd=26,_3rd=28;
  add_to_list(&list,&_1st);
  add_to_list(&list,&_2nd);
  add_to_list(&list,&_3rd);
  int hint=1;;
  int initialValue=8;
  result=(reduce(list,sum,&hint,&initialValue));
  assert(TYPEINT(result)==84);
}
