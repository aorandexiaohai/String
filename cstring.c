#include "cstring.h"
#include <string.h>
#include <assert.h>
#include "delete_pointer_to_pointer.h"

char *trim_string(const char *str, char c)
{
    assert(str);
    int len = strlen(str);
    int begin_index = 0;
    int end_index = len - 1;
    for (begin_index = 0; begin_index < len; ++begin_index)
    {
        if (str[begin_index] != c)
            break;
    }
    for (end_index = len - 1; end_index >= begin_index; --end_index)
    {
        if (str[end_index] != c)
            break;
    }
    if (begin_index > end_index)
        return create_empty_string();
    else
        return get_string(str, begin_index, end_index + 1);
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

int **find_string(const char *origin_str, const char *str)
{
    assert(origin_str && str);
    if (!is_empty_string(str))
    {
        int i_count = 0;
        int max_len = strlen(origin_str);

        {

            for (int begin_index = 0; begin_index < max_len; begin_index++)
            {
                for (int end_index = begin_index + 1; end_index <= max_len; end_index++)
                {
                    char *tmp_str = get_string(origin_str, begin_index, end_index);
                    if (compare_string(tmp_str, str) == 0)
                    {
                        i_count++;
                    }
                    free(tmp_str);
                }
            }
        }
        {
            int **result = (int **)malloc(sizeof(int *) * (i_count + 1));
            result[i_count] = 0;
            int i_index = 0;

            for (int begin_index = 0; begin_index < max_len; begin_index++)
            {
                for (int end_index = begin_index + 1; end_index <= max_len; end_index++)
                {
                    char *tmp_str = get_string(origin_str, begin_index, end_index);
                    if (compare_string(tmp_str, str) == 0)
                    {
                        result[i_index] = (int *)malloc(sizeof(int) * 2);
                        result[i_index][0] = begin_index;
                        result[i_index][1] = end_index;
                        i_index++;
                    }
                    free(tmp_str);
                }
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