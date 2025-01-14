class Solution {
public:
    string orderlyQueue(string s, int k) {
       if(k>1){
        sort(s.begin(),s.end());
        return s;
       }
       string result=s;
       int n=s.size();
       for(int l=0;l<n;l++){
        string temp=s.substr(l)+s.substr(0,l);
        result=min(result,temp);
       } 
       return result;
       
    }
};