#include <stdio.h>
#include <stdlib.h>
#include "placementApart.h"

int main()
{
    List l1,l2,l3;
    int choice;
    int num;

    while (true)
    {
        printf("1)Insert in list 1\n2)Insert in list 2\n3)Merge into list 3\n4)Display\n5)Exit\n");
        do
        {
            printf("Enter your choice: ");
            scanf("%d", &choice);
            if ((choice < 1) || (choice > 5))
            {
                printf("Invalid input.\n");
            }
        } while ((choice < 1) || (choice > 5));

        switch(choice)
        {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &num);
                l1.InsertAscending(num);
                break;

            case 2:
                printf("Enter number to insert: ");
                scanf("%d", &num);
                l2.InsertAscending(num);
                break;

            case 3:
                l3.Merge(&l1, &l2);
                break;

            case 4:
                printf("\nList 1:\n");
                l1.display();
                printf("\n");

                printf("List 2:\n");
                l2.display();
                printf("\n");

                printf("List 3:\n");
                l3.display();
                break;

            default:
                printf("Exiting Program...\n");
                return 0;
        }
        printf("\n");
    }
}
