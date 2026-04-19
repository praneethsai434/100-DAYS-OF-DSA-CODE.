// 78) Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

#include <stdio.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int visited[MAX];
int key[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph with INF
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    // Initialize key values
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    // Start from vertex 1
    key[1] = 0;

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int min = INF, u = -1;

        // Find minimum key vertex not yet visited
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update key values of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}
