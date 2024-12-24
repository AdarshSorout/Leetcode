class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        int m=nums1.size();
        int n=nums2.size();
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
          while(!st.empty() && st.top() <=nums2[i]){
           st.pop();
          }
          if(st.empty()){
            nge[i]=-1;
          }
          else{
            nge[i]=st.top();
          }
          st.push(nums2[i]);
        }
     for (int i = 0; i < n; i++) {
    mp[nums2[i]] = nge[i];
}

        for(int i=0;i<m;i++){
if(mp.find(nums1[i])!=mp.end()){
    nums1[i]=mp[nums1[i]];
}
        }
        return nums1;
    }
};