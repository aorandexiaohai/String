#ifndef __CSTRING_H_
#define __CSTRING_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//>=0: fount
//-1: not found
int find_char(const char* str, char c);
char *trim_string(const char *str, char c);
char *trim_str_string(const char *str, char* trim_str);
char *trim_str_optional_string(const char *str, char* trim_str, int reverse );

char *get_string(const char *str, int begin_index, int end_index);
char *clone_string(const char *str);
char *cat_string(const char *str1, const char *str2);
char *create_string(char c, int len);
char *create_empty_string();
int is_empty_string(const char* str);

//if str1 > str2, return > 0
//if str1==str2, return=0;
//if str1 < str2, return<0
int compare_string(const char *str1, const char *str2);
int **find_string(const char *origin_str, const char *str);
int **find_range_string(const char *origin_str,int begin, int end, const char *str);
char *replace_string(const char *origin_str, const char *old_str, const char *new_str);

char** spliter_string(const char* origin_str, const char *str, int need_spliters);

char* int2str(int value);
int is_comment_string(char* str);

#endif //__CSTRING_H_