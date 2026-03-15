// 43) Construct a Binary Tree from the given level-order traversal.



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order construction
typedef struct Queue {
    Node** arr;
    int front, rear, size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(size * sizeof(Node*));
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    q->arr[q->rear++] = node;
}

Node* dequeue(Queue* q) {
    return q->arr[q->front++];
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Construct tree from level order array
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = createNode(arr[0]);
    Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n && !isEmpty(q)) {
        Node* current = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }

    free(q->arr);
    free(q);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);
    inorder(root);

    return 0;
}
