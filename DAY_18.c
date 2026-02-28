//18) Problem: Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], result[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;   // Handle k > n

    // Place last k elements at beginning
    for(int i = 0; i < k; i++) {
        result[i] = arr[n - k + i];
    }

    // Place remaining elements
    for(int i = k; i < n; i++) {
        result[i] = arr[i - k];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}

