#include <stdio.h>

#include "HelperFuncs.h"
#include "Node.h"


int main()
{
    struct Node *head = NULL;
    int menuChoice, x;

    while (1)
    {
        system("cls");
        printf("Menu\n"
               "1. Adding a new node to the top of the list\n"
               "2. Adding a new node to the end of the list\n"
               "3. Adding a new node after a given node\n"
               "4. Printing the list\n"
               "5. Search for a given value\n"
               "0. Exit\n");
        menuChoice = range_scan(0, 5);
        switch (menuChoice)
        {
            case 1:
                printf("Enter the data to be inserted");
                x = scan_safe_func_int();
                if (search(head, x) == NULL)
                    push(&head, x);
                else
                    printf("Value already exists in the list\n");
                break;
            case 2:
                printf("Enter the data to be inserted");
                x = scan_safe_func_int();
                if (search(head, x) == NULL)
                    append(&head, x);
                else
                    printf("Value already exists in the list\n");
                break;
            case 3:
                printf("Enter the data after which to insert");
                x = scan_safe_func_int();
                struct Node *temp_node = search(head, x);

                if (temp_node == NULL)
                    printf("No such value in list\n");
                else
                {
                    printf("Enter the data to be inserted");
                    x = scan_safe_func_int();
                    if(search(head, x)==NULL)
                        insertAfter(temp_node, x);
                    else
                        printf("Value already exists in the list\n");
                }
                break;
            case 4:
                printList(head);
                break;
            case 5:
                printf("Enter the value to search for");
                x = scan_safe_func_int();
                if (search(head, x) == NULL)
                    printf("No such value in list\n");
                else
                    printf("Value is in list\n");
                break;
            case 0:
                return 0;
        }
        printf("\n\n");
        system("pause");
    }
}
