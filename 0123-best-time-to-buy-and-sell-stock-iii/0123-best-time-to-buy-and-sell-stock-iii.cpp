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

    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
       for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        dp[idx][buy][cap] = max(
                            -prices[idx] + dp[idx + 1][0][cap],  
                            dp[idx + 1][1][cap]                  
                        );
                    } else {
                        dp[idx][buy][cap] = max(
                            prices[idx] + dp[idx + 1][1][cap - 1],  
                            dp[idx + 1][0][cap]                    
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};
