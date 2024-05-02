#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} node;

void show(node *);
int insert_at_beg(node **, int);
int insert_at_end(node **, int);




int main()
{

    node *head = NULL;

    int val = 2;
    insert_at_beg(&head, val);
    show(head);

    // insert_at_beg(&head, 3);
    // show(head);

    return 0;
}

int insert_at_beg(node **head1, int val)
{

    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\n overflow in memeory");
        return 1;
    }
    temp->info = val;

    if (*head1 == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = *head1; // now new temp.next points to old head which is 2nd in list mow.
    }

    *head1 = temp; // now head point to new head which is temp.

    return 0;
}

void show(node *head)
{

    node *temp = head;

    while (temp != NULL)
    {
        printf("%d->", temp->info);
        temp = temp->next;
    }
}

int insert_at_end(node **head1, int val)
{

    node *temp = (node *)malloc(sizeof(node));

    if (temp == NULL)
    {
        printf("\noverflow");
        return 0;
    }

    temp->info = val;
    temp->next = NULL;

    if (*head1 == NULL)
    {
        *head1 = temp;
    }

    else
    {
        node *loc = *head1;

        while (loc->next != NULL)
        {
            loc=loc->next;
        }

        loc->next=temp;
    }
}
