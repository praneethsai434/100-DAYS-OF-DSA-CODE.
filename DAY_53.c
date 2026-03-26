// 53) Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000
#define OFFSET 1000
#define COLSIZE 2005

// ---------------------- Tree Node ----------------------
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// ---------------------- Queue for Tree Building ----------------------
typedef struct {
    Node *arr[MAXN];
    int front, rear;
} NodeQueue;

void initNodeQueue(NodeQueue *q) {
    q->front = q->rear = 0;
}

int isNodeQueueEmpty(NodeQueue *q) {
    return q->front == q->rear;
}

void enqueueNode(NodeQueue *q, Node *node) {
    q->arr[q->rear++] = node;
}

Node* dequeueNode(NodeQueue *q) {
    return q->arr[q->front++];
}

// ---------------------- Queue for BFS with HD ----------------------
typedef struct {
    Node *node;
    int hd;
} Pair;

typedef struct {
    Pair arr[MAXN];
    int front, rear;
} PairQueue;

void initPairQueue(PairQueue *q) {
    q->front = q->rear = 0;
}

int isPairQueueEmpty(PairQueue *q) {
    return q->front == q->rear;
}

void enqueuePair(PairQueue *q, Node *node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

Pair dequeuePair(PairQueue *q) {
    return q->arr[q->front++];
}

// ---------------------- Create New Node ----------------------
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ---------------------- Build Tree from Level Order ----------------------
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node *root = createNode(arr[0]);
    NodeQueue q;
    initNodeQueue(&q);
    enqueueNode(&q, root);

    int i = 1;

    while (i < n && !isNodeQueueEmpty(&q)) {
        Node *current = dequeueNode(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueueNode(&q, current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueueNode(&q, current->right);
        }
        i++;
    }

    return root;
}

// ---------------------- Vertical Order Traversal ----------------------
void verticalOrderTraversal(Node *root) {
    if (root == NULL)
        return;

    // columns[col][k] stores kth node in that vertical column
    int columns[COLSIZE][MAXN];
    int count[COLSIZE] = {0};

    int minHD = 0, maxHD = 0;

    PairQueue q;
    initPairQueue(&q);
    enqueuePair(&q, root, 0);

    while (!isPairQueueEmpty(&q)) {
        Pair p = dequeuePair(&q);
        Node *current = p.node;
        int hd = p.hd;

        int index = hd + OFFSET;
        columns[index][count[index]++] = current->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (current->left != NULL)
            enqueuePair(&q, current->left, hd - 1);

        if (current->right != NULL)
            enqueuePair(&q, current->right, hd + 1);
    }

    // Print from leftmost vertical line to rightmost
    for (int hd = minHD; hd <= maxHD; hd++) {
        int index = hd + OFFSET;
        for (int j = 0; j < count[index]; j++) {
            printf("%d", columns[index][j]);
            if (j < count[index] - 1)
                printf(" ");
        }
        printf("\n");
    }
}

// ---------------------- Main Function ----------------------
int main() {
    int n;
    scanf("%d", &n);

    int arr[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node *root = buildTree(arr, n);
    verticalOrderTraversal(root);

    return 0;
}
