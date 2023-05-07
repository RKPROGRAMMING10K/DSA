// Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. Implement functions to print indegree of all vertices of graph.

#include <stdio.h>

#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int indegree[MAX_VERTICES];

int main() {
    int num_vertices, num_edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    // Initialize the adjacency matrix to all 0s
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    // Read the edges and update the adjacency matrix
    printf("Enter the edges (vertex1 vertex2): \n");
    for (int i = 0; i < num_edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        adj_matrix[vertex1][vertex2] = 1;
    }

    // Calculate the indegree of each vertex
    for (int i = 0; i < num_vertices; i++) {
        indegree[i] = 0;
        for (int j = 0; j < num_vertices; j++) {
            if (adj_matrix[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    // Print the indegree of each vertex
    printf("Indegree of each vertex: \n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %d\n", i, indegree[i]);
    }

    return 0;
}
