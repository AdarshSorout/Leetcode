class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
         if(n<=1)
        return 0;
        int steps=0;
        int t=nums[0];
        int m=0;
        int r=0;
        while(r<n-1){
        for(int i=m;i<=r;i++){
         t=max(t,nums[i]+i);
        }
        m=r+1;
        r=t;
    steps++;
        }
        return steps;
    }
};