#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//字符串转换整数

int myAtoi(char* s) {
    int i = 0;
    int out = 0;
    int pol = 1;
    int len = strlen(s);

    if (len == 0) 
    {
        return 0;
    }
    while (s[i] == ' ') i++;  //删除空格
    if (s[i] == '-')
    {         //判断正负
        pol = -1;
        i++;
    }
    else if (s[i] == '+') 
    {
        pol = 1;
        i++;
    }
    else 
    {
        pol = 1;
    }

    while (s[i] != '\0') 
    {
        if (s[i] < '0' || s[i]>'9') 
        { //非法字符检查
            i++;
            break;
        }
        if (out > INT_MAX / 10)
        {
            return (pol > 0 ? INT_MAX : INT_MIN);  //越界判断
        }
        if (out == INT_MAX / 10)
        {
            if (pol > 0 && s[i] > '7') 
            {
                return INT_MAX;
            }
            else if (pol < 0 && s[i] >= '8')
            {
                return INT_MIN;
            }
        }
        //下面正常来写应该是out=10*out+(s[i]-'0')，之所以先减去'0',
        //是为了防止10*out+s[i]越界
        out = 10 * out - '0' + s[i];
        //由于本题没有不允许64位的存储数据，所以非法判断可以更加简单
        //可以直接将out定义为long型，直接判断即可
        //if(pol*out>INT_MAX) return INT_MAX;
        //if(pol*out<INT_MIN) return INT_MIN;
        i++;
    }
    out = out * pol;
    return out;
}

//字符串转换整数的main函数

//int main()
//{
//	int a = myAtoi("123a");
//	printf("%d", a);
//	return 0;
//}
