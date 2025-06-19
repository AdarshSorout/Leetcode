class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vec(n);

        for (int i = 0; i < n; i++) {
            vec[i] = make_pair(nums1[i], nums2[i]);
        }

        sort(vec.begin(), vec.end(), comp);

        priority_queue<int, vector<int>, greater<int>> pq;
        long long Ksum = 0;

        for (int i = 0; i < k; i++) {
            Ksum += vec[i].first;
            pq.push(vec[i].first);
        }

        long long result = Ksum * vec[k - 1].second;

        for (int i = k; i < n; i++) {
            Ksum += vec[i].first - pq.top();
            pq.pop();
            pq.push(vec[i].first);
            result = max(result, Ksum * (long long)vec[i].second);
        }

        return result;
    }
};
