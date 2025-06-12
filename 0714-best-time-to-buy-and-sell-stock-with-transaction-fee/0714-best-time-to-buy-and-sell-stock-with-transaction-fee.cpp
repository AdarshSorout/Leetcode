class Solution {
public:
int f(int idx,int buy,vector<int>& prices,int n, vector<vector<int>>&dp,int fee){
    if(idx==n)return 0;
    long profit=0;
    if(dp[idx][buy]!=-1)return dp[idx][buy];
    if(buy){
        profit=max(-prices[idx]+f(idx+1,0,prices,n,dp,fee),
                    0+f(idx+1,1,prices,n,dp,fee));

    }
    else{
        profit=max(prices[idx]-fee+f(idx+1,1,prices,n,dp,fee),
                0+ f(idx+1,0,prices,n,dp,fee));
    }
    return dp[idx][buy]=profit;
}
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,dp,fee);
    }
};