#include "cstring.h"
#include <string.h>

char *trim_string(const char *str, char c)
{
    assert(str);
    int len = strlen(str);
    int begin_index = 0;
    int end_index = len-1;
    for(begin_index=0; begin_index<len; ++begin_index)
    {
        if(str[begin_index] != c)
            break;
    }
    for(end_index=len-1; end_index>=begin_index; --end_index)
    {
        if(str[end_index] != c)
            break;
    }
    if(begin_index > end_index)
        return create_empty_string();
    else 
        return get_string(str, begin_index, end_index+1);
}

char *get_string(const char *str, int begin_index, int end_index)
{
    assert(str);
    int len = strlen(str);
    assert(begin_index >= 0);
    assert(begin_index <= len);
    assert(end_index <= len);
    assert(end_index >= begin_index);
    int copy_length = end_index - begin_index;
    assert(copy_length>=0);
    char *new_str = (char *)malloc(copy_length + 1);
    new_str[copy_length] = 0;
    if(copy_length > 0)
        memcpy(new_str, str + begin_index, copy_length);
    return new_str;
}

char *clone_string(const char *str)
{
    assert(str);
    int len = strlen(str);
    return get_string(str, 0, len);
}
char *cat_string(const char *str1, const char *str2)
{
    assert(str1 && str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *new_str = (char *)malloc(len1 + len2 + 1);
    new_str[len1 + len2] = 0;
    memcpy(new_str, str1, len1);
    memcpy(new_str + len1, str2, len2);
    return new_str;
}

char *create_string(char c, int len)
{
    assert(len >= 0);
    char *new_str = (char *)malloc(len + 1);
    new_str[len] = 0;
    if(len>0)
        memset(new_str, (int)c, len);
    return new_str;
}
char *create_empty_string()
{
    return create_string(' ', 0);
}
//if str1 > str2, return > 0
//if str1==str2, return=0;
//if str1 < str2, return<0
int compare_string(const char *str1, const char *str2)
{
    assert(str1 && str2);
    return strcmp(str1, str2);
}

int **find_string(const char *origin_str, const char *str)
{
    if (!origin_str)
        return 0;
    if (!str)
        return 0;
    int begin_index = 0;
    int end_index = 0;
    int max_len = strlen(origin_str);
    while (1)
    {
    }
}

char *replace_string(const char *origin_str, const char *old_str, const char *new_str)
{
    if (!origin_str)
        return 0;
    if (!old_str)
        return clone_string(origin_str);
}