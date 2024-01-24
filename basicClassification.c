#include "numClass.h"

int isPrime(int num)
{
    if (num < 1) return 0;
    if (num == 2 || num == 1) return 1;
    if (num % 2 == 0) return 0;
    int i;
    for (i = 3; i*i <= num; i+=2)
    {
        if (num % i == 0) return 0;
    }
    return 1;
}

int isStrong(int num)
{
    if (num == 0) return 0;
    int check = 0, numCopy = num;
    while (num != 0)
    {
        check = check + factorial(num % 10);
        num = num / 10;
    }
    if (check == numCopy) return 1;
    return 0;
}

int factorial(int n)
{
    if (n == 0 || n==1) return 1;
    int ans = 1;
    int i;
    for (i = 2; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
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
int power(int a, int b)
{
    if (a==0 || a==1) return a;
    if (b == 0) return 1;
    int ans = 1;
    while (b > 0)
    {
        ans = ans * a;
        b--;
    }
    return ans;
}
