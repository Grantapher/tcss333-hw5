#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void printDup(int b) {
    printf("No duplicates in above? = %s\n", b ? "true" : "false");
}

int main(void) {

    struct node *intlist = NULL;
    int i;
    
    int array[] = {10,10,9,9,8,5,5,5,4,3,3,2,1};
    for (i = 0; i < sizeof(array) / sizeof(*array); i++) {  
        intlist = add_to_list(intlist, array[i]);
    }
    
    printf("Double list\n");
    printAll(intlist);
    doubleAll(intlist);
    printAll(intlist);
    doubleAll(intlist);
    printAll(intlist);
    
    printf("\nDelete 1\n");
    intlist = deleteAll(intlist, 1);
    printAll(intlist);

    printf("Delete 5\n");
    intlist = deleteAll(intlist, 5);
    printAll(intlist);

    int l1[] = {8,7,5,3,1};
    int l2[] = {9,8,6,5,2};
    struct node *ll1 = NULL, *ll2 = NULL;
    for (i = 0; i < 5; i++){
        ll1 = add_to_list(ll1, l1[i]);
        ll2 = add_to_list(ll2, l2[i]);
    }
    
    printf("\nMerge two lists\n");
    printAll(ll1);
    printAll(ll2);
    struct node *merged = merge(ll1, ll2);
    printAll(merged);
    
    printf("\n");
    printAll(merged);
    printAll(intlist);
    merged = merge(merged, intlist);
    printAll(merged);

    printf("\nCheck for duplicates\n");
    printAll(intlist);
    printDup(nodupdata(intlist));
    printAll(merged);
    printDup(nodupdata(merged));

    int arr[] = {1,2,3,4,5};
    struct node *noDup;
    for (i = 0; i < sizeof(arr) / sizeof(*arr); i++) {  
        noDup = add_to_list(noDup, arr[i]);
    }

    printAll(noDup);
    printDup(nodupdata(noDup));

    printf("\nDetect loops with negative lengths\n");
    printAll(noDup);
    printf("length = %d\n", looplesslength(noDup));
    
    noDup = add_to_list(noDup, 6);
    printAll(noDup);
    printf("length = %d\n", looplesslength(noDup));
    
    struct node *loopStart = noDup->next;
    loopStart->next->next->next->next->next->next = loopStart;
    printAll(noDup);
    printf("length = %d\n", looplesslength(noDup));

    return 0;
}
