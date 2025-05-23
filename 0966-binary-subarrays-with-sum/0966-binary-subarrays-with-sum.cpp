class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
    int atMost(vector<int>& nums, int goal){
        int r, l = 0, sum = 0, count = 0;
        for (r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum > goal && l <= r) {
                sum -= nums[l];
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
};