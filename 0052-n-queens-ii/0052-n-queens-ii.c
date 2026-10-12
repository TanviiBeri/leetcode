
int col[20], d1[40], d2[40];
int count;

void backtrack(int row, int n) {
    if (row == n) {
        count++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col[c] || d1[row - c + n] || d2[row + c])
            continue;

        col[c] = d1[row - c + n] = d2[row + c] = 1;

        backtrack(row + 1, n);

        col[c] = d1[row - c + n] = d2[row + c] = 0;
    }
}

int totalNQueens(int n) {
    count = 0;

    for (int i = 0; i < 20; i++)
        col[i] = 0;

    for (int i = 0; i < 40; i++)
        d1[i] = d2[i] = 0;

    backtrack(0, n);

    return count;
}
