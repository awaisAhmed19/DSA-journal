// Write a program to check whether the given number is a palindrome or not.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int n, temp;
    printf("enter the nrange\n");
    scanf("%d", &n);

    temp = n;
    int digit;
    while (temp != 0) {
        digit++;
        temp = temp / 10;
    }

    int* arr = (int*)malloc(sizeof(int) * digit);
    for (int i = 0; n != 0; i++) {
        arr[i] = n % 10;
        n = (int)n / 10;
    }
    int i = 0, palindrome = 1;
    int j = digit - 1;
    while (i < j) {
        if (arr[i] != arr[j]) {
            palindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if (palindrome == 1) {
        printf("it is a palindrome\n");
    } else {
        printf("it is not a palindrome\n");
    }

    return 0;
}
