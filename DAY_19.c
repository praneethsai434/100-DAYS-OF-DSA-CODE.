//19) Problem: Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Compare function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int min_sum = INT_MAX;
    int num1, num2;

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", num1, num2);

    return 0;
}
