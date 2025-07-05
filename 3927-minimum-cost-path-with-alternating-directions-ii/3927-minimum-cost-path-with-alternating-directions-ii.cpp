class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        
        vector<vector<long long>> mat(m, vector<long long>(n, 0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                mat[i][j] = 1LL*(i+1)*(j+1) + waitCost[i][j];
            }
        }

        mat[0][0] = 1;
        mat[m-1][n-1] = m*n;

        vector<vector<long long>> dp = mat;

        for(int i = 1; i<m; i++) dp[i][0] = dp[i-1][0]+mat[i][0];
        for(int i = 1; i<n; i++) dp[0][i] = dp[0][i-1]+mat[0][i];
        

        
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + mat[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};