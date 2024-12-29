class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        unordered_set<int>set;
        int l=0;
        int maxans=0;
        for(int r=0;r<s.size();r++){
            if(set.find(s[r]) !=set.end()){
                while(l<r && set.find(s[r]) !=set.end()){
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
maxans=max(maxans,r-l+1);
        }
        return maxans;
    }
};