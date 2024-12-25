class Solution {
private:
    vector<int> ngeindex(vector<int> arr){
        int n=arr.size();
        vector<int> ans(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=n;
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> pgeeindex(vector<int> arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long submax(vector<int> arr){
        vector<int> nge=ngeindex(arr);
        vector<int> pgee=pgeeindex(arr);
        int mod=(int)(1e9+7);
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            int left=i-pgee[i];
            int right=nge[i]-i;
            sum=(sum+(left*right*1LL*arr[i]));
        }
        return sum;
    }
    vector<int> nseindex(vector<int> arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=n;
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> pseeindex(vector<int> arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long submin(vector<int> arr){
        int n=arr.size();
        vector<int> nse=nseindex(arr);
        vector<int> psee=pseeindex(arr);
        int mod=(int)(1e9+7);
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            sum=(sum+(left*right*1LL*arr[i]));
        }
        return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
       
        return (submax(nums)-submin(nums));
    }
};