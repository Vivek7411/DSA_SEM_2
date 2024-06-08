#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int info;
    struct link *next;
} node;

void travers(node *);
void insertatstart(node **, int);
void insertatend(node **, int);

void main()
{

    node *head = NULL;

    while (1)
    {

        int choice;
        int a;

        printf("\n\n\nEnter Your Choice : \n");

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
        printf("12.Exit\n");

        scanf("%d", &choice);

        printf("\nYour choice is %d", choice);

        switch (choice)
        {
        case 1:
            printf("\n");
            travers(head);
            break;

        case 2:
            printf("\nEnter the value u wanted to add. ");
            scanf("%d", &a);
            insertatstart(&head, a);
            break;

        case 3:

            printf("\nEnter the value u wanted to add. ");
            scanf("%d", &a);
            insertatend(&head, a);

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:

            break;

        case 9:

            break;

        case 10:

            break;

        default:

            printf("\nPlease enter a valid choice");
            break;
        }
    }
}

void travers(node *head1)
{
    node *temp = head1;
    while (temp != NULL)
    {
        printf("%d->", temp->info);
        temp = temp->next;
    }
}

void insertatstart(node **head1, int val)
{

    node *temp = (node *)malloc(sizeof(node));
    temp->info = val;

    if (*head1 == NULL)
    {
        temp->next = NULL;
    }

    else
    {
        temp->next = *head1;
    }

    *head1 = temp;
}

void insertatend(node **head1, int val)
{

    node *temp = (node *)malloc(sizeof(node));
    temp->info = val;
    temp->next = NULL;

    if (*head1 == NULL)
    {
        *head1 = temp;
    }
    else
    {
        node *loc = *head1;
        while(loc->next!=NULL){
            loc=loc->next;
        }
        loc->next=temp;
    }

    printf("\n reachedddddddddd");
}