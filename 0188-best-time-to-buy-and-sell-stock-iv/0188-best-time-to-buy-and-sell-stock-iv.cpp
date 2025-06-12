class Solution {
public:
int f(int idx, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
        if (cap == 0 || idx == n) return 0;
        
        if (dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

        long profit = 0;
        if (buy) {
            profit = max(-prices[idx] + f(idx + 1, 0, cap, prices, n, dp),
                         0 + f(idx + 1, 1, cap, prices, n, dp));
        } else {
            profit = max(prices[idx] + f(idx + 1, 1, cap - 1, prices, n, dp),
                         0 + f(idx + 1, 0, cap, prices, n, dp));
        }

        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0,1,k,prices,n,dp);
    }
};