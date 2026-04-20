// 79) Find shortest distances from source vertex in a weighted graph with non-negative weights.

#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main() {
    int n, m;
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX];
    int i, j, u, v, w, source;

    scanf("%d %d", &n, &m);

    // Initialize graph
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Read edges
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        // If graph is undirected, also use:
        // graph[v][u] = w;
    }

    scanf("%d", &source);

    // Initialize distance and visited arrays
    for (i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    // Dijkstra's algorithm
    for (i = 1; i <= n - 1; i++) {
        int min = INF, minIndex = -1;

        // Find unvisited vertex with minimum distance
        for (j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) break;

        visited[minIndex] = 1;

        // Update distances
        for (j = 1; j <= n; j++) {
            if (!visited[j] &&
                graph[minIndex][j] != INF &&
                dist[minIndex] + graph[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }

    // Print result
    for (i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("-1 ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}
