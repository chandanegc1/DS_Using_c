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


void *deleteElementAt(Linked_list *, int);

int asArray(Linked_list, void **, int maxElements);

typedef int MatchFunc(void* hint, void* item);
Linked_list  filter(Linked_list, MatchFunc ,void *);

Linked_list reverse(Linked_list);

typedef void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);
Linked_list map(Linked_list, ConvertFunc, void * );

typedef void* Reducer(void* hint, void* previousItem, void* item);
void *reduce(Linked_list, Reducer, void *hint, void *initialValue);
