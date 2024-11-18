class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int life = 0;

                // Count live neighbors
                if (j + 1 < m && abs(board[i][j + 1]) == 1) life++;
                if (i + 1 < n && abs(board[i + 1][j]) == 1) life++;
                if (i - 1 >= 0 && abs(board[i - 1][j]) == 1) life++;
                if (j - 1 >= 0 && abs(board[i][j - 1]) == 1) life++;
                if (i + 1 < n && j + 1 < m && abs(board[i + 1][j + 1]) == 1) life++;
                if (i - 1 >= 0 && j - 1 >= 0 && abs(board[i - 1][j - 1]) == 1) life++;
                if (i - 1 >= 0 && j + 1 < m && abs(board[i - 1][j + 1]) == 1) life++;
                if (i + 1 < n && j - 1 >= 0 && abs(board[i + 1][j - 1]) == 1) life++;

                // Update state temporarily
                if (board[i][j] == 1) {
                    if (life < 2 || life > 3) 
                        board[i][j] = -1; // Live to dead
                } else if (board[i][j] == 0) {
                    if (life == 3) 
                        board[i][j] = -2; // Dead to live
                }
            }
        }

        // Finalize the board states
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == -2) 
                    board[i][j] = 1; // Dead to live
                else if (board[i][j] == -1) 
                    board[i][j] = 0; // Live to dead
            }
        }
    }
};
