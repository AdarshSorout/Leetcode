class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if (t.size() > n) {
            return "";
        }
        
        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }
        
        int reqCount = t.size(); 
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int start_i = 0;
        
        while (r < n) {
            char ch = s[r];
            if (mp[ch] > 0) {
                reqCount--;
            }
            mp[ch]--;
            
            while (reqCount == 0) {
                int currWindSize = r - l + 1;
                if (minLen > currWindSize) {
                    minLen = currWindSize;
                    start_i = l;
                }
                
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    reqCount++;
                }
                l++;
            }
            r++;
        }
        
        return (minLen == INT_MAX) ? "" : s.substr(start_i, minLen);
    }
};
