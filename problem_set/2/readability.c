#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



int main(int argc, string argv[])
{
    // Getting input string of text

    string text = get_string("Text: ");

    // Calculating letters

    float letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    // Calculating words

    float words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }

    // Calcualting sentences

    float sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }


    // Calculating grade

    float l = (letters / words * 100.0);
    float s = (sentences / words * 100.0);
    float grade = ((0.0588 * l) - (0.296 * s) - 15.8);
    int finalgrade = round(grade);

    // Printing result to terminal

    if (finalgrade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (finalgrade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", finalgrade);
    }

}


