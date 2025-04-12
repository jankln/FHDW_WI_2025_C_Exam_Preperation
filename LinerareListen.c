#include <stdio.h>
#include <stdlib.h>

struct Elem_
{
    int wert;
    char *Name;

    struct Elem_ *next;
};
typedef struct Elem_ Elem;

void strCopy(char *von, char *nach)
{
    while (*von != '\0')
    {
        // printf("%c\n", *von);

        *nach = *von;

        von++;
        nach++;
    }
    *nach = '\0';
}

int strLen(char *st)
{
    int len = 0;

    while (*st++)
        len++;

    return len;
}
char *CreateString(char *st)
{
    char *st1 = (char *)malloc((strLen(st) + 1) * sizeof(char));

    strCopy(st, st1);

    return st1;
}

Elem *CreateElem(int wert, char *name)
{
    Elem *E = (Elem *)malloc(sizeof(Elem));

    E->wert = wert;
    E->Name = CreateString(name);
    E->next = NULL;

    return E;
}

Elem *createList()
{
    Elem *E = CreateElem(0, "Hugo");

    return E;
}

Elem *AddElemToList(Elem *L, int wert)
{

    Elem *E = CreateElem(wert, "Hugo");

    E->next = L->next;
    L->next = E;
    return L;
}

void PrintElem(Elem *E)
{
    printf("  %d\n", E->wert);
}
void PrintList(Elem *L)
{

    printf("List:\n");
    L = L->next;

    while (L != NULL)
    {
        PrintElem(L);
        L = L->next;
    }
}
Elem *AddElemToListEnd(Elem *L, int wert)
{

    Elem *L1 = L;

    while (L1->next != NULL)
    {
        L1 = L1->next;
    }
    L1->next = CreateElem(wert, "Hugo");

    return L;
}

int isListEmpty(Elem *L)
{
    int no = 0;
    L = L->next;
    while (L != NULL)
    {
        no++;
        L = L->next;
    }
    return no;
}

Elem *FindPrevElem(Elem *L, int wert)
{

    Elem *prevE = L;
    Elem *nextE = L->next;

    while (nextE != NULL)
    {
        if (nextE->wert == wert)
            return prevE;

        prevE = nextE;
        nextE = nextE->next;
    }
    return nextE;
}

Elem *DeleteElem(Elem *L, int wert)
{

    Elem *prevE = FindPrevElem(L, wert);
    Elem *nextE;
    if (prevE != NULL)
    {
        nextE = prevE->next;
        prevE->next = nextE->next;

        free(nextE);
    }
    return L;
}

Elem *FindSmallestListElem(Elem *L)
{
    int smallest;
    Elem *smallestE;
    L = L->next;
    if (L != NULL)
    {
        smallest = L->wert;
        smallestE = L;
        while (L != NULL)
        {
            if (smallest > L->wert)
            {
                smallest = L->wert;
                smallestE = L;
            }
            L = L->next;
        }
        return smallestE;
    }
    return NULL;
}

Elem *SortList(Elem *L1)
{

    Elem *L2 = createList();

    while (isListEmpty(L1) != 0)
    {
        Elem *smallestE = FindSmallestListElem(L1);

        L2 = AddElemToListEnd(L2, smallestE->wert);

        L1 = DeleteElem(L1, smallestE->wert);
    }
    free(L1);

    return L2;
}

int main()
{

    Elem *L = createList();
    int NoElems;

    L = AddElemToList(L, 3);
    L = AddElemToList(L, 2);
    L = AddElemToListEnd(L, 1);
    L = AddElemToList(L, 34);
    L = AddElemToList(L, 54);
    L = AddElemToListEnd(L, 4);

    PrintList(L);

    if ((NoElems = isListEmpty(L)) == 0)
        printf("L ist leer\n");
    else
        printf("L enthaelt %d Elemente\n", NoElems);

    printf("Der Vorgaenger von 3 ist:");
    Elem *prevE = FindPrevElem(L, 3);
    PrintElem(prevE);

    L = DeleteElem(L, 3);
    PrintList(L);

    printf("das kleinste Element ist:");
    Elem *smallestE = FindSmallestListElem(L);
    PrintElem(smallestE);

    L = SortList(L);
    PrintList(L);

    return 0;
}
