#include <stdio.h>
#include <stdbool.h>
#include "StrFunc.h"

void TestStr(bool isSuccess);

// struct twoStrings={

// }

int main(void)
{
    char s1[] = "asdfghjkl";
    char s2[] = "gh";
    printf("%s", STRSTR(s1, s2));

    //TestStr(STRLEN("Proverochka") == strlen("Proverochka"));

    return 0;
}

void TestStr(bool isSuccess)
{
    if(isSuccess)
        printf("Test    Successed");
    else
        printf("Test    Failed");
}