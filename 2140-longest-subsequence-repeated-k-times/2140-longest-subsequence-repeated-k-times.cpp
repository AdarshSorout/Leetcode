class Solution {
public:
    string result = "";

    bool isSubsequence(string& s, string& sub, int k) {
        int i = 0, j = 0;
        int L = sub.size(), n = s.size();
        while (i < n && j < k * L) {
            if (s[i] == sub[j % L]) {
                j++;
            }
            i++;
        }
        return j == k * L;
    }

    void backtrack(string& s, string& curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if (curr.size() > maxLen) return;

        if ((curr.size() > result.size() || (curr.size() == result.size() && curr > result)) && isSubsequence(s, curr, k)) {
            result = curr;
        }

        for (int i = 0; i < 26; i++) {
            if (!canUse[i] || requiredFreq[i] == 0) continue;

            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            backtrack(s, curr, canUse, requiredFreq, k, maxLen);

            curr.pop_back();
            requiredFreq[i]++;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        int freq[26] = {};
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i] / k;
            }
        }

        int maxLen = n / k;
        string curr;
        backtrack(s, curr, canUse, requiredFreq, k, maxLen);
        return result;
    }
};
