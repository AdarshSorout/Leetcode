class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        unordered_map<string,char>mp;
        stringstream ss(s);
string token;
        while(getline(ss,token,' ')){
            words.push_back(token);

        }
        set<char>used;
        int n=pattern.size();
        if(n!=words.size()){
            return false;
        }
        for(int i=0;i<n;i++){
            string word=words[i];
            char ch=pattern[i];

            if(mp.find(word)==mp.end() && used.find(ch)==used.end() ){
                used.insert(ch);
                mp[word]=ch;
            }else if(mp[word] !=ch){
                return false;
            }
        }
        return true;
    }
};