#ifndef PRACT10_2_NODE_H
#define PRACT10_2_NODE_H

#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


void append(struct Node **head, int new_data);
void fillingList(struct Node **head, int first, ...);
void printList(struct Node *node);
void freeList(struct Node **head);
struct Node *mergeList(struct Node *list1, struct Node *list2);
struct Node *mergeListSort(struct Node *list1, struct Node *list2);


#endif //PRACT10_2_NODE_H