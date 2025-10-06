class Solution {
public:
 bool isDigit(char n){
    for(int i=0;i<10;i++){
        if(n=='0'+i){
            return true;
        }
     
    
 }
 return false;
 }
    int myAtoi(string s) {
        int n=s.size();
        int sign = 1;
        long long ans = 0; 
        int i = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && s[i] == '+') {
            sign = 1;
            i++;
        } else if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
         while (i < n && isDigit(s[i])) {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;
            if (ans * sign > INT_MAX) return INT_MAX;
            if (ans * sign < INT_MIN) return INT_MIN;

            i++;
        }
return ans*sign;
    }
};