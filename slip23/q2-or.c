#include <stdio.h>

#define INF 99999
#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

void floydWarshall(int numVertices) {
    int i, j, k;
    
    // Initialize the distance matrix
    int dist[numVertices][numVertices];
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            dist[i][j] = adjMatrix[i][j];
        }
    }
    
    // Calculate the shortest paths between all pairs of vertices
    for (k = 0; k < numVertices; k++) {
        for (i = 0; i < numVertices; i++) {
            for (j = 0; j < numVertices; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances between all pairs of vertices
    printf("All pairs shortest path:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int numVertices, numEdges, i, j, v1, v2, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Initialize the adjacency matrix with large values
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = INF;
        }
    }

    // Read edges and update the adjacency matrix
    for (i = 0; i < numEdges; i++) {
        printf("Enter edge (v1 v2 weight): ");
        scanf("%d %d %d", &v1, &v2, &weight);
        adjMatrix[v1][v2] = weight;
        adjMatrix[v2][v1] = weight;
    }

    floydWarshall(numVertices);

    return 0;
}
