#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_Length 50
#define ERR -1

typedef struct
{
    char* subDigit;
    char* subString;
    int subDigitLen;
}SUB_STR_T;

int splitString(char *str,SUB_STR_T* subStrIn)
{
    SUB_STR_T* subStr = subStrIn;
    subStr->subDigit = (char*)malloc(MAX_Length);
    subStr->subString = (char*)malloc(MAX_Length);
    int i = 0;
    int j = 0;

    while(*str != 0)
    {
        if(*str >= '0' && *str <= '9')
        {
            *(subStr->subDigit + i) = *str;
            i++;
        }
        else if(*str >= 'A' && *str <= 'z')
        {
            *(subStr->subString + j) = *str;
            j++;
        }
        else
        {
            return ERR;
        }
        str++;
    }

    *(subStr->subDigit + i) = '\0';
    *(subStr->subString + j) = '\0';
    subStr->subDigitLen = i;
    //free(&subStr->subDigit);
    //free(&subStr->subString);
}

int compareTwoSubString(char* str1,char* str2)
{
    int ret = 0;
    ret = strcmp(str1,str2);
    return ret;
}

int compareTwoSubDigit(char* str1,size_t str1_len,char* str2,size_t str2_len)
{
    int int_str1 = atoi(str1);
    int int_str2 = atoi(str2);
    if(int_str1 == int_str2)
    {
        if(str1_len == str2_len)
        {
            return 1;
        }
        return str2_len - str1_len;
    }
    return int_str1 - int_str2;
}

int compareTwoString(char* str1,char* str2)
{
    SUB_STR_T sub_str1 = {0};
    SUB_STR_T sub_str2 = {0};

    splitString(str1,&sub_str1);
    splitString(str2,&sub_str2);

    if(compareTwoSubString(sub_str1.subString,sub_str2.subString) > 0)
    {
        return 1;
    }
    if(compareTwoSubString(sub_str1.subString,sub_str2.subString) < 0)
    {
        return -1;
    }
    if(compareTwoSubDigit(sub_str1.subDigit,sub_str1.subDigitLen,sub_str2.subDigit,sub_str2.subDigitLen) > 0)
    {
        return 1;
    }

    free(sub_str1.subDigit);
    free(sub_str1.subString);
    free(sub_str2.subDigit);
    free(sub_str2.subString);

    return -1;
}

void sortString(char str[][MAX_Length], size_t n)
{
    int i, j;
    char temp[MAX_Length] = {0};
    for (j = 0; j < n - 1; j++)
    for (i = 0; i < n - 1 - j; i++)
    {
        if(compareTwoString(str[i],str[i+1]) > 0)
        {
            strcpy(temp,str[i]);
            strcpy(str[i],str[i + 1]);
            strcpy(str[i + 1],temp);
        }
    }
}

int main()
{
    char str[][50] = {"B1","B2","B01","B11","1","1","a"};
    sortString(str,7);

    int k = 0;
    for(k=0;k<7;k++)
    {
        printf("%s \n",str[k]);
    }

    return 1;
}
