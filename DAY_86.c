//86) Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.


#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid <= n) {
            ans = mid;          // mid can be answer
            low = mid + 1;      // search for greater value
        } else {
            high = mid - 1;     // mid is too large
        }
    }

    printf("%lld", ans);

    return 0;
}
