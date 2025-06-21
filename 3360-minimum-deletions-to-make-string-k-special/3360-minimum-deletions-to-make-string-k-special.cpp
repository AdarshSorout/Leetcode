class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for (char ch : word) {
            mp[ch]++;
        }

        vector<int> freqs;
        for (auto it : mp) {
            freqs.push_back(it.second);
        }

        sort(freqs.begin(), freqs.end());

        int min_deletions = INT_MAX;

        for (int i = 0; i < freqs.size(); i++) {
            int target = freqs[i];
            int deletions = 0;

            for (int j = 0; j < freqs.size(); j++) {
                if (freqs[j] < target) {
                    deletions += freqs[j];  
                } else if (freqs[j] > target + k) {
                    deletions += freqs[j] - (target + k); 
                }
            }

            min_deletions = min(min_deletions, deletions);
        }

        return min_deletions;
    }
};
