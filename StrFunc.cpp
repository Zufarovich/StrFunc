#include <stdio.h>
#include "StrFunc.h"

size_t STRLEN(const char *str)
{
    int counter = 0;

    while (str[counter] != '\0')
        counter++;

    return counter;
}

char *STRCPY(char *str1, const char *str2)
{
    int counter = 0;

    while (str2[counter] != '\0')
    {
        str1[counter] = str2[counter];
        counter++;
    }

    str1[counter] = '\0';

    return str1;
}

char *STRNCPY(char *str1, const char *str2, int n)
{
    int counter = 0;

    while (str2[counter] != '\0' && counter < n)
    {
        str1[counter] = str2[counter];
        counter++;   
    }

    str1[counter] = '\0';

    return str1;
}

char *STRCAT(char *str1, const char *str2)
{
    int counter1 = STRLEN(str1);

    for (int i = 0; str2[i]; i++)
    {
        str1[counter1] = str2[i];
        counter1++;
    }
    
    str1[counter1] = '\0';

    return str1;
}

char *STRNCAT(char *str1, const char *str2, int n)
{
    int counter1 = STRLEN(str1);
    const int sizeStr2 = STRLEN(str2); 

    for (int i = 0; i < sizeStr2 && (i + counter1) < n; i++)
    {
        str1[counter1] = str2[i];
        counter1++;
    }

    str1[counter1] = '\0';
    
    return str1;
}

int STRCMP(const char *str1, const char *str2)
{
    int counter = 0;

    while (str1[counter] != '\0' && str1[counter] == str2[counter])
        counter++;

    return (str1[counter] - str2[counter]); 
}

int STRNCMP(const char *str1, const char *str2, int n)
{
    int counter = 0;

    while (str1[counter] != '\0' && counter < n && str1[counter] == str2[counter])
        counter++;

    return (str1[counter] - str2[counter]); 
}

const char *STRCHR(const char *str, int c)
{
    int counter = 0;

    while (str[counter] != '\0')
    {
        if (str[counter] == c)
            return &str[counter];
        
        counter++;
    }

    if (str[counter] == c)
        return &str[counter];
    
    return NULL;   
}

const char *STRPBRK(const char *str1, const char *str2)
{
    int counter1 = 0;

    while (str1[counter1] != '\0')
    {
        int counter2 = 0;

        while (str2[counter2] != '\0')
        {
            if (str1[counter1] == str2[counter2])
                return &str1[counter1];
            
            counter2++;
        }

        counter1++;
    }

    return NULL;
}

const char *STRRCHR(const char *str, int c)
{
    int counter = 0;

    const char *ptr = NULL;

    while (str[counter] != '\0') 
    {
        if (str[counter] == c)
            ptr = &str[counter];
        
        counter++;
    }

    if (str[counter] == c)
        ptr = &str[counter];

    return ptr;
}

const char *STRSTR(const char *str1, const char *str2)
{
    if (str2[0] == '\0')
        return &str1[0];

    for (int i = 0; str1[i] != '\0'; i++)
    {
        const char *ptr = &str1[i];
        int j = 0;
        while (str1[i] == str2[j])
        {
            i++;
            j++;
            if (str2[j] == '\0')
                return ptr;
        }

    }

    return NULL;
}

