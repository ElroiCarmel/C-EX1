#include "numClass.h"

int isPalindrome(int num)
{
    if (num < 0) return 0;
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

int isArmstrongHelper(int sumLeft, int numWithoutLastDigit, int len)
{
    if (sumLeft < 0) return 0;
    if (numWithoutLastDigit == 0) return sumLeft==0;
    int ldp = power(numWithoutLastDigit%10, len);
    return isArmstrongHelper(sumLeft-ldp, numWithoutLastDigit/10, len);
}

int isArmstrong(int num)
{
    if (num < 0) return 0;
    int nd = numDigits(num);
    int ans = isArmstrongHelper(num, num, nd);
    return ans;
}


