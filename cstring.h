#ifndef __CSTRING_H_
#define __CSTRING_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static char* get_string(const char* str, int begin_index, int end_index)
{
    if(!str) return 0;
    int len = strlen(str);
    assert(begin_index>=0);
    assert(begin_index<=len);
    assert(end_index<=len);
    assert(end_index>=begin_index);
    int copy_length = end_index - begin_index;
    if(copy_length == 0 ) return 0;
    char* new_str =  (char*)malloc(copy_length + 1);
    new_str[copy_length] = 0;
    memcpy(new_str, str+begin_index, copy_length);
    return new_str;
}

static char *clone_string(const char *str)
{
    if (!str)
        return 0;
    int len = strlen(str);
    return get_string(str, 0, len);
}
static char *cat_string(const char *str1, const char *str2)
{
    if (!str1)
        return clone_string(str2);
    if (!str2)
        return clone_string(str1);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *new_str = (char *)malloc(len1 + len2 + 1);
    new_str[len1 + len2] = 0;
    memcpy(new_str, str1, len1);
    memcpy(new_str + len1, str2, len2);
    return new_str;
}

static char* create_string(char c, int len)
{
    assert(len > 0);
    char *new_str = (char *)malloc(len + 1);
    new_str[len] = 0;
    memset(new_str, (int)c, len);
    return new_str;
}
//if str1 > str2, return > 0
//if str1==str2, return=0;
//if str1 < str2, return<0
static int compare_string(const char* str1, const char* str2)
{
    if(!str1 && !str2) return 0;
    if(!str1) return -1;
    if(!str2) return 1;
    return compare(str1, str2);
}

static int** find_string(const char* origin_str, const char* str)
{
    if(!origin_str) return 0;
    if(!str) return 0;
    int begin_index =0;
    int end_index   =0;
    int max_len = strlen(origin_str);
    while(1)
    {
    }
}

static char* replace_string(const char* origin_str, const char* old_str, const char* new_str)
{
    if(!origin_str) return 0;
    if(!old_str) return clone_string(origin_str);
}


#endif //__CSTRING_H_