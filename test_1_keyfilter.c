// uz len okomentovat
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 101
#define ROW 42
#define SIZE ROW * LENGTH

int arraySize(char array[]);
char lowerCaseToUpperCase(char letter);
char upperCaseToLowerCase(char letter);
char *arrayCleaner(char array[]);
char *lowerCaseToUpperCaseArray(char array[]);
char *fixInput(char array[]);
int error(char letter);

int main(int argc, char *argv[])
{

    char fileArray[SIZE] = {0};
    char characters[SIZE] = {0};
    char *inputChar;
    // int letter;
    // char wordArray[SIZE] = {0};
    int i = 0, j = 0;

    if (argc < 1)
    {
        fprintf(stderr,"To few arguments");
        return 1;
    }
    
    // while ((letter = getchar()) != EOF)
    // {
    //     wordArray[i] = letter;
    //     while (letter == '\n')
    //     {
    //         characters[j] = wordArray[0];
    //     }
        
    // }
    

    while ((fileArray[i] = getchar()) != EOF)
    {
        error(fileArray[i]);
        fileArray[i] = upperCaseToLowerCase(fileArray[i]);
        fileArray[0] = lowerCaseToUpperCase(fileArray[0]);
        characters[0] = fileArray[0];

        if (fileArray[i] == '\n')
        {
            j++;
            i++;
            scanf("%c", &fileArray[i]);
            fileArray[i] = lowerCaseToUpperCase(fileArray[i]);
            characters[j] = fileArray[i];
        }
        
        i++;
    }
    printf("%s", fileArray);
    if (argc == 1)
    {
        printf("Enable: %s\n", arrayCleaner(characters));
    }
    char choices[SIZE] = {0};
    if (argc == 2)
    {

        inputChar = fixInput(argv[1]);

        int i = 0, j = 0, k = 0;
        int size = arraySize(fileArray);

        while (i <= size)
        {
            while (((fileArray[i] == inputChar[k]) && (fileArray[i] != '\n')))
            {

                k++;
                i++;

                if (k == arraySize(inputChar))
                {
                    choices[j] = fileArray[i];
                    j++;
                }
            }

            k = 0;
            i++;
        }

        if (arraySize(choices) == 0)
        {
            printf("Not Found\n");
        }

        if (arraySize(choices) == 1)
        {
            char word[SIZE] = {0};
            j = 0, i = 0, k = 0;
            while ((i <= size))
            {
                while ((fileArray[i] == inputChar[k]) && (fileArray[i] != '\n'))
                {
                    k++;
                    i++;
                    while (k >= arraySize(inputChar) && (fileArray[i] != '\n') && i <= size)
                    {
                        word[j] = fileArray[i];
                        j++;
                        i++;
                    }
                }
                k = 0;
                i++;
            }

            printf("Found: %s%s\n", lowerCaseToUpperCaseArray(inputChar), lowerCaseToUpperCaseArray(word));
        }

        if (arraySize(choices) > 1)
        {
            printf("Enable: %s\n", lowerCaseToUpperCaseArray(arrayCleaner(choices)));
        }
    }

    if (argc > 2)
    {
        printf("Vacsi pocet argumentov nie je povoleny!\nAk chces zadat medzeru, tak zadaj: SLOVO_1\\_SLOVO_2\n");
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
        printf("Wrong input\n");
        exit(0);
    }
    else
    {
        return 0;
    }
}