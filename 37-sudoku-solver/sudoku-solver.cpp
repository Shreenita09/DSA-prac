class Solution {
public:
    bool safe(char digit, int i, int j, vector<vector<char>>& board) {
        // Check column
        for (int a = 0; a < 9; a++) {
            if (board[a][j] == digit) {
                return false;
            }
        }

        // Check row
        for (int b = 0; b < 9; b++) {
            if (board[i][b] == digit) {
                return false;
            }
        }

        // Check 3x3 subgrid
        i = (i / 3) * 3;
        j = (j / 3) * 3;
        for (int a = i; a < i + 3; a++) {
            for (int b = j; b < j + 3; b++) {
                if (board[a][b] == digit) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (safe(digit, i, j, board)) {
                            board[i][j] = digit;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};