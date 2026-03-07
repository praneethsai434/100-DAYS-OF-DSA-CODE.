// 35) Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = value;
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is Empty");
        return;
    }

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int n, i, value;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}
