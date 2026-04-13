// 71) Implement a hash table using quadratic probing with formula:

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);   // size of hash table
    scanf("%d", &q);   // number of operations

    int table[m];
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    for (int op = 0; op < q; op++) {
        char operation[10];
        int key;
        scanf("%s %d", operation, &key);

        int h = key % m;

        if (strcmp(operation, "INSERT") == 0) {
            int inserted = 0;

            for (int i = 0; i < m; i++) {
                int index = (h + i * i) % m;

                if (table[index] == EMPTY || table[index] == key) {
                    table[index] = key;
                    inserted = 1;
                    break;
                }
            }

            // If table is full or insertion not possible, ignore
            if (!inserted) {
                // do nothing
            }
        }
        else if (strcmp(operation, "SEARCH") == 0) {
            int found = 0;

            for (int i = 0; i < m; i++) {
                int index = (h + i * i) % m;

                if (table[index] == key) {
                    found = 1;
                    break;
                }

                if (table[index] == EMPTY) {
                    break;
                }
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
