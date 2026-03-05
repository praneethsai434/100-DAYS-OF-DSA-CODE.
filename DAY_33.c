// 33) Problem: Convert an infix expression to postfix notation using stack.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char x)
{
    stack[++top] = x;
}

// Pop function
char pop()
{
    return stack[top--];
}

// Check precedence
int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;

    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        // If operand
        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        // If '(' push
        else if(ch == '(')
        {
            push(ch);
        }
        // If ')'
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}
