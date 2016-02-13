#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void printDup(int b) {
    printf("No duplicates in above? = %s\n", b ? "true" : "false");
}

int main(void) {

    struct node *intlist = NULL;
    int i;
    
    int array[] = {1,1,1,2,2,3,4,5,5,10,10,11,12,12,12};
    for (i = 0; i < sizeof(array) / sizeof(*array); i++) {  
        intlist = add_to_list(intlist, array[i]);
    }
    
    printAll(intlist);
    doubleAll(intlist);
    printAll(intlist);
    
    intlist = deleteAll(intlist, 10);
    printAll(intlist);

    int l1[] = {8,7,5,3,1};
    int l2[] = {9,8,6,5,2};
    struct node *ll1 = NULL, *ll2 = NULL;
    for (i = 0; i < 5; i++){
        ll1 = add_to_list(ll1, l1[i]);
        ll2 = add_to_list(ll2, l2[i]);
    }

    struct node *merged = merge(ll1, ll2);
    printAll(merged);
    
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

    return 0;
}
