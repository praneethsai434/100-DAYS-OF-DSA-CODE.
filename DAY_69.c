// 69) Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 100
#define MAXE 1000
#define INF INT_MAX

// Edge node for adjacency list
typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

Edge* graph[MAXV];

// Min-heap node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

HeapNode heap[MAXE];
int heapSize = 0;

// Swap heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into min-heap
void push(int vertex, int dist) {
    heap[++heapSize].vertex = vertex;
    heap[heapSize].dist = dist;

    int i = heapSize;
    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

// Remove minimum from heap
HeapNode pop() {
    HeapNode minNode = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int left = 2 * i, right = 2 * i + 1, smallest = i;

        if (left <= heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return minNode;
}

// Add edge to graph
void addEdge(int u, int v, int w) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->to = v;
    newEdge->weight = w;
    newEdge->next = graph[u];
    graph[u] = newEdge;
}

// Dijkstra algorithm
void dijkstra(int V, int source) {
    int dist[MAXV];
    int i;

    for (i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;
    push(source, 0);

    while (heapSize > 0) {
        HeapNode current = pop();
        int u = current.vertex;
        int d = current.dist;

        // Skip outdated heap entry
        if (d > dist[u]) continue;

        Edge* temp = graph[u];
        while (temp != NULL) {
            int v = temp->to;
            int w = temp->weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("Vertex %d -> INF\n", i);
        else
            printf("Vertex %d -> %d\n", i, dist[i]);
    }
}

int main() {
    int V = 5; // number of vertices

    for (int i = 0; i < MAXV; i++)
        graph[i] = NULL;

    // Example graph
    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(1, 4, 2);
    addEdge(2, 3, 4);
    addEdge(3, 0, 7);
    addEdge(3, 2, 6);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);

    int source = 0;
    dijkstra(V, source);

    return 0;
}
