#ifndef PRACT10_NODE_H
#define PRACT10_NODE_H

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};


/**
 * @brief Function for pushing element in the list head.
 *
 * @param head The head of the list.
 * @param new_data The element to be pushed.
 */
void push(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}


/**
 * @brief Function for appending element in the end of the list.
 *
 * @param head The head of the list.
 * @param new_data The element to be appended.
 */
void append(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}


/**
 * @brief Function for inserting element after the given node.
 *
 * @param prev_node The previous node of the list.
 * @param new_data The element to be inserted.
 */
void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}


/**
 * @brief Function for printing the list.
 *
 * @param head The head of the list.
 */
void printList(struct Node *node)
{
    if (node == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    printf("List: ");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}


/**
 * @brief Function for searching the element in the list.
 *
 * @param head The head of the list.
 * @param x The element to be searched.
 *
 * @return The node of the searched element.
 */
struct Node *search(struct Node *head, int x)
{
    struct Node *current = head;

    while (current != NULL)
    {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}


#endif //PRACT10_NODE_H
