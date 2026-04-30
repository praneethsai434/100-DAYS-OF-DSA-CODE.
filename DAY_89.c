// 89) Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.


#include <stdio.h>

int isPossible(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages)
            return 0;

        if (sum + pages[i] <= maxPages) {
            sum += pages[i];
        } else {
            students++;
            sum = pages[i];
        }
    }

    return students <= m;
}

int allocateBooks(int pages[], int n, int m) {
    if (m > n)
        return -1;

    int low = 0, high = 0, ans = -1;

    for (int i = 0; i < n; i++) {
        if (pages[i] > low)
            low = pages[i];
        high += pages[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(pages, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("%d", allocateBooks(pages, n, m));

    return 0;
}
