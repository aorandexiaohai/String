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
}