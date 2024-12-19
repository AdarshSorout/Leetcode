class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // Sort the cuts
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxHorizontalGap = max(horizontalCuts[0], h - horizontalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxHorizontalGap = max(maxHorizontalGap, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        int maxVerticalGap = max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 1; i < verticalCuts.size(); i++) {
            maxVerticalGap = max(maxVerticalGap, verticalCuts[i] - verticalCuts[i - 1]);
        }
        
        long long maxArea = (long long)maxHorizontalGap * maxVerticalGap;
        return maxArea % 1000000007;
    }
};
