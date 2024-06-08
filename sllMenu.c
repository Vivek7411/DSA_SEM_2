// Role of head1 is to point to the head pointer.
// *head1 means value at(derefeer) address which is stored in head1;
// means the value stored at head pointer.
// when changing value use call by pointer else use call by val(in which head addres will be given.)
// head and *head1 points to same thing i.e first node.
// *head1 cant be used with -> so store *head1 in temp or use (*head1)-> why used in delete.
// when trying to free memeonry call by pointer **node is recommende cuz issue in freeing memory then.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
} node;

void insertAtStart(node **, int);
void insertAtEnd(node **, int);
void show(node *);
void insertAfter(node **, int, int);
node *search(node *, int);
void deleteAtStart(node **);
void deleteAtEnd(node **);
void insertBefore(node **, int, int);
void deleteList(node **);
void deleteAfter(node **, int);
void deleteBefore(node **, int);


// void deleteAtEnd2(node *);
// void insertBefore(node **,int,int); // i belive insert before is not possiable in sll.

void main()
{

    int c, val, item;
    node *head = NULL; // must declare outside loop.

    while (1)
    {

        printf("\n******MENU********\n");
        printf("\n1.Traverse");          // 1
        printf("\n2.Insert at start");   // 1
        printf("\n3.Insert at end");     // 1
        printf("\n4.Delete from start"); // 1
        printf("\n5.Delete from end");   // 1
        printf("\n6.Insert after");      // 1
        printf("\n7.Insert Before");     // 1
        printf("\n8.Delete entire list");//1
        printf("\n9.Search"); // 1
        printf("\n10.Reverse");
        printf("\n11.Delete after");//1
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
            insertAtStart(&head, val);
            break;

        case 3:
            printf("\nEnter the value you wanted to add at end : ");
            scanf("%d", &val);
            insertAtEnd(&head, val);
            break;

        case 4:
            printf("\nFirst value from th e list has been deleted");
            deleteAtStart(&head);
            break;

        case 5:
            printf("\nValue is deleted from the end");
            deleteAtEnd(&head);
            break;

        case 6:
            printf("Enter the element After which you wanted to add the value and new value you want to add : ");
            scanf("%d %d", &item, &val);
            insertAfter(&head, item, val);
            break;

        case 7:
            printf("Enter the element Before which you wanted to add the value and new value you want to add : ");
            scanf("%d %d", &item, &val);
            insertBefore(&head, item, val);

            break;

        case 8:
            printf("\nLinked list deleted.");
            deleteList(&head);
            break;

        case 9:
            printf("\nEnter the value whoese address you want : ");
            scanf("%d", &item);
            node *address = search(head, item);
            //printf("\n%u is the addres of %d", address, item);
            break;

        case 10:

            break;

        case 11:
            printf("\nEnter the value after which you wanted to delte node : ");
            scanf("%d",&item);
            deleteAfter(&head,item);
            printf("\nNode Deleted");

            break;

        case 12:
            printf("\nEnter the value befor which you wanted to delte node : ");
            scanf("%d",&item);
            deleteBefore(&head,item);
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

void insertAtStart(node **head1, int val)
{

    node *temp = (node *)malloc(sizeof(node));

    if (temp == NULL)
    {
        printf("\noverflow");
        exit(1);
    }

    temp->item = val;
    if (*head1 == NULL)
    {
        temp->next = NULL;
    }

    else
    {
        temp->next = *head1;
    }

    *head1 = temp;

    printf("\nreacheeeeeeeeed");
}

void show(node *head1)
{

    // node *temp = head1;
    // head1 here is local pointer used to travers linked list which has address of first node not head pointer.

    if (head1 == NULL)
    {
        printf("\nList is empty.");
    }

    while (head1 != NULL)
    {
        printf("%d->", head1->item);
        head1 = head1->next;
    }
}

void insertAtEnd(node **head1, int val)
{
    node *temp = malloc(sizeof(node));

    temp->item = val;
    temp->next = NULL;

    if (*head1 == NULL)
    {
        *head1 = temp;
    }
    else
    {
        node *loc = (node *)malloc(sizeof(node));
        loc = *head1;
        while (loc->next != NULL)
        {
            loc = loc->next;
        }
        loc->next = temp;
    }
}

node *search(node *head1, int val)
{ // this is call by value.

    // while (head1->item == val) // first condition is only correct.
    // {
    //     head1 = head1->next;
    // }

    while (head1 != NULL)
    {
        if (head1->item == val)
        {
            // printf("9349u394uhello--");

            return head1;
        }

        else
        {
            // printf("hello--");
            head1 = head1->next;
        }
    }
    printf("\nitem not found ");
}

void insertAfter(node **head1, int item, int val)
{

    node *temp = (node *)malloc(sizeof(node));

    temp->item = val;

    node *loc = search(*head1, item);
    if (loc == NULL)
    {
        printf("\niteam not found");
    }

    temp->next = loc->next;
    loc->next = temp;
}

void deleteAtStart(node **head1)
{

    // node *temp=*head1; // no need if we use (*head1)->

    if (*head1 == NULL)
    {
        printf("\nList is already empty");
    }

    else
    {
        node *temp = *head1;
        *head1 = (*head1)->next;
        free(temp);
    }
}

void deleteAtEnd(node **head1)
{

    if (*head1 == NULL)
    {
        printf("\nList is empty");
        exit(1);
    }

    else if ((*head1)->next == NULL)
    {
        free(*head1);
        *head1 = NULL;
    }

    else
    {
        node *temp = *head1;

        while ((temp->next)->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void insertBefore(node **head1, int item, int val)
{
    if (*head1 == NULL)
    {
        printf("\nList is empty");
        // exit(0);
    }

    else if ((*head1)->next == NULL)
    {

        if ((*head1)->item != item)
        {
            printf("Iteam not found");
        }

        else // in this case we could have called insert at start.
        {
            node *newnode = (node *)malloc(sizeof(node));
            newnode->item = val;
            newnode->next = *head1;
            *head1 = newnode;
            // old*head1->next already had a null.
        }
    }

    else
    {
        node *temp = *head1;

        while ((temp->next)->item != item)
        {
            temp = temp->next;
        }

        node *newnode = (node *)malloc(sizeof(node));
        newnode->item = val;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteList(node **head1)
{
    node *temp, *loc;
    temp = *head1;

    if (*head1 == NULL)
    {
        printf("\nList is allready empty");
    }

    while (temp->next != NULL)
    {
        // order of below statements is rally important.
        loc = temp;        // give current node address to loc
        temp = temp->next; // give next node address to temp.
        free(loc);         // free the current node.

        // if u free the current node first then it is unsafe or impossiable to find next node address.

        printf("\nwhile");
    }
    printf("\nwhile out ");

    free(temp);
    *head1 = NULL;
}

void deleteAfter(node **head1, int item)
{

    node *temp = search(*head1, item);

    if (temp->next == NULL)
    { // this handels both the first and last node.
        printf("\nThere is no element after %d ", item);
    }

    else
    {
        node *loc = temp->next;          // give loc the address which is to be freed.
        temp->next = (temp->next)->next; // if only 1 node after the node to be deleted then null is also handeld.
        free(loc);
    }
}

void deleteBefore(node **head1, int item){
    if(*head1==NULL || (*head1)->next==NULL){
        printf("\nThere is notthing before this node or list is empty.");
    }

    else if(((*head1)->next)->next==NULL && ((*head1)->next)->item==item){// if there is only 2 nodes.
        node *temp=*head1;
        *head1=(*head1)->next;
        free(temp);
    }

    else{
        node *temp=*head1;

        while (temp->next!=NULL)
        {
            if(((temp->next)->next)->item!=item){
                node *loc=temp->next;// giving loc the addres which is to freed.
                temp->next=loc->next;// giving current node the next part of node which going to deleted.
                free(loc);
            }

            // else{// this else not returning control to main.....?***********************************
            //     temp=temp->next;
            //     printf("\nHiii");
            // }

                temp=temp->next;
                printf("\nHiii");

        }

        printf("\nIteam not found");        
    }
}

























// void deleteBefore(node **head1, int item){

//     if (item==(*head1)->item)
//     {
//         printf("\nThere is nothing before this %d ",item);
//     }

//     node *temp=*head1;

//      while(((temp)->next)->next!=NULL){// run this loop until we are at node after which we need to delete
//         if((temp->next)->item==item){
//             node *loc=temp;//give address of node which is to be deeted to loc.

//         }
//     }
//     if((temp->next)->item==item){// checking if last node is the node which is to be find.

//     }
   

//     //now we
    
// }












//  while(((temp)->next)->item!=item && (temp->next)->next!=NULL){// run this loop until we are at node after which we need to delte AND we are at the secound last node
//         if((temp->next)->next!=NULL){
            
//         }
//     }





// sumit delete entire code writing comments to understand
//  void delete_entire(node **head1){
//      node *temp = *head1;
//      node *loc;
//      while(temp != NULL){//stop when current node is null
//          loc = temp->next;//give loc address of next node.
//          free(temp);//delete current node.
//          temp = loc;//give temp address of next node
//      }
//      *head1 = NULL;
// }

// void deleteAtEnd2(node *head)
// {

//     if (head == NULL)
//     {
//         printf("\nlist is already enpty: ");
//         printf("\nhi i am if");

//     }

//     else if (head->next == NULL)
//     {
//         free(head);
//         head==NULL; // but this wont make og head to point to null.
//         printf("\nhi i am else if");

//     }

//     else
//     {
//         printf("\nhi i am else");

//         while ((head->next)->next != NULL)
//         {

//             printf("\nhi i am while");
//             head = head->next;
//         }

//         printf("\nhi i am out side while");
//         node *temp=head->next;
//         free(temp);
//         head->next == NULL; // ****************this is not working or the above one*******************//
//         printf("\n%d",head->item);
//         printf("\n%d",head->next);

//     }
// }

// void deleteAtEnd2(node *temp){

//     if(temp==NULL){
//         printf("\nList is allready empty");
//     }

//     else{
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         free(temp);
//     }
// }

// void deleteAtEnd(node **head1){

//     if(*head1==NULL){
//         printf("\nList is already empty");
//     }
//     else{
//         // while((*head1)->next!=NULL){
//         //     *head1=(*head1)->next;
//         // }
//         // free(head1);
//         //this changes the og value of head.

//         node *temp=*head1;

//         while(*temp!=NULL){
//             // actuall no need to use double pointer here since there will be no change in head value.
//             //no no no what if only one node is there.
//             //but i dont want to use double here discuss it
//         }
//     }
// }
