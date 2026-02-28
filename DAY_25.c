//25) Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, value, key;
    struct Node *head = NULL, *temp = NULL, *newNode;
    int count = 0;

    // Read number of nodes
    scanf("%d", &n);

    // Create linked list dynamically
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    // Read key to count
    scanf("%d", &key);

    // Traverse linked list and count occurrences
    temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    // Print result
    printf("%d\n", count);

    return 0;
}
