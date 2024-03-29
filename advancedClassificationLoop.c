#include "numClass.h"


int isArmstrong(int x)
{
    if (x < 0) return 0;
    int dn = numDigits(x);
    int sum = 0, xc = x;
    while (xc != 0)
    {
        int ld = xc % 10;
        sum = sum + power(ld, dn);
        if (sum > x) return 0;
        xc = xc/10;
    }
    if (sum == x) return 1;
    return 0;
}

int isPalindrome(int num)
{
    if (num < 0) return 0;
    int nd = numDigits(num);
    int numArr[nd];
    int i = 0;
    while (num != 0)
    {
        numArr[i] = num % 10;
        num = num / 10;
        i++;
    }
    for (i = 0; i<=nd/2; i++)
    {
        if (numArr[i] != numArr[nd - i - 1])
        {
            return 0;
        }
    }
    return 1;
}
