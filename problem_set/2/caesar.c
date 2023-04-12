#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Make sure two arguments
    if (argc == 2)
    {
        // Ensures it is a positive integer
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            // Returns error message if anything other than digits
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        // Converts plaintext to ciphertext
        for (int i = 0; i < strlen(plaintext); i++)
        {
            // Lowers
            if islower(plaintext[i])
            {
                printf("%c", ((((plaintext[i] - 'a') + key) % 26) + 'a'));
            }
            // Uppers
            else if isupper(plaintext[i])
            {
                printf("%c", ((((plaintext[i] - 'A') + key) % 26) + 'A'));
            }
            // Retains any non alphabet chars as they are
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
    // Returns an error message if the code isn't executed in proper format, i.e, "./caesar key"
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}