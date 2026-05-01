// 96) Problem: Count number of inversions using modified merge sort.
// Inversion if i < j and a[i] > a[j].

#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;

            /*
              arr[i] > arr[j]
              Since left half is sorted,
              all elements from arr[i] to arr[mid]
              are greater than arr[j].
            */
            invCount += (mid - i + 1);
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }

    return invCount;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long invCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];
    int temp[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long answer = mergeSort(arr, temp, 0, n - 1);

    printf("%lld\n", answer);

    return 0;
}
