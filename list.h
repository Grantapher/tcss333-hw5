#include <stdio.h>
#include <stdlib.h>

struct node {
   int value;
   struct node *next;
};



/* prints all data in list */
void printAll(struct node* list);

/* adds n to front of list */
struct node *add_to_list(struct node *list, int n);

/* adds n to front of list, alternative version */
void add_to_listP2P( struct node **list  ,int n);

/* return boolean indicating if list is in order,
   i.e. never decreasing */
int inOrder(struct node *list);

/* remove n from the list */
struct node *delete_from_list(struct node *list, int n);



int looplesslength(struct node *list);

struct node *merge(struct node* list1, struct node* list2);

int nodupdata(struct node *list);

struct node *doubleAll(struct node* list);

struct node *deleteAll(struct node *list, int n);


