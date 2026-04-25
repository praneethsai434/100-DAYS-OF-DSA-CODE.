// 83) Problem: Implement Selection Sort - Implement the algorithm.

#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);

        if (i < n - 1)
        {
            printf(" ");
        }
    }

    return 0;
}
