
#include <stdio.h>

int stLength(char st[])
{
    int length = 0;
    while (st[length] != '\0')
    {
        length++;
    }
    return length;
}

int numberVocals(char st[])
{
    int vocals = 0;

    for (int i = 0; i < stLength(st); i++)
    {
        switch (st[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            vocals++;
            break;
        }
    }
    return vocals;
}

void stMerge(char st[], char st2[], char st3[])
{
    int laengeBeide = stLength(st) + stLength(st2);
    for (int i = 0; i < stLength(st); i++)
    {
        st3[i] = st[i];
    }
    for (int j = stLength(st) + 1; j < laengeBeide; j++)
    {
        st3[j] = st2[j];
    }
}

void ChangeLetters(char st[])
{
    for (int i = 0; i < stLength(st); i++)
    {

        if (st[i] >= 'a' && st[i] <= 'z')
        {
            st[i] += 'A' - 'a';
        }
        else
        {
            st[i] += 'a' - 'A';
        }
    }
}

void ReverseString(char st[])
{
    char reverse[100];
    int j = 0;
    for (int i = stLength(st); i > 0; i--)
    {
        reverse[j] = st[i - 1];
        j++;
    }

    reverse[stLength(st)] = '\0';
    printf("\nReversed String: %s", reverse);
}

int main()
{
    char st1[100] = "Hallo";
    char st2[100] = "Welt";
    char st3[100];

    stMerge(st1, st2, st3);
    printf("String Laenge: %d", stLength(st1));
    printf("\nAnzahl Vokale: %d", numberVocals(st1));
    printf("\nMerged String: %s", st3);

    ChangeLetters(st2);
    printf("\nChanged String: %s", st2);

    ReverseString(st1);

    return 0;
}
