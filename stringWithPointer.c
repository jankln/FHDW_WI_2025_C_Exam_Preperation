#include <stdio.h>
#include <stdlib.h>

void AddiereArrays(int *ia, int *ib, int *ic, int Arraylaenge);
void PrintArray(int *ia, int Arraylaenge);

int main()
{
    int Arraylaenge = 5;
    int *ia = (int *)malloc(Arraylaenge * sizeof(int));
    int *ib = (int *)malloc(Arraylaenge * sizeof(int));
    int *ic = (int *)malloc(Arraylaenge * sizeof(int));

    for (int i = 0; i < Arraylaenge; i++)
    {
        *(ia + i) = i + 1;
        *(ib + i) = i + 6;
    }

    AddiereArrays(ia, ib, ic, Arraylaenge);
    PrintArray(ia, Arraylaenge);

    free(ia);
    free(ib);
    free(ic);

    return 0;
}

void AddiereArrays(int *ia, int *ib, int *ic, int Arraylaenge)
{
    printf("Array ic:");
    for (int i = 0; i < Arraylaenge; i++)
    {
        *(ic + i) = *(ia + i) + *(ib + i);
        printf("\n%d", *(ic + i));
    }
}

void PrintArray(int *ia, int Arraylaenge)
{
    printf("\nArray ia:");
    for (int i = 0; i < Arraylaenge; i++)
    {
        printf("\n%d", *(ia + i));
    }
}
