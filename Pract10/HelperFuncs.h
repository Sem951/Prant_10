#ifndef PRACT3_HELPERFUNCS_H
#define PRACT3_HELPERFUNCS_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * @brief Prompts the user to input a number. If incorrect data (non-numeric) is entered,
 * the function continues to request input until a valid INTEGER number is provided.
 *
 * @return The number entered by the user
 */
int scan_safe_func_int()
{
    int number;
    char line[256];
    bool isNumber = false;

    while (!isNumber)
    {
        printf("\nPlease enter the number(int): ");

        if (fgets(line, sizeof(line), stdin))
        {
            if (sscanf(line, "%d", &number) == 1)
                isNumber = true;
            else
                printf("Invalid input\n");
        }
    }

    return number;
}


/**
 * @brief Prompts the user to input a number. If incorrect data (non-numeric) is entered,
 * the function continues to request input until a valid DOUBLE number is provided.
 *
 * @return The number entered by the user
 */
double scan_safe_func_double()
{
    double number;
    char line[256];
    bool isNumber = false;

    while (!isNumber)
    {
        printf("\nPlease enter the number(double): ");

        if (fgets(line, sizeof(line), stdin))
        {
            if (sscanf(line, "%lf", &number) == 1)
                isNumber = true;
            else
                printf("Invalid input\n");
        }
    }

    return number;
}


/**
 * @brief Receiving a number from the user in a strictly limited range.
 *
 * @param bottom Bottom border
 * @param top Top border
 * @return temp Number specified by the user in the given range.
 */
int range_scan(int bottom, int top)
{
    int temp;
    if (top < bottom) // swap if passed in the wrong order
    {
        temp = top;
        top = bottom;
        bottom = temp;
    }
    printf("\n");
    do
    {
        printf("The number must be in the range (%d ; %d)", bottom, top);
        temp = scan_safe_func_int();
    } while (temp < bottom || temp > top);
    printf("Done!\n\n");

    return temp;
}


#endif //PRACT3_HELPERFUNCS_H
