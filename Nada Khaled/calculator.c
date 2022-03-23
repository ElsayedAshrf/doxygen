#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

/** @file calculator.c
 *  @brief A console driver.
 *  This is the implementation of the calculator functions.
 *  @author Nada Khaled
 *  @bug No known bugs
 */


int Add (int x, int y)
{
    int sum;
    sum = x+y;
    return sum;
}

int Sub(int a,int b)
{
    int diff;
    diff=a-b;
    return diff;
}

int Multiply (int x,int y)
{
    int ans;
    ans=x*y;
    return ans;
}

float divide (int i,int j)
{
    float quo;
    quo=i/j;
    return quo;
}
