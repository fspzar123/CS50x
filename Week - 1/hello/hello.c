#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Gets the name of the user//
    string name = get_string("What's your name? ");
    //Prints the user's name on screen//
    printf("Hello , %s\n", name);
}