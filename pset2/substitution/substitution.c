#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // if argument count is as expected, user goes down Branch A
    if (argc == 2)
    {
        int checker = 0;
        // for loop iterating over every character in the second string of argv
        for (int i = 0, s = strlen(argv[1]); i < s; i++)
        {
            // checking for non-alphabetic characters in argv[1]
            if (isalpha(argv[1][i]))
            {
                checker++;
            }
            // error for non-alphabetic characters
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return (1);
            }
            // checking that argv[1] has 26 characters
            if (checker == strlen(argv[1]))
            {
                if (checker == 26)
                {
                    // for loop iterating over the different characters in argv[1] at different points to check for duplicates
                    for (int a = 0, b = a + 1; a < strlen(argv[1]); a++)
                    {
                        if (argv[1][a] == argv[1][b])
                        {
                            // repeating characters error
                            return (1);
                            printf("Key must not contain repeating characters.\n");
                            a++;
                            b++;
                            break;
                        }
                        // main program - encipher stage
                        else if (argv[1][a] != argv[1][b] && checker == 26)
                        {
                            string text = get_string("plaintext: ");
                            int textlength = strlen(text);
                            char sub[textlength];
                            printf("ciphertext: ");
                            // for loop iterating over character in the plaintext string
                            for (int l = 0; text[l] != 0; l++)
                            {
                                // branch for alphabetic characters being printed and alternative branch for non-alphabetic
                                // characters
                                if (isalpha(text[l]))
                                {
                                    // ifupper it is enciphered to the character in the same array position in argv[1] - case is
                                    // preserved by using toupper
                                    if (isupper(text[l]))
                                    {
                                        sub[l] = toupper(argv[1][text[l] - 65]);
                                    }
                                    // iflower it is enciphered to the character in the same array position in argv[1] - case is
                                    // preserved by using tolower
                                    if (islower(text[l]))
                                    {
                                        sub[l] = tolower(argv[1][text[l] - 97]);
                                    }
                                }
                                // if character entered isn't alphabetical, it is printed as normal
                                else
                                {
                                    sub[l] = text[l];
                                }
                                printf("%c", sub[l]);
                            }
                            printf("\n");
                            break;
                        }
                    }
                }
                // branch for users who enters !26 characters
                else
                {
                    printf("Key must contain 26 characters.\n");
                    return (1);
                }
            }
        }
    }
    // branch for users who don't enter a key or too many keys
    else
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }
}