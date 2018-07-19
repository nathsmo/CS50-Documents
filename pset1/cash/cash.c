#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int coins = 0;
    float cas;
    do {
        cas = get_float("Enter cash please: ");
    } while (cas < 0);
    // There is an error with the floats, 0.01 looks like 0.0099 so I added 0.001 to make it a one
    int cash = cas*100;
    while (cash != 0)
    {
        if (cash >= 50)
        {
            coins++;
            cash = cash - 50;
        };
        if (cash >= 25)
        {
            coins++;
            cash = cash - 25;
        };
        if (cash >= 10)
        {
            coins++;
            cash = cash - 10;
        };
        if (cash >= 5)
        {
            coins++;
            cash = cash - 5;
        };
        if (cash >= 1)
        {
            coins++;
            cash = cash - 1;
        };
    };
    printf("You need at least %i coins\n", coins);
};