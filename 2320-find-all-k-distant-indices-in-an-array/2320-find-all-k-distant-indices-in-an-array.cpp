class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>res;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                res.push_back(i);
            }
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<res.size();j++){
 if(abs(i-res[j])<=k){ans.push_back(i);
 break;}
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};