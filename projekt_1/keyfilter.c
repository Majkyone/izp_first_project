/*
Marián Šuľa
259787
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// velkost podporovaneho pola
#define LENGTH 101
#define ROW 42
#define SIZE ROW *LENGTH
// funkcie potrebne k fungovaniu programu
int arraySize(char array[]);
char lowerCaseToUpperCase(char letter);
char upperCaseToLowerCase(char letter);
char *arrayCleaner(char array[]);
char *lowerCaseToUpperCaseArray(char array[]);
char *fixInput(char array[]);
char *fromAtoZ(char array[]);
int error(char letter);

int main(int argc, char *argv[])
{
    // nespravny pocet argumentov
    if (argc < 1)
    {
        fprintf(stderr, "Too few arguments");
        return 1;
    }
    if (argc > 2)
    {
        fprintf(stderr, "Too many arguments");
        return 1;
    }

    char fileArray[SIZE] = {0};
    char characters[SIZE] = {0};
    char *inputChar;
    int letter;
    int i = 0, j = 0;
    // nacitanie adries do pola, zistenie zaciatocnych pismen a zmena malych pismen na velke a naopak
    while ((letter = getchar()) != EOF)
    {
        error(letter);
        fileArray[i] = letter;
        fileArray[i] = upperCaseToLowerCase(fileArray[i]);
        fileArray[0] = lowerCaseToUpperCase(fileArray[0]);
        characters[0] = fileArray[0];

        if (fileArray[i] == '\n')
        {
            j++;
            i++;
            fileArray[i] = getchar();
            fileArray[i] = lowerCaseToUpperCase(fileArray[i]);
            characters[j] = fileArray[i];
        }

        i++;
    }

    // argument je iba textovy subor s adresami
    if (argc == 1)
    {
        printf("Enable: %s\n", fromAtoZ(arrayCleaner(characters)));
    }
    char choices[SIZE] = {0};
    // argumenty su pismena zadane uzivatelom a textovy subor
    if (argc == 2)
    {

        inputChar = fixInput(argv[1]);

        int i = 0, j = 0, k = 0, l = 0;
        int size = arraySize(fileArray);
        char word[SIZE] = {0};

        // zistenie nasledujuceho pismena a slova
        while (fileArray[i] != '\0')
        {
            while (((fileArray[i] == inputChar[k]) && (fileArray[i] != '\n')))
            {

                k++;
                i++;
                if (k == arraySize(inputChar))
                {
                    choices[j] = fileArray[i];
                    j++;
                    while ((fileArray[i] != '\n') && i <= size)
                    {
                        word[l] = fileArray[i];
                        l++;
                        i++;
                    }
                }
            }

            k = 0;
            i++;
        }
        // Slovo sa nenachadza v databaze
        if (arraySize(choices) == 0)
        {
            printf("Not Found\n");
        }
        // program nasiel hladane slovo
        if (arraySize(choices) == 1)
        {
            printf("Found: %s%s\n", lowerCaseToUpperCaseArray(inputChar), lowerCaseToUpperCaseArray(word));
        }
        // program potrebuje dalsiu specifikaciu pre hladane slovo
        if (arraySize(choices) > 1)
        {

            printf("Enable: %s\n", lowerCaseToUpperCaseArray(fromAtoZ(arrayCleaner(choices))));
        }
    }

    return 0;
}
// zistenie velkosti pola
int arraySize(char array[])
{
    int i = 0, size = 0;

    while (i < (int)strlen(array))
    {
        if (error(array[i]) == 0)
        {
            i++;
            size++;
        }
    }

    return size;
}
// odstrani redundantne data
char *arrayCleaner(char array[])
{
    int size = arraySize(array);
    for (int i = 0; i <= size; i++)
    {
        for (int j = i + 1; j <= size; j++)
        {
            if (array[i] == array[j])
            {
                for (int k = j; k <= size; k++)
                {
                    array[k] = array[k + 1];
                }
                size--;
                j--;
            }
        }
    }
    return array;
}
// zmena malych pismen na velke
char lowerCaseToUpperCase(char letter)
{
    if ((letter >= 'a' && letter <= 'z'))
    {
        letter += ('A' - 'a');
    }
    return letter;
}
// zmena velkych pismen na male
char upperCaseToLowerCase(char letter)
{
    if ((letter >= 'A' && letter <= 'Z'))
    {
        letter += ('a' - 'A');
    }
    return letter;
}
// zmena malych pismen na velke v celom poly
char *lowerCaseToUpperCaseArray(char array[])
{
    for (int i = 0; i < arraySize(array); i++)
    {
        array[i] = lowerCaseToUpperCase(array[i]);
    }
    return array;
}
// zmena inputu ak pouzivatel zadal zle male a velke pismena
char *fixInput(char array[])
{
    array[0] = lowerCaseToUpperCase(array[0]);
    for (int i = 1; i < arraySize(array); i++)
    {
        array[i] = upperCaseToLowerCase(array[i]);
    }
    return array;
}
// chybova hlaska
int error(char letter)
{

    if (!((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z') || (letter == '\n') || (letter == ' ') || (letter == '-')))
    {
        fprintf(stderr, "Wrong input\n");
        exit(1);
    }
    else
    {
        return 0;
    }
}

// vypise pole od A po Z
char *fromAtoZ(char array[])
{
    char buffer;
    for (int i = 0; i < arraySize(array); i++)
    {
        for (int j = i + 1; j < arraySize(array); j++)
        {
            if (array[i] > array[j])
            {
                buffer = array[i];
                array[i] = array[j];
                array[j] = buffer;
            }
        }
    }

    return array;
}