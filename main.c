#include "string.h"
#include <stdio.h>
int main()
{
    {
        char *res = trim_string("", ' ');
        printf("%d\n", compare_string(res, ""));
        free(res);
    }
    {
        char *res = trim_string(" ", ' ');
        printf("%d\n", compare_string(res, ""));
        free(res);
    }
    {
        char *res = trim_string("  12345", ' ');
        printf("%d\n", compare_string(res, "12345"));
        free(res);
    }
    {
        char *res = trim_string("  12345 ", ' ');
        printf("%d\n", compare_string(res, "12345"));
        free(res);
    }
    {
        char *res = trim_string("12345  ", ' ');
        printf("%d\n", compare_string(res, "12345"));
        free(res);
    }
    {
        char *res = replace_string(",1,2,3,45", ",", "xx");
        printf("%d\n", compare_string(res, "xx1xx2xx3xx45"));
        free(res);
    }
    {
        char *res = replace_string(",1,2,3,45", ",", "");
        printf("%d\n", compare_string(res, "12345"));
        free(res);
    }
    {
        char *res = replace_string(",1,2,3,45", "", "");
        printf("%d\n", compare_string(res, ",1,2,3,45"));
        free(res);
    }
    {
        char *res = replace_string(" ", " ", "123");
        printf("%d\n", compare_string(res, "123"));
        free(res);
    }
    {
        char *res = replace_string("  ", " ", "123");
        printf("%d\n", compare_string(res, "123123"));
        free(res);
    }
}