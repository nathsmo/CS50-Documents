#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc > 2 || argc == 1){
        printf("Usage: ./caesar k\n");
        return 1;
    };
    int k = atoi(argv[1]);
    string plain = get_string("Enter plain text: ");
    int j = strlen(plain);
    int valuelist[j];
    int newnu, mnew;
    for (int i = 0; i < j; i++)
    {
        if (isalpha(plain[i]))
        {
            newnu = k + plain[i];
            if (isupper(plain[i]))
            {
                mnew = newnu - 65;
                mnew = mnew % 25;
                mnew = mnew + 65;
                valuelist[i] = mnew;
            }
            if (islower(plain[i]))
            {
                mnew = newnu - 97;
                mnew = mnew % 25;
                mnew = mnew + 97;
                valuelist[i] = mnew;
            }
        }
      else
        {
            valuelist[i] = plain[i];
        }
    }
    for (int i = 0; i < j; i++)
    {
        printf("%c", valuelist[i]);
    }
    printf("\n");
}