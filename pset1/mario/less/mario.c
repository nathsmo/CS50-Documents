#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;
    do
    {
      n = get_int("Positive number: ");
    }
    while(n < 0 || n > 23);

    for (int i = 1; i < n+1; i++)
    {
        for (int k = i; k < n; k++ )
        {
            printf(" ");
        }
        for (int j = n-i; j < n; j++ )
        {
            printf("#");
        };
        printf("#");
        printf("\n");
    };
}