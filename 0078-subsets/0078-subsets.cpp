class Solution {
public:
    vector<int>temp;
vector<vector<int>>result;
     void solve(int i,vector<int>& nums,vector<int>& temp){
        if(i>=nums.size()){
            result.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        solve(i+1,nums,temp);
     }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        solve(0,nums,temp);
        return result;
    }
};