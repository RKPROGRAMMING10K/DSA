#include <stdio.h>
#include <stdlib.h>

void bfs(int **adj, int *visited, int n, int start) {
    int queue[n];
    int front = 0, rear = -1;
    queue[++rear] = start;
    visited[start] = 1;
    while (front <= rear) {
        int i, current = queue[front++];
        printf("%d ", current);
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int n, m, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    int **adj = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        adj[i] = (int *) malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter the edges:\n");
    for (i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    printf("Adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    int *visited = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("BFS traversal:\n");
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            bfs(adj, visited, n, i);
        }
    }
    return 0;
}
