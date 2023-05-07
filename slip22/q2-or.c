//  Write a C program that accepts the vertices and edges of a graph and store it as anadjacency matrix. Implement function to traverse the graph using Depth First Search (DFS) traversal. 


#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void initializeMatrix(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    adjacencyMatrix[src][dest] = 1;
    adjacencyMatrix[dest][src] = 1;
}

void DFS(int vertex, int vertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < vertices; i++) {
        if (adjacencyMatrix[vertex][i] == 1 && visited[i] == 0) {
            DFS(i, vertices);
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeMatrix(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int src, dest;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Depth First Search Traversal: ");
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < vertices; i++) {
        if (visited[i] == 0) {
            DFS(i, vertices);
        }
    }

    return 0;
}

