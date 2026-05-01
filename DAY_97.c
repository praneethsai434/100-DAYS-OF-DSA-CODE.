// 97) Problem: Given meeting intervals, find minimum number of rooms required.

#include <stdio.h>
#include <stdlib.h>

struct Meeting {
    int start;
    int end;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compareMeetings(const void *a, const void *b) {
    struct Meeting *m1 = (struct Meeting *)a;
    struct Meeting *m2 = (struct Meeting *)b;

    return m1->start - m2->start;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index]) {
            break;
        }

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest == index) {
            break;
        }

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

void removeMin(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int minMeetingRooms(struct Meeting meetings[], int n) {
    if (n == 0) {
        return 0;
    }

    qsort(meetings, n, sizeof(struct Meeting), compareMeetings);

    int heap[n];
    int heapSize = 0;

    insertHeap(heap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {
        if (heap[0] <= meetings[i].start) {
            removeMin(heap, &heapSize);
        }

        insertHeap(heap, &heapSize, meetings[i].end);
    }

    return heapSize;
}

int main() {
    int n;

    scanf("%d", &n);

    struct Meeting meetings[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    int answer = minMeetingRooms(meetings, n);

    printf("%d\n", answer);

    return 0;
}
