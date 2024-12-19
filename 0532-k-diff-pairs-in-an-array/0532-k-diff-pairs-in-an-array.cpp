class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
         unordered_map<int,int>mp;
         int i=0;
         int j=1;
         int count=0;
         while(i<n && j<n){
            if( i!=j &&abs(nums[i]-nums[j])==k){
                 count++;
                 i++;
                 j++;
                 while (i < n && nums[i] == nums[i - 1])
             i++;
            while ( j < n && nums[j] == nums[j - 1])
             j++;
            }
            else if (nums[j] - nums[i] < k) {
            j++;
        } else {
            i++;
            if (i == j) j++;
        }
         }
        return count; 

   }
};