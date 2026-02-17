//Problem 1: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
#include <stdio.h>

int main()
{
    int n, pos, x;
    int a[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
  }
    scanf("%d", &pos);
    scanf("%d", &x);

    for(int i = n - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos - 1] = x;
    for(int i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
