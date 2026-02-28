//22) Problem: Count Nodes in Linked List

#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int count = 0;

    // Read number of nodes
    scanf("%d", &n);

    // Create linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Count nodes
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Print count
    printf("%d", count);

    return 0;
}
