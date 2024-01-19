#include <stdio.h>
int isPrime(int);

int main() {
    int x;
    printf("Hello, World!\n");
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("%d\n", isPrime(x));
    return 0;
}
