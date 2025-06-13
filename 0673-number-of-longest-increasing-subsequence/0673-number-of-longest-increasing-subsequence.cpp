class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> dp(n, 1);        
        vector<int> count(n, 1);    
        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] > nums[prev]){
                    if(dp[prev] + 1 > dp[i]){
                        dp[i] = dp[prev] + 1;
                        count[i] = count[prev]; 
                    }
                    else if(dp[prev] + 1 == dp[i]){
                        count[i] += count[prev]; 
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi){
                ans += count[i];
            }
        }

        return ans;
    }
};
