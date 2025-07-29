
// Write a program to check if a number is a Amstrong number or not.
#include <stdio.h>
#include <stdlib.h>

int getdigit(long long int a) {
    int digit = 0;
    while (a > 0) {
        digit++;
        a = a / 10;
    }
    return digit;
}

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        res *= a;
        b--;
    }
    return res;
}
int main() {
    long long int n, temp, in, res;
    printf("enter the natural number range\n");
    scanf("%lld", &n);
    for (long long int i = 2; i <= n; i++) {
        temp = i;
        res = 0;
        int count = getdigit(i);
        while (temp > 0) {
            in = temp % 10;
            res += power(in, count);
            temp = temp / 10;
        }
        if (i == res) {
            printf("%lld is a Armstrong number \n", res);
        }
    }
    return EXIT_SUCCESS;
}
