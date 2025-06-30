class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int n = nums.size();
        int maxLen = 0;

        while (r < n) {
            if (nums[r] - nums[l] == 1) {
                maxLen = max(maxLen, r - l + 1);
                r++;
            }
            else if (nums[r] == nums[l]) {
                r++;
            }
            else {
                l++;
            }
        }

        return maxLen;
    }
};
