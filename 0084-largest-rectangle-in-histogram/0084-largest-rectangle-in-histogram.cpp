class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int nse;
        int pse;
       int  maxArea=0;
       int element;
       int n=heights.size();
       for(int i=0;i<n;i++){
           while(!st.empty() && heights[st.top()]>heights[i]){
             element=st.top();
            st.pop();
            nse=i;
            if(st.empty()){
                pse=-1;
            }
            else{
                pse=st.top();
            }
           maxArea=max(maxArea,(nse-pse-1)*heights[element]);
           }
           st.push(i);
       }
       while(!st.empty()){
        nse=n;
        element=st.top();
        st.pop();
      if(st.empty()){
        pse=-1;
      }
      else{
        pse=st.top();
      }
      maxArea=max(maxArea,(nse-pse-1)*heights[element]);
       }
       return maxArea;
    }
};