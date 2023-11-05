#include <stdio.h>
#include <stdbool.h>

static int my_strlen(const char* str)
{
    int i = 0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}
static void my_strcpy(char* str1,char* str2)
{
    while(*str2!='\0')
    {
        *str1++ = *str2++;
    }
}
static void my_strrev(char* str)
{
    int len = my_strlen(str);
    int j=0;
    char str2[len];
    my_strcpy(str2,str);
    for(int i = len-1; 0<=i;i--)
    {
        str[j++] = str2[i];
    }       
}
static int my_strcmp(const char* str1,const char* str2)
{   
    int i =0;
    while(str1[i] == str2[i] && str1[i] == '\0'&& str2[i] == '\0')
    {
        i++;
    }
    return str1[i] - str2[i];
}
static void my_strcat(char* str1,const char* str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    for(int i = len1; i<=len1+len2;i++)
    {
        str1[i] = str2[i-len1];
    }
}

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    printf("Length of str1: %lu\n", my_strlen(str1));
    my_strcpy(str1, str2);
    printf("str1 after copy: %s\n", str1);
    my_strrev(str1);
    printf("str1 after reverse: %s\n", str1);
    // char str3[50] = "World";
    // my_strcpy(str1,str3);
    printf("Comparison between str1 and str2: %d\n", my_strcmp(str1, str2));
    my_strcat(str1, str2);
    printf("str1 after concatenation: %s\n", str1);
    return 0;
}
