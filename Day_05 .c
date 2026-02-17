//Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
#include <stdio.h>

int main()
{
    int p, q, i, j, k;
    
    printf("Enter number of elements in first log: ");
    scanf("%d", &p);
    
    int arr1[p];
    
    printf("Enter %d sorted elements:\n", p);
    for(i = 0; i < p; i++)
    {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter number of elements in second log: ");
    scanf("%d", &q);
    
    int arr2[q];
    
    printf("Enter %d sorted elements:\n", q);
    for(i = 0; i < q; i++)
    {
        scanf("%d", &arr2[i]);
    }
    
    int merged[p + q];
    
    i = 0; 
    j = 0; 
    k = 0; 
  
    while(i < p && j < q)
    {
        if(arr1[i] <= arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }
    
    while(i < p)
    {
        merged[k++] = arr1[i++];
    }
    
    while(j < q)
    {
        merged[k++] = arr2[j++];
    }
    
    printf("Merged chronological log:\n");
    for(i = 0; i < p + q; i++)
    {
        printf("%d ", merged[i]);
    }
    
    return 0;
}
