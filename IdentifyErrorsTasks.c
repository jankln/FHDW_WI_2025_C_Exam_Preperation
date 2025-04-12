// Aufgaben


// Aufgabe 1
#include <stdio.h>

int main()
{
    int arr[5];
    for (int i = 0; i <= 5; i++)
    {
        arr[i] = i * 2;
    }
    printf("%d\n", arr[5]);
    return 0;
}

// Aufgabe 2
#include <stdio.h>

int main()
{
    int x, y;
    x += 10;
    y = x * 2;
    printf("Ergebnis: %d\n", y);
    return 0;
}

// Aufgabe 3
#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 5; i++)
        ;
    printf("i ist: %d\n", i);
    return 0;
}

// Aufgabe 4
#include <stdio.h>

float division(int a, int b)
{
    return a / b;
}

int main()
{
    printf("%f\n", division(5, 0));
    return 0;
}

// Aufgabe 5
#include <stdio.h>

int main()
{
    char text[5];
    text[0] = 'H';
    text[1] = 'a';
    text[2] = 'l';
    text[3] = 'l';
    text[4] = 'o';
    printf("%s\n", text);
    return 0;
}

// Aufgabe 6
#include <stdio.h>

int summe(int arr[], int size)
{
    int sum;
    for (int i = 0; i <= size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int werte[3] = {1, 2, 3};
    printf("%d\n", summe(werte, 3));
    return 0;
}

// Aufgabe 7
#include <stdio.h>

int main()
{
    int *p;
    *p = 100;
    printf("%d\n", *p);
    return 0;
}

// Aufgabe 8
#include <stdio.h>

struct Person
{
    char name[10];
    int alter;
};

int main()
{
    struct Person p;
    p.alter++;
    printf("%s ist %d Jahre alt\n", p.name, p.alter);
    return 0;
}

// Aufgabe 9
#include <stdio.h>

int main()
{
    int i = 0;
    while (i < 5)
        i++;
    printf("%d\n", i);
    return 0;
}

// Aufgabe 10
#include <stdio.h>

int main()
{
    int n = 5;
    int feld[n];
    for (int i = 0; i < n; i++)
    {
        feld[i] = i * 2;
    }
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", feld[i]);
    }
    return 0;
}
