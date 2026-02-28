//20) Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefix_sum = 0;

    // Since C doesn't have built-in hashmap easily,
    // we assume values are within reasonable range
    // For simplicity, we use frequency array with offset

    int freq[20001] = {0};   // Range handling
    int offset = 10000;      // To handle negative sums

    freq[offset] = 1;  // prefix_sum = 0 already occurred once

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(freq[prefix_sum + offset] > 0) {
            count += freq[prefix_sum + offset];
        }

        freq[prefix_sum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}
