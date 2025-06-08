class Solution {
public:
    bool subsetSum(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (idx == 0) return nums[0] == target;
        if (dp[idx][target] != -1) return dp[idx][target];

        bool notTaken = subsetSum(idx - 1, target, nums, dp);
        bool taken = false;
        if (nums[idx] <= target) {
            taken = subsetSum(idx - 1, target - nums[idx], nums, dp);
        }

        return dp[idx][target] = taken || notTaken;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for (int num : nums) totSum += num;

        if (totSum % 2 != 0) return false;

        int target = totSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return subsetSum(n - 1, target, nums, dp);
    }
};
