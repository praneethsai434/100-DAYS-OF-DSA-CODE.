// 65) Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

int dfs(int node, int parent, int n) {
    int i;

    visited[node] = 1;

    for (i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            if (visited[i] == 0) {
                if (dfs(i, node, n)) {
                    return 1;
                }
            }
            else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

int hasCycle(int n) {
    int i;

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, -1, n)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int n, i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (hasCycle(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
