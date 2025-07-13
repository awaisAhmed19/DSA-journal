/*
0/1 Knapsack Problem
Last Updated : 12 Mar, 2025
Given n items where each item has some weight and profit associated with it and also given a bag
with capacity W, [i.e., the bag can hold at most W weight in it]. The task is to put the items into
the bag such that the sum of profits associated with them is the maximum possible.

Note: The constraint here is we can either put an item completely into the bag or cannot put it at
all [It is not possible to put a part of an item into the bag].

Input:  W = 4, profit[] = [1, 2, 3], weight[] = [4, 5, 1]
Output: 3
Explanation: There are two items which have weight less than or equal to 4. If we select the item
with weight 4, the possible profit is 1. And if we select the item with weight 1, the possible
profit is 3. So the maximum possible profit is 3. Note that we cannot put both the items with weight
4 and 1 together as the capacity of the bag is 4.

Input: W = 3, profit[] = [1, 2, 3], weight[] = [4, 5, 6]
Output: 0


[Naive Approach] Using Recursion O(2^n) Time and O(n) Space
[Better Approach 1] Using Top-Down DP (Memoization)- O(n x W) Time and Space
[Better Approach 2] Using Bottom-Up DP (Tabulation) - O(n x W) Time and Space
[Expected Approach] Using Bottom-Up DP (Space-Optimized) - O(n x W) Time and O(W) Space
Problems based on 0-1 Knapsack
[Naive Approach] Using Recursion O(2^n) Time and O(n) Space
A simple solution is to consider all subsets of items and calculate the total weight and value of
all subsets. Consider the only subsets whose total weight is smaller than W. From all such subsets,
pick the subset with maximum value.

Optimal Substructure: To consider all subsets of items, there can be two cases for every item.

Case 1: The item is included in the optimal subset.
Case 2: The item is not included in the optimal set.
Follow the below steps to solve the problem:

The maximum value obtained from 'n' items is the max of the following two values.

Case 1 (pick the nth item): Value of the nth item + maximum value obtained by remaining (n-1) items
and remaining weight i.e. (W-weight of the nth item).
Case 2 (don't pick the nth item): Maximum
value obtained by (n-1) items and W weight.
If the weight of the 'nth' item is greater than 'W',
then the nth item cannot be included and Case 2 is the only possibility.


 * */

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }

int Knapsack(int size, int w_a[], int p_a[], int weight) {
    int **dp = malloc(size * sizeof(int *));
    for (int i = 0; i < weight; i++) {
        dp[i] = malloc(weight * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < weight; j++) {
            dp[i][j] = 0;
        }
    }
    for (int l = 0; l < size; l++) {
        for (int k = 0; k < weight; k++) {
            if (w_a[l] > weight) {
                dp[l][k] = dp[l - 1][k];
            }
            if (w_a[l] <= weight) {
                dp[l][k] = max(dp[l - 1][k], dp[l - 1][(k - w_a[l - 3])] + p_a[l]);
            }
        }
    }
}
int main() {}
