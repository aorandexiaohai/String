#include "string.h"
#include <stdio.h>
#include "map.h"
#include "delete_pointer_to_pointer.h"
#include <assert.h>
#include "cstring.h"
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
    {
        char *res = replace_string("  ", "1234 ", "123");
        printf("%d\n", compare_string(res, "  "));
        free(res);
    }
    {
        struct StringStringMap *ssm = createStringStringMap();
        setValueStringStringMap(ssm, "1", "2");
        setValueStringStringMap(ssm, "2", "3");
        setValueStringStringMap(ssm, "3", "4");
        setValueStringStringMap(ssm, "3", "5");
        setValueStringStringMap(ssm, "2", "4");
        char *res = printStringStringMap(ssm);
        printf("res:%s\n", res);
        printf("%d\n", getValueStringStringMap(ssm, "10", 0));
        printf("%d\n", getValueStringStringMap(ssm, "2", 0));
        printf("%d\n", getValueStringStringMap(ssm, "4", 0));
        free(res);
        freeStringStringMap(ssm);
    }
    {
        StringVec *ssm = createStringVec();
        pushStringVec(ssm, "1");
        pushStringVec(ssm, "2");
        pushStringVec(ssm, "3");
        pushStringVec(ssm, "3");
        pushStringVec(ssm, "2");
        pushStringVec(ssm, "4");
        pushStringVec(ssm, "5");
        pushStringVec(ssm, "6");
        pushStringVec(ssm, "7");
        {
            char *res = printStringVec(ssm);
            printf("res:%s\n", res);
            free(res);
        }
        freeStringStringMap(ssm);
    }
    {
        char** res = spliter_string(" 1 2 3"," ", 5);
        int len = GetPtoPLengthChar(res);
        for(int index=0; index<len; index++)
        {
            printf("%s\n", res[index]);
        }
        DeletePtoP(res, char);
    }
}