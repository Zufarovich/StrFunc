#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <Windows.h>
#include "StrFunc.h"

void TestConstStr(const struct twoConstStrings *test1, int n);
void TestStr(const struct twoStrings *test3, int n);
void printResult(bool isSuccess, const char *func, int n);
void SetColor(int text, int background);

struct twoConstStrings 
{
    const char *str1;
    const char *str2;
    const char ch;
};

struct twoStrings
{
    char *str1;
    const char *str2;
};

int main(void)
{   
    struct twoConstStrings data1[] = {
        {.str1 = "asdfghjkl"   , .str2 = "ghj"     , .ch = 'f'},
        {.str1 = "qwertyuiop"  , .str2 = "tyu"     , .ch = 'p'},
        {.str1 = "asdfghjkl"   , .str2 = "\0tyu"   , .ch = '\0'},
        {.str1 = "   "         , .str2 = "ghj"     , .ch = 'e'},
        {.str1 = "ono_rabotaet", .str2 = "rabotaet", .ch = '\0'},
        {.str1 = "bn"          , .str2 = ""        , .ch = 'n'}
    };

    char example[40] = "dhsjrkfhrg";

    struct twoStrings data2[] = {
        {.str1 = example, .str2 = "cdrtyhb"},
        {.str1 = example, .str2 = "vgyujn"},
        {.str1 = example, .str2 = "n bvcdfrtgyhujiklpkjhbvg"},
        {.str1 = example, .str2 = "vfghjmnb v njdma"},
        {.str1 = example, .str2 = "rabotaet"},
        {.str1 = example, .str2 = ""}
    };

    for (unsigned int i = 0; i < sizeof(data1) / sizeof(data1[0]); i++)
    {
        TestConstStr(&data1[i], i);
        TestStr(&data2[i], i);
    }

    return 0;
}

void TestConstStr(const struct twoConstStrings *test1, int n)
{ 
    
    printResult(STRSTR(test1->str1, test1->str2) == strstr(test1->str1, test1->str2)                                                    , "STRSTR" , n);
    printResult(STRPBRK(test1->str1, test1->str2) == strpbrk(test1->str1, test1->str2)                                                  , "STRPBRK", n);
    printResult(STRLEN(test1->str1) == strlen(test1->str1)                                                                              , "STRLEN" , n);
    printResult(STRCHR(test1->str1, test1->ch) == strchr(test1->str1, test1->ch)                                                        , "STRCHR" , n);
    printResult(STRRCHR(test1->str1, test1->ch) == strrchr(test1->str1, test1->ch)                                                      , "STRRCHR", n);

    int resSTRCMP = STRCMP(test1->str1, test1->str2);
    int resstrcmp = strcmp(test1->str1, test1->str2);

    bool condition  = true;

    if(!resstrcmp || !resSTRCMP)
        condition = (resSTRCMP == resstrcmp); 

    printResult((resSTRCMP * resstrcmp > 0) && condition                                                                                , "STRCMP" , n);
    printResult(STRNCMP(test1->str1, test1->str2, sizeof(test1->str1) - 2) == strncmp(test1->str1, test1->str2, sizeof(test1->str1) - 2), "STRNCMP", n);
}

void TestStr(const struct twoStrings *test3, int n)
{
    printResult(STRCPY(test3->str1, test3->str2) == strcpy(test3->str1, test3->str2)                                                , "STRCPY" , n);
    printResult(STRNCPY(test3->str1, test3->str2, 2*strlen(test3->str1)) == strncpy(test3->str1, test3->str2, 2*strlen(test3->str1)), "STRNCPY", n);
    printResult(STRNCAT(test3->str1, test3->str2, 2*strlen(test3->str1)) == strncat(test3->str1, test3->str2, 2*strlen(test3->str1)), "STRNCAT", n);
}

void printResult(bool isSuccess, const char *func, int n)
{
    if (isSuccess)
    {
        printf("test %-7s #%d", func, n + 1);

        SetColor(2, 0);

        printf("   success\n");

        SetColor(15, 0);

    }
    else
    {
        printf("test %-7s #%d", func, n + 1);

        SetColor(4, 0);

        printf("   fail\n");

        SetColor(15, 0);
    }  
}

void SetColor(int text, int background)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}