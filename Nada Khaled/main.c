#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"


/** @file main.c
 *  @brief An initial main.c
 *
 *  This file contains the
 *  main() function.
 *
 *
 *  @author Nada Khaled
 *  @bug No known bugs.
 */

// this code uses some functions to simulate a simple calculator
int main()
{
     float a; //first number
    float b; //second number
    char c;  // operation
    float z; // answer
    char d;  // continue or not

    do
    {
        system("cls");
        printf("please enter first #\n");
        scanf("%f",&a);
        printf("please enter second #\n");
        scanf("%f",&b);
        _flushall();
        printf("choose operation +, - , * , /\n");
        scanf("%c",&c);
        switch (c)
        {
        case '+':
            z=Add(a,b);
            printf("ans = %f\n",z);
            break;

        case '-' :
            z=Sub(a,b);
            printf("ans = %f\n",z);
            break;

        case '*':
            z=Multiply(a,b);
            printf("ans = %f\n",z);
            break;

        case '/':

            if (b==0)
            {
                printf("invalid, can't divide by zero\n");
            }
            else{
                z=divide(a,b);
                printf("ans = %f\n",z);
            }

            break;
        default:
            printf("invalid operation\n");
            break;
        }

        printf("continue ? y/n\n");
        _flushall();
        scanf("%c",&d);
    }

    while(d=='y');
}


