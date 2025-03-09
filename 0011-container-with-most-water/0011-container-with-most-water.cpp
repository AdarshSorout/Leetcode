class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        int n=height.size();
        int l=0;
        int r=n-1;
        int currh=0;
        int currd=0;
        int curr_area=0;
        while(l<r){
       currh=min(height[l],height[r]);
       currd=r-l;
       curr_area=currh*currd;
       max_area=max(max_area,curr_area);
       if(height[l]<height[r]){
        l++;
       }
       else{
        r--;
       }
        }
        return max_area;
    }
};