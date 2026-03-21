// 48) Problem: Count Leaf Nodes

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXE 200010

int head[MAXN], to[MAXE], nextEdge[MAXE], edgeCount = 0;
int visited[MAXN];

void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
}

int countLeaves(int node) {
    visited[node] = 1;
    int childCount = 0;
    int leafCount = 0;

    for (int i = head[node]; i != -1; i = nextEdge[i]) {
        int nei = to[i];
        if (!visited[nei]) {
            childCount++;
            leafCount += countLeaves(nei);
        }
    }

    if (childCount == 0)
        return 1;

    return leafCount;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
        visited[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    int result = countLeaves(1);
    printf("%d\n", result);

    return 0;
}
