#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
//Getting input from the user
    string text = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
//Counts the number of letters
        if (isalpha(text[i]))
        {
            letters++;
        }
//Counts the number of words
        else if (text[i] == ' ')
        {
            words++;
        }
//Counts the number of sentences
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
//Calculates the Grade using the Coleman-Liau index
    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

//The different outputs for different indices
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}