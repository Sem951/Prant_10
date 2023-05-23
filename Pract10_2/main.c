#include <stdio.h>
#include "Node.h"

int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;


    fillingList(&list1, -4, -2, 5, 6, 8, 10, 11, INT_MIN);
    fillingList(&list2, 1, 2, 6, 46, INT_MIN);

    printList(list1);
    printList(list2);

    struct Node *merged = mergeList(list1, list2);
    printList(merged);
    freeList(&merged);

    struct Node *merged_sorted = mergeListSort(list1, list2);
    printList(merged_sorted);
    freeList(&merged_sorted);

    freeList(&list1);
    freeList(&list2);

    return 0;
}
