#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int solve(int n, int m) {
    int count = 0;
    for (int i = n; i <= m - 2; i++) {
        if (isPrime(i) && isPrime(i + 2)) {
            count++;
        }
    }
    return count;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("\nUsage %s <start> <end> \n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    if (n > m) {
        printf("Invalid input");
        return 1;
    }

    printf("\nThe number of twin primes in the range of %d and %d is %d\n", n, m, solve(n, m));

    return 0;
}
