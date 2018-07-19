#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
        // this verifies that only the execution command and another item is entered, no less, no more
    if (argc > 2 || argc == 1){
        printf("Usage: ./vigenere k\n");
        return 1;
    };
    int h = strlen(argv[1]);
    string key = argv[1];
    int t;
    int keylist[h]; // list with all shift codes of key string
    // here verifies whether a letter or a number is entered
    // also the letter (either upper or lower case) is simplified by shift code
    for (int a = 0; a < h; a++)
    {
        if (isupper(key[a]))
        {
            t = (key[a]);
            t -= 65;
            keylist[a] = t;
//            printf("%i ", t);
        }
        else if (islower(key[a]))
        {
            t = (key[a]);
            t -= 97;
            keylist[a] = t;
//            printf("%i ", t);
        }
        // there is an error printed if a letter is between the key string entered
        else
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    //user enters the string to be encoded
    string plain = get_string("Enter plain text: ");
    int k, o = 0;
    int j = strlen(plain);
    int valuelist[j]; // list with ASCII values of string to be encoded
    int newnu, mnew;
    for (int i = 0; i < j; i++)
    {
        // here it is used the variable o so that the counter does not count the spaces as another iteration over the keylist
        k = o % h;
        newnu = keylist[k] + plain[i];
//        printf("k = %i\n", keylist[k]);
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                mnew = newnu - 65;
                mnew = mnew % 26;
                mnew = mnew + 65;
                valuelist[i] = mnew;
/*                printf("prev = %i ", plain[i]);
                printf("ib = %i ", keylist[k]);
                printf("mnew = %i ", newnu);
                printf("valuelist[i] = %i \n", valuelist[i]);
*/            }
            if (islower(plain[i]))
            {
                mnew = newnu - 97;
                mnew = mnew % 26;
                mnew = mnew + 97;
                valuelist[i] = mnew;
/*                printf("prev = %i ", plain[i]);
                printf("ib = %i ", keylist[k]);
                printf("mnew = %i ", newnu);
                printf("valuelist[i] = %i \n", valuelist[i]);
*/            }
            o ++;
        }
      else
        {
            valuelist[i] = plain[i];
        }
    }
    printf("ciphertext: ");
    for (int e = 0; e < j; e++)
    {
        printf("%c", valuelist[e]);
    }
    printf("\n");
}