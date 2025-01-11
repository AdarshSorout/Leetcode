class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a="";
        string b="";
        for(auto &word:word1){
            a=a+word;
        }
        for(auto & word:word2){
            b=b+word;
        }
        if(a==b){
            return true;
        }
        return false;
    }
};