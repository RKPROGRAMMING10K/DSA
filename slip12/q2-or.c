#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to print the adjacency matrix
void printAdjMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print the indegree of all vertices
void printInDegree(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Indegree of vertices:\n");
    for (int i = 0; i < numVertices; i++) {
        int inDegree = 0;
        for (int j = 0; j < numVertices; j++) {
            inDegree += adjMatrix[j][i];
        }
        printf("Vertex %d: %d\n", i, inDegree);
    }
}

// Function to print the outdegree of all vertices
void printOutDegree(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Outdegree of vertices:\n");
    for (int i = 0; i < numVertices; i++) {
        int outDegree = 0;
        for (int j = 0; j < numVertices; j++) {
            outDegree += adjMatrix[i][j];
        }
        printf("Vertex %d: %d\n", i, outDegree);
    }
}

// Function to print the total degree of all vertices
void printTotalDegree(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Total degree of vertices:\n");
    for (int i = 0; i < numVertices; i++) {
        int totalDegree = 0;
        for (int j = 0; j < numVertices; j++) {
            totalDegree += adjMatrix[i][j];
            totalDegree += adjMatrix[j][i];
        }
        printf("Vertex %d: %d\n", i, totalDegree);
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;
    }

    printAdjMatrix(adjMatrix, numVertices);
    printInDegree(adjMatrix, numVertices);
    printOutDegree(adjMatrix, numVertices);
    printTotalDegree(adjMatrix, numVertices);

    return 0;
}
