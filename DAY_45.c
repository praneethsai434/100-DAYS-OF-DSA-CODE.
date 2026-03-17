// 45) Find the height (maximum depth) of a given binary tree.

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for tree construction
struct Queue {
    struct Node** arr;
    int front, rear, size;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(n * sizeof(struct Node*));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->rear++;
    q->arr[q->rear] = node;
    q->size++;
}

struct Node* dequeue(struct Queue* q) {
    if (q->size == 0) return NULL;
    struct Node* temp = q->arr[q->front];
    q->front++;
    q->size--;
    return temp;
}

// Build tree from level-order traversal
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n && q->size > 0) {
        struct Node* current = dequeue(q);

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

    return root;
}

// Find height of tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("%d\n", height(root));

    return 0;
}
