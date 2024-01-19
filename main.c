#include <stdio.h>
#include "numClass.h"

int main() {
    int x;
    printf("Hello, World!\n");
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("Armstrong number is: %d\n", getArmstrongNumber(x, numDigits(x)));
    printf("%d\n", isArmstrong(x));
    return 0;
}
