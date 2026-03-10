// 38) Problem: Deque (Double-Ended Queue)

#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1;
int rear = -1;

/* Check if deque is empty */
int empty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}

/* Check if deque is full */
int full()
{
    if((front == 0 && rear == MAX-1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

/* Insert at front */
void push_front(int value)
{
    if(full())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else if(front == 0)
        front = MAX - 1;
    else
        front--;

    deque[front] = value;
}

/* Insert at rear */
void push_back(int value)
{
    if(full())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else if(rear == MAX-1)
        rear = 0;
    else
        rear++;

    deque[rear] = value;
}

/* Delete from front */
void pop_front()
{
    if(empty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else if(front == MAX-1)
        front = 0;
    else
        front++;
}

/* Delete from rear */
void pop_back()
{
    if(empty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else if(rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

/* Get front element */
void get_front()
{
    if(empty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

/* Get rear element */
void get_back()
{
    if(empty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

/* Find size */
int size()
{
    if(front == -1)
        return 0;
    else if(rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

/* Clear deque */
void clear()
{
    front = rear = -1;
    printf("Deque cleared\n");
}

/* Display deque */
void display()
{
    if(empty())
    {
        printf("Deque is empty\n");
        return;
    }

    int i = front;

    printf("Deque elements: ");

    while(1)
    {
        printf("%d ", deque[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

/* Main Menu */
int main()
{
    int choice, value;

    while(1)
    {
        printf("\n----- DEQUE MENU -----\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Get Front\n");
        printf("6. Get Back\n");
        printf("7. Size\n");
        printf("8. Check Empty\n");
        printf("9. Clear\n");
        printf("10. Display\n");
        printf("11. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                get_front();
                break;

            case 6:
                get_back();
                break;

            case 7:
                printf("Size: %d\n", size());
                break;

            case 8:
                if(empty())
                    printf("Deque is empty\n");
                else
                    printf("Deque is not empty\n");
                break;

            case 9:
                clear();
                break;

            case 10:
                display();
                break;

            case 11:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
