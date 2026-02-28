//21) Problem: Create and Traverse Singly Linked List

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

    // Input number of nodes
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory for new node
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

    // Traversing the linked list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
