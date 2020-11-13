# include <stdio.h>
# include <cs50.h>
# include <math.h>

int coins;

int main(void)
{
    float dollars = get_float("Change owed: ");
    while (true)
    {
        if (dollars >= 0)
        {
            break;
        }
        else
        {
            dollars = get_float("Change owed: ");
        }
    }

    int cents = round(dollars * 100);
    do
    {
        // if can use quarters
        if (cents >= 25)
        {
            cents -= 25;
            coins++;
        }
        // if can use dimes
        else if (cents >= 10)
        {
            cents -= 10;
            coins++;
        }
        // if can use 5c
        else if (cents >= 5)
        {
            cents -= 5;
            coins++;
        }
        // if can use 1c
        else if (cents >= 1)
        {
            cents -= 1;
            coins++;
        }
    }
    while (cents > 0);
    printf("%i\n", coins);
}
