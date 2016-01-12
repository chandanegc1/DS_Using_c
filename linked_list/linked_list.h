typedef struct element{
	void *value;
	struct element *next;
	
} Element;
typedef struct linkedList{
	Element *head,*tail;
	int length;
} Linked_list;

Linked_list createList();
int add_to_list(Linked_list * , void *);

