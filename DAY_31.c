// 31)) Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

/* Function to push element into stack */
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

/* Function to pop element from stack */
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}

/* Function to display stack from top to bottom */
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, operation, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &operation);

        if (operation == 1) {
            scanf("%d", &value);
            push(value);
        }
        else if (operation == 2) {
            pop();
        }
        else if (operation == 3) {
            display();
        }
    }

    return 0;
}
