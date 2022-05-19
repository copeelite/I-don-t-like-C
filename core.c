/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  :FanghaoMeng
Student ID#:180210213
Email      :fmeng18@myseneca.ca
Section    :IPC144 NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include "core.h"
#include<string.h>
// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
int i = 0;
void clearInputBuffer(void)
{ // Discard all remaining char's from the standard input buffer: 
    while (getchar() != '\n') {
        ;
        // do nothing! 
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt()
{

    int val1;
    char val2 = 'x';
    scanf("%d%c", &val1, &val2);
    while (val2 != '\n')
    {
        clearInputBuffer();
        printf("Error! Input a whole number: ");
        scanf("%d%c", &val1, &val2);
    }

    return val1;
}

int inputIntPositive()
{
    int val1;
    scanf("%d", &val1);
    while (val1 <= 0)
    {
        clearInputBuffer();
        printf("ERROR! Value must be > 0: ");
        scanf("%d", &val1);
    }
    return val1;
}

int inputIntRange(int lower, int upper)
{
    int val1;
    char val2;
    scanf("%d%c", &val1, &val2);
    while (val2 != '\n')
    {
        clearInputBuffer();
        printf("Error! Input a whole number: ");
        scanf("%d%c", &val1, &val2);
    }

    while (val1 < lower || val1 > upper)
    {
        printf("ERROR! Value must be between %d and %d inclusive: ", val1, val2);
        scanf("%d", &val1);

    }
    return val1;
}

char inputCharOption(char str[])
{
    int i = 0, j = 0;
    char val2;
    while (i == 0)
    {
        scanf("%c", &val2);
        clearInputBuffer();
        for (j = 0; j < 6; j++)
        {
            if (val2 == str[j])
            {
                i++;
            }
        }
        if (i == 0)
        {
            printf("ERROR: Character must be one of [qwErty]: ");

        }




    }
    return val2;
}

void inputCString(char* ptr, int min, int max)
{  
    char str[100] = { '\0' };
    int j = 0; int length = 0;
    while (j == 0)
    {

        scanf("%[^\n]", str);
        
        length = strlen(str);

        if (length >= min && length <= max)
        {
            j++;

        }
        else if (min != max && length > max)
        {
            printf("ERROR: String length must be no more than %d chars: ", max);

        }
        else if (min != max && length < min)
        {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);

        }

        else if (min == max && (length< min || length> max))
        {
            printf("ERROR: String length must be exactly %d chars: ", max);

        }
    }
    strcpy(ptr, str);
}


void displayFormattedPhone(const char* ptr)
{

    int i = 0, j = 0;
    int length = 0;
    if (ptr == NULL)
    {
        //printf("(___)___-____");
        return;
    }
    while (i == 0)
    {
        if (ptr[length] != '\0')
        {

            if ((!isdigit(ptr[length])))
            {
                printf("(___)___-____");
                j++;
            }
            length++;
        }
        else {
            i = 1;

        }
    }


    if (length != 10)
    {
        printf("(___)___-____");

    }
    else if (j != 1)
    {
        printf("(");
        for (i = 0; i < 3; i++)
        {
            printf("%c", ptr[i]);
        }
        printf(")");
        for (i = 3; i < 6; i++)
        {
            printf("%c", ptr[i]);
        }
        printf("-");
        for (i = 6; i < 10; i++)
        {
            printf("%c", ptr[i]);
        }

    }

    //void displayFormattedPhone(const char *phone_number)
    //{
    //int i = 0, j = 0;
    //int count = 0;
    //int length = 0;
    //if (phone_number == NULL)
    //{
    //printf("(___)___-____");
    //return;
    //}
    //length = strlen(phone_number);
    //for(i = 0; i < length ; i++)
    //{
    //if (phone_number[i] >= '0' && phone_number[i] <= '9')
    //{
    //count++;
    //}
    //}
    //if (length != 10 || length != count)
    //{
    //printf("(___)___-____");
    //}
    //else
    //{
    //printf("(%c%c%c)%c%c%c-%c%c%c%c",
    //phone_number[0],
    //phone_number[1],
    //phone_number[2],
    //phone_number[3],
    //phone_number[4],
    //phone_number[5],
    //phone_number[6],
    //phone_number[7],
    //phone_number[8],
    //phone_number[9]);
    //}
}






