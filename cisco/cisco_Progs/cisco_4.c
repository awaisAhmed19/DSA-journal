/*
Sort an array in wave form
Last Updated : 12 Feb, 2025
Given an unsorted array of integers, sort the array into a wave array. An array arr[0..n-1] is
sorted in wave form if: arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= .....

Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80}
Explanation:
here you can see {10, 5, 6, 2, 20, 3, 100, 80} first element is larger than the second and the same
thing is repeated again and again. large element - small element-large element -small element and so
on .it can be small element-larger element - small element-large element -small element too. all you
need to maintain is the up-down fashion which represents a wave. there can be multiple answers.

Input: arr[] = {20, 10, 8, 6, 4, 2}
Output: arr[] = {20, 8, 10, 4, 6, 2}

Try it on GfG Practice
redirect icon
Naive Approach - Sorting - O(n Log n) time and O(1) Space
A idea is to use sorting. First sort the input array, then swap all adjacent elements.

Follow the steps mentioned below to implement the idea:

Sort the array.
Traverse the array from index 0 to n-1, and increase the value of the index by 2.
While traversing the array swap arr[i] with arr[i+1].


Expected Approach - O(n) Time and O(1) Space
The idea is based on the fact that if we make sure that all even positioned (at index 0, 2, 4, ..)
elements are greater than their adjacent odd elements, we don’t need to worry about oddly positioned
elements.

Follow the steps mentioned below to implement the idea:

Traverse all even positioned elements of the input array, and do the following.
If the current element is smaller than the previous odd element, swap the previous and current.
If the current element is smaller than the next odd element, swap next and current.
 */
#include <stdio.h>
void wave_sort(int a[], int size) {
    int temp = 0;
    for (int i = 0; i < size - 1; i += 2) {
        if (i > 0 && a[i] < a[i - 1]) {
            temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
        }
        if (i < size - 1 && a[i] < a[i + 1]) {
            temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }
}
int main() {
    int a[] = {10, 20, 40, 50, 60, 70, 80, 90};
    int size = sizeof(a) / sizeof(int);
    wave_sort(a, size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
