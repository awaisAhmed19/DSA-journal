// Find common elements in three sorted arrays
/*
To find common elements in three sorted arrays, you can use the three-pointer technique. This
approach leverages the fact that the arrays are sorted in non-decreasing order, allowing you to
efficiently traverse and compare elements. Here's how it works:

Initialize three pointers, one for each array. These pointers start at the beginning of their
respective arrays. Compare the elements at the current positions of the three pointers. If all three
elements are equal, it means you have found a common element. Add it to the result and move all
three pointers forward. If the elements are not equal, move the pointer pointing to the smallest
element forward. This is because the smallest element cannot be a common element, and moving it
forward allows you to check the next potential candidate. Repeat the process until at least one of
the arrays is fully traversed. This method ensures that you efficiently find all common elements in
linear time, O(N), where N is the maximum size among the sizes of the arrays.

For example, consider the following three arrays:

Array 1: [1, 5, 10, 20, 30]
Array 2: [5, 13, 15, 20]
Array 3: [5, 20]
Using the three-pointer technique, you would find that the common elements are 5 and 20.

Another approach involves using a hash map to track the presence of elements across the arrays. By
iterating through each array and marking elements in the hash map, you can identify elements that
are present in all three arrays. This method also has a linear time complexity, O(N), but requires
additional space for the hash map.

Both methods are effective, and the choice between them depends on the specific requirements of your
problem, such as space constraints and the need for sorted output.

*/
#include <stdio.h>
#include <stdlib.h>
int *common_3(int arr1[], int a, int arr2[], int b, int arr3[], int c, int *size) {
    int *i = arr1 + a, *j = arr2 + b, *k = arr3 + c;
    int *output = malloc(sizeof(int) * (a + b + c));
    int *ptr1 = arr1;
    int *ptr2 = arr2;
    int *ptr3 = arr3;
    int ind = 0;
    while (ptr1 < i && ptr2 < j && ptr3 < k) {
        if (*ptr1 == *ptr2 && *ptr1 == *ptr3) {
            output[ind++] = *ptr1;
            ptr1++;
            ptr2++;
            ptr3++;
        } else {
            if (*ptr1 < *ptr2 && *ptr1 < *ptr3) {
                ptr1++;
            } else if (*ptr2 < *ptr1 && *ptr2 < *ptr3) {
                ptr2++;
            } else {
                ptr3++;
            }
        }
    }
    *size = ind;
    return output;
}

int main() {
    int a1[] = {5, 10, 15};
    int a2[] = {15, 10, 5};  // Not sorted
    int a3[] = {10, 5, 15};  // Not sorted
    int a = sizeof(a1) / sizeof(a1[0]);
    int b = sizeof(a2) / sizeof(a2[0]);
    int c = sizeof(a3) / sizeof(a3[0]);
    int size = 0;
    int *out = common_3(a1, a, a2, b, a3, c, &size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", out[i]);
    }
    free(out);
    return 0;
}
