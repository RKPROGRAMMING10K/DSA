#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Define a structure for a graph node
typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

// Define a structure for a graph
typedef struct Graph {
    int numVertices;
    GraphNode** adjLists;
} Graph;

// Function to create a new graph node
GraphNode* createNode(int v) {
    GraphNode* newNode = (GraphNode*) malloc(sizeof(GraphNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (GraphNode**) malloc(numVertices * sizeof(GraphNode*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    GraphNode* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to perform a depth-first search on the graph
void DFS(Graph* graph, int v, int* visited, int* stack, int* top) {
    visited[v] = 1;
    GraphNode* adjList = graph->adjLists[v];
    while (adjList != NULL) {
        int adjVertex = adjList->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited, stack, top);
        }
        adjList = adjList->next;
    }
    stack[++(*top)] = v;
}

// Function to perform topological sorting on the graph
void topologicalSort(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int top = -1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack, &top);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Topological sorting order: ");
    topologicalSort(graph);
    printf("\n");

    return 0;
}
