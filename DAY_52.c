// 52) Problem Statement:
//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Find LCA in Binary Tree
Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    if (N == 0 || arr[0] == -1) {
        return 0;
    }

    // Create nodes array
    Node* nodes[N];
    for (int i = 0; i < N; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Build tree from level order
    for (int i = 0; i < N; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < N)
                nodes[i]->left = nodes[leftIndex];
            if (rightIndex < N)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    Node* root = nodes[0];
    Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}
