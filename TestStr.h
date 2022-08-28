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

/**
* TestConstStr
* This function tests str functions(from StrFunc.cpp) which accepts const strings.
* TestConstStr accepts pointer to const struct twoConstStrings and prints result of tests.
* @param const struct twoConstStrings *test1 - pointer to struct with data for tests
* @param int n - number of test
*/

void TestConstStr(const struct twoConstStrings *test1, int n);

/**
* TestStr
* This function tests str functions(from StrFunc.cpp) which accepts const one string and one const string.
* TestStr accepts pointer to const struct twoConstStrings and prints result of tests.
* @param const struct twoConstStrings *test3 - pointer to struct with data for tests
* @param int n - number of test
*/

void TestStr(const struct twoStrings *test3, int n);

/**
* printResult
* This function prints result of test(success or fail), name of function, that has been tested,and number of test.
* printResult accepts bool isSuccess(result of test), name of function, that has been tested,and number of test.
* @param bool isSuccess - result of test
* @param const char *func - name of function
* @param int n - number of test
*/

void printResult(bool isSuccess, const char *func, int n);

/**
* testAll
* This function runs all tests. 
*/

void testAll(void);