// 74 ) Problem Statement: Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 100

int main() {
    int n, i, j;
    char votes[MAX][LEN];
    char unique[MAX][LEN];
    int count[MAX] = {0};
    int uniqueCount = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    // Count votes for each candidate
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < uniqueCount; j++) {
            if (strcmp(votes[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(unique[uniqueCount], votes[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = count[0];
    char winner[LEN];
    strcpy(winner, unique[0]);

    for (i = 1; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
