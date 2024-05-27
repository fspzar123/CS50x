#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // All the integers used//
    int n, i, j, k ;
    // The condition the user should abide to//
    do
    {
        n = get_int("Enter Height: ");
    }
    while (n < 1 || n > 8);
    //For increasing the row//
    for (j = 0; j < n; j++)
    {
        //This for the right alignment//
        for (k = 0; k < n - j - 1; k++)
        {
            printf(" ");
        }
        //This for increasing column//
        for (i = 0; i <= j; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}