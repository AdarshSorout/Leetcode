class Solution {
public:
    bool detectCapitalUse(string word) {
        int countUpper=0;
        int countLower=0;
        int n=word.size();
        for(char ch:word){
            if(ch>='A'&&ch<='Z'){
                countUpper++;
            }
            if(ch>='a' && ch<='z'){
                countLower++;
            }

        }
        if(countLower==n || countUpper==n){
            return true;
        }
        if(countUpper==1 && word[0]<='Z' && word[0]>='A')
        return true;

       return false; 
    }
};