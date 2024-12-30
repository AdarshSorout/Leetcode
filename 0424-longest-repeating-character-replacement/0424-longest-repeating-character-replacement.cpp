class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int n = s.size();
        int hash[26] = {0};
        int maxFreq = 0;
        int l = 0, r = 0;

        while (r < n) {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            while ((r - l + 1) - maxFreq > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
