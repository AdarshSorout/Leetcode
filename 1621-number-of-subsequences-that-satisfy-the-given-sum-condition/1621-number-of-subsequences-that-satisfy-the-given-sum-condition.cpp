class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        long long sum = 0;
        int count = 0;
          int mod = 1e9 + 7;
         vector<int> power(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }
         

              while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                count = (count + power[r - l]) % mod;
                l++;
            } else {
                r--;
            }
        }

        return count;
    }
};
