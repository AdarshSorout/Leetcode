class Solution {
public:
long f(int idx,int t,vector<int>&nums,vector<vector<long>>&dp){
    if(idx==0){
        return (t % nums[0]==0);
    }
if(dp[idx][t]!=-1)return dp[idx][t];
    long notTake=f(idx-1,t,nums,dp);
    long take=0;
    if(nums[idx]<=t)take=f(idx,t-nums[idx],nums,dp);
    return dp[idx][t]=take+notTake;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
       vector<vector<long>>dp(n,vector<long>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};