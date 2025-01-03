class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        long long totalSum = prefSum[n - 1];
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            long long leftSum = prefSum[i];
            long long rightSum = totalSum - leftSum;
            if (leftSum >= rightSum) {
                count++;
            }
        }
        return count;
    }
};
