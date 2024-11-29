class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix=0;
        int t=0;
        int n=nums.size();
        unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        prefix+=nums[i];
        if(prefix==k){
           t++;
        }
       
        
         if(mp.find(prefix-k)!=mp.end()){
            t+=mp[prefix-k];
        }
        mp[prefix]++;
    }
    return t;
    }
};