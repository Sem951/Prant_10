#include <stdio.h>
#include "Node.h"


/**
 * @brief Copies a list of nodes.
 *
 * @param head The head of the list.
 * @return The head of the copied list.
 */
struct Node *copyList(struct Node *head)
{
    struct Node *new_list = NULL, *current = head;
    while (current != NULL)
    {
        append(&new_list, current->data);
        current = current->next;
    }
    return new_list;
}


/**
 * @brief Appends a new node to the end of a list.
 *
 * @param head The head of the list.
 * @param new_data The data to append to the list.
 */
void append(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(1);
    }
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    struct Node *last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}


/**
 * @brief Fills a list with values. !!! At the end, pass INT_MIN.
 *
 * @param head The head of the list.
 * @param first The first value to fill the list with.
 * @param ... Additional values to fill the list with.
 */
void fillingList(struct Node **head, int first, ...)
{
    va_list args;
    int value = first;

    va_start(args, first);
    while (value != INT_MIN)
    {
        append(head, value);
        value = va_arg(args, int);
    }
    va_end(args);
}


/**
 * @brief Prints a list.
 *
 * @param node The head of the list.
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
    printf("\n");
}


/**
 * @brief Frees a list.
 *
 * @param head The head of the list.
 */
void freeList(struct Node **head)
{
    struct Node *tmp;

    while (*head != NULL)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}


/**
 * @brief Merges two sorted lists.
 *
 * @param list1 The head of the first list.
 * @param list2 The head of the second list.
 *
 * @return The head of the merged list.
 */
struct Node *mergeList(struct Node *list1, struct Node *list2)
{
    struct Node *copy1 = copyList(list1);
    struct Node *copy2 = copyList(list2);

    if (copy1 == NULL) return copy2;
    if (copy2 == NULL) return copy1;

    struct Node *tail = copy1;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = copy2;

    return copy1;
}


/**
 * @brief Merges/sorting two sorted lists.
 *
 * @param list1 The head of the first list.
 * @param list2 The head of the second list.
 * @return The head of the merged list.
 */
struct Node *mergeListSort(struct Node *list1, struct Node *list2)
{
    struct Node *copy1 = copyList(list1);
    struct Node *copy2 = copyList(list2);

    struct Node *result = NULL;

    while (copy1 != NULL && copy2 != NULL)
    {
        if (copy1->data < copy2->data)
        {
            append(&result, copy1->data);
            copy1 = copy1->next;
        } else
        {
            append(&result, copy2->data);
            copy2 = copy2->next;
        }
    }

    while (copy1 != NULL)
    {
        append(&result, copy1->data);
        copy1 = copy1->next;
    }

    while (copy2 != NULL)
    {
        append(&result, copy2->data);
        copy2 = copy2->next;
    }

    freeList(&copy1);
    freeList(&copy2);

    return result;
}
