#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    if (isPrime(104729)) {
        printf("isPrime");
    } else {
        printf("not Prime");
    }
}
