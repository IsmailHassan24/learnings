#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        string plaintext = get_string("plaintext: ");
        int k = atoi(argv[1]);
        printf("ciphertext: ");
        for (int j = 0; j < strlen(plaintext); j++)
        {
            char ciphertext = rotate(plaintext[j], k);
            printf("%c", ciphertext);
        }
        printf("\n");
        return 0;
    }
}

char rotate(char c, int n)
{
    if (islower(c))
    {
        char x = ((c - 97) + n) % 26 + 97;
        return x;
    }
    else if (isupper(c))
    {
        char x = ((c - 65) + n) % 26 + 65;
        return x;
    }
    else
    {
        return c;
    }
    return 0;
}
