class Solution {
public:
int helper(vector<int>&coins,int amount,vector<int>&dp){
     if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount] != -1)
        return dp[amount];

        int minCoins=INT_MAX;
    
            for(int i=0;i<coins.size();i++){
           int res=helper(coins,amount-coins[i],dp);
           if(res!=INT_MAX){
            minCoins=min(minCoins,1+res);
           }
            }
            return dp[amount]=minCoins;
        
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
       int result=helper(coins,amount,dp);
      if(result==INT_MAX){
        return -1;
      }
return result;

    }
};