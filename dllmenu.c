// null printf 0....?

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

void intit(node **, node **, int);
void insertAtStart(node **, node **, int);
void insertAtEnd(node **, node **, int);
void deleteList(node **, node **);
void deleteAtStart(node **, node **);
void deleteAtEnd(node **, node **);
void deleteAfter(node **, node **, int);
void insertAfter(node *, node **, int, int);
void insertBefore(node **, node *, int, int);
void deleteBefore(node **, node **, int);
void show(node *);
node *search(node *, int);

void main()
{

    int c, val, item;
    node *head = NULL; // must declare outside loop.
    node *tail = NULL;
    while (1)
    {

        printf("\n******MENU********\n");
        printf("\n1.Traverse");           // 1
        printf("\n2.Insert at start");    // 1
        printf("\n3.Insert at end");      // 1
        printf("\n4.Delete from start");  // 1
        printf("\n5.Delete from end");    // 1
        printf("\n6.Insert after");       // 1
        printf("\n7.Insert Before");      // 1
        printf("\n8.Delete entire list"); // 1
        printf("\n9.Search");             // 1
        printf("\n10.Reverse");
        printf("\n11.Delete after"); // 1
        printf("\n12.Delete before");
        printf("\n13.Exit\n"); // 1
        printf("\nChoose a option from the menu : ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("\nYou chose to traverse the linked list\n");
            show(head); // only head means addres of first node.
            break;

        case 2:
            printf("\nEnter the value you wanted to add at start : ");
            scanf("%d", &val);
            insertAtStart(&head, &tail, val);
            break;

        case 3:
            printf("\nEnter the value you wanted to add at end : ");
            scanf("%d", &val);
            insertAtEnd(&head, &tail, val);
            break;

        case 4:
            printf("\nFirst value from the list has been deleted");
            deleteAtStart(&head, &tail);
            break;

        case 5:
            printf("\nValue is deleted from the end");
            deleteAtEnd(&head, &tail);
            break;

        case 6:
            printf("Enter the element After which you wanted to add the value and new value you want to add : ");
            scanf("%d %d", &item, &val);
            insertAfter(head, &tail, item, val);
            break;

        case 7:
            printf("Enter the element Before which you wanted to add the value and new value you want to add : ");
            scanf("%d %d", &item, &val);
            insertBefore(&head, tail, item, val);

            break;

        case 8:
            printf("\nLinked list deleted.");
            deleteList(&head, &tail);
            break;

        case 9:
            printf("\nEnter the value whoese address you want : ");
            scanf("%d", &item);
            node *address = search(head, item);
            printf("\n%u is the addres of %d", address, item);
            break;

        case 10:

            break;

        case 11:
            printf("\nEnter the value after which you wanted to delte node : ");
            scanf("%d", &item);
            // deleteAfter(&head, item);
            printf("\nNode Deleted");

            break;

        case 12:
            printf("\nEnter the value befor which you wanted to delte node : ");
            scanf("%d", &item);
            // deleteBefore(&head, item);
            printf("\nNode Deleted");
            break;

        case 13:
            exit(1);
            break;

        default:
            printf("\nEnter a valid option");
            break;
        }
    }
}

void insertAtStart(node **head, node **tail, int val)
{

    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->prev = NULL;

    if (*head == NULL)
    {
        temp->next = NULL;
        *head = temp;
        *tail = temp;
    }
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}

void show(node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty");
    }

    else
    {
        while (head != NULL)
        {
            printf("%d->", head->data);
            head = head->next;
        }
    }
}

node *search(node *head, int item)
{
    if (head == NULL)
    {
        printf("\nlist is empty");
        exit(1);
    }

    else if (head->data == item)
    {
        return head;
    }

    else
    {
        while (head->next != NULL)
        {
            if (head->data == item)
            {
                return head;
            }
            head = head->next;
        }

        if (head->data == item)
        {
            return head;
        }
    }

    printf("\nitem not found");
    return NULL;
}

void insertAtEnd(node **head, node **tail, int val)
{

    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    if (*head == NULL)
    {
        temp->next = NULL;
        *head = temp;
        *tail = temp;
    }

    else
    {

        (*tail)->next = temp;
        temp->prev = *tail;
        *tail = temp;
    }
}

void insertAfter(node *head, node **tail, int item, int val) // head is neccery to travese and tail may need to be changed in a case
{

    node *add = search(head, item);
    if (add == NULL)
    {
        printf("\nitem not found");
    }

    else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = val;
        if (add->next == NULL)
        {
            *tail = temp;
        }
        temp->next = add->next;
        temp->prev = add;
        add->next = temp;
    }
}

void insertBefore(node **head, node *tail, int item, int val) // no use to give tail
{
    if (*head == NULL)
    {
        printf("\nList is empty");
    }

    else if ((*head)->data == item)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = val;
        temp->prev = NULL;
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }

    else
    {
        node *add = search(*head, item);
        // printf("\n%u",add);

        node *temp = (node *)malloc(sizeof(node));
        temp->data = val;
        (add->prev)->next = temp;
        temp->next = add;
        temp->prev = add->prev;
        add->prev = temp;
    }
}

void deleteAtStart(node **head, node **tail)
{
    if (*head == NULL)
    {
        printf("\nList is empty");
    }

    else if ((*head)->next == NULL)
    { // if only one node.
        node *loc = *head;
        free(loc);
        *head = *tail = NULL;
    }

    else
    {
        node *loc = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(loc);
    }
}

void deleteAtEnd(node **head, node **tail)
{

    if (*head == NULL)
    {
        printf("\nList is empty");
    }

    else if ((*head)->next == NULL)
    {
        node *loc = *head;
        free(loc);
        *head = *tail = NULL;
    }

    else
    {
        node *loc = *tail;
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
        free(loc);
    }
}

void deleteList(node **head, node **tail)
{
    if (*head == NULL)
    {
        printf("\nList is empty");
    }

    else
    {
        while ((*head)->next != NULL)
        {
            node *temp = *head;
            *head = (*head)->next;
            free(*head);
        }

        free(*head);
        *head = *tail = NULL;
    }
}

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct dlList
// {
//     struct dlList *prev;
//     int info;
//     struct dlList *next;
// }node;

// void insert_at_beg(node **head1, node **tail, int val)
// {
//    node *temp = (node *)malloc(sizeof(node));
//    temp->prev = NULL;
//    temp->info = val;

//    if(*head1 == NULL)
//    {
//     temp->next = NULL;
//     *head1 = temp;
//     *tail = temp;
//    }else{
//     temp->next = *head1;
//     (*head1)->prev = temp;
//     *head1 = temp;
//    }
// }

// void insert_at_end(node **head1, node **tail1, int val){
//   node temp = (node)malloc(sizeof(node));
//   temp->info = val;
//   temp->next = NULL;
//   if(tail1 == NULL){
//     temp->prev = NULL;
//     *head1 = *tail1 = temp;
//   }else{
//   temp->prev = *tail1;
//   (*tail1)->next = temp;
//   *tail1 = temp;
//   }

// }

// node* search(node *head, int item){
//    while(head != NULL)
//    {
//     if(head->info == item)
//     {
//         return head;
//     }else{
//         head = head->next;
//     }
//    }
// }

// void insert_after(node *head, node **tail, int val, int val2){
//   node temp = (node)malloc(sizeof(node));
//   temp->info = val2;
//   node *loc = search(head, val);
//   if(loc->next == NULL){
//     temp->next = loc->next;
//     temp->prev = loc;
//     *tail = temp;
//   }
//   temp->next = loc->next;
//   temp->prev = loc;
//   (loc->next)->prev = temp;
//   loc->next = temp;
// }

// void insert_before(node **head1, node *tail1, int val, int val2){
//   node temp = (node)malloc(sizeof(node));
//   temp->info = val2;
//   node *loc = search(head1, val2);
//   if(loc->prev != NULL){
//     temp->prev = loc->prev;
//     temp->next = loc;
//     (loc->prev)->next = temp;
//     loc->prev = temp;
//   }
//   if(loc->prev == NULL){
//     temp->next = loc;
//     temp->prev = loc->prev;
//     loc->prev = temp;
//     *head1 = temp;
//   }
// }

// void traverse(node *head){
//   while(head != NULL)
//   {
//     printf("%d->", head->info);
//     head = head->next;
//   }
// }
