class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
           if (nums.empty()) return 0;
    int maxLength = 1, currentLength = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1]) {
            ++currentLength;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 1;
        }
    }
    return maxLength;
    }
};