// Write a C program that accepts the vertices and edges of a graph and storesit as an adjacency matrix. Display the adjacency matrix.

#include <stdio.h>

int main() {
    int n, m, i, j, v1, v2;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int adj_matrix[n][n];

    // Initialize all elements of the adjacency matrix to 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    // Get input for the edges and update the adjacency matrix
    for (i = 0; i < m; i++) {
        printf("Enter the vertices for edge %d: ", i+1);
        scanf("%d %d", &v1, &v2);
        adj_matrix[v1-1][v2-1] = 1;
        adj_matrix[v2-1][v1-1] = 1;
    }

    // Display the adjacency matrix
    printf("\nThe adjacency matrix for the graph is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
