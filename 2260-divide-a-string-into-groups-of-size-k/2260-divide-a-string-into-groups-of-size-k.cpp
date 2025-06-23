class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.size();
        
        for (int i = 0; i < n; i += k) {
            string temp = "";
            for (int j = 0; j < k; ++j) {
                if (i + j < n)
                    temp += s[i + j];
                else
                    temp += fill;
            }
            result.push_back(temp);
        }
        
        return result;
    }
};
