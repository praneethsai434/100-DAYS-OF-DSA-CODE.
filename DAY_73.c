// 73) Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};

    scanf("%s", s);

    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating character
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // If all characters repeat
    printf("$\n");

    return 0;
}
