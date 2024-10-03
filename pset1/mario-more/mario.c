#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_block(int n);

int height;

int main(void)
{
    // Function to prompt for height that limits input to between 1 and 8 (inclusive)
    height = get_height();

    // First main loop that runs the amount of times the user inputs
    for (int i = 0; i < height; i++)
    {
        // Loop that right aligns the first hash block
        for (int k = height - 1; k > i; k--)
        {
            printf(" ");
        }
        // Loop to print the the first right aligned hash block
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // Prints the two spaces in between the two blocks
        printf("  ");
        // Final loop to print a left aligned hash block after the spaces
        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }
        // Prints a new line after each row/run of the loop
        printf("\n");
    }
}

// Function to get height
int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}
