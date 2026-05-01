// 95) Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.

#include <stdio.h>
#include <stdlib.h>

void insertionSort(float bucket[], int size) {
    for (int i = 1; i < size; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float buckets[n][n];
    int bucketCount[n];

    for (int i = 0; i < n; i++) {
        bucketCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * n;

        buckets[bucketIndex][bucketCount[bucketIndex]] = arr[i];
        bucketCount[bucketIndex]++;
    }

    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCount[i]);
    }

    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
