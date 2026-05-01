// 99) Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.

#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    int speed;
};

int compareCars(const void *a, const void *b) {
    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;

    return c2->position - c1->position;
}

int carFleet(int target, struct Car cars[], int n) {
    qsort(cars, n, sizeof(struct Car), compareCars);

    int fleets = 0;
    double previousTime = 0.0;

    for (int i = 0; i < n; i++) {
        double currentTime = (double)(target - cars[i].position) / cars[i].speed;

        if (currentTime > previousTime) {
            fleets++;
            previousTime = currentTime;
        }
    }

    return fleets;
}

int main() {
    int n, target;

    scanf("%d %d", &n, &target);

    struct Car cars[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    int answer = carFleet(target, cars, n);

    printf("%d\n", answer);

    return 0;
}
