
class Solution {
public:
    int n;

    // Custom hash function for vector<int>
    struct VectorHash {
        std::size_t operator()(const std::vector<int>& vec) const {
            std::size_t hash = 0;
            for (int num : vec) {
                hash ^= std::hash<int>()(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };

    std::unordered_set<std::vector<int>, VectorHash> result;

    void solve(int idx, std::vector<int>& nums) {
        if (idx == n) {
            result.insert(nums); // Add the current permutation to the set
            return;
        }
        for (int i = idx; i < n; i++) {
            std::swap(nums[i], nums[idx]);
            solve(idx + 1, nums);
            std::swap(nums[i], nums[idx]); // Backtrack
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        n = nums.size();
        solve(0, nums);

        // Convert the unordered_set to a vector of vectors
        return std::vector<std::vector<int>>(result.begin(), result.end());
    }
};
