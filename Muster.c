#include <stdio.h>

int main()
{
    const int n = 12;
    int counter = 0;
    int counter2 = n;
    int counter3 = 0;
    int counter32 = n;

    // Task 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("x");
        }
        printf("\n");
    }

    printf("\n");

    // Task 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == counter)
            {
                printf("O");
            }
            else
            {
                printf("X");
            }
        }
        counter++;
        printf("\n");
    }

    printf("\n");

    // Task 3
    for (int i = 0; i < n; i++)
    {
        counter2--;
        for (int j = 0; j < n; j++)
        {
            if (j == counter2)
            {
                printf("O");
            }
            else
            {
                printf("X");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Task 4
    counter3 = 0;
    counter32 = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == counter3 && j == counter32)
            {
                printf("A");
            }
            else if (j == counter3)
            {
                printf("A");
            }
            else if (j == counter32)
            {
                printf("B");
            }
            else
            {
                printf("X");
            }
        }
        counter3++;
        counter32--;
        printf("\n");
    }
    printf("\n");

    // Task 5
    int x = 1;
    int empty = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < empty; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < x; k++)
        {
            printf("X");
        }
        printf("\n");
        empty--;
        x += 2;
    }

    x -= 4;
    empty = 1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < empty; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < x; k++)
        {
            printf("X");
        }
        printf("\n");
        empty++;
        x -= 2;
    }

    return 0;
}
