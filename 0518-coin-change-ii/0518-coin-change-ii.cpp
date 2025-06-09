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
    int n = coins.size();
    using ull = unsigned long long;
    vector<vector<ull>> dp(n, vector<ull>(amount + 1, 0));

    for (int T = 0; T <= amount; T++) {
        if (T % coins[0] == 0) dp[0][T] = 1;
    }

    for (int idx = 1; idx < n; idx++) {
        for (int T = 0; T <= amount; T++) {
            ull notTake = dp[idx - 1][T];
            ull take = 0;
            if (coins[idx] <= T)
                take = dp[idx][T - coins[idx]];
            dp[idx][T] = take + notTake;
        }
    }

    return dp[n - 1][amount];
}

};