// Write a program to calculate mn
//  value using do-while loop.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("enter the n range\n");
    scanf("%d", &n);
    printf("enter the m range\n");
    scanf("%d", &m);
    long long int res = 1;
    do {
        res *= m;
        n--;
    } while (n > 0);
    printf("res =%lld\n", res);
    return 0;
}
