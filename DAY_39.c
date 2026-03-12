// 39) Implement a Min Heap using an array where the smallest element is always at the root.


#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
            break;
    }
}

void heapifyDown(int index)
{
    while(1)
    {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
            break;
    }
}

void insert(int x)
{
    heap[size] = x;
    size++;

    heapifyUp(size-1);
}

void extractMin()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size-1];
    size--;

    heapifyDown(0);
}

void peek()
{
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

int main()
{
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        scanf("%s", op);

        if(strcmp(op,"insert") == 0)
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"extractMin") == 0)
        {
            extractMin();
        }
        else if(strcmp(op,"peek") == 0)
        {
            peek();
        }
    }

    return 0;
}
