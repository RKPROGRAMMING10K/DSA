#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void dfs(int vertex, int n) {
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, e, i, j, v1, v2;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Add edges to adjacency matrix
    for (i = 0; i < e; i++) {
        printf("Enter edge (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }

    // Perform DFS traversal
    printf("DFS Traversal: ");
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }
    printf("\n");

    return 0;
}
