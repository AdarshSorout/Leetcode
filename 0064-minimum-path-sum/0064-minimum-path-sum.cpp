class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return INT_MAX;
if(dp[i][j]!=-1)return dp[i][j];
        int up = f(i - 1, j, grid,dp);
        int left = f(i, j - 1, grid,dp);

        return dp[i][j]=grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>cur(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0)cur[j]=grid[i][j];
                else{
                    int up=grid[i][j];
                    if(i>0)up+=prev[j];
                    else up=INT_MAX;

                    int left=grid[i][j];
                    if(j>0)left+=cur[j-1];
                    else left=INT_MAX;

                    cur[j]=min(left,up);
                }
            }
            prev=cur;
        }
        return prev[m-1];
    }
};
