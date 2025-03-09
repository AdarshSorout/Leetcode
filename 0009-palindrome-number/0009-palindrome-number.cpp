class Solution {
public:
    bool isPalindrome(int x) {
       
        string res=to_string(x);
        int n=res.size();
        int l=0;
        int r=n-1;
    if(n==1 && x>=0){
        return true;
    }
        while(l<r){
            if (res[l]==res[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        if(l>=r){
            return true ;
        }
        return false;
    }
};