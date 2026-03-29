// 57) Convert a binary tree into its mirror image by swapping left and right children at every node.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Queue {
    Node **arr;
    int front, rear, size, capacity;
} Queue;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Queue* createQueue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = -1;
    q->arr = (Node**)malloc(capacity * sizeof(Node*));
    return q;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, Node *node) {
    if (q->size == q->capacity)
        return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = node;
    q->size++;
}

Node* dequeue(Queue *q) {
    if (isEmpty(q))
        return NULL;
    Node *temp = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return temp;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node *root = createNode(arr[0]);
    Queue *q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n && !isEmpty(q)) {
        Node *current = dequeue(q);

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;

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

void mirrorTree(Node *root) {
    if (root == NULL)
        return;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void inorderTraversal(Node *root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void freeTree(Node *root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node *root = buildTree(arr, n);

    mirrorTree(root);
    inorderTraversal(root);

    freeTree(root);
    free(arr);

    return 0;
}
