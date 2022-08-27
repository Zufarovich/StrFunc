/**
* STRLEN
* This function accepts string and returns lendth of this string
* @param char *str - pointer to string
* @return size_t counter - ledth of string  
*/
size_t STRLEN(const char *str);

/**
* STRCPY
* This function accepts two pointers to strings and copies 2end to 1st string
* @param char *str1 - pointer to first string
* @param char *str2 - pointer to second string
* @return char *str1 - first string with copy of second string
*/
char *STRCPY(char *str1, const char *str2);

/**
* STRNCPY
* This function accepts two pointers to strings, number of max symbols and copies 2end to 1st string, but no more then n symbols
* @param char *str1 - pointer to first string
* @param char *str2 - pointer to second string
* @param int n - max amount of copiing symbols from second string
* @return char *str1 - first string with copy of second string, but no more than n symbols
*/
char *STRNCPY(char *str1, const char *str2, int n);

/**
* STRCAT
* This function accepts two pointers to strings and copies 2end to the end of 1st string
* @param char *str1 - pointer to first string
* @param char *str2 - pointer to second string
* @return char *str1 - first string with copy of second string, that copied in the end of first one
*/
char *STRCAT(char *str1, const char *str2);

/**
* STRCAT
* This function accepts two pointers to strings,max number of symbols  and copies 2end to the end of 1st string, but no more than n symbols can be in first string
* @param char *str1 - pointer to first string
* @param char *str2 - pointer to second string
* @param int n - max number of symbols in first string
* @return char *str1 - first string with copy of second string, that copied in the end of first one, but no more than n symbols in first string
*/
char *STRNCAT(char *str1, const char *str2, int n);

/**
* STRCMP
* This function accepts 2 strings and returns 0 if they're the same and difference with first different symbols
* @param char *str1 - pointer to first string
* @param char *str2 - pointer to second string
* @return diifferenсу with first different symbols or 0 if strings are the same
*/
int STRCMP(const char *str1, const char *str2);

/**
* STRNCMP
* This function accepts 2 strings, max symbols to compare and returns 0 if they're the same and difference with first different symbols
* @param char *str1 - pointer to first string
* @param char *str2 - pointer to second string
* @param n - max amount of symbols to compare
* @return diifferenсу with first different symbols or 0 if strings are the same
*/
int STRNCMP(const char *str1, const char *str2, int n);

/**
* STRCHR
* This function accepts string, symbol and returns adress to slot where this symbol apears first time
* @param char *str - pointer to string
* @param int c - symbol to find
* @return slot where this symbol apears first time or NULL
*/
const char *STRCHR(const char *str, int c);

/**
* STRBRK
* This function accepts 2 strings and returns pointer to cell of 1st string where is located any symbol from 2nd string or NULL if theri no such cell
* @param char @str1 - first string
* @param char @str2 - second string
* @return slot of first string where contains first any symbol from second string or NULL
*/
const char *STRPBRK(const char *str1, const char *str2);

/**
* STRRCHR
* This function accepts string, symbol and returns slot where located this symbol last time
* @param char *str - string
* @param int c - symbol
* @return slot where located this symbol last time or NULL 
*/
const char *STRRCHR(const char *str, int c);

/**
* STRSTR
* This function accepts 2 strings and returns slot where begins string2 in string1 or NULL
* @param char *str1 - first string
* @param char *str2 - second string
* @return  slot where begins string2 in string1 or NULL
*/
const char *STRSTR(const char *str1, const char *str2);