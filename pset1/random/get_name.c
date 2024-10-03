#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string first_answer = get_string("What's your first name? ");
    printf("thanks, %s\n", first_answer);
    string second_answer = get_string("What's your last name? ");
    printf("Great. hello, %s %s\n", first_answer, second_answer);
}