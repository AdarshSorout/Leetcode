class Solution {
public:
   int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (j < 0 || j >= mat[0].size()) return INT_MAX;
    if (i == 0) return mat[0][j];
    if (dp[i][j] != -1) return dp[i][j];

    int u = f(i - 1, j, mat, dp);
    int ld = f(i - 1, j - 1, mat, dp);
    int rd = f(i - 1, j + 1, mat, dp);

    int minPath = INT_MAX;
    if (u != INT_MAX) minPath = min(minPath, mat[i][j] + u);
    if (ld != INT_MAX) minPath = min(minPath, mat[i][j] + ld);
    if (rd != INT_MAX) minPath = min(minPath, mat[i][j] + rd);

    return dp[i][j] = minPath;
}


  
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = dp[i - 1][j];
                int ld, rd;

                if (j > 0) {
                    ld = dp[i - 1][j - 1];
                } else {
                    ld = INT_MAX;
                }

                if (j < m - 1) {
                    rd = dp[i - 1][j + 1];
                } else {
                    rd = INT_MAX;
                }

                dp[i][j] = matrix[i][j] + min(min(up, ld), rd);
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (dp[n - 1][j] < ans) {
                ans = dp[n - 1][j];
            }
        }

        return ans;
    }
};
