class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char, int> mp;
        for (auto ch : word) {
            mp[ch]++;
        }
        int n = word.size();
        int count = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word[j] == word[i]) {
                j++;
            }
            int len = j - i;
            if (len >= 2) {
                count += (len - 1);
            }
            i = j;
        }
        return 1 + count;
    }
};
