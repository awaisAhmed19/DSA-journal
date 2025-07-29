// Write a program to reverse the given number.
/*
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int n;
    printf("enter the natural number range\n");
    scanf("%d", &n);
    long long int temp;
    while (n != 0) {
        temp = temp * 10 + n % 10;
        n = (int)n / 10;
    }
    printf("%d\n", temp);
    return 0;
}
