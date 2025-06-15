/*Count 1's in a sorted binary array
Last Updated : 07 Mar, 2025
Given a binary array arr[] of size n, which is sorted in non-increasing order, count the number of
1's in it.

Examples:

Input: arr[] = [1, 1, 0, 0, 0, 0, 0]
Output: 2
Explanation: Count of the 1's in the given array is 2.

Input: arr[] = [1, 1, 1, 1, 1, 1, 1]
Output: 7

Input: arr[] = [0, 0, 0, 0, 0, 0, 0]
Output: 0

Table of Content

[Naive approach] Using linear Search - O(n) Time and O(1) Space
[Expected Approach] Using Binary Search - O(log n) Time and O(1) Space
[Alternate Approach] Using inbuilt functions
[Naive approach] Using linear Search - O(n) Time and O(1) Space
A simple solution is to linearly traverse the array until we find the 1's in the array and keep
count of 1s. If the array element becomes 0 then return the count of 1's.
 */

#include <stdio.h>
int get_ones(int a[], int size) {
    int count = 0, i = 0;
    while (a[i] != 0 && i < size) {
        if (a[i] == 1) {
            count++;
        }
        i++;
    }
    return count;
}
int main() {
    int a[] = {1, 1, 1, 1, 0, 0, 0, 0, 0};
    int size = sizeof(a) / sizeof(int);
    printf("%d\n", get_ones(a, size));
    return 0;
}
