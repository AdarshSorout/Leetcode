class Solution {
public:
int f(int i,int buy,vector<int>& prices,int n, vector<vector<int>>&dp){
    if(i==n)return 0;
    long profit=0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy){
        profit=max(-prices[i]+f(i+1,0,prices,n,dp),
                    0+f(i+1,1,prices,n,dp));

    }
    else{
        profit=max(prices[i]+f(i+1,1,prices,n,dp),
                0+ f(i+1,0,prices,n,dp));
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2, 0), cur(2, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy)
                cur[buy] = max(-prices[i] + ahead[0], ahead[1]);
            else
                cur[buy] = max(prices[i] + ahead[1], ahead[0]);
        }
        ahead = cur;
    }

    return ahead[1];
}

};