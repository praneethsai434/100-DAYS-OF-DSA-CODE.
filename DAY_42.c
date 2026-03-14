// 42) Given a queue of integers, reverse the queue using a stack.

#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = -1;
int rear = -1;
int top = -1;

/* Queue Operations */

void enqueue(int x)
{
    if(rear == MAX - 1)
        return;

    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue()
{
    if(front == -1 || front > rear)
        return -1;

    return queue[front++];
}

/* Stack Operations */

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

/* Reverse Queue Using Stack */

void reverseQueue()
{
    while(front <= rear)
    {
        push(dequeue());
    }

    while(top != -1)
    {
        enqueue(pop());
    }
}

int main()
{
    int N, x;

    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    reverseQueue();

    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }

    return 0;
}
