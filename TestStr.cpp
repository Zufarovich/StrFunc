#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include "StrFunc.h"

void TestStr(const struct twoStrings *test1, const struct twoStrings *test2);

struct twoStrings 
{
    const char *str1;
    const char *str2;
};

int main(void)
{
    struct twoStrings data1[] = {
        {.str1 = "asdfghjkl"   , .str2 = "ghj"},
        {.str1 = "qwertyuiop"  , .str2 = "tyu"},
        {.str1 = "asdfghjkl"   , .str2 = "\0tyu"},
        {.str1 = " "           , .str2 = "ghj"},
        {.str1 = "ono_rabotaet", .str2 = "rabotaet"},
        {.str1 = "bn"          , .str2 = ""}
    };

    struct twoStrings data2[] = {
        {.str1 = "asdfghjkl"   , .str2 = "cdrtyhb"},
        {.str1 = "qwertyuiop"  , .str2 = "vgyujn"},
        {.str1 = "asdfghjkl"   , .str2 = "n bvcdfrtgyhujiklpkjhbvg"},
        {.str1 = " "           , .str2 = "vfghjmnb v njdma"},
        {.str1 = "ono_rabotaet", .str2 = "rabotaet"},
        {.str1 = "bn"          , .str2 = ""}
    };

    for (int i = 0; i < sizeof(data1)/sizeof(data1[0]); i++)
        TestStr(&data1[i], &data2[i]);

    return 0;
}

void TestStr(const struct twoStrings *test1, const struct twoStrings *test2)
{
    if (STRSTR(test1->str1, test1->str2) == strstr(test1->str1, test1->str2))
        printf("test STRSTR    success\n");
    else
        printf("test STRSTR    fail\n");

    if (STRPBRK(test2->str1, test2->str2) == strpbrk(test2->str1, test2->str2))
        printf("test STRPBRK    success\n");
    else
        printf("test STRPBRK    fail\n");

    if (STRPBRK(test2->str1, test2->str2) == strpbrk(test2->str1, test2->str2))
        printf("test STRPBRK    success\n");
    else
        printf("test STRPBRK    fail\n");
}