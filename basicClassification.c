#include <math.h>
#include <stdio.h>

int factorial(int);
int isPrime(int);
int isStrong(int);

//int main()
//{
//    printf("%d\n", factorial(4));
//    printf("%d\n", isStrong(145));
//    return 0;
//}

int isPrime(int num)
{
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    int i;
    for (i = 3; i <= sqrt(num); i+=2)
    {
        if (num % i == 0) return 0;
    }
    return 1;
}

int isStrong(int num)
{
    int num2 = 0, numCopy = num;
    while (num != 0)
    {
        num2 = num2 + factorial(num%10);
        num = num / 10;
    }
    if (num2 == numCopy) return 1;
    return 0;
}

int factorial(int n)
{
    if (n == 0 | n==1) return 1;
    int ans = 1;
    int i;
    for (i = 2; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}
