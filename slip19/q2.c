// Write a C program that accepts the vertices and edges of a graph. Create adjacency list and display the adjacency list


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int num_vertices;
    struct Node** adj_lists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->num_vertices = vertices;

    graph->adj_lists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adj_lists[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj_lists[src];
    graph->adj_lists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        struct Node* current = graph->adj_lists[i];
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int src, dest;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    return 0;
}
