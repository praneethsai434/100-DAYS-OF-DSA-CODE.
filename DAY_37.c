//37) Problem Statement:
//Implement a Priority Queue using an array. An element with smaller value has higher priority.

#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

/* Insert element in sorted order */
void insert(int x)
{
    int i;

    if(size == 0)
    {
        pq[size++] = x;
        return;
    }

    for(i = size - 1; i >= 0 && pq[i] > x; i--)
    {
        pq[i + 1] = pq[i];
    }

    pq[i + 1] = x;
    size++;
}

/* Delete highest priority element */
void deleteElement()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for(int i = 0; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

/* Peek highest priority element */
void peek()
{
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main()
{
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0)
        {
            deleteElement();
        }
        else if(strcmp(op, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}
