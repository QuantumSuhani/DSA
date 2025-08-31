class Solution {
public:
    bool issafe(int row, int col, vector<vector<char>>& board, char val) {
        for (int i = 0; i < 9; i++) {
            // Row check
            if (board[row][i] == val) return false;

            // Column check
            if (board[i][col] == val) return false;

            // 3x3 subgrid check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) 
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') { // empty cell
                    for (char val = '1'; val <= '9'; val++) {
                        if (issafe(row, col, board, val)) {
                            board[row][col] = val;

                            if (solve(board)) return true;

                            // backtrack
                            board[row][col] = '.';
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};




