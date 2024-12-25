class Solution {
public:
vector<int>getnsl(vector<int>&arr,int n){
    stack<int>st;
    vector<int>result(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            result[i]=-1;
        }
        else{
            result[i]=st.top();
        }
        st.push(i);
    }
    return result;
}
vector<int>getnsr(vector<int>&arr,int n){
    stack<int>st;
    vector<int>result(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()){
            result[i]=n;
        }
        else{
            result[i]=st.top();
        }
        st.push(i);
    }
    return result;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsl=getnsl(arr,n);
        vector<int>nsr=getnsr(arr,n);

        int M=1e9+7;
        long long sum=0;
        for(int i=0;i<n;i++){
         long long ls=i-nsl[i];
         long long rs=nsr[i]-i;
         long long totalways=ls*rs;
         long long totalSum=arr[i]*totalways;
         sum=(sum+totalSum)%M;
        }
        return sum;
    }
};