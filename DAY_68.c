// 68) Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void topologicalSort(int graph[MAX][MAX], int n) {
    int indegree[MAX] = {0};
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    printf("Topological Order: ");

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (j = 0; j < n; j++) {
            if (graph[u][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    if (count != n)
        printf("\nGraph contains a cycle, so topological sorting is not possible.\n");
}

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int u, v, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) for directed graph:\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort(graph, n);

    return 0;
}
