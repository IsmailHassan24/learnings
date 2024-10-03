#include <cs50.h>
#include <stdio.h>

int start_size;
int end_size;
int get_start_size(void);
int get_end_size(void);

int main(void)
{
    // TODO: Prompt for start size
    start_size = get_start_size();
    // TODO: Prompt for end size
    end_size = get_end_size();
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (start_size < end_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}

int get_start_size(void)
{
    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);
    return start_size;
}

int get_end_size(void)
{
    do
    {
        end_size = get_int("End Size: ");
    }
    while (end_size < start_size);
    return end_size;
}