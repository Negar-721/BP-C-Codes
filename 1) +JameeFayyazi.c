 #include <stdio.h>
#include <stdlib.h>

int main()
{
    int aDigits, bDigits;

    scanf("%d", &aDigits);
    while (getchar() != '\n');  

    char a[1000];
    scanf("%s", a);

    scanf("%d", &bDigits);
    while (getchar() != '\n');  

    char b[1000];
    scanf("%s", b);

    int max = aDigits > bDigits ? aDigits : bDigits;
    max += 3;

    int c[max];
    for (int i = 0; i < max; i++)
    {
        c[i] = 0;
    }

    int carry = 0;
    int index = max - 1;
    int aIndex = aDigits - 1;
    int bIndex = bDigits - 1;

    while (aIndex >= 0 || bIndex >= 0)
    {
        int sum = c[index];
        if (aIndex >= 0)
        {
            sum += a[aIndex] - '0';
            aIndex--;
        }
        if (bIndex >= 0)
        {
            sum += b[bIndex] - '0';
            bIndex--;
        }

        c[index] = sum % 10;
        carry = sum / 10;

        if (index - 3 >= 0)
        {

            c[index - 3] = carry;
        }

        index--;
    }
 
    int start = 0;
    for (int i = 0; i < max; i++)
    {
        if (c[i] != 0)
        {
            start = i;
            break;
        }
    }

    if (c[start] == 0)
    {
        printf("0");
        return 0;
    }

    for (int i = start; i < max; i++)
    {
        printf("%d", c[i]);
    }

    return 0;
}