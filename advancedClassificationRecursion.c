#include "numClass.h"

int isPalindrome(int num)
{
    int nd = numDigits(num);
    int numArr[nd];
    int i;
    for (i = 0; i<nd; i++)
    {
        numArr[i] = num % 10;
        num = num / 10;
    }
    return isPalindromeHelper(numArr, 0, nd-1);
}

int isPalindromeHelper(int* num, int i, int j)
{
    if (j <= i) return 1;
    if (num[i] == num[j])
    {
        return isPalindromeHelper(num, i+1, j-1);
    }
    return 0;
}

int getArmstrongNumber(int num, int len)
{
    if (num == 0)
    {
        return 0;
    }
    return pow(num%10, len) + getArmstrongNumber(num/10, len);
}

int isArmstrong(int num)
{
    int nd = numDigits(num);
    int armNum = getArmstrongNumber(num, nd);
    return num == armNum;
}


