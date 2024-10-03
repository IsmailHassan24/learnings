#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int convert_decimal_to_binary(int decimal);

int main(void)
{
    string message = get_string("Message: ");
    for (int i = 0; i < strlen(message); i++)
    {
        int j = message[i];
        int z = convert_decimal_to_binary(j);
        for (int x = 0; x < BITS_IN_BYTE; x++)
        {
            if (z == 1)
            {
                print_bulb(1);
            }
            else
            {
                print_bulb(0);
            }
        }
        printf("\n");
    }
}

int convert_decimal_to_binary(int decimal)
{
    int i = 0;
    int binary[10];
    for (i = 0; decimal > 0; i++)
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%i", binary[j]);
        return binary[j];
    }
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}


/*
    if (decimal != 0)
    {
    int binary[8];
    int i = 0;
    for (i = 0; decimal > 0; i++)
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
    }
    for (int j = i-1; j >=0; j--)
    {
        printf("%i", binary[j]);
    }
    }
    else
    {
        printf("No\n");
    }
    printf("\n");
    return 0;
*/