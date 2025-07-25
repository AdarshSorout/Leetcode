class Solution {
public:
    int f(int idx, int t, vector<int>& coins) {
        if (idx == 0) {
            if (t % coins[0] == 0) return t / coins[0];
            return 1e9; 
        }

        int notTake = f(idx - 1, t, coins);
        int take = 1e9;
        if (coins[idx] <= t) take = 1 + f(idx, t - coins[idx], coins);

        return min(take, notTake); 
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0)dp[0][T]=T/coins[0];
            else dp[0][T]=1e9;
        }


for(int i=1;i<n;i++){
    for(int T=0;T<=amount;T++){
int notTake=0+dp[i-1][T];
int take=1e9;
if(coins[i]<=T){
    take=1+dp[i][T-coins[i]];

}
dp[i][T]=min(take,notTake);
    }
}
int ans=dp[n-1][amount];
if(ans>=1e9)return -1;
return ans;
    }
};
