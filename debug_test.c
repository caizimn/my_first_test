#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* ConvertToChinese(unsigned long);

#define TEST(IN,EXP) assert(strcmp(ConvertToChinese(IN),EXP) == 0)

char  chineseNum[23] = "��һ�����������߰˾�ʮ";
char * GetNum(int oneNum)
{
    return (chineseNum + oneNum * 2);
}

/* TEST(0,"��"); */

/*char *ultoa(unsigned long value��char *string��int radix)*/

char* result_t = NULL;
void  init()
{
    result_t = (char*) malloc(100);
}

void destroy()
{
    free(result_t);
}

char * ConvertToChinese(unsigned long num)
{
    memcpy(result_t,GetNum(num),2);
    * (result_t + 2) = '\0' ;

    return result_t;
}

int main()
{
    init();
    TEST(1,"һ");

    destroy();
    return 1;
}

/*
const char chineseUnit[11] = "ʮ��ǧ����"��
char *GetUnit(int unit)
{

}
*/

