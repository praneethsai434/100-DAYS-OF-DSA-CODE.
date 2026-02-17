//Problem 2: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.
#include <stdio.h>

int main()
{
    int n, pos;
    int a[100];
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &pos);

    for(int i = pos - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    for(int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
