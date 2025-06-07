class Solution {
public:
int f(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(i>=0 && j>=0 && mat[i][j]==1){
        return 0;
    }
    if(i==0 && j==0)return 1;
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=f(i-1,j,mat,dp);
    int left=f(i,j-1,mat,dp);
    return dp[i][j]=up+left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int mod=2*10^9;
        vector<int>prev(m,0);


        for(int i=0;i<n;i++){
             vector<int>cur(m,0);
            for(int j=0;j<m;j++){
               
                if(obstacleGrid[i][j]==1){
                    cur[j]=0;
                }
                else if(i==0 && j==0){
                    cur[j]=1;
                }
                else{
                    int up=0,left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=cur[j-1];
                    cur[j]=up+left;
                }
            }
            prev=cur;
        }
     return prev[m-1];
    }
};