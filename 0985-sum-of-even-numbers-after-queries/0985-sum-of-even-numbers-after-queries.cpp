class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
int sumEven=0;
        for(auto&i:nums){
            if(i%2==0){
            sumEven+=i;
            }
        }
        vector<int>result;

for(auto&it:queries){
    int val=it[0];
    int idx=it[1];
    
 if (nums[idx]%2==0){
    sumEven-=nums[idx];
 }

 nums[idx]+=val;
 if(nums[idx]%2==0){
    sumEven+=nums[idx];
 }
result.push_back(sumEven);
}
return result;
    }
};