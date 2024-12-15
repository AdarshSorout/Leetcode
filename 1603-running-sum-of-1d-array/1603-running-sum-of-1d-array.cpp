class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prefixSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            nums[i]=prefixSum;
        }
        return nums;
    }
};