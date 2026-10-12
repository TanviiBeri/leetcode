
#include <stdlib.h>
#include <string.h>

char ***ans;
char **board;
int col[20], d1[40], d2[40];
int count, n;

void backtrack(int row, int *returnColumnSizes) {
    if (row == n) {
        ans[count] = malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            ans[count][i] = malloc(n + 1);
            strcpy(ans[count][i], board[i]);
        }
        returnColumnSizes[count] = n;
        count++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col[c] || d1[row - c + n] || d2[row + c])
            continue;

        board[row][c] = 'Q';
        col[c] = d1[row - c + n] = d2[row + c] = 1;

        backtrack(row + 1, *(&returnColumnSizes));

        board[row][c] = '.';
        col[c] = d1[row - c + n] = d2[row + c] = 0;
    }
}

char*** solveNQueens(int N, int* returnSize, int** returnColumnSizes) {
    n = N;
    count = 0;

    ans = malloc(1000 * sizeof(char **));
    *returnColumnSizes = malloc(1000 * sizeof(int));
    board = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        board[i] = malloc(n + 1);
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    memset(col, 0, sizeof(col));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));

    backtrack(0, *returnColumnSizes);

    *returnSize = count;

    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);

    return ans;
}
