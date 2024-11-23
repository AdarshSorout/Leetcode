class Solution {
public:
    string largestOddNumber(string num) {
        int res=INT_MIN;
        int n=num.size();
        for(int i=0;i<n;i++){
            if((num[i]- '0')%2!=0){
                res=max(res,num[i]- '0');
            }
        }
        if (res == INT_MIN) {
            return ""; 
        }
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);  
            }
        }
        return "";
    }
};