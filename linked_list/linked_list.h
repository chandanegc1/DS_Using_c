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

void *get_first_element(Linked_list);
void *get_last_element(Linked_list);

typedef void (*ElementProcessor)(void *);
void forEach(Linked_list,ElementProcessor);

void * getElementAt(Linked_list, int);

int indexOf(Linked_list, void *);
