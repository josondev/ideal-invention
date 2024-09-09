#include <stdio.h>
#include "bpart.h"

int main()
{
    int x;
    list l;
    printf("1. New Webpage\n2. Front\n3. Back\n4. Exit\nEnter choice: ");
    scanf("%d", &x);

    while (0 < x < 4)
    {
        if (x == 1)
        {
            l.add();
        }

        else if (x == 2)
        {
            l.back();
        }

        else if (x == 3)
        {
            l.front();
        }

        else
        {
            break;
        }

        printf("\n\n1. New Webpage\n2. Front\n3. Back\n4. Exit\nEnter choice: ");
        scanf("%d", &x);
    }
}