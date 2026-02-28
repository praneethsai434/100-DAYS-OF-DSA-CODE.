// 17) Problem: Write a program to find the maximum and minimum values present in a given array of integers.

#include <stdio.h>

int main() {
    int n;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min
    int max = arr[0];
    int min = arr[0];

    // Traverse array
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Output results
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
