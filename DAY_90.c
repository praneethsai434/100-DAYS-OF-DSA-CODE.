// 90) Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

#include <stdio.h>

int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + boards[i] <= maxTime) {
            currentSum += boards[i];
        } else {
            painters++;
            currentSum = boards[i];

            if (painters > k) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int maxBoard = 0;
    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);

        if (boards[i] > maxBoard) {
            maxBoard = boards[i];
        }

        totalSum += boards[i];
    }

    int low = maxBoard;
    int high = totalSum;
    int answer = totalSum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", answer);

    return 0;
}
