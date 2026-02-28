//27) Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to get length of list
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection node
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node *ptr1 = head1, *ptr2 = head2;

    // Move pointer of longer list
    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Traverse together
    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL, *newNode;

    // First list
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head1 == NULL) {
            head1 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Second list
    scanf("%d", &m);
    struct Node *temp2 = NULL;
    for(int i = 0; i < m; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head2 == NULL) {
            head2 = newNode;
            temp2 = newNode;
        } else {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    // Simulate intersection by matching values
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    while(ptr2 != NULL) {
        ptr1 = head1;
        while(ptr1 != NULL) {
            if(ptr1->data == ptr2->data) {
                temp2->next = ptr1; // attach intersection
                break;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr2->next;
    }

    struct Node* intersection = findIntersection(head1, head2);

    if(intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
