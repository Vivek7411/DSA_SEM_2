#include <stdio.h>
void main()
{

    typedef struct node
    {

        int info;
        // node *link;

    };

    while (1)
    {

        int choice;

        printf("\nEnter Your Choice : ");

        printf("1.Travese\n");
        printf("2.Add at start\n");
        printf("3.Add at end\n");
        printf("4.Add after in between\n");
        printf("5.Search\n");
        printf("6.Reverse\n");
        printf("7.Delete list\n");
        printf("8.Create list\n");
        printf("9.Modify\n");
        printf("10.Delete at start\n");
        printf("11.Delete at end\n");
        printf("11.Increse size\n");
        printf("11.Exit\n");

        scanf("%d", &choice);

        printf("\nYour choice is %d", choice);
    }
}