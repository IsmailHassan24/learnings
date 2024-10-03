#include <stdio.h>
#include <cs50.h>

int main(void)
{
int x = get_int("What's x? ");
for (int counter = 0; counter < x; counter++)
    {
        printf("Meow\n");
    }
}