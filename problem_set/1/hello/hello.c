#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ask for first name
    string firstname = get_string("what's your name? ");
    printf("hello, %s \n", firstname);
}