// 80) Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.

#include <stdio.h>

#define INF 1000000000

int main() {
    int n, i, j, k;
    scanf("%d", &n);

    int graph[n][n];
    int dist[n][n];

    // Read adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize distance matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Print shortest distance matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
