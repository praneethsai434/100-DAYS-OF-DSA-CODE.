// 64) Problem: Perform BFS from a given source using queue.

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    return 0;
}

void bfs(int n, int adj[MAX][MAX], int source) {
    int visited[MAX] = {0};
    int i, current;

    visited[source] = 1;
    enqueue(source);

    printf("BFS Traversal Order: ");

    while (!isEmpty()) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, source;
    int adj[MAX][MAX];
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    bfs(n, adj, source);

    return 0;
}
