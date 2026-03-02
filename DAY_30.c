// 30) Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Structure for Polynomial Node
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int c, int e)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node* insertEnd(struct Node *head, int c, int e)
{
    struct Node *newNode = createNode(c, e);

    if(head == NULL)
        return newNode;

    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to display polynomial
void display(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main()
{
    int n, coeff, exp;
    struct Node *head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &exp);
        head = insertEnd(head, coeff, exp);
    }

    display(head);

    return 0;
}
