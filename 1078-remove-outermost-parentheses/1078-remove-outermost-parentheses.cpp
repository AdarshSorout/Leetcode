class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
       
        int n=s.size();
        vector<char>str;
for(int i=0;i<n;i++){
    if(s[i]=='('){
if(count>0){
        str.push_back(s[i]);
}count++;}
    
 else{
    count--;
    if(count>0){
        str.push_back(s[i]);
    }
}

    }
     string result(str.begin(), str.end());
    return result;}
};