class Solution {
public:
vector<vector<int>>res;
vector<int>ans;
     void backtrack(vector<int>&candidates,int k,int target,int sum,int start){
        
        if(sum==target && ans.size()==k){
            res.push_back(ans);
            return ;
        }
        if (sum>target){
            return ;
        }
       
        for(int i=start;i<candidates.size();i++){
            ans.push_back(candidates[i]);
            backtrack(candidates,k,target,sum+candidates[i],i+1);
            ans.pop_back();
        }
       }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        backtrack(candidates,k,n,0,0);
       return res;
    }
};