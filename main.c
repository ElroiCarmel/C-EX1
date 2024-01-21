#include <stdio.h>
#include "numClass.h"

int main() {
    int a, b, curr;
    scanf("%d%d", &a, &b);
    printf("The Armstrong numbers are:");
    for (curr = a; curr <= b; curr++)
    {
        if (isArmstrong(curr))
        {
            printf(" %d", curr);
        }
    }
    printf("\n");
    printf("The Palindromes are:");
    for (curr = a; curr <= b; curr++)
    {
        if (isPalindrome(curr))
        {
            printf(" %d", curr);
        }
    }
    printf("\n");
    printf("The Prime numbers are:");
    for (curr = a; curr <= b; curr++)
    {
        if (isPrime(curr))
        {
            printf(" %d", curr);
        }
    }
    printf("\n");
    printf("The Strong numbers are:");
    for (curr = a; curr <= b; curr++)
    {
        if (isStrong(curr))
        {
            printf(" %d", curr);
        }
    }
    printf("\n");
    return 0;
}
