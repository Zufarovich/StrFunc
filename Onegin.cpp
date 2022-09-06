#include <stdio.h>
#include <stdlib.h>
#include "StrFunc.h"
#include "TestStr.h"

const int ERROR_OPEN_FILE = 1;

void swap(char **ptr1, char **ptr2);

int main(void)
{
    FILE* Onegin = fopen("Onegin.txt", "r");
    
    if (Onegin ==  NULL)
    {
        printf("File doesn't opened\n");
        return ERROR_OPEN_FILE;
    }

    printf("File opened\n");

    int counterStr = 0,
        counterMax = 0;

    char ch = '\0';

    while ((ch = fgetc(Onegin)) != EOF)
    {
        if (ch == '\n')
            counterStr++;
    }

    printf("%d\n", counterStr);
    printf("Symbols have read\n");

    char **arrOfStrings = (char**)calloc(counterStr, sizeof(char*));

    int save = 0;

    rewind(Onegin);

    for (int i = 0; i < counterStr; i++)
    {
        while ((ch = fgetc(Onegin)) != '\n' && ch != EOF)
        {
            counterMax++;
        }

        arrOfStrings[i] = (char *)calloc(counterMax, sizeof(char));

        if (save < counterMax)
            save = counterMax;

        counterMax = 0;
    } // seek, lseek

    rewind(Onegin);

    for (int i = 0; i < counterStr; i++)
    {
        fgets(arrOfStrings[i], save, Onegin);
        printf("%s", arrOfStrings[i]);
    }

    printf("Strings have written\n");

    for (int i = 0; i < counterStr - 1; i++)
    {
        for (int j = 0 ; j < counterStr - i - 1; j++)
        {
            if (STRCMP(arrOfStrings[j], arrOfStrings[j+1]) > 0)
                swap(&arrOfStrings[j], &arrOfStrings[j+1]);
        }
    }
    
    for (int i = 0; i < counterStr; i++)
        printf("%s", arrOfStrings[i]);

    fclose(Onegin);
    
    for (int i = 0; i < counterStr; i++)
    {
        free(arrOfStrings[i]);
    }

    free(arrOfStrings);

    return 0;
}

void swap(char **ptr1, char **ptr2)
{
    char *save;
    save = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = save;
}