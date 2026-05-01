// 94) Problem: Sort array of non-negative integers using counting sort.

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int max = arr[0];

    // Step 1: Find maximum element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Step 2: Create frequency array
    int freq[max + 1];

    for (int i = 0; i <= max; i++) {
        freq[i] = 0;
    }

    // Step 3: Count frequency of each element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Step 4: Compute prefix sum
    for (int i = 1; i <= max; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }

    // Step 5: Build output array
    int output[n];

    // Traverse from right to left to make sorting stable
    for (int i = n - 1; i >= 0; i--) {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    // Step 6: Copy output back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
