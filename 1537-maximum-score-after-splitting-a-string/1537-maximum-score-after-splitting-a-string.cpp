class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int prefSum = 0, count = 0;
        vector<int> arr(n), left(n);

        for (int i = n - 1; i >= 0; --i) {
            arr[i] = (s[i] - '0');
            if (i < n - 1) arr[i] += arr[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            left[i] = (s[i] == '0') ? 1 : 0;
            if (i > 0) left[i] += left[i - 1];
        }

        for (int i = 0; i < n - 1; ++i) {
            count = left[i] + arr[i + 1];
            prefSum = max(count, prefSum);
        }

        return prefSum;
    }
};
