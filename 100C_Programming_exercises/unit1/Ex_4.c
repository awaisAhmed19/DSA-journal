// Write a program to calculate sum of squares of cubes of first n natural numbers.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    long long int sq_num, res;
    printf("enter the natural number range\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sq_num = i * i;
        res += sq_num * sq_num * sq_num;
    }
    printf("%lld\n", res);
    return EXIT_SUCCESS;
}
