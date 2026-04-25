// 82)  Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

#include <stdio.h>

int lowerBound(int arr[], int n, int x)
{
    int low = 0;
    int high = n;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int upperBound(int arr[], int n, int x)
{
    int low = 0;
    int high = n;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    int n, x;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}
