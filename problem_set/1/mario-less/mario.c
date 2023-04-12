#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // Get size of pryamid
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n > 8 || n < 1);


    // Print pyramid

    for (int row = 0; row < n; row++)       // to create 8 rows
    {
        for (int space = n - row - 1; space > 0; space--)       // to create the white space
        {
            printf(" ");
        }
        for (int brick = 0; brick < row + 1; brick++)       // to create the bricks
        {
            printf("#");
        }
        printf("\n");
    }
}




