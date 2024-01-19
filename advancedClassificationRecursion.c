#include <stdio.h>

int numDigits(int);
int isPalindromeHelper(int* , int, int);
int isPalindrome(int);
int isArmstrong(int);


int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", isPalindrome(x));
    return 0;
}

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
int numDigits(int num)
{
    int ans = 0;
    while (num != 0)
    {
        num = num / 10;
        ans++;
    }
    return ans;
}