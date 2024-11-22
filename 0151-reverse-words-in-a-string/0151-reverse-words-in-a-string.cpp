class Solution {
public:
string reStr(string s) {
        stringstream ss(s);
        string token="";
        string result="";
        while(ss>>token){
            reverse(begin(token),end(token));
            result+=token + " ";
        }
    return result.substr(0,result.size()-1);
    }
   
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        return reStr(s);
    }
};