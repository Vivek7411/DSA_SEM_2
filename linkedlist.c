// #include <stdio.h>

// typedef struct linkedlist{

//     int data;
//     struct linkedlist *next;
// }node;

// void main(){

// }

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct link *next;
} node;

void insert_at_beg(node **head1, int val)
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

    *head1 = temp; // making head point to temp now which is new head now.
}

void insert_at_end(node **head1, int val)
{

    node *temp = (node *)malloc(sizeof(int));
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

            loc = loc->next;
        }
        loc->next = temp;
    }
}

node *search(node *head, int item)
{
    while (head != NULL)
    {
        if (head->info == item)
        {
            return head;
        }
        else
        {
            head = head->next;
        }
    }
}

void insert_after(node **head1, int item, int val)
{
    node *loc = search(*head1, 30); // this must be inputed.
    if (loc == NULL)
    {
        printf("item not found");
        return;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp->info = val;
    temp->next = loc->next;
    loc->next = temp;
}

void show(node *head1)
{
    node *temp = head1;
    while (temp != NULL)
    {
        printf("%d->", temp->info);
        temp = temp->next;
    }
}

// void delete_at_start(node **head1)
// {
//     node *temp = *head1;
// }

void main()
{
    node *head = NULL;

    insert_at_beg(&head, 10);
    insert_at_beg(&head, 20);
    insert_at_beg(&head, 30);
    insert_at_end(&head, 40);

    insert_after(&head, 30, 50);
    show(head);
}

//    node head1 = (node)malloc(sizeof(node));
//     head->info = 10;
//     head->next = head1;
//     head1->info = 20;
//     head1->next = NULL;