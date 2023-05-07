#include<stdio.h>

int main() {
    int vertices, edges, i, j, vertex1, vertex2;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int adj_matrix[vertices][vertices];
    // Initializing all elements of adjacency matrix to zero
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    // Creating the adjacency matrix
    for(i=0; i<edges; i++) {
        printf("Enter the vertices of edge %d: ", i+1);
        scanf("%d%d", &vertex1, &vertex2);
        adj_matrix[vertex1-1][vertex2-1] = 1;
        adj_matrix[vertex2-1][vertex1-1] = 1; // For undirected graphs
    }
    // Displaying the adjacency matrix
    printf("\nThe adjacency matrix is:\n\n");
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
