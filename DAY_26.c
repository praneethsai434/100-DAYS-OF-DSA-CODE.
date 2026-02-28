//26) Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Structure for Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode;

    // Read number of nodes
    scanf("%d", &n);

    // Insert nodes into doubly linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Traverse forward and print
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
