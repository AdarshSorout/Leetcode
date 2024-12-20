class Solution {
public:
    struct VectorHash {
        size_t operator()(const vector<int>& vec) const {
            hash<int> hasher;
            size_t seed = 0;
            for (int val : vec) {
                seed ^= hasher(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    void solve(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, unordered_map<vector<int>, int, VectorHash>& mp) {
        if (i >= nums.size()) {
            if (mp[temp] == 0) {
                result.push_back(temp);
            }
            mp[temp]++;
            return;
        }
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, result, mp);
        temp.pop_back();
        solve(i + 1, nums, temp, result, mp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        unordered_map<vector<int>, int, VectorHash> mp;
        sort(nums.begin(), nums.end());

        solve(0, nums, temp, result, mp);
        return result;
    }
};
