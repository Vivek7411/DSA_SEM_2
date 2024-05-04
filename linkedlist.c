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
    node *temp = head1; // no need of temp.............?????
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

/*


                        #include<stdio.h>
#include<Stdlib.h>
typedef struct link{
    int info;
    struct link *next;
}node;

node* search(node *head, int item){
   while(head != NULL)
   {
    if(head->info == item)
    {
        return head;
    }else{
        head = head->next;
    }
   }
}
void insert_at_beg(node **head1, int val)
{
    node temp = (node)malloc(sizeof(node));
    temp->info = val;
    if(*head1 == NULL)
    {
      temp->next = NULL;
    }else{
        temp->next = *head1;
    }

    *head1 = temp;
}

void insert_at_end(node **head1, int val){

    node temp = (node)malloc(sizeof(int));
    temp->info = val;
    temp->next = NULL;
    if(*head1 == NULL){

      *head1 = temp;
    }else{
        node *loc = *head1;
        while(loc->next != NULL){

           loc = loc->next;
        }
        loc->next = temp;
    }
}


void insert_after(node **head1,int item, int val){
   node *loc = search(*head1, 3);
    if (loc == NULL) {
        printf("item not found");
        return;
    }
   node temp = (node)malloc(sizeof(node));
   temp->info = val;
   temp->next = loc->next;
   loc->next = temp;
}

void traverse(node *head1){
    node *temp = head1;
    if(temp == NULL){
    printf("no modes found");
    }
    while(temp != NULL)
    {
        printf("%d->", temp->info);
        temp = temp->next;
    }
}

void delete_at_beg(node **head1){
    node *temp = *head1;
    *head1 = (*head1)->next;
    free(temp);
}

void delete_at_end(node**head1){
    node *temp = (*head1);
    node *loc;
    if(temp->next == NULL)
    {
        loc = (*head1);
        (*head1) = NULL;
        free(loc);

    }else{
        loc = *head1;
    while(loc->next != NULL)
    {
      temp = loc;
      loc = loc->next;
    }
     temp->next = NULL;
     free(loc);
    }
}

void delete_after(node **head1, int val)
{
    node *loc = search(*head1, val);
    node *temp = loc->next;
    loc->next = temp->next;
    free(temp);

}

void delete_entire(node **head1){
    node *temp = *head1;
    node *loc;
    while(temp != NULL){
        loc = temp->next;
        free(temp);
        temp = loc;
    }
    *head1 = NULL;
}



void main()
{
//     int op;
//     while(1){

//     printf("1: Insert at begining\n");
//     printf("2: Insert after element\n");
//     printf("3: Insert at end\n");
//     printf("4: traverse\n");
//     printf("5: traverse in reverse\n");
//     printf("6: Delete at begining\n");
//     printf("7: Delete at end\n");
//     printf("8: Delete after element\n");
//     printf("9: delete entire list\n");
//     printf("10: search an element\n");
//     printf("11: Reverse the list\n");
//     printf("12: Exit\n");
//     printf("\nEnter your choice: \n");
//     scanf("%d",op);

//     break;
//     }

       node *head = NULL;

insert_at_beg(&head, 3);
insert_at_beg(&head, 'a');
insert_at_beg(&head, 2);
insert_at_beg(&head, 1);
insert_at_end(&head, 4);
// delete_at_beg(&head);
insert_after(&head,3, 5);
// delete_at_end(&head);
delete_after(&head, 97);
delete_entire(&head);

traverse(head);
printf("*");
}







//    node head1 = (node)malloc(sizeof(node));
//     head->info = 10;
//     head->next = head1;
//     head1->info = 20;
//     head1->next = NULL;


*/