#include <cs50.h>
#include <stdio.h>

// Declares our two main functions to prompt user for restricted input + print the block
int get_height(void);
void print_block(int n);

// Declares global variable - height
int height;

// Our main function just calls on the two functions that make up the program
int main(void)
{
    height = get_height();
    print_block(height);
}

// Function that prompts user for input and limits their input to being greater or equal to 1 OR less than or equal to 8
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

// Main function that prints the right aligned hash block
void print_block(int n)
{
    // Main loop that runs however many times the user decides via height
    for (int i = 0; i < height; i++)
    {
        // This right aligns the block - no idea why the loop has to run at height - 1, but it works
        for (int k = height - 1; k > i; k--)
        {
            printf(" ");
        }
        // Loop to just print the hashes after the empty spaces
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // Print new line at the end of every iteration of the loop
        printf("\n");
    }
}