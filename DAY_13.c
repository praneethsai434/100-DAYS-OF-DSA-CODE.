//13) Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];

    // Input matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    while(top <= bottom && left <= right) {

        // 1. Traverse top row (left → right)
        for(int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // 2. Traverse right column (top → bottom)
        for(int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // 3. Traverse bottom row (right → left)
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. Traverse left column (bottom → top)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}
