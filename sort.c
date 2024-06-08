#include <stdio.h>
void inarr(int[], int);
void outarr(int[], int);
void bubble(int[], int);
void selection(int[], int);
void insertion(int[], int);

void main()
{

    int ch, a[10];

    while (1)
    {
        inarr(a, 5);

        printf("\nSelect a option form the menu\n");
        printf("\n1.BubbleSort");
        printf("\n2.InsertionSort");
        printf("\n3.SelectonSort\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nBefore sort :\n");
            outarr(a, 5);
            printf("\nAfter sort :\n");
            bubble(a, 5);
            outarr(a, 5);
            break;

        case 2:

            printf("\nBefore sort :\n");
            outarr(a, 5);
            printf("\nAfter sort :\n");
            insertion(a, 5);
            outarr(a, 5);
            break;


        case 3:

            printf("\nBefore sort :\n");
            outarr(a, 5);
            printf("\nAfter sort :\n");
            selection(a, 5);
            outarr(a, 5);
            break;

        default:
            printf("\nChoose a correct choice");
            break;
        }
    }
}

void inarr(int a[], int n)
{
    printf("\nEnter elements of array of size %d :\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void outarr(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}

void bubble(int a[], int n)
{

    int pass, i, temp,flag=1;//so that loop runs for th e first time.

    for (pass = 1; (pass < n) && flag; pass++)
    {
        flag=0;// if swaping does not happen then next time no need to run loop.
        for (int i = 0; i < (n - pass); i++)
        {
            if (a[i] > a[i + 1])
            {   
                flag=1;//array is not sorted so run the loop next time.
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
            
        }
    }
}

void insertion(int a[], int n){

int c;
}

void selection(int a[], int n){  

    int min, mini, i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        mini = i;
        for (j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                mini = j;
            }
        }
        if (i != mini)
        {
            temp = a[i];
            a[i] = a[mini];
            a[mini] = temp;
        }
    }

}




// void selectionsort(int a[], int n)
// {
//     int min, mini, i, j, temp;
//     for (i = 0; i < n - 1; i++)
//     {
//         min = a[i];
//         mini = i;
//         for (j = i + 1; j < n; j++)
//         {
//             if (min > a[j])
//             {
//                 min = a[j];
//                 mini = j;
//             }
//         }
//         if (i != mini)
//         {
//             temp = a[i];
//             a[i] = a[mini];
//             a[mini] = temp;
//         }
//     }
// }
