/*Search in an almost sorted array
Last Updated : 05 May, 2025
Given a sorted integer array arr[] consisting of distinct elements, where some elements of the array
are moved to either of the adjacent positions, i.e. arr[i] may be present at arr[i-1] or arr[i+1].
Given an integer target.  You have to return the index ( 0-based ) of the target in the array. If
target is not present return -1.

Examples :

Input: arr[] =  [10, 3, 40, 20, 50, 80, 70], target = 40
Output: 2
Explanation: Output is index of 40 in given array i.e. 2

Input: arr[] =  [10, 3, 40, 20, 50, 80, 70], target = 90
Output: -1
Explanation: 90 is not present in the array.

Try it on GfG Practice
redirect icon
Table of Content

[Naive Approach] - Linear Search - O(n) Time and O(1) Space
[Expected Approach] - Using Binary Search - O(log n) Time and O(1) Space
[Naive Approach] - Linear Search - O(n) Time and O(1) Space
A idea is to linearly search the given key in array arr[]. To do so, run a loop starting from index
0 to n - 1, and for each index i, check if arr[i] == target, if so print the index i, else move to
the next index. At last, if no such index is found, print -1.


[Expected Approach] - Using Binary Search - O(log n) Time and O(1) Space
The idea is to compare the key with middle 3 elements, if present then return the index. If not
present, then compare the key with middle element to decide whether to go in left half or right
half. Comparing with middle element is enough as all the elements after mid+2 must be greater than
element mid and all elements before mid-2 must be smaller than mid element.

Follow the steps below to implement the idea:

Initialize a variable mid with l+(r-l)/2.
If arr[mid] is equal to x return mid
Else if arr[mid-1] is equal to x return mid-1
Else if arr[mid+1] is equal to x return mid+1
If arr[mid] > x recur for search space r to mid-2 else recur for search space mid+2 to l.
 */

#include <stdio.h>

int binary(int a[], int size, int target) {
    int m = 0;
    int l = 0, r = size;
    while (l < r) {
        m = l + (r - l) / 2;
        if (a[m] == target) {
            return m;
        } else if (a[m - 1] == target) {
            return m - 1;
        } else if (a[m + 1] == target) {
            return m + 1;
        }
        if (a[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    int a[] = {10, 40, 20, 50, 60, 70, 80, 90};
    int size = sizeof(a) / sizeof(int);
    int out = binary(a, size, 40);
    printf("%d\n", out);
    return 0;
}
