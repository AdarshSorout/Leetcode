class Solution {
public:

int twoSum(vector<int>& nums,int closestSum,int i,int j,int n1,int target){
    int currSum;
    while(i<j){
           currSum = n1 + nums[i] + nums[j];
        if(abs(target-currSum)<abs(target-closestSum)){
          closestSum=currSum;
        }
        if(currSum<target){
         i++;}
        else if(currSum>target){
           j--;
            }
       else{return currSum;}
        }
         
            return closestSum;
            
    
}
  
    int threeSumClosest(vector<int>& nums, int target) {
        int res=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<3)
        return 0;
        int closestSum=nums[0]+nums[1]+nums[2];
         for(int i=0;i<n-2;i++){
             int n1=nums[i];
     closestSum=twoSum(nums,closestSum,i+1,n-1,n1,target);
         }
return closestSum;
    }
};