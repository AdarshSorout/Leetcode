class Solution {
public:
int findWays(int idx,int target, vector<int>&nums, vector<vector<int>>&dp){
    if(idx==0){
        if(nums[idx]==0 && target==0){
            return 2;
        }
        if(target==0 || target==nums[0]){
            return 1;
        }
        return 0;
    }
if((dp[idx][target]!=-1))return dp[idx][target];

int notTaken=findWays(idx-1,target,nums,dp);
int taken=0;
if(nums[idx]<=target)taken=findWays(idx-1,target-nums[idx],nums,dp);

return dp[idx][target]=(taken +notTaken);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            totSum+=nums[i];
        }
        if(totSum-target<0  || (totSum-target)%2==1)return 0;

        int s2=(totSum-target)/2;

        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return findWays(n-1,s2,nums,dp); 
    }
};