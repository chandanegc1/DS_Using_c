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