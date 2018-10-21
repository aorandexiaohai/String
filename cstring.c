#include "cstring.h"
#include <string.h>
#include <assert.h>
#include "delete_pointer_to_pointer.h"

int find_char(const char *str, char c)
{
    assert(str);
    int len = strlen(str);
    for (int index = 0; index < len; index++)
    {
        if (c == str[index])
            return index;
    }
    return -1;
}
int GetPtoPLengthInt(int **pp)
{
    assert(pp);
    int index = 0;
    while (pp[index])
    {
        index++;
    }
    return index;
}
int GetPtoPLengthChar(char **pp)
{
    assert(pp);
    int index = 0;
    while (pp[index])
    {
        index++;
    }
    return index;
}
char *trim_str_string(const char *str, char *trim_str)
{
    return trim_str_optional_string(str, trim_str, 0);
}

char *trim_str_optional_string(const char *str, char *trim_str, int reverse)
{
    assert(str && trim_str);

    int len = strlen(str);
    int begin_index = 0;
    int end_index = len - 1;
    for (begin_index = 0; begin_index < len; ++begin_index)
    {
        if (!reverse)
        {
            if (find_char(trim_str, str[begin_index]) < 0)
                break;
        }
        else
        {
            if (find_char(trim_str, str[begin_index]) >= 0)
                break;
        }
    }
    for (end_index = len - 1; end_index >= begin_index; --end_index)
    {
        if (!reverse)
        {
            if (find_char(trim_str, str[end_index]) < 0)
                break;
        }
        else
        {
            if (find_char(trim_str, str[end_index]) >= 0)
                break;
        }
    }
    if (begin_index > end_index)
        return create_empty_string();
    else
        return get_string(str, begin_index, end_index + 1);
}

char *trim_string(const char *str, char c)
{
    char *tmp_str = create_string(c, 1);
    char *res = trim_str_string(str, tmp_str);
    free(tmp_str);
    return res;
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
    assert(copy_length >= 0);
    char *new_str = (char *)malloc(copy_length + 1);
    new_str[copy_length] = 0;
    if (copy_length > 0)
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
    if (len > 0)
        memset(new_str, (int)c, len);
    return new_str;
}
char *create_empty_string()
{
    return create_string(' ', 0);
}

int is_empty_string(const char *str)
{
    assert(str);
    return str[0] == 0;
}

//if str1 > str2, return > 0
//if str1==str2, return=0;
//if str1 < str2, return<0
int compare_string(const char *str1, const char *str2)
{
    assert(str1 && str2);
    return strcmp(str1, str2);
}

int **find_range_string(const char *origin_str, int begin, int end, const char *str)
{
    int max_len = strlen(origin_str);
    assert(begin >= 0 && begin <= max_len);
    assert(end >= begin && end <= max_len);

    assert(origin_str && str);
    if (!is_empty_string(str))
    {
        int i_count = 0;

        {

            for (int begin_index = begin; begin_index < end; )
            {
                int flag = 0;
                for (int end_index = begin_index + 1; end_index <= end; end_index++)
                {
                    char *tmp_str = get_string(origin_str, begin_index, end_index);
                    if (compare_string(tmp_str, str) == 0)
                    {
                        i_count++;
                        flag = 1;
                        begin_index = end_index;
                    }
                    free(tmp_str);
                    if(flag)
                        break;
                }
                if(!flag)
                    begin_index++;
            }
        }
        {
            int **result = (int **)malloc(sizeof(int *) * (i_count + 1));
            result[i_count] = 0;
            int i_index = 0;

            for (int begin_index = begin; begin_index < end; )
            {
                int flag = 0;
                for (int end_index = begin_index + 1; end_index <= end; end_index++)
                {
                    char *tmp_str = get_string(origin_str, begin_index, end_index);
                    if (compare_string(tmp_str, str) == 0)
                    {
                        result[i_index] = (int *)malloc(sizeof(int) * 2);
                        result[i_index][0] = begin_index;
                        result[i_index][1] = end_index;
                        i_index++;
                        begin_index = end_index;
                        flag =1;
                    }
                    free(tmp_str);
                    if(flag)
                        break;
                }
                if(!flag)
                    begin_index++;
            }
            assert(i_index == i_count);
            return result;
        }
    }
    else
    {
        int **result = (int **)malloc(sizeof(int *));
        result[0] = 0;
        return result;
    }
    assert(0);
    return 0;
}

int **find_string(const char *origin_str, const char *str)
{
    assert(origin_str && str);
    int max_len = strlen(origin_str);
    return find_range_string(origin_str, 0, max_len, str);
}

char *replace_string(const char *origin_str, const char *old_str, const char *new_str)
{
    assert(origin_str && old_str && new_str);
    int **locations = find_string(origin_str, old_str);
    int index = 0;
    char *result = create_empty_string();
    int copy_begin = 0;
    do
    {
        int *current = locations[index++];
        if (!current)
        {
            char *head_str = get_string(origin_str, copy_begin, strlen(origin_str));
            char *new_result = cat_string(result, head_str);
            free(result);
            result = new_result;
            break;
        }
        int begin = current[0];
        int end = current[1];
        assert(copy_begin <= begin);
        char *head_str = get_string(origin_str, copy_begin, begin);
        char *new_result = cat_string(result, head_str);
        free(result);
        result = new_result;
        new_result = cat_string(result, new_str);
        free(result);
        result = new_result;
        copy_begin = end;
        free(head_str);
    } while (1);
    assert(locations);
    DeletePtoP(locations, int);
    return result;
}

char *int2str(int value)
{
    char buffer[100];
    snprintf(buffer, 100, "%d", value);
    return clone_string(buffer);
}

char **spliter_string(const char *origin_str, const char *str, int need_spliters)
{
    assert(origin_str && str);
    int **locations = find_string(origin_str, str);
    // ShowPtoP(locations, int);
    int len = GetPtoPLengthInt(locations);
    int min_len = (len + 1) < need_spliters ? (len + 1) : need_spliters;
    if(need_spliters<0)
        min_len = len + 1;
    char **result = (char **)(malloc(sizeof(char *) * (min_len + 1)));
    result[min_len] = 0;
    int begin_index = 0;
    for (int index = 0; index < len && index < min_len - 1; index++)
    {
        int *location = locations[index];
        result[index] = get_string(origin_str, begin_index, location[0]);
        begin_index = location[1];
    }
    result[min_len - 1] = get_string(origin_str, begin_index, strlen(origin_str));
    DeletePtoP(locations, int);

    int res_len = GetPtoPLengthChar(result);
    if (need_spliters>=0 && res_len < need_spliters)
    {
        char **new_res = (char **)malloc(sizeof(char *) * (need_spliters + 1));
        new_res[need_spliters] = 0;
        for (int index = 0; index < res_len; index++)
        {
            new_res[index] = result[index];
        }
        for (int index = res_len; index < need_spliters; index++)
        {
            new_res[index] = create_empty_string();
        }
        free(result);
        result = new_res;
    }

    return result;
}