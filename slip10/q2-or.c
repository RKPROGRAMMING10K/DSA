#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

void initializeMatrix(int vertices) {
    int i, j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    adjacencyMatrix[src][dest] = 1;
    adjacencyMatrix[dest][src] = 1;
}

void bfs(int start, int vertices) {
    int queue[MAX_VERTICES], front = -1, rear = -1, i, current;
    for (i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    visited[start] = true;
    queue[++rear] = start;

    while (front != rear) {
        current = queue[++front];
        printf("%d ", current);

        for (i = 0; i < vertices; i++) {
            if (adjacencyMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int vertices, edges, i, src, dest, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initializeMatrix(vertices);

    for (i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(start, vertices);

    return 0;
}
