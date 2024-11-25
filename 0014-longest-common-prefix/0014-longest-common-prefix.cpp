class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string st1 = strs[0];
        string st2 = strs[strs.size() - 1];
        int idx = 0;
        while (idx < st1.size() && idx < st2.size()) {
            if (st1[idx] == st2[idx]) {
                idx++;
            } else {
                break;
            }
        }
        return st1.substr(0, idx);
    }
};
