class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &ch:nums){
          mp[ch]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>1){
                return true;
            }
        }
        return false;
    }
};