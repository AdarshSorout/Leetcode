class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0;
        int lastEndTime = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < lastEndTime) {
                count++; 
            } else {
                lastEndTime = intervals[i][1]; 
            }
        }
        return count;
    }
};
