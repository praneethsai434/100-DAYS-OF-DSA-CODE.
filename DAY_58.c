// 58) Construct a binary tree from given preorder and inorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findIndex(int inorder[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    int rootValue = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = createNode(rootValue);

    if (inStart == inEnd) {
        return root;
    }

    int inIndex = findIndex(inorder, inStart, inEnd, rootValue);

    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorderTraversal(root);

    return 0;
}
