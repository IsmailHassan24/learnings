#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int n;
    do
    {
        n = get_int("Cents: ");
    }
    while (n < 0);
    return n;
}

int calculate_quarters(int cents)
{
    int quarter_counter = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarter_counter++;
    }
    return quarter_counter;
}

int calculate_dimes(int cents)
{
    int dime_counter = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dime_counter++;
    }
    return dime_counter;
}

int calculate_nickels(int cents)
{
    int nickel_counter = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickel_counter++;
    }
    return nickel_counter;
}

int calculate_pennies(int cents)
{
    int cent_counter = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        cent_counter++;
    }
    return cent_counter;
}
