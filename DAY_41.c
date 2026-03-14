// 41) Implement a Queue using a linked list supporting enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct Node *temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main()
{
    int N;
    scanf("%d", &N);

    char operation[10];
    int value;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", operation);

        if (strcmp(operation, "enqueue") == 0)
        {
            scanf("%d", &value);
            enqueue(value);
        }
        else if (strcmp(operation, "dequeue") == 0)
        {
            dequeue();
        }
    }

    return 0;
}
