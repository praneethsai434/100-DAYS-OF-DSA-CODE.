// 76) Problem Statement
// Using DFS or BFS, count number of connected components.

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void dfs(int node, int n) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, n);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}
