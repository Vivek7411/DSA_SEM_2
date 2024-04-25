#include <stdio.h>
#include <stdlib.h>

void addarr(int[2][2], int[2][2]);
void mularr(int[2][2], int[2][2]);
void traarr(int[2][2]);

void main()
{
    while (1)
    {

        int choice;

        int arr1[2][2] = {{1, 2}, {3, 4}};
        int arr2[2][2] = {{3, 4}, {5, 6}};

        printf("Enter your Choice : ");

        printf("\nChoices\n1.Add");
        printf("\n2.Multiply");
        printf("\n3.Transpose");
        printf("\n4.Exit");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addarr(arr1, arr2);
            break;

        case 2:
            mularr(arr1, arr2);
            break;

        case 3:
            traarr(arr1);
            break;

        case 4:
            exit(1);
        }
    }
}

void addarr(int a[2][2], int b[2][2])
{
    int c[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
}

void mularr(int a[2][2], int b[2][2])
{
    int c[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c[i][j] = a[i][k] + b[k][j];
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
}

void traarr(int a[2][2])
{
    int c[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = a[j][i];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
}
