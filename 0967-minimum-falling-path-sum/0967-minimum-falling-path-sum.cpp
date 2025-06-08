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
vector<int>prev(m,0),cur(m,0);

      
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = prev[j];
                int ld, rd;

                if (j > 0) {
                    ld = prev[j - 1];
                } else {
                    ld = INT_MAX;
                }

                if (j < m - 1) {
                    rd = prev[j + 1];
                } else {
                    rd = INT_MAX;
                }

                cur[j] = matrix[i][j] + min(min(up, ld), rd);
            }
            prev=cur;
        }

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (prev[j] < ans) {
                ans = prev[j];
            }
        }

        return ans;
    }
};
