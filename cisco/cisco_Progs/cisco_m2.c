/*For a directed acyclic graph (DAG), a topological ordering is a linear ordering of its vertices
such that for every directed edge from vertex u  to vertex v (i.e., edge u->v ),  u is listed before
v.

As you may know, a given DAG may have multiple topological orderings. For example, consider the
following graph:

graph

In this diagram, [1,2,3,5,4] and [2,5,1,3,4] are two of the possible topological orderings.

A topological ordering a1,a2,.....an is considered lexicographically smaller than another ordering,
b1,b2.,b3....bn , if ai<bi, for the first index i where  ai and  bi differ.

Given a DAG and a topological ordering,p , find the smallest topological ordering that is also
lexicographically greater than p.

Note: Each pair of vertices have at most one directed edge between them.

Input Format

The first line contains two space-separated integers describing the respective values of  (the
number of vertices) and  (the number of directed edges) in the DAG. Each of the  subsequent lines
contains a pair of space-separated integers,  and , describing a directed edge from vertex  (the
first value) to vertex  (the second value). The last line contains a permutation of  distinct
space-separated positive integers (where each integer is ) denoting topological ordering .

Constraints

Subtasks

For  of the maximum score,  and .
For additional  of the maximum score,  and .
Output Format

Print  space-separated integers denoting the smallest topological ordering that is also
lexicographically greater than ; if  is already the lexicographically largest topological ordering,
print  instead.

Sample Input

5 5
1 3
2 3
3 4
2 5
5 4
1 2 5 3 4
Sample Output

2 1 3 5 4
Explanation

The image shown in the Problem Statement above depicts the graph in the Sample Case. If we start
with topological ordering  1 2 5 3 4, the next lexicographically largest topological ordering is 2 1
3 5 4.
 * */
#include <stdio.h>
#include <stdlib.h>
struct priority_queue {
    int item;
    int priority;
};
int **Adj_matrix(int e_s, int v_s, int v[], int e[]) {
    int **adj = malloc(sizeof(int *) * v_s);
    for (int i = 0; i < v_s; i++) {
        adj[i] = malloc(sizeof(int) * v_s);
    }

    for (int i = 0; i < v_s; i++) {
        int x = v[i];
        int y = e[i];
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    return adj;
}

int *topological_sort(int size, int **adj, int adjsize, int a[]) {
    int *priority_q = malloc(sizeof(int) * size);
    int *indeg = malloc(sizeof(int) * size);
    int sum = 0;
    int i = 0;
    for (int col = 0; col < adjsize; col++) {
        indeg[col] = 0;
        for (int row = 0; row < adjsize; row++) {
            indeg[col] += adj[row][col];
        }
    }
    for (int i = 0; i < size; i++) {
        if (indeg[i] == 0) {
            priority_q[i] = i;
        }
    }
    return priority_q;
}

int main() {
    int size = 7;

    int a[] = {0, 0, 1, 1, 2, 3, 4};
    int b[] = {1, 2, 2, 3, 4, 5, 5};
    int c[] = {0, 1, 2, 3, 4, 5};
    int **adj = Adj_matrix(size, size, a, b);
    topological_sort(6, adj, 7, c);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d |", adj[i][j]);
        }
        printf("\n");
    }
}
