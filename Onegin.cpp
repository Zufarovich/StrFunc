#include <stdio.h>
#include <stdlib.h>
#include "StrFunc.h"
#include "TestStr.h"

const int ERROR_OPEN_FILE = -1;

int main(void)
{
    FILE* Onegin = fopen("Onegin.txt", "r");
    
    if (Onegin ==  NULL)
    {
        printf("File doesn't opened");
        return ERROR_OPEN_FILE;
    }

    int save       = 0,
        counterStr = 0,
        counterMax = 0;

    char ch = '\0';

    while (fscanf(Onegin, "%c", &ch) != EOF)
    {
        save++;

        if (ch == '\n')
        {
            counterStr++;

            if (save > counterMax)
                counterMax = save;
        }
    }

    char *arr = (char *)calloc(counterStr, sizeof(char)*counterMax);

    if (arr ==NULL)
    {
        printf("Vse ploho");
        return -1;
    }

    int numStr = 0;

    while (numStr <= counterStr)
    {
        fgets(&arr[numStr], counterMax, Onegin);
        numStr++;
    }

    char *ptrTostr[counterStr];

    for (int i = 0; i < counterStr; i++)
        ptrTostr[i] = &arr[i];

    fclose(Onegin);

    return 0;
}