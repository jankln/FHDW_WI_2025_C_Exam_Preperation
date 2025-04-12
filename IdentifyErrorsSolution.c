/******************************************************************************
 * Aufgabe 1 - Korrektur
 * Was war falsch?
 * - Die Schleife lief mit i <= 5 und griff damit außerhalb des Array-Bereichs zu.
 * - arr[5] ist Out-of-Bounds, denn das Array arr[5] besitzt gültige Indizes 0..4.
 ******************************************************************************/
#include <stdio.h>

int main_Aufgabe1(void)
{
    int arr[5];
    // KORREKTUR: Schleife nur bis i < 5
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 2;
    }
    // KORREKTUR: Auf Index 4 statt 5 zugreifen
    printf("%d\n", arr[4]);
    return 0;
}

/******************************************************************************
 * Aufgabe 2 - Korrektur
 * Was war falsch?
 * - Variable x war nicht initialisiert, x += 10 führt zu undefiniertem Verhalten.
 ******************************************************************************/
#include <stdio.h>

int main_Aufgabe2(void)
{
    // KORREKTUR: x und y initialisieren
    int x = 0, y = 0;
    x += 10;
    y = x * 2;
    printf("Ergebnis: %d\n", y); // Sollte nun 20 sein
    return 0;
}

/******************************************************************************
 * Aufgabe 3 - Korrektur
 * Was war falsch?
 * - Semikolon hinter der for-Schleife sorgt dafür, dass die Schleife keinen
 *   sichtbaren Block hat. Die printf-Anweisung liegt außerhalb der Schleife.
 ******************************************************************************/
#include <stdio.h>

int main_Aufgabe3(void)
{
    // KORREKTUR: Semikolon entfernt
    for (int i = 0; i < 5; i++)
    {
        printf("i ist: %d\n", i);
    }
    return 0;
}

/******************************************************************************
 * Aufgabe 4 - Korrektur
 * Was war falsch?
 * - Division durch 0 (b kann 0 sein).
 * - Ganzzahldivision ohne Typumwandlung bei float-Rückgabewert.
 ******************************************************************************/
#include <stdio.h>

// KORREKTUR: Schutz vor Division durch 0 und Typumwandlung auf float
float division(int a, int b)
{
    if (b == 0)
    {
        printf("Fehler: Division durch Null!\n");
        return 0.0f;
    }
    return (float)a / (float)b;
}

int main_Aufgabe4(void)
{
    printf("%f\n", division(5, 0));
    printf("%f\n", division(5, 2));
    return 0;
}

/******************************************************************************
 * Aufgabe 5 - Korrektur
 * Was war falsch?
 * - Kein Platz für '\0'-Terminierung im Array "text".
 * - Dadurch wird keine gültige C-String-Ausgabe möglich sein.
 ******************************************************************************/
#include <stdio.h>

int main_Aufgabe5(void)
{
    // KORREKTUR: Array sollte mindestens 6 Zeichen haben (5 + '\0')
    char text[6];
    text[0] = 'H';
    text[1] = 'a';
    text[2] = 'l';
    text[3] = 'l';
    text[4] = 'o';
    text[5] = '\0'; // Nullterminator
    printf("%s\n", text);
    return 0;
}

/******************************************************************************
 * Aufgabe 6 - Korrektur
 * Was war falsch?
 * - Variable sum nicht initialisiert.
 * - Schleife mit i <= size greift außerhalb des Bereichs zu.
 ******************************************************************************/
#include <stdio.h>

int summe(int arr[], int size)
{
    // KORREKTUR: sum initialisieren
    int sum = 0;
    // KORREKTUR: Schleife nur bis i < size
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main_Aufgabe6(void)
{
    int werte[3] = {1, 2, 3};
    printf("%d\n", summe(werte, 3));
    return 0;
}

/******************************************************************************
 * Aufgabe 7 - Korrektur
 * Was war falsch?
 * - Pointer p wurde nie initialisiert (zeigt ins Nirgendwo).
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main_Aufgabe7(void)
{
    // KORREKTUR: Speicher allozieren oder auf lokale Variable zeigen
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL)
    {
        return 1;
    }
    *p = 100;
    printf("%d\n", *p);
    free(p);
    return 0;
}

/******************************************************************************
 * Aufgabe 8 - Korrektur
 * Was war falsch?
 * - Struktur p.name und p.alter wurden nicht initialisiert.
 * - p.alter++ erhöht einen Zufallswert.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

struct Person
{
    char name[10];
    int alter;
};

int main_Aufgabe8(void)
{
    struct Person p;
    // KORREKTUR: Felder initialisieren
    strcpy(p.name, "Max");
    p.alter = 0;
    p.alter++;
    printf("%s ist %d Jahre alt\n", p.name, p.alter);
    return 0;
}

/******************************************************************************
 * Aufgabe 9 - Korrektur
 * Was war falsch?
 * - Fehlende geschweifte Klammern bei der while-Schleife, wodurch die printf
 *   außerhalb der Schleife ausgeführt wird.
 ******************************************************************************/
#include <stdio.h>

int main_Aufgabe9(void)
{
    int i = 0;
    // KORREKTUR: Geschweifte Klammern hinzufügen
    while (i < 5)
    {
        i++;
        printf("%d\n", i);
    }
    return 0;
}

/******************************************************************************
 * Aufgabe 10 - Korrektur
 * Was war falsch?
 * - Zweite Schleife greift mit i <= n auf feld[n] zu, was Out-of-Bounds ist.
 ******************************************************************************/
#include <stdio.h>

int main_Aufgabe10(void)
{
    int n = 5;
    int feld[5];
    for (int i = 0; i < n; i++)
    {
        feld[i] = i * 2;
    }
    // KORREKTUR: Schleife nur bis i < n
    for (int i = 0; i < n; i++)
    {
        printf("%d ", feld[i]);
    }
    printf("\n");
    return 0;
}
