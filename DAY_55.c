// 55) Problem Statement:
//Print the nodes visible when the binary tree is viewed from the right side.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Queue {
    Node *arr[1000];
    int front, rear;
} Queue;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, Node *node) {
    q->arr[++q->rear] = node;
}

Node* dequeue(Queue *q) {
    if (isEmpty(q)) return NULL;
    return q->arr[q->front++];
}

int queueSize(Queue *q) {
    return q->rear - q->front + 1;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node *root = createNode(arr[0]);
    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;

    while (i < n && !isEmpty(&q)) {
        Node *current = dequeue(&q);

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

void printRightView(Node *root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int levelSize = queueSize(&q);

        for (int i = 0; i < levelSize; i++) {
            Node *current = dequeue(&q);

            if (i == levelSize - 1) {
                printf("%d ", current->data);
            }

            if (current->left)
                enqueue(&q, current->left);

            if (current->right)
                enqueue(&q, current->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node *root = buildTree(arr, n);
    printRightView(root);

    return 0;
}
