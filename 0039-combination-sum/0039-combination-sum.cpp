class Solution {
public:
    vector<vector<int>> result;
    vector<int> ans;
    
    void backtrack(vector<int>& candidates, int target, int start, int sum) {
        if (sum == target) {
            result.push_back(ans);
            return;
        }
        
        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            ans.push_back(candidates[i]);
            backtrack(candidates, target, i, sum + candidates[i]);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0, 0);
        return result;
    }
};
