/*
 * ) Write a program to print the multiplication table in the following format.
 1 2 3 4 5
 1 1 2 3 4 5
 2 2 4 6 8 10
 3 3 6 9 12 15
 4 4 8 12 16 20
 5 5 10 15 20 25
 * */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;

    printf("   ");
    for (int j = 1; j <= n; j++) {
        printf(" %d ", j);
    }
    for (int i = 1; i <= n; i++) {
        printf("\n");
        printf(" %d ", i);
        for (int j = 1; j <= n; j++) {
            printf(" %d ", i * j);
        }
    }
    return 0;
}
