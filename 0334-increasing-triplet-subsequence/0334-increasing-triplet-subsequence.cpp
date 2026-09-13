class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int num1=INT_MAX;
        int num2=INT_MAX;

        for(int i=0;i<n;i++){
           int  nums3=nums[i];

           if(nums3<=num1){
            num1=nums3;
           }else if(nums3<=num2){
            num2=nums3;
           }else{
            return true;
           }
        }
        return false;
    }
};