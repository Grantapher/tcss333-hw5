#include <stdio.h>
#include <stdlib.h>

#include "list.h"



void printAll(struct node* list) {
    struct node* curr = list, * fast;
    if(curr) fast = list->next;
    
    int count = 0;
    printf("List: ");
    while (curr && fast != curr) {  // Watch Out: curr->next !=  NULL
        printf("%d ", curr->value);
        curr = curr->next;
        count++;

        if(!fast || !fast->next) fast = NULL;
        else fast = fast->next->next;
    }

    if(!fast) {
        printf("\n");
        return; //no cycle so we're done
    }
    
    //we have cycle
    int len = -looplesslength(list);

    fast = list;
    while (fast != curr->next) {
        if(count++ < len) printf("%d ", curr->value);
        fast = fast->next;
        curr = curr->next;
    }
    while(count++ < len) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("(loops back to %d)\n", fast->value);
}

struct node *add_to_list(struct node *list, int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

void add_to_listP2P( struct node **list  ,int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

int inOrder(struct node *list) {
    struct node *curr = list;
    if (curr == NULL)
        return 1;
    while (curr->next != NULL) {  // SAFETY CHECK: curr  != NULL
        if (curr->value > curr->next->value) {  // SAFETY CHECK:  curr->next != NULL
            return 0;
        }
        curr = curr->next;
    }
    return 1;
} 

struct node *delete_from_list(struct node *list, int n) {
   struct node *cur, *prev;
   for (cur = list, prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
       if (cur->value == n) {
           if (prev == NULL)
               list = list->next; /* n is in the first node */
           else
               prev->next = cur->next; /* n is in some other node */
           free(cur);
           break;
       }
   }
   return list;
}

struct node* deleteAll(struct node *list, int n) {
    struct node *cur = list, *prev = NULL;
    while (cur != NULL) {
        if (cur->value == n) {
            if (prev == NULL) { //first node
                list = list->next; 
                free(cur);
                cur = list;
            } else {
                cur = cur->next;
                free(prev->next);
                prev->next = cur;
            }
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return list;
}

struct node* doubleAll(struct node* list) {
    struct node *cur = list, *prev = NULL;
    while (cur != NULL) {
        struct node *dup = malloc(sizeof(struct node));
        if (dup == NULL) {
            printf("Error: malloc failed in add_to_list\n");
            exit(EXIT_FAILURE);
        }
        dup->value = cur->value;
        dup->next = cur->next;
        cur->next = dup;
        cur = dup->next;
    }
    return list;
}

struct node* merge (struct node* l1, struct node* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    else if (l1 == NULL) return l2;
    else if (l2 == NULL) return l1;

    struct node* cur;
    struct node head;
    cur = &head;

    while (NULL != l1 && NULL != l2) {
        if (l1->value < l2->value) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
        cur->next = NULL;
    }
    cur->next = NULL == l1 ? l2 : l1;
    return head.next;
}

int nodupdata(struct node *list) {
    struct node *front, *back;
    for (front = list; NULL != front; front = front->next) {
        for (back = front->next; NULL != back; back = back->next) {
            if (front->value == back->value) return 0;
        }
    }
    return 1;
}

int looplesslength(struct node* list) {
    if(list == NULL) return 0;
    else if (list->next == NULL) return 1;
    else if (list->next == list) return -1;

    struct node *slow = list, *fast = list->next;
    int count = 0;
    while(slow && fast != slow) {
        count++;
        slow = slow->next;
        if(fast && fast->next) fast = fast->next->next;
        else fast = NULL;
    }

    if(!fast) 
        return count;

    //we have a cycle
    count = 0;
    slow = list;

    //find meeting point
    while(slow != fast->next) {
        count++;
        slow = slow->next;
        fast = fast->next;
    }

    //traverse cycle and increment count
    while(slow != fast) {
        count++;
        slow = slow->next;
    }

    return -(count + 1);
}
