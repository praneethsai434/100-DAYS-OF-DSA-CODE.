// 54) Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// ---------------- Tree Node ----------------
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// ---------------- Queue ----------------
typedef struct {
    Node *arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, Node *node) {
    q->arr[q->rear++] = node;
}

Node* dequeue(Queue *q) {
    return q->arr[q->front++];
}

int queueSize(Queue *q) {
    return q->rear - q->front;
}

// ---------------- Create Node ----------------
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ---------------- Build Tree from Level Order ----------------
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node *root = createNode(arr[0]);
    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;

    while (i < n && !isEmpty(&q)) {
        Node *current = dequeue(&q);

        // left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

// ---------------- Zigzag Traversal ----------------
void zigzagTraversal(Node *root) {
    if (root == NULL)
        return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int leftToRight = 1;

    while (!isEmpty(&q)) {
        int levelSize = queueSize(&q);
        int levelNodes[MAX];

        for (int i = 0; i < levelSize; i++) {
            Node *current = dequeue(&q);
            levelNodes[i] = current->data;

            if (current->left != NULL)
                enqueue(&q, current->left);

            if (current->right != NULL)
                enqueue(&q, current->right);
        }

        if (leftToRight) {
            for (int i = 0; i < levelSize; i++) {
                printf("%d ", levelNodes[i]);
            }
        } else {
            for (int i = levelSize - 1; i >= 0; i--) {
                printf("%d ", levelNodes[i]);
            }
        }

        leftToRight = !leftToRight;
    }
}

// ---------------- Main ----------------
int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node *root = buildTree(arr, n);
    zigzagTraversal(root);

    return 0;
}
