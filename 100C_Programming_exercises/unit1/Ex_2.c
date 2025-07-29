// Write a program to calculate the sum of squares of first n natural numbers using while
// loop.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i = 0;
    size_t sum = 0;
    printf("Input the n natural numbers\n");
    scanf("%d", &n);
    while (i < n) {
        sum += i * i;
        i++;
    }

    printf("sum = %d\n", sum);
    return EXIT_SUCCESS;
}
