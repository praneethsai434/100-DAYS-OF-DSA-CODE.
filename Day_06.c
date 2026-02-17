//Problem 6: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include <stdio.h>

int main()
{
    int n, i, j;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    if(n == 0 || n == 1)
    {
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        return 0;
    }
    
    i = 0; 
    
    for(j = 1; j < n; j++)
    {
        if(arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    
    printf("Unique elements:\n");
    for(j = 0; j <= i; j++)
    {
        printf("%d ", arr[j]);
    }
    
    return 0;
}
