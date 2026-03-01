// 29) Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append node
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL)
        return newNode;
        
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
        
    temp->next = newNode;
    return head;
}

// Function to rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    int count = 1;
    struct Node* temp = head;

    // Count nodes and reach last node
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    k = k % count;
    if (k == 0)
        return head;

    // Make circular
    temp->next = head;

    int steps = count - k;
    struct Node* newTail = head;

    // Move to (count - k)th node
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, k, value;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = append(head, value);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}

