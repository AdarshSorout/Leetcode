class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int count = 0;
        mp[0] = 1; 
        int prefix = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int mod = ((prefix % k) + k) % k; 

            if (mp.find(mod) != mp.end()) {
                count += mp[mod];
            }

            mp[mod]++;
        }

        return count;
    }
};
