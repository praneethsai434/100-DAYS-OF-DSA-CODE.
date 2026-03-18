// 46) Problem: Level Order Traversal

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue for level order traversal
struct Queue {
    struct TreeNode *arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(struct Queue *q) {
    return q->front == q->rear;
}

void enqueue(struct Queue *q, struct TreeNode *node) {
    if (q->rear < MAX) {
        q->arr[q->rear++] = node;
    }
}

struct TreeNode* dequeue(struct Queue *q) {
    if (!isEmpty(q)) {
        return q->arr[q->front++];
    }
    return NULL;
}

// Function to perform level order traversal
void levelOrderTraversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int levelSize = q.rear - q.front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode *current = dequeue(&q);
            printf("%d ", current->val);

            if (current->left != NULL) {
                enqueue(&q, current->left);
            }
            if (current->right != NULL) {
                enqueue(&q, current->right);
            }
        }
        printf("\n"); // new line after each level
    }
}

// Helper function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Example main function
int main() {

    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    levelOrderTraversal(root);

    return 0;
}
