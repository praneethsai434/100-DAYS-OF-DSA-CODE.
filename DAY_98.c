//98) Problem: Given intervals, merge all overlapping ones.

#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;

    return i1->start - i2->start;
}

void mergeIntervals(struct Interval intervals[], int n) {
    qsort(intervals, n, sizeof(struct Interval), compare);

    int index = 0;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= intervals[index].end) {
            if (intervals[i].end > intervals[index].end) {
                intervals[index].end = intervals[i].end;
            }
        } else {
            index++;
            intervals[index] = intervals[i];
        }
    }

    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    struct Interval intervals[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    return 0;
}
