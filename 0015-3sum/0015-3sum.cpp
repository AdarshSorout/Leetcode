class Solution {
public:
    vector<vector<int>> res;

    void twoSum(vector<int>& nums, int idx, int target, int n) {
        int l = idx, r = n - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                res.push_back({-target, nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            } 
            else if (sum < target) {
                l++;
            } 
            else {
                r--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        res.clear();
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int idx = i + 1;
            twoSum(nums, idx, target, n);
        }
        return res;
    }
};
