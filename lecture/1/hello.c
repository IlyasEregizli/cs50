#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string first = get_string("what's your first name? ");
    string last = get_string("what's your last name? ");
    printf("hello, %s %s\n", first, last);
}