#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
// Initial argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
//Checking if the user typed numbers
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
//Converting string num to int num
    int k = atoi(argv[1]);

//Converting Plaintext to Ciphertext
    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");

    for (int j = 0; j < strlen(plaintext); j++)
    {
//For Uppercase situations
    if (isupper(plaintext[j]))
    {
        printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
    }
//For Lowercase situations
    else if (islower(plaintext[j]))
    {
        printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
    }
//For non-letter characters
    else
    {
        printf("%c", plaintext[j]);
    }
    }
    printf("\n");
}