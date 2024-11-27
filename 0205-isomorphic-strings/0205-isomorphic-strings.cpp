class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        set<char>used;
        int n=s.size();
        if(n!=t.size()){
            return false;
        }
        for(int i=0;i<n;i++){
            char cs=s[i];
            char ct=t[i];
            if(mp.find(cs)==mp.end() && used.find(ct)==used.end()){
                used.insert(ct);
                mp[cs]=ct;
            }else if(mp[cs]!=ct){
                return false;
            }
        }
        return true;
    }
};