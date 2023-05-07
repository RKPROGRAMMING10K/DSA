#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
int inDegree[MAX_VERTICES]; // array to store indegree of vertices
int n; // number of vertices

void initializeGraph() {
    int i, j;
    
    // initialize adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    
    // initialize indegree array
    for (i = 0; i < n; i++) {
        inDegree[i] = 0;
    }
}

void addEdge(int u, int v) {
    // add edge to the adjacency matrix
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
    
    // update the indegree of vertex v
    inDegree[v]++;
}

void printInDegree() {
    int i;
    
    printf("Vertex\tIn Degree\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, inDegree[i]);
    }
}

int main() {
    int i, m, u, v;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    initializeGraph();
    
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    
    printf("Enter the edges (u v):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    
    printInDegree();
    
    return 0;
}
