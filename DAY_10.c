// 10) Problem: Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int left, right, length, flag = 1;

    // Read string
    scanf("%s", s);

    // Find length of string
    length = strlen(s);

    left = 0;
    right = length - 1;

    // Two pointer comparison
    while (left < right) {
        if (s[left] != s[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if (flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
